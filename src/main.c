#include <avr/interrupt.h>
#include <xc.h>

#include "BH1750.h"
#include "BMP.h"
#include "DHT.h"
#include "EC.h"
#include "I2C.h"
#include "USART.h"

int main() {
    // ======== INICIANDO OS M�TODOS DE COMUNICA��O E SENSORES ========

    // Iniciando o USART.
    // OBS: Para todos os comandos, verificar arquivo "USART.h"
    USART_Init(MYUBRR);

    // Iniciando o sensor BH1750 juntamente com TWI.
    // OBS: Para todos os comandos, verificar arquivo "BH1750.h" e "TWI.h"
    bh1750_init();
    uint16_t lux;

    // Vari�vel de press�o do BMP
    uint16_t pres;

    // Iniciando o rotary encoder EC11E.
    // OBS: Para todos os comandos, verificar arquivo "EC.h"
    EC_init();
    // Vari�vel para armazenar as rota��es do encoder EC11E
    uint16_t Rotations;

    // Vari�veis do DHT22
    uint8_t I_RH, D_RH, I_Temp, D_Temp, CheckSum;

    // Iniciando interrupt
    sei();

    // ================

    // ======== USART ========

    // Para printar no USART:

    uint8_t i = 0;
    unsigned char temp[] = "Temperatura: ";
    unsigned char hum[] = "Umidade: ";
    unsigned char lum[] = "Luminosidade: ";
    char luxbuff[100];
    char pre[] = "Pressao: ";
    unsigned char sent[] = "Sentido da rotacao: ";
    unsigned char puls[] = "Numero de pulsos: ";

    // ================

    while (1) {
        // ======== DHT22 ========

        // Pedir data:
        Request();  /* enviando start pulse */
        Response(); /* recebendo resposta */

        // Receber data:
        I_RH = Receive_data(); /* armazenar primeiro byte em I_RH */
        D_RH = Receive_data(); /* armazenar �ltimo byte em D_RH */
        i = 0;
        while (hum[i] != 0) /* printar temp */ {
            USART_Transmit(hum[i]);
            i++;
        }
        USART_Transmit(I_RH);
        USART_Transmit(D_RH);

        I_Temp = Receive_data(); /* armazenar primeiro byte em I_Temp */
        D_Temp = Receive_data(); /* armazenar �ltimo byte em D_Temp */
        i = 0;
        while (temp[i] != 0) /* printar temp */ {
            USART_Transmit(temp[i]);
            i++;
        }
        USART_Transmit(I_Temp);
        USART_Transmit(D_Temp);

        // Checksum n�o usado no c�digo,
        // por�m, pode ser usado para conferir
        // se os dados est�o corretos l� no Data Logger.
        CheckSum = Receive_data(); /* armazenar byte do checksum em CheckSum */

        // ======== BH1750 ========

        // Pegar n�vel de lux
        lux = bh1750_getlux();
        itoa(lux, luxbuff, 10); /* integer => string */

        // Transmitir lux para USART
        i = 0;
        while (lum[i] != 0) /* printar lum */ {
            USART_Transmit(lum[i]);
            i++;
        }

        i = 0;
        while (luxbuff[i] != 0) /* printar lux */ {
            USART_Transmit(luxbuff[i]);
            i++;
        }

        // ======== BMP180 ========

        Request_BMP();

        pres = Receive_data_BMP(__BMP_DELAY_PRESSURE_STD);
        itoa(pres, pre, 10);

        i = 0;
        while (pre[i] != 0) {
            USART_Transmit(pre[i]);
            i++;
        }
        USART_Transmit(pres);

        // ======== EC11E ========

        // Recebendo os dados do rotary encoder e transmitindo via USART
        Rotations = Receive_data_EC();
        i = 0;
        while (sent[i] != 0) {
            USART_Transmit(sent[i]);
            i++;
        }
        USART_Transmit(Rotations >> 15);

        i = 0;
        while (puls[i] != 0) {
            USART_Transmit(puls[i]);
            i++;
        }
        USART_Transmit((Rotations >> 8) &
                       0b1111111101111111);  // Trasnmitindo primeiro byte (mais
                                             // significativos)
        USART_Transmit(
            Rotations &
            0xFF);  // Transmitindo segundo byte (menos significativos))

        // ================

        // Dando Flush() no USART
        USART_Flush();
    }
    return 0;
}
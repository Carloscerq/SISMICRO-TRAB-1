#include "UTILS.h"

int main() {
    /** INICIANDO VARI�VEIS **/

    // Vari�vel de lux para o BH1750
    uint16_t lux;
    // Vari?vel de press?o do BMP
    uint16_t pres;
    // Vari?vel para armazenar as rota??es do encoder EC11E
    uint16_t Rotations;
    // Vari?veis do DHT22
    uint8_t I_RH, D_RH, I_Temp, D_Temp, CheckSum;

    // ======== USART ========
    unsigned char temp[] = "Temperatura: ";
    unsigned char hum[] = "Umidade: ";
    unsigned char lum[] = "Luminosidade: ";
    char luxbuff[100];
    unsigned char pre[] = "Pressao: ";
    char prebuff[100];
    unsigned char sent[] = "Sentido da rotacao: ";
    unsigned char puls[] = "Numero de pulsos: ";

    while (1) {
        // ======== DHT22 ========

        // Pedir data:
        Request();  /* enviando start pulse */
        Response(); /* recebendo resposta */

        // Receber data:
        I_RH = Receive_data(); /* armazenar primeiro byte em I_RH */
        D_RH = Receive_data(); /* armazenar ?ltimo byte em D_RH */
        print_word_usart(hum);
        USART_Transmit(I_RH);
        USART_Transmit(D_RH);

        I_Temp = Receive_data(); /* armazenar primeiro byte em I_Temp */
        D_Temp = Receive_data(); /* armazenar ?ltimo byte em D_Temp */
        print_word_usart(temp);
        USART_Transmit(I_Temp);
        USART_Transmit(D_Temp);

        // Checksum n?o usado no c?digo,
        // por?m, pode ser usado para conferir
        // se os dados est?o corretos l? no Data Logger.
        CheckSum = Receive_data(); /* armazenar byte do checksum em CheckSum */

        // ======== BH1750 ========

        // Pegar n?vel de lux
        lux = bh1750_getlux();
        itoa(lux, luxbuff, 10); /* integer => string */

        // Transmitir lux para USART
        print_word_usart(hum);

        print_word_usart(0);

        // ======== BMP180 ========

        Request_BMP();

        pres = Receive_data_BMP(__BMP_DELAY_PRESSURE_STD);
        itoa(pres, prebuff, 10);

        print_word_usart(pre);
        USART_Transmit(pres);

        // ======== EC11E ========

        // Recebendo os dados do rotary encoder e transmitindo via USART
        Rotations = Receive_data_EC();
        print_word_usart(sent);
        USART_Transmit(Rotations >> 15);

        print_word_usart(puls);
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
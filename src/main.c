#include <xc.h>

#include "USART.h"
#include "DHT.h"
#include "EC.h"

int main(void) {
    // Inicinado o USART.
    // OBS: Para todos os comandos, verificar arquivo "USART.h"
    USART_Init(MYUBRR);

    // Relembrando: DHT22 usa PIN6, PD6.
    uint8_t I_RH, D_RH, I_Temp, D_Temp, CheckSum;

    // Para printar no USART:
    uint8_t i = 0;
    unsigned char data[] = "Carlos e lindo";
    unsigned char temp[] = "Temperatura: ";
    unsigned char hum[] = "Umidade: ";



    while (1) {
        // Pedir data:
        Request(); /* send start pulse */
        Response(); /* receive response */

        // Receber data:
        I_RH = Receive_data(); /* store first eight bit in I_RH */
        D_RH = Receive_data(); /* store next eight bit in D_RH */
        while (data[i] != 0) /* print temp */ {
            USART_Transmit(hum[i]);
            i++;
        }
        USART_Transmit(I_RH);
        USART_Transmit(D_RH);

        I_Temp = Receive_data(); /* store next eight bit in I_Temp */
        D_Temp = Receive_data(); /* store next eight bit in D_Temp */
        while (data[i] != 0) /* print temp */ {
            USART_Transmit(temp[i]);
            i++;
        }
        USART_Transmit(I_Temp);
        USART_Transmit(I_Temp);


        CheckSum = Receive_data(); /* store next eight bit in CheckSum */




    }

    return 0;
}
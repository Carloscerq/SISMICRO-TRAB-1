#include "DHT.h"
#include "FCPU.h"

// Configura√ß√µes do DHT22
#define __DHT_Temperature_Min	-40
#define __DHT_Temperature_Max	80
#define __DHT_Humidity_Min		0
#define __DHT_Humidity_Max		100
#define __DHT_Delay_Read		20


// Vamos usar o PIN6, porta PD6

void Request() /* Microcontroller envia p start pulse/request */ {
    DDRD |= (1 << DDD6); // usar o PD6 como OUTPUT
    PORTD &= ~(1 << PB6); /* colocar como low pin */
    _delay_ms(__DHT_Delay_Read); /* wait for 20ms */
    PORTD |= (1 << PB6); /* colocar como high pin */
}

void Response() /* receber resposta do DHT22 */ {
    DDRD &= ~(1 << DDD6);
    while (PIND & (1 << PIND6));
    while ((PIND & (1 << PIND6)) == 0);
    while (PIND & (1 << PIND6));
}

uint8_t c = 0;

uint8_t Receive_data() /* receber dados do DHT22 */ {
    for (int q = 0; q < 8; q++) {
        while ((PIND & (1 << PIND6)) == 0); /* checar qual se È bit 0 ou 1 */
        _delay_us(30);
        if (PIND & (1 << PIND6))/* se o high pulse for maior do que 30us */
            c = (c << 1) | (0x01); /* È HIGH */
        else /* sen„o, È LOW */
            c = (c << 1);
        ;
        while (PIND & (1 << PIND6));
    }
    return c;
}

uint8_t Receive_PIN_data() /* receber data do PIN */ {
    c = PIND;
    return c;
}
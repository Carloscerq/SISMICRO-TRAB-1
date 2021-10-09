#include "DHT.h"

// Configurações do DHT22
#define __DHT_Temperature_Min	-40
#define __DHT_Temperature_Max	80
#define __DHT_Humidity_Min		0
#define __DHT_Humidity_Max		100
#define __DHT_Delay_Read		20


// Vamos usar o PIN6, porta PD6

void Request() /* Microcontroller send start pulse/request */ {
    DDRD |= (1 << DDD6); // usar o PD6 como OUTPUT
    PORTD &= ~(1 << PB6); /* set to low pin */
    _delay_ms(__DHT_Delay_Read); /* wait for 20ms */
    PORTD |= (1 << PB6); /* set to high pin */
}

void Response() /* receive response from DHT22 */ {
    DDRD &= ~(1 << DDD6);
    while (PIND & (1 << PIND6));
    while ((PIND & (1 << PIND6)) == 0);
    while (PIND & (1 << PIND6));
}

uint8_t c = 0;

uint8_t Receive_data() /* receive data */ {
    for (int q = 0; q < 8; q++) {
        while ((PIND & (1 << PIND6)) == 0); /* check received bit 0 or 1 */
        _delay_ms(__DHT_Delay_Read);
        if (PIND & (1 << PIND6))/* if high pulse is greater than 20ms */
            c = (c << 1) | (0x01); /* then its logic HIGH */
        else /* otherwise its logic LOW */
            c = (c << 1);
        ;
        while (PIND & (1 << PIND6));
    }
    return c;
}

uint8_t Receive_PIN_data() /* receive data from PIN */ {
    c = PIND;
    return c;
}
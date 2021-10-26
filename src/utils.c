
#include "UTILS.h"

void init_sensors_and_communication() {
    // Iniciando o USART.
    USART_Init(MYUBRR);

    // Iniciando o sensor BH1750 juntamente com TWI.
    bh1750_init();

    // Iniciando o rotary encoder EC11E.
    EC_init();

    // Iniciando interrupt
    sei();
}

uint8_t i = 0;
void print_word_usart(unsigned char word[]) {
    i = 0;
    while (word[i] != 0) {
        USART_Transmit(word[i]);
        ++i;
    }
}

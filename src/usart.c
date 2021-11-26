#include "USART.h"

void USART_Init(unsigned int ubrr) {
    /* Setar baud rate */
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;

    /* Ativar receiver etransmitter */
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);

    /* Setar frame format: 8data, 2 stop bit */
    UCSR0C = (1 << USBS0) | (3 << UCSZ00);
}

void USART_Transmit(unsigned char data) {
    /* Esperar para esvaziar o transmit buffer */
    while (!(UCSR0A & (1 << UDRE)))
        ;
    /* Colocar data no buffer (enviar data) */
    UDR0 = data;
}

unsigned char USART_Receive() {
    /* Esperar receber a data */
    while (!(UCSR0A & (1 << RXC)))
        ;
    /* Retornar data recebida no buffer */
    return UDR0;
}

void USART_Flush() {
    // Dar Flush no o Receive Buffer:
    unsigned char dummy;
    while (UCSR0A & (1 << RXC)) dummy = UDR0;
}
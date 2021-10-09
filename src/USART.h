#include <xc.h>

#define FOSC 1843200 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

// Flags:
#define 	UCSRA 	UCSR0A
#define 	UCSRB 	UCSR0B
#define 	UCSRC 	UCSR0C
#define 	UBRRH 	UBRR0H
#define 	UBRRL 	UBRR0L
#define 	UDRE 	UDRE0
#define 	UDR 	UDR0
#define 	RXC 	RXC0

void USART_Init(unsigned int ubrr);

void USART_Transmit(unsigned char data);

unsigned char USART_Receive(void);

// Flushing the Receive Buffer:
void USART_Flush(void);
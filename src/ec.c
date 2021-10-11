#include "EC.h"

// Defini��o das vari�veis
uint16_t res;
uint8_t actual_state;
uint8_t previous_state;
uint8_t direction;

void init_EC()
{

    // Vamos usar o PIN0, porta PC0 e o PIN1, porta PC1
    
    DDRC &= ~(1<<DDC0); 
    DDRC &= ~(1<<DDC1);                             // Configurando as portas de entrada
    
    OCR1AH = 0x13;                                  //Carregando o maior byte de 4882 (0x1312)
    OCR1AL = 0x12;                                  //Carregando o menor byte de 4882 (0x1312)
    
}

uint16_t Receive_data_EC()
{
    
    res = 0b00000000;                               // Zerando o contador
    
    TCCR1A = 0b00000000;
    TCCR1B = 0b00001101;                            //Ligando o modo CTC e prescaler CLK/1024
    
    previous_state = (PINC & (1<<PINC0));           //Lendo o estado do PINC0 e armazenando na vari�vel previous_state

    while (!(TIFR0 & (1 << OCF0A)))                 //Executando o loop enquanto o contador n�o atinge o valor (0x1312)
    {
        
        actual_state = (PINC & (1<<PINC0));         //Lendo novamnete o estado do PINC0 e armazenando na vari�vel actual_state
        
        if(actual_state != previous_state)          //Caso haja uma mudan�a de estado, outros pulsos est�o sendo enviados (rota��o ocorrendo)
        {
            res++;
            previous_state = actual_state;
        }  
        
    }
    
    if((PINC & (1<<PINC0)) == (PINC &(1<<PINC)))    //Comparando os sinais de input para definir a dire��o do vento
    {
        direction = 0b0000000000000000;
    } else {
        direction = 0b1000000000000000;
    }
    
    res |= direction;                               //Aplicando uma m�scara para que o MSB seja referente � dire��o
    
    TCCR1A = 0;
    TCCR1B = 0;                                     //Parando o contador
    TIFR1 = (1<<OCF1A);                             //Limpando o OCF1A para a pr�xima contagem
    
    return res;                                     //Retornando o resultado da opera��o
    
}


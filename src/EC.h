#include <xc.h>
#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>

#define F_CPU 1000000UL                             // Definindo a frequência de clock para 1MHz

#include <util/delay.h>

// Constantes para a leitura dos dados do EC11E
#define __EC_READING_TIME               5000        // Tempo de leitura do rotary encoder (5ms)
#define __EC_PULSES_PER_ROTATION		15          // Pulsos por rotação do rotary encoder 
#define __ANEMOMETER_RADIUS             100         // Raio do anemômetro (Tamanho das pás): 100 mm

void init_EC();                                     // Iniciar o EC11E;
uint8_t Receive_data_EC();                          // Receber os dados do EC11E;
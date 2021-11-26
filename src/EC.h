#include <xc.h>
#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include "FCPU.h"

#include <util/delay.h>

// Constantes para a leitura dos dados do EC11E
#define __EC_READING_TIME               5000        // Tempo de leitura do rotary encoder (5000ms)
#define __EC_PULSES_PER_ROTATION		15          // Pulsos por rotação do rotary encoder 
#define __ANEMOMETER_RADIUS             100         // Raio do anemômetro (Tamanho das p?s): 100 mm

void EC_init();                                     // Iniciar o EC11E;
uint16_t Receive_data_EC();                          // Receber os dados do EC11E;
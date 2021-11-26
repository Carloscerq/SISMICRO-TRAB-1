#include <xc.h>
#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include "FCPU.h"
#include <util/delay.h>




// Configurações do DHT22
#define __DHT_Temperature_Min	-40
#define __DHT_Temperature_Max	80
#define __DHT_Humidity_Min		0
#define __DHT_Humidity_Max		100
#define __DHT_Delay_Read		20


// Vamos usar o PIN6, porta PD6

void Request(); /* Microcontroller send start pulse/request */

void Response(); /* receive response from DHT22 */

uint8_t Receive_data(); /* receive data */
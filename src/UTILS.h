
#include <avr/interrupt.h>
#include <xc.h>

#include "BH1750.h"
#include "BMP.h"
#include "DHT.h"
#include "EC.h"
#include "I2C.h"
#include "RTC.h"
#include "USART.h"

void init_sensors_and_communication();

void print_word_usart(unsigned char word[]);
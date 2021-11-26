#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>


// Configurações do BMP180
// Pressure in hPa
// Temperature will have 16 bits
// Pressure will have 16 to 19 bits
// ULP -> Ultra Low Power
// STD -> Standard
// HR -> High Resolution
// UHR -> Ultra High Resolution
#define __BMP_PRESSURE_MIN          300
#define __BMP_PRESSURE_MAX          1100
#define __BMP_TEMPERATURE_MIN       0
#define __BMP_TEMPERATURE_MAX       60
#define __BMP_DELAY_TEMPERATURE     4.5
#define __BMP_DELAY_PRESSURE_ULP    4.5
#define __BMP_DELAY_PRESSURE_STD    7.5
#define __BMP_DELAY_PRESSURE_HR     13.5
#define __BMP_DELAY_PRESSURE_UHR    25.5
#define __BMP_I2CINIT               1
#define __BMP_ADDR_TEMP             (0x2e<<1)
#define __BMP_ADDR_PRESSURE         (0x74) //Using the default value

void Request_BMP(); /* Microcontroller send start pulse/request */

/* Should be:
 *  |
 *  | __BMP_TEMPERATURE_MAX
 *  V
 * TEMPERATURE
 *  |
 *  | PRESSURE DELAY
 *  V
 * PRESSURE
 */
uint16_t Receive_data_BMP(uint8_t TIME); /* receive data */

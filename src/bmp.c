#include "BMP.h"
#include "I2C.h"

void Request_BMP() // Microcontroller sends start pulse
{
    // Doesn't need to initialize the I2C as BH1750 should have done it
    i2c_start_wait(__BMP_ADDR_PRESSURE | I2C_WRITE);
    i2c_write(__BMP_ADDR_PRESSURE);
    i2c_stop();
}

uint16_t ret_temp, ret_press = 0;
// Variable time as it can have dif await times

uint16_t Receive_data_BMP(uint8_t TIME) {
    i2c_start_wait(__BMP_ADDR_PRESSURE | I2C_READ);
    ret_temp = i2c_readAck();
    ret_temp <<= 8;
    ret_temp |= i2c_readAck();
    ret_press = i2c_readAck();
    ret_press <<= 8;
    ret_press |= i2c_readAck();

    i2c_stop();

    return ret_press;
}
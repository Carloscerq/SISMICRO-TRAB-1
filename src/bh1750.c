#include <stdio.h>
#include "FCPU.h"
#include <util/delay.h>

#include "BH1750.h"
#include "I2C.h"

/* Init BH1750 sensor */
void bh1750_init() {

#if BH1750_I2CINIT == 1
    // Init i2c
    i2c_init();
    _delay_us(10);
#endif

    // Write config
    i2c_start_wait(BH1750_ADDR | I2C_WRITE);
    i2c_write(BH1750_MODE);
    i2c_stop();
}

/* Read lux value */
uint16_t bh1750_getlux() {
    uint16_t ret = 0;

    i2c_start_wait(BH1750_ADDR | I2C_READ);
    ret = i2c_readAck();
    ret <<= 8;
    ret |= i2c_readNak();
    i2c_stop();

    ret = ret / 1.2;
    return ret;
}

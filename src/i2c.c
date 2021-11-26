#include "I2C.h"

#include <compat/twi.h>
#include <inttypes.h>

#include "FCPU.h"

/* D i2c clock in Hz */
#define SCL_CLOCK 10000L

/* Initialization of the I2C bus interface. Need to be called only once */
void i2c_init() {
    /* Initialize TWI clock: 100 kHz clock, TWPS = 0 => prescaler = 1 */

    TWSR = 0; /* no prescaler */
    TWBR = ((F_CPU / SCL_CLOCK) - 16) /
           2; /* Formula from datasheet, must be > 10 for stable operation */
}

/* Issues a start condition and sends address and transfer direction.
  return 0 = device accessible, 1= failed to access device */
unsigned char i2c_start_with_address(unsigned char address) {
    uint8_t twst;

    // Send START condition
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

    // Wait until transmission completed
    while (!(TWCR & (1 << TWINT)))
        ;

    // Check value of TWI Status Register. Mask prescaler bits.
    twst = TW_STATUS & 0xF8;
    if ((twst != TW_START) && (twst != TW_REP_START)) return 1;

    // send device address
    TWDR = address;
    TWCR = (1 << TWINT) | (1 << TWEN);

    // Wait until transmission completed and ACK/NACK has been received
    while (!(TWCR & (1 << TWINT)))
        ;

    // Check value of TWI Status Register. Mask prescaler bits.
    twst = TW_STATUS & 0xF8;
    if ((twst != TW_MT_SLA_ACK) && (twst != TW_MR_SLA_ACK)) return 1;

    return 0;
}

/* Issues a start condition */
void i2c_start() {
    TWCR = ((1 << TWINT) | (1 << TWSTA) | (1 << TWEN));
    while (!(TWCR & (1 << TWINT)))
        ;
}

/* Issues a start condition and sends address and transfer direction.
 If device is busy, use ack polling to wait until device is ready */
void i2c_start_wait(unsigned char address) {
    uint8_t twst;

    while (1) {
        // Send START condition
        TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

        // Wait until transmission completed
        while (!(TWCR & (1 << TWINT)))
            ;

        // Send device address
        TWDR = address;
        TWCR = (1 << TWINT) | (1 << TWEN);

        // Wait until transmission completed
        while (!(TWCR & (1 << TWINT)))
            ;

        // Check value of TWI Status Register. Mask prescaler bits.
        twst = TW_STATUS & 0xF8;
        if ((twst == TW_MT_SLA_NACK) || (twst == TW_MR_DATA_NACK)) {
            /* Device busy, send stop condition to terminate write operation */
            TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);

            // Wait until stop condition is executed and bus released
            while (TWCR & (1 << TWSTO))
                ;

            continue;
        }

        break;
    }
}

/* Terminates the data transfer and releases the I2C bus */
void i2c_stop() {
    /* Send stop condition */
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

/* Send one byte to I2C device */
unsigned char i2c_write(unsigned char data) {
    uint8_t twst;

    // Send data to the previously addressed device
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);

    // Wait until transmission completed
    while (!(TWCR & (1 << TWINT)))
        ;

    // Check value of TWI Status Register. Mask prescaler bits
    twst = TW_STATUS & 0xF8;
    if (twst != TW_MT_DATA_ACK) return 1;
    return 0;
}

/* Read one byte from I2C device, request more data from device */
unsigned char i2c_readAck() {
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while (!(TWCR & (1 << TWINT)))
        ;

    return TWDR;
}

/* Read one byte from I2C device, read then a stop condition */
unsigned char i2c_readNak() {
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)))
        ;

    return TWDR;
}
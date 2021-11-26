#include <avr/io.h>

/* Defines the data direction (reading from I2C device) in i2c_start() and
 * i2c_rep_start() */
#define I2C_READ 1

 /* Defines the data direction (writing to I2C device) in i2c_start() and
  * i2c_rep_start() */
#define I2C_WRITE 0

  // Functions

  /* Initialize the I2C master interace. Need to be called only once */
extern void i2c_init();

/* Terminates the data transfer and releases the I2C bus */
extern void i2c_stop();

/* Issues a start condition and sends address and transfer direction */
extern unsigned char i2c_start_with_address(unsigned char addr);

/* Issues a start condition */
extern void i2c_start();

/* Issues a start condition and sends address and transfer direction */
extern void i2c_start_wait(unsigned char addr);

/* Send one byte to I2C device */
extern unsigned char i2c_write(unsigned char data);

/* Read one byte from the I2C device, request more data from device */
extern unsigned char i2c_readAck();

/* Read one byte from the I2C device, read is followed by a stop condition */
extern unsigned char i2c_readNak();

/* Read one byte from the I2C device
 Implemented as a macro, which calls either i2c_readAck, if ack = 1, or
 i2c_readNak, if ack = 0 */
extern unsigned char i2c_read(unsigned char ack);
#define i2c_read(ack) (ack) ? i2c_readAck() : i2c_readNak();

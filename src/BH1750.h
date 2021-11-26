#define BH1750_ADDR (0x23<<1) // Device address

// I2C settings
#define BH1750_I2CINIT 1 //init i2c

// Resolution modes
#define     BH1750_MODEH    0x10 // Continuously h-resolution mode, 1lx resolution, 120ms
#define     BH1750_MODEH2   0x11 // Continuously h-resolution mode, 0.5lx resolution, 120ms
#define     BH1750_MODEL    0x13 // Continuously l-resolution mode, 4x resolution, 16ms

// Define active resolution mode
#define     BH1750_MODE     BH1750_MODEH

// Functions
extern void bh1750_init();
extern uint16_t bh1750_getlux();

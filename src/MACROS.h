#define bit_get(p,m) ((p) & (m))
#define bit_set(p,m) ((p) |= (m))
#define bit_clear(p,m) ((p) &= ~(m))
#define bit_flip(p,m) ((p) ^= (m))
#define bit_write(c,p,m) (c ? bit_set(p,m) : bit_clear(p,m))
#define BIT(x) (0x01 << (x))
#define LONGBIT(x) ((unsigned long)0x00000001 << (x))



/**
 * === EXEMPLOS DE COMO USAR AS MACROS! ===
 * 
 * To set a bit:
    bit_set(foo, 0x01);
 * To set bit number 5:
    bit_set(foo, BIT(5));
 * To clear bit number 6 with a bit mask:
    bit_clear(foo, 0x40);
 * To flip bit number 0:
    bit_flip(foo, BIT(0));
 * To check bit number 3:
    if(bit_get(foo, BIT(3))){...}
 * To set or clear a bit based on bit number 4:
    if(bit_get(foo, BIT(4)))
    {
        bit_set(bar, BIT(0));
    }
    else
    {
        bit_clear(bar, BIT(0));
    }
 * To do it with a macro:
    bit_write(bit_get(foo, BIT(4)), bar, BIT(0));
**/ 

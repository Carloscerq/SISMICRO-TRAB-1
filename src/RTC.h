#ifndef _RTC_H_
#define _RTC_H_

#include <xc.h>

typedef struct {
    uint8_t sec;
    uint8_t min;
    uint8_t hour;
    uint8_t weekDay;
    uint8_t date;
    uint8_t month;
    uint8_t year;
} rtc_t;

/** Valores constantes no Datasheet do DS1307 **/

#define C_Ds1307ReadMode_U8 0xD1u   // DS1307 ID
#define C_Ds1307WriteMode_U8 0xD0u  // DS1307 ID

#define C_Ds1307SecondRegAddress_U8 \
    0x00u  // Address to access Ds1307 SEC register
#define C_Ds1307DateRegAddress_U8 \
    0x04u  // Address to access Ds1307 DATE register
#define C_Ds1307ControlRegAddress_U8 \
    0x07u  // Address to access Ds1307 CONTROL register

/** ---- **/

void RTC_Init();
void RTC_SetDateTime(rtc_t* rtc);
void RTC_GetDateTime(rtc_t* rtc);

#endif

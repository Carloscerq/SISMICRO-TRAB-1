#include <avr/interrupt.h>
#include <xc.h>

#include "BH1750.h"
#include "BMP.h"
#include "DHT.h"
#include "EC.h"
#include "ESP.h"
#include "FILTER.h"
#include "I2C.h"
#include "RTC.h"
#include "USART.h"

int main(void) {
    // ======== INICIANDO OS M�TODOS DE COMUNICA��O E SENSORES ========

    // OBS: Para todos os comandos, verificar arquivo "USART.h"
    USART_Init(MYUBRR); // Iniciando o USART.


    // OBS: Para todos os comandos, verificar arquivo "BH1750.h" e "TWI.h"
    bh1750_init();
    uint16_t lux; // Iniciando o sensor BH1750 juntamente com TWI.

    uint16_t pres; // Vari�vel de press�o do BMP

    // OBS: Para todos os comandos, verificar arquivo "EC.h"
    EC_init(); // Iniciando o rotary encoder EC11E.

    uint16_t Rotations; // Vari�vel para armazenar as rota��es do encoder EC11E

    // Vari�veis do DHT22
    uint8_t I_RH, D_RH, I_Temp, D_Temp;
    // uint8_t CheckSum;

    uint8_t Connect_Status; // Status da conex�o

    // RTC:
    rtc_t rtc;
    RTC_Init();
    rtc.hour = rtc.min = rtc.sec = rtc.date = rtc.month = rtc.year = rtc.weekDay = 0;
    RTC_SetDateTime(&rtc);


    sei(); // Iniciando interrupt

    // ================

    // ======== ESP8266 ========

    // Para enviar via ESP8266:
    // char temp[] = "Temperatura: ";
    // char hum[] = "Umidade: ";
    // char lum[] = "Luminosidade: ";
    // char luxbuff[100];
    // char pre[] = "Pressao: ";
    // char sent[] = "Sentido da rotacao: ";
    // char puls[] = "Numero de pulsos: ";

    // ================

    // ======== Inicializa��o do ESP8266 e conex�o com a rede ========

    while (!ESP8266_Begin())
        ;

    ESP8266_WIFIMode(BOTH_STATION_AND_ACCESPOINT); /* 3 = Both (AP and STA) */
    ESP8266_ConnectionMode(SINGLE); /* 0 = Single; 1 = Multi */
    ESP8266_ApplicationMode(NORMAL); /* 0 = Normal Mode; 1 = Transperant Mode */
    if (ESP8266_connected() == ESP8266_NOT_CONNECTED_TO_AP)
        ESP8266_JoinAccessPoint(SSID, PASSWORD);
    ESP8266_Start(0, DOMAIN, PORT);

    while (1) {
        // ======== ESP8266 ========

        // Verificando a conex�o

        Connect_Status = ESP8266_connected();
        if (Connect_Status == ESP8266_NOT_CONNECTED_TO_AP)
            ESP8266_JoinAccessPoint(SSID, PASSWORD);
        if (Connect_Status == ESP8266_TRANSMISSION_DISCONNECTED)
            ESP8266_Start(0, DOMAIN, PORT);

        // ========= RTC =========

        // Pedir time:
        RTC_GetDateTime(&rtc);

        ESP8266_Send((uint16_t)rtc.hour);
        _delay_ms(THINGSPEAKER_DELAY);
        ESP8266_Send((uint16_t)rtc.min);
        _delay_ms(THINGSPEAKER_DELAY);
        ESP8266_Send((uint16_t)rtc.sec);
        _delay_ms(THINGSPEAKER_DELAY);

        ESP8266_Send((uint16_t)rtc.date);
        _delay_ms(THINGSPEAKER_DELAY);
        ESP8266_Send((uint16_t)rtc.month);
        _delay_ms(THINGSPEAKER_DELAY);
        ESP8266_Send((uint16_t)rtc.year);
        _delay_ms(THINGSPEAKER_DELAY);
        ESP8266_Send((uint16_t)rtc.weekDay);
        _delay_ms(THINGSPEAKER_DELAY);

        // ======== DHT22 ========

        // Pedir data:

        Request(); /* enviando start pulse */
        Response(); /* recebendo resposta */

        // Receber data:

        I_RH = Receive_data(); /* armazenar primeiro byte em I_RH */
        D_RH = Receive_data(); /* armazenar �ltimo byte em D_RH */

        ESP8266_Send(I_RH);
        _delay_ms(THINGSPEAKER_DELAY);

        ESP8266_Send(D_RH);
        _delay_ms(THINGSPEAKER_DELAY);

        I_Temp = Receive_data(); /* armazenar primeiro byte em I_Temp */
        D_Temp = Receive_data(); /* armazenar �ltimo byte em D_Temp */

        ESP8266_Send(I_Temp);
        _delay_ms(THINGSPEAKER_DELAY);

        ESP8266_Send(D_Temp);
        _delay_ms(THINGSPEAKER_DELAY);

        // Checksum n�o usado no c�digo, por�m, pode ser usado para conferir se os dados est�o corretos l� no Data Logger.
        // CheckSum = Receive_data(); /* armazenar byte do checksum em CheckSum */

        Receive_data();

        // ======== BH1750 ========

        lux = bh1750_getlux();
        // itoa(lux, luxbuff, 10); /* integer => string */

        ESP8266_Send(lux);
        _delay_ms(THINGSPEAKER_DELAY);

        // ======== BMP180 ========

        Request_BMP();

        pres = Receive_data_BMP(__BMP_DELAY_PRESSURE_STD);

        ESP8266_Send(pres);
        _delay_ms(THINGSPEAKER_DELAY);

        // ======== EC11E ========


        Rotations = Receive_data_EC(); // Recebendo os dados do rotary encoder

        ESP8266_Send(Rotations);
        _delay_ms(THINGSPEAKER_DELAY);
    }
    return 0;
}
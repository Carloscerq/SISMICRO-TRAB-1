#include <xc.h>
#include <avr/interrupt.h>

#include "USART.h"
#include "I2C.h"
#include "DHT.h"
#include "BH1750.h"
#include "BMP.h"
#include "EC.h"
#include "ESP.h"

int main(void) {
    // ======== INICIANDO OS MÉTODOS DE COMUNICAÇÃO E SENSORES ========

    // Iniciando o USART.
    // OBS: Para todos os comandos, verificar arquivo "USART.h"
    USART_Init(MYUBRR);

    // Iniciando o sensor BH1750 juntamente com TWI.
    // OBS: Para todos os comandos, verificar arquivo "BH1750.h" e "TWI.h"
    bh1750_init();
    uint16_t lux;

    // Variável de pressão do BMP
    uint16_t pres;

    // Iniciando o rotary encoder EC11E.
    // OBS: Para todos os comandos, verificar arquivo "EC.h"
    EC_init();
    // Variável para armazenar as rotações do encoder EC11E
    uint16_t Rotations;

    // Variáveis do DHT22
    uint8_t I_RH, D_RH, I_Temp, D_Temp;
    // uint8_t CheckSum;
    
    // Status da conexão
    uint8_t Connect_Status;

    // Iniciando interrupt
    sei();


    // ================

    // ======== ESP8266 ========

    // Para enviar via ESP8266:

    //char temp[] = "Temperatura: ";
    //char hum[] = "Umidade: ";
    //char lum[] = "Luminosidade: ";
    //char luxbuff[100];
    //char pre[] = "Pressao: ";
    //char sent[] = "Sentido da rotacao: ";
    //char puls[] = "Numero de pulsos: ";

    // ================

    // ======== Inicialização do ESP8266 e conexão com a rede ========
    
    while(!ESP8266_Begin());
    
	ESP8266_WIFIMode(BOTH_STATION_AND_ACCESPOINT);/* 3 = Both (AP and STA) */
	ESP8266_ConnectionMode(SINGLE);		/* 0 = Single; 1 = Multi */
	ESP8266_ApplicationMode(NORMAL);	/* 0 = Normal Mode; 1 = Transperant Mode */
	if(ESP8266_connected() == ESP8266_NOT_CONNECTED_TO_AP)
	ESP8266_JoinAccessPoint(SSID, PASSWORD);
	ESP8266_Start(0, DOMAIN, PORT);
    
    while (1) {
        
        // ======== ESP8266 ========
        // Verificando a conexão
        
        Connect_Status = ESP8266_connected();
		if(Connect_Status == ESP8266_NOT_CONNECTED_TO_AP)
		ESP8266_JoinAccessPoint(SSID, PASSWORD);
		if(Connect_Status == ESP8266_TRANSMISSION_DISCONNECTED)
		ESP8266_Start(0, DOMAIN, PORT);
        
        // ======== DHT22 ========

        // Pedir data:
        Request(); /* enviando start pulse */
        Response(); /* recebendo resposta */

        // Receber data:
        I_RH = Receive_data(); /* armazenar primeiro byte em I_RH */
        D_RH = Receive_data(); /* armazenar último byte em D_RH */
        //i = 0;
        
        
        ESP8266_Send(I_RH);
		_delay_ms(THINGSPEAKER_DELAY);	
        
        ESP8266_Send(D_RH);
		_delay_ms(THINGSPEAKER_DELAY);	

        I_Temp = Receive_data(); /* armazenar primeiro byte em I_Temp */
        D_Temp = Receive_data(); /* armazenar último byte em D_Temp */
        
        ESP8266_Send(I_Temp);
		_delay_ms(THINGSPEAKER_DELAY);	
        
        ESP8266_Send(D_Temp);
		_delay_ms(THINGSPEAKER_DELAY);	
        
        // Checksum não usado no código,
        // porém, pode ser usado para conferir
        // se os dados estão corretos lá no Data Logger.
        // CheckSum = Receive_data(); /* armazenar byte do checksum em CheckSum */
        Receive_data();
           
        // ======== BH1750 ========


        // Pegar nível de lux
        lux = bh1750_getlux();
        // itoa(lux, luxbuff, 10); /* integer => string */
        
        // Transmitir lux para USART
        ESP8266_Send(lux);
		_delay_ms(THINGSPEAKER_DELAY);


        // ======== BMP180 ========

        Request_BMP();

        pres = Receive_data_BMP(__BMP_DELAY_PRESSURE_STD);

        ESP8266_Send(pres);
		_delay_ms(THINGSPEAKER_DELAY);


        // ======== EC11E ========

        // Recebendo os dados do rotary encoder e transmitindo via USART
        Rotations = Receive_data_EC();

        ESP8266_Send(Rotations);
		_delay_ms(THINGSPEAKER_DELAY);

    }
    return 0;
}
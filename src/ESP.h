#include "FCPU.h"

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "USART.h"


#define SREG    _SFR_IO8(0x3F)

#define DEFAULT_BUFFER_SIZE		160
#define DEFAULT_TIMEOUT			10000

/* Connection Mode */
#define SINGLE				0
#define MULTIPLE			1

/* Application Mode */
#define NORMAL				0
#define TRANSPERANT			1

/* Application Mode */
#define STATION				1
#define ACCESSPOINT			2
#define BOTH_STATION_AND_ACCESPOINT	3

#define RECEIVE_DEMO

/* Configura��o - Thingspeak */
#define DOMAIN				"api.thingspeak.com"
#define PORT				"80"
#define API_WRITE_KEY		"api_write_key"
#define CHANNEL_ID			"channel_id"

#define SSID				"ssid"
#define PASSWORD			"password"

#define THINGSPEAKER_DELAY  15000

enum ESP8266_RESPONSE_STATUS {
	ESP8266_RESPONSE_WAITING,
	ESP8266_RESPONSE_FINISHED,
	ESP8266_RESPONSE_TIMEOUT,
	ESP8266_RESPONSE_BUFFER_FULL,
	ESP8266_RESPONSE_STARTING,
	ESP8266_RESPONSE_ERROR
};

enum ESP8266_CONNECT_STATUS {
	ESP8266_CONNECTED_TO_AP,
	ESP8266_CREATED_TRANSMISSION,
	ESP8266_TRANSMISSION_DISCONNECTED,
	ESP8266_NOT_CONNECTED_TO_AP,
	ESP8266_CONNECT_UNKNOWN_ERROR
};

enum ESP8266_JOINAP_STATUS {
	ESP8266_WIFI_CONNECTED,
	ESP8266_CONNECTION_TIMEOUT,
	ESP8266_WRONG_PASSWORD,
	ESP8266_NOT_FOUND_TARGET_AP,
	ESP8266_CONNECTION_FAILED,
	ESP8266_JOIN_UNKNOWN_ERROR
};


uint8_t ESP8266_Start(uint8_t _ConnectionNumber, const char* Domain, const char* Port); // Iniciar o ESP

void ESP8266_Clear(); // Limpar o ESP8266

void Start_Read_Response(char _ExpectedResponse[]); // Iniciar a leitura da Response
void Read_Response(char _Expected_Response[]); // Ler a Response
bool WaitForExpectedResponse(char ExpectedResponse[]); // Conferir a Response
bool SendATandExpectResponse(char ATCommand[], char ExpectedResponse[]); // Enviar o comando AT

bool ESP8266_ApplicationMode(const uint8_t Mode); // Definir o Application Mode
bool ESP8266_ConnectionMode(const uint8_t Mode); // Definir o Connection Mode
bool ESP8266_WIFIMode(const uint8_t _mode); // Definir o WIFI Mode

uint8_t ESP8266_JoinAccessPoint(const char _SSID[], const char _PASSWORD[]); // Configura��o do ponto de acesso
uint8_t ESP8266_connected(); // Status da conex�o do ESP

uint8_t ESP8266_Send(char Data[]); // Envio de dados pelo ESP
int16_t ESP8266_DataAvailable(); // Verifica��o da disponibilidade de dados
uint16_t Read_Data(char _buffer[]);
uint8_t ESP8266_DataRead(); // Leitura de dados

bool ESP8266_Begin(); // Iniciar a comunica��o
void GetResponseBody(char Response[], uint16_t ResponseLength); // Extrair o corpo da Response
bool ESP8266_Close(); // Fechar o comunica��o

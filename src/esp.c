#include "ESP.h"

int8_t Response_Status;
volatile int16_t Counter = 0, pointer = 0;
uint32_t TimeOut = 0;
char RESPONSE_BUFFER[DEFAULT_BUFFER_SIZE];

uint8_t ESP8266_Start(uint8_t _ConnectionNumber, const char* Domain, const char* Port) {
	bool _startResponse;
	char _atCommand[60];
	memset(_atCommand, 0, 60);
	_atCommand[59] = 0;

    char _expectedResponse[] = "CONNECT\r\n";
    
	_startResponse = SendATandExpectResponse(_atCommand, _expectedResponse);
    
	if(!_startResponse)	{
		if(Response_Status == ESP8266_RESPONSE_TIMEOUT)
		return ESP8266_RESPONSE_TIMEOUT;
		return ESP8266_RESPONSE_ERROR;
	}
    
	return ESP8266_RESPONSE_FINISHED;
}

void ESP8266_Clear()
{
	memset(RESPONSE_BUFFER,0,DEFAULT_BUFFER_SIZE);
	Counter = 0;	pointer = 0;
}

void Start_Read_Response(char* _ExpectedResponse) {
	Response_Status = ESP8266_RESPONSE_STARTING;
	do {
		Read_Response(_ExpectedResponse);
	} while(Response_Status == ESP8266_RESPONSE_WAITING);
}

void Read_Response(char* _Expected_Response) {
  uint8_t EXPECTED_RESPONSE_LENGTH = strlen(_Expected_Response);
  uint32_t TimeCount = 0, ResponseBufferLength;
  char RECEIVED_CRLF_BUF[EXPECTED_RESPONSE_LENGTH];

  while(1)
  {
    if(TimeCount >= (DEFAULT_TIMEOUT+TimeOut))
    {
	TimeOut = 0;
	Response_Status = ESP8266_RESPONSE_TIMEOUT;
	return;
    }

    if(Response_Status == ESP8266_RESPONSE_STARTING)
    {
	Response_Status = ESP8266_RESPONSE_WAITING;
    }

    ResponseBufferLength = strlen(RESPONSE_BUFFER);
    if (ResponseBufferLength)
    {
	_delay_ms(1);
	TimeCount++;
	if (ResponseBufferLength==strlen(RESPONSE_BUFFER))
	{
	    for (uint16_t i=0;i<ResponseBufferLength;i++)
	    {
		memmove(RECEIVED_CRLF_BUF, RECEIVED_CRLF_BUF + 1, EXPECTED_RESPONSE_LENGTH-1);
		RECEIVED_CRLF_BUF[EXPECTED_RESPONSE_LENGTH-1] = RESPONSE_BUFFER[i];
		if(!strncmp(RECEIVED_CRLF_BUF, _Expected_Response, EXPECTED_RESPONSE_LENGTH))
		{
			TimeOut = 0;
			Response_Status = ESP8266_RESPONSE_FINISHED;
			return;
		}
	    }
	}
    }
    _delay_ms(1);
    TimeCount++;
  }
}

bool WaitForExpectedResponse(char* ExpectedResponse) {
	Start_Read_Response(ExpectedResponse);	
	if((Response_Status != ESP8266_RESPONSE_TIMEOUT)) {
        return true;
    }
	return false;				
}

bool SendATandExpectResponse(char* ATCommand, char* ExpectedResponse) {
    
	ESP8266_Clear();
    
    int i = 0;
    
    while (ATCommand[i] != 0) {
        USART_Transmit(ATCommand[i]);
        i++;
    }
    
	USART_Transmit('\r');
    USART_Transmit('\n');
    
	return WaitForExpectedResponse(ExpectedResponse);
    
}

bool ESP8266_ApplicationMode(const uint8_t Mode) {
	char _atCommand[20];
	memset(_atCommand, 0, 20);
	sprintf(_atCommand, "AT+CIPMODE=%d", Mode);
	_atCommand[19] = 0;
    
    char _expectedResponse[] = "\r\nOK\r\n";
    
	return SendATandExpectResponse(_atCommand, _expectedResponse);
}

bool ESP8266_ConnectionMode(const uint8_t Mode) {
	char _atCommand[20];
	memset(_atCommand, 0, 20);
	sprintf(_atCommand, "AT+CIPMUX=%d", Mode);
	_atCommand[19] = 0;
    
    char _expectedResponse[] = "\r\nOK\r\n";
    
	return SendATandExpectResponse(_atCommand, _expectedResponse);
}

bool ESP8266_WIFIMode(const uint8_t _mode) {
	char _atCommand[20];
	memset(_atCommand, 0, 20);
	sprintf(_atCommand, "AT+CWMODE=%d", _mode);
	_atCommand[19] = 0;
    
    char _expectedResponse[] = "\r\nOK\r\n";
    
	return SendATandExpectResponse(_atCommand, _expectedResponse);
}

uint8_t ESP8266_JoinAccessPoint(const char* _SSID, const char* _PASSWORD) {
    
	char _atCommand[60];
	memset(_atCommand, 0, 60);
	sprintf(_atCommand, "AT+CWJAP=\"%s\",\"%s\"", _SSID, _PASSWORD);
	_atCommand[59] = 0;
    
    char _expectedResponse[] = "\r\nWIFI CONNECTED\r\n";
    
	if(SendATandExpectResponse(_atCommand, _expectedResponse))
	return ESP8266_WIFI_CONNECTED;
	else{
		if(strstr(RESPONSE_BUFFER, "+CWJAP:1"))
		return ESP8266_CONNECTION_TIMEOUT;
		else if(strstr(RESPONSE_BUFFER, "+CWJAP:2"))
		return ESP8266_WRONG_PASSWORD;
		else if(strstr(RESPONSE_BUFFER, "+CWJAP:3"))
		return ESP8266_NOT_FOUND_TARGET_AP;
		else if(strstr(RESPONSE_BUFFER, "+CWJAP:4"))
		return ESP8266_CONNECTION_FAILED;
		else
		return ESP8266_JOIN_UNKNOWN_ERROR;
	}
    
}

uint8_t ESP8266_connected() {
    
    char _atcommand[] = "AT+CIPSTATUS";
    char _expectedResponse[] = "\r\nOK\r\n";
    
	SendATandExpectResponse(_atcommand, _expectedResponse);
	if(strstr(RESPONSE_BUFFER, "STATUS:2"))
	return ESP8266_CONNECTED_TO_AP;
	else if(strstr(RESPONSE_BUFFER, "STATUS:3"))
	return ESP8266_CREATED_TRANSMISSION;
	else if(strstr(RESPONSE_BUFFER, "STATUS:4"))
	return ESP8266_TRANSMISSION_DISCONNECTED;
	else if(strstr(RESPONSE_BUFFER, "STATUS:5"))
	return ESP8266_NOT_CONNECTED_TO_AP;
	else
	return ESP8266_CONNECT_UNKNOWN_ERROR;
    
}

uint8_t ESP8266_Send(char* Data) {
	char _atCommand[20];
	memset(_atCommand, 0, 20);
	sprintf(_atCommand, "AT+CIPSEND=%d", (strlen(Data)+2));
	_atCommand[19] = 0;
    
    char _expectedResponse[] = "\r\nOK\r\n>";
    char _expectedResponseSend[] = "\r\nSEND OK\r\n";
    
	SendATandExpectResponse(_atCommand, _expectedResponse);
	if(!SendATandExpectResponse(Data, _expectedResponseSend)) {
		if(Response_Status == ESP8266_RESPONSE_TIMEOUT)
		return ESP8266_RESPONSE_TIMEOUT;
		return ESP8266_RESPONSE_ERROR;
	}
	return ESP8266_RESPONSE_FINISHED;
}

int16_t ESP8266_DataAvailable() {
	return (Counter - pointer);
}

uint16_t Read_Data(char* _buffer) {
    
	uint16_t len = 0;
	_delay_ms(100);
	while(ESP8266_DataAvailable() > 0)
	_buffer[len++] = ESP8266_DataRead();
	return len;

}

uint8_t ESP8266_DataRead() {
    
	if(pointer < Counter)
	return RESPONSE_BUFFER[pointer++];
	else{
		ESP8266_Clear();
		return 0;
	}
    
}

bool ESP8266_Begin() {
    
    char _atCommandE[] = "ATE0";
    char _atCommand[] = "AT";
    
    char _expectedResponse[] = "\r\nOK\r\n";
    
	for (uint8_t i=0;i<5;i++)
	{
		if(SendATandExpectResponse(_atCommandE, _expectedResponse)||SendATandExpectResponse(_atCommand, _expectedResponse))
		return true;
	}
	return false;
    
}

void GetResponseBody(char* Response, uint16_t ResponseLength) {

	uint16_t i = 12;
	char buffer[5];
	while(Response[i] != '\r')
	++i;

	strncpy(buffer, Response + 12, (i - 12));
	ResponseLength = atoi(buffer);

	i += 2;
	uint16_t tmp = strlen(Response) - i;
	memcpy(Response, Response + i, tmp);

	if(!strncmp(Response + tmp - 6, "\r\nOK\r\n", 6))
	memset(Response + tmp - 6, 0, i + 6);
}

bool ESP8266_Close() {
    
    char _atCommand[] = "AT+CIPCLOSE=1";
    char _expectedResponse[] = "\r\nOK\r\n";
    
	return SendATandExpectResponse(_atCommand, _expectedResponse);
}



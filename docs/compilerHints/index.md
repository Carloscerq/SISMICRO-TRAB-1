# Dicas do compilador

O atmega328 tem pouca memoria e estrutura de 8 bits por isso, é importante que sigamos algumas dicas para melhorar o desempenho.

- #### Usar variáveis de 8 bits
- #### Evitar recursão
- #### Evite alocar grande quantidade de variáveis locais. Em vez disso, use variáveis globais.
- #### Evite passar variáveis e estruturas por valor. Em vez disso, passe por referência, com um ponteiro (*).
- #### Não use recursão
- #### Cuidado com StackOverflow

## Tipos

| Traditional Names | Portable Name | Bytes | Max | Min                |
| ----------------- | ------------- | ----- | ------------------------ | --- |
| signed char       | int8_t        | 1     | 127 | -128               |
| unsigned char     | uint8_t       | 1     | 255 | 0                  |
| signed int        | int16_t       | 2     | 32767 | -32768           |
| unsigned int      | uint16_t      | 2     | 65535 | 0                |
| signed long       | int32_t       | 4     | 2147483647 | -2147483648 |
| unsigned long     | uint32_t      | 4     | 4294967295 | 0           |

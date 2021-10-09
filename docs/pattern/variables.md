# Variáveis

Usar camelCase para variáveis e SCREAMING_SNAKE_CASE para constantes.

- ## Use nomes que mostrem a intenção

```c
int i // x
int index // ✔
float temp1, temp2 // x
float initialTemperature, finalTemperature // ✔
```

- ## Substitua numeros magicos por constantes
Importante ressaltar a que talvez seja melhor coloca-los no EEPROM
```c
7 // x
#define NUMBER_CHECKS_DAY 7 // ✔
const int DAYS_SINCE_ERROR = 15; // ✔
```

- ## Utilize substantivos para nomear variáveis

```c
bool umidityHandler // x
bool handleUmidity // ✔
```

- ## Utilize termos relacionados à área
Todo mundo aqui é estudante de engenharia

```c
int transactionStorage // x
int transactionCache // ✔
```

- ## Evite prefixos e sufixos auto-explicativos

```c
float [] temperatureHistoryArray // x
float [] temperatureHistory // ✔
```
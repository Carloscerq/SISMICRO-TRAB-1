# Funções

Usar PascalCase para nome de funções

```c

int function_handle_this(*params){return this} // x
int FunctionHandleThis(*params){return this} // ✔

```

- ## Evite duplicatas
Evite ter varias funções que realizem a mesma coisa

- ## Faça funções especialistas
 Funções devem , idealmente, ser pequenas e realizar uma unica atividade

- ## Agrupe por funcionalidade

- ## Tente não passar booleanos como parametros
Veja se é possivel ter aquela logica interna a função

- ## Faça um breve comentario explicando a função antes da sua declaração (Ideal: 2 linhas)
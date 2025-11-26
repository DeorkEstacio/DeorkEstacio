#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Tamanho máximo da fila

// Estrutura que representa uma peça
typedef struct {
    char tipo[2]; // 1 caractere + terminador nulo
    int id;
} Peca;

// Estrutura que representa a fila circular
typedef struct {
    Peca itens[MAX];
    int inicio;
    int fim;
    int total;
} Fila;
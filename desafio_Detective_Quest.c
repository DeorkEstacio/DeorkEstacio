#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um local do mapa
typedef struct No {
    char nome[50];          // Nome do local
    struct No* esquerda;    // Caminho para esquerda
    struct No* direita;     // Caminho para direita
} No;
// Criando as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10 // número máximo de itens na mochila

// Estrutura que representa um item
typedef struct {
    char nome[30];     // nome do item
    char tipo[20];     // tipo do item (ex: alimento, ferramenta)
    int quantidade;    // quantidade do item
} Item;
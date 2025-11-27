#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um local do mapa
typedef struct No {
    char nome[50];          // Nome do local
    struct No* esquerda;    // Caminho para esquerda
    struct No* direita;     // Caminho para direita
} No;

// Cria um novo local
No* criarSala(const char* nome) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}
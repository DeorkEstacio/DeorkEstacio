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

// Estrutura que representa o cadastro (a mochila)
typedef struct {
    Item itens[MAX_ITENS]; // vetor de itens
    int quantidade;        // contador de itens cadastrados
} Cadastro;

// Inicializa o cadastro, definindo quantidade como 0
void inicializarCadastro(Cadastro *cadastro) {
    cadastro->quantidade = 0;
}

// Lista todos os itens cadastrados
void listarItens(const Cadastro *cadastro) {
    if (cadastro->quantidade == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    printf("\n--- ITENS NA MOCHILA ---\n");
    for (int i = 0; i < cadastro->quantidade; i++) {
        printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1,
               cadastro->itens[i].nome,
               cadastro->itens[i].tipo,
               cadastro->itens[i].quantidade);
    }
    printf("------------------------\n");
}

// Insere um novo item na mochila
void inserirItem(Cadastro *cadastro) {
    if (cadastro->quantidade == MAX_ITENS) {
        printf("Erro: mochila cheia, nao e possivel inserir mais itens.\n");
        return;
    }
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

    Item novo;
    // Lê o nome
    printf("\n--- Adicionar novo item ---\n");
    printf("Nome do item: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0'; // remove o \n

    // Lê o tipo
    printf("Tipo do item (arma, municao, cura, etc.): ");
    fgets(novo.tipo, sizeof(novo.tipo), stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

    // Lê a quantidade
    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);
    getchar(); // limpa o buffer

    // Adiciona ao vetor
    cadastro->itens[cadastro->quantidade] = novo;
    cadastro->quantidade++;

    printf("Item inserido com sucesso!\n");

        // Mostra os itens imediatamente após a inserção
    listarItens(cadastro);
}

// Remove um item pelo nome
void removerItem(Cadastro *cadastro) {
    if (cadastro->quantidade == 0) {
        printf("Mochila vazia, nada a remover.\n");
        return;
    }

    char nome[30];
    printf("Digite o nome do item a remover: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
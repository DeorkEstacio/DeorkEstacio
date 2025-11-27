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

// Libera memória
void liberar(No* raiz) {
    if (raiz != NULL) {
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
}

// Função principal de deslocamento
void explorarMapa(No* inicio) {
    No* atual = inicio;
    int escolha;

    while (1) {
        // Sempre mostra o local atual
        printf("\nVoce esta em: %s\n", atual->nome);

        // Se não houver caminhos, fim do mapa
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Nao ha mais caminhos a seguir.\n");
            break;
        }

        // Menu mostra apenas direções
        printf("Escolha seu caminho:\n");
        if (atual->esquerda != NULL) printf("1 - Ir para a esquerda\n");
        if (atual->direita != NULL) printf("2 - Ir para a direita\n");

        printf("Opcao: ");
        scanf("%d", &escolha);

        if (escolha == 1 && atual->esquerda != NULL) {
            atual = atual->esquerda;
        } else if (escolha == 2 && atual->direita != NULL) {
            atual = atual->direita;
        } else {
            printf("Caminho invalido!\n");
        }
    }
}

int main() {
    // Construção do mapa
    No* hall = criarSala("Hall de Entrada");
    No* sala = criarSala("Sala de Estar");
    No* biblioteca = criarSala("Biblioteca");
    No* quarto = criarSala("Quarto");
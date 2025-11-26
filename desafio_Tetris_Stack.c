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

// Inicializa a fila
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

// Verifica se a fila está cheia
int filaCheia(Fila *f) {
    return f->total == MAX;
}

// Verifica se a fila está vazia
int filaVazia(Fila *f) {
    return f->total == 0;
}

// Insere uma peça na fila
void inserir(Fila *f, Peca p) {
    if (filaCheia(f)) {
        printf("Fila cheia. Não é possível inserir.\n");
        return;
    }
    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
}

// Remove uma peça da fila
void remover(Fila *f, Peca *p) {
    if (filaVazia(f)) {
        printf("Fila vazia. Não é possível remover.\n");
        return;
    }
    *p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
}

// Mostra todos os elementos da fila
void mostrarFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Fila de pecas: ");
    int idx = f->inicio;
    for (int i = 0; i < f->total; i++) {
        printf("[%s%d] ", f->itens[idx].tipo, f->itens[idx].id);
        idx = (idx + 1) % MAX;
    }
    printf("\n");
}

// Função principal com menu
int main() {
    Fila f;
    inicializarFila(&f);

    // Pré-carrega algumas peças
    inserir(&f, (Peca){"T", 0});
    inserir(&f, (Peca){"O", 1});
    inserir(&f, (Peca){"L", 2});
    inserir(&f, (Peca){"I", 3});
    inserir(&f, (Peca){"I", 4});

    int opcao;
    int contadorID = 5; // próximo ID para novas peças

    do {
        mostrarFila(&f);
        printf("1 - Jogar peca (dequeue)\n");
        printf("2 - Inserir Nova Peca (enqueue)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch (opcao) {
            case 1: {
                Peca removida;
                remover(&f, &removida);
                printf("Peca jogada: [%s%d]\n", removida.tipo, removida.id);
                break;
            }
            case 2: {
                char tipo[2];
                printf("Digite o tipo da nova peca (1 caractere): ");
                fgets(tipo, sizeof(tipo), stdin);
                for (int i = 0; tipo[i] != '\0'; i++) {
                  if (tipo[i] == '\n') {
                  tipo[i] = '\0'; // substitui o '\n' por terminador de string
                  break;          // sai do loop
    }
}

                Peca nova = { "", contadorID++ };
                int i = 0;
                  while (tipo[i] != '\0') {   // percorre até o fim da string
                  nova.tipo[i] = tipo[i]; // copia caractere
                  i++;
}
nova.tipo[i] = '\0';        // garante o terminador nulo no final
                inserir(&f, nova);
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
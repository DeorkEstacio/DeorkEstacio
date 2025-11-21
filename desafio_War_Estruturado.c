// Criando as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Criando as constantes globais
#define MAX_TERRITORIOS 5 
#define TAM_STRING 30

// definição da estrutura
struct Territorio {
  char nome [TAM_STRING];
  char cor_exercito [TAM_STRING];
  int quantidade_tropas;
  
};

void limparBufferentrada () {
  int c;
  while ((c = getchar()) != '\n' &&  c != EOF); 
}

int main() {
  struct Territorio territorios [MAX_TERRITORIOS];
  int totalTerritorios = 0;
  int opcao;

do { 
    
  printf("========================================\n");
  printf("   WAR ESTRUTURADO - CADASTRO INICIAL\n");
  printf("========================================\n");
  printf("1 - Cadastrar novo territorio\n");
  printf("2 - Listar todos os territorios\n");
  printf("3 - Sair\n");
  printf("----------------------------------------\n");
  printf("Escolha uma opcao\n");  

  scanf("%d", &opcao);
  limparBufferentrada(); 

  switch (opcao){
    case 1: //cadasto de território
        printf("--- Cadastrando territorio %d ---\n", totalTerritorios + 1);
        if (totalTerritorios < MAX_TERRITORIOS) {
          printf("Digite o nome do territorio\n");
          fgets(territorios[totalTerritorios].nome, TAM_STRING, stdin);

          printf("Digite a cor do exercito\n");
          fgets(territorios[totalTerritorios].cor_exercito, TAM_STRING, stdin);

          territorios[totalTerritorios].nome[strcspn(territorios[totalTerritorios].nome, "\n")] = '\0';
          territorios[totalTerritorios].cor_exercito[strcspn(territorios[totalTerritorios].cor_exercito, "\n")] = '\0';

          printf("Digite a quantidade de tropas\n");
          scanf("%d", &territorios[totalTerritorios].quantidade_tropas);
          limparBufferentrada();

          totalTerritorios++;

          printf("\nTerritorio cadastrado com sucesso!\n");
        } else {
          printf("Não e possivel cadastrar mais territorios.");
        }

        printf("\nPressione enter para continuar...");
        getchar(); // Pausa para o usuário ler a mensagem antes de voltar ao menu.
        break;

        case 2: // Listagem de Territórios
          printf("---Lista de territorios cadastrados---\n");
          
          if (totalTerritorios == 0) {
            printf("Nenhum territorio cadastrado ainda.\n");
          } else {
              for (int i = 0; i < totalTerritorios; i++) {
                printf("-----------------------------------------\n");
                printf("TERRITORIO %d\n", i + 1);
                printf("Nome: %s\n", territorios[i].nome);
                printf("Cor do exercito (ex: Azul, Verde): %s\n", territorios[i].cor_exercito);
                printf("Quantidade tropas: %d\n", territorios[i].quantidade_tropas);
              }
                printf("-----------------------------------------\n");
          }
          /* A pausa é crucial para que o usuário veja a lista antes 
             do próximo loop limpara a tela */
          
          printf("\nPressione enter para continuar...");
          getchar();
          break;
        }

} while (opcao != 3);
return 0;

}


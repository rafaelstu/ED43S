#include "ArvoreB.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  char chave[33];
  int opcao;
  int id;
  char caminho[100];

  Node *raiz = NULL;

  printf("Criacao de Arvore-B de ordem %d, ou seja, nos com %d filhos, e no "
         "maximo %d chaves:\n",
         M, M, M - 1);
  while (1) {
    printf("\n1.Inserir\n");
    printf("2.Remover\n");
    printf("3.Buscar\n");
    printf("4.Imprimir arvore\n");
    printf("5.Sair do programa\n");
    printf("\nEscolha uma das opcoes do menu: ");
    setbuf(stdin, NULL);
    scanf("%d", &opcao); // eatline();

    switch (opcao) {
    case 1:
      printf("Informe a palavra-chave (tag): ");
      setbuf(stdin, NULL);
      scanf(" %32[^\n]", chave);
      printf("Informe o ID do arquivo: ");
      setbuf(stdin, NULL);
      scanf("%d", &id);
      printf("Informe o caminho/URL de armazenamento: ");
      setbuf(stdin, NULL);
      scanf(" %99[^\n]", caminho);
      raiz = inserirNo(raiz, chave, id, caminho);
      break;
    case 2:
      printf("Informe a palavra-chave (tag) a ser removida: ");
      setbuf(stdin, NULL);
      scanf(" %32[^\n]", chave); // eatline();
      raiz = excluirNo(raiz, chave);
      break;
    case 3:
      printf("Informe a palavra-chave (tag) a ser procurada: ");
      setbuf(stdin, NULL);
      scanf(" %32[^\n]", chave); // eatline();
      busca(raiz, chave);
      break;
    case 4:
      //                        printf("Impressao da Arvore-B de ordem %d:\n",
      //                        M);
      printf("Printing the B-Tree of order %d:\n", M);
      imprime_arvore(raiz, 0);
      break;
    case 5:
      free(raiz);
      exit(1);
    default:
      printf("Opcao invalida.\n");
      break;
    } /*Fim switch*/
  } /*Fim while*/
  return 0;
} /*Fim main()*/

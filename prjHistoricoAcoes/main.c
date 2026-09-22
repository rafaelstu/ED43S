#include "itemHistoricoAcoes.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Pilha *p;
  Item *item;
  int opcao;

  p = criaPilhaVazia();

  do {
    printf("\nhistorico de acoes - editor vetorial\n");
    printf("1 - inserir nova acao\n");
    printf("2 - desfazer ultima acao\n");
    printf("3 - imprimir historico\n");
    printf("0 - sair\n");
    printf("escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      item = criaItem();
      empilha(p, item);
      free(item);
      break;
    case 2:
      desempilha(p);
      break;
    case 3:
      printf("\nhistorico de acoes:\n");
      imprimePilha(p);
      break;
    case 0:
      liberaPilha(p);
      printf("saindo\n");
      break;
    default:
      printf("opcao invalida\n");
    }
  } while (opcao != 0);

  return 0;
}

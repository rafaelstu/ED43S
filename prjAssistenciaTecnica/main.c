#include "itemListaEnc.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Lista *lst, *lstFiltrada;
  Item *item;
  int opcao, id_os, prioridade;

  lst = criaListaVazia();

  do {
    printf("\nassistencia tecnica\n");
    printf("1 - inserir nova OS\n");
    printf("2 - excluir OS\n");
    printf("3 - buscar OS\n");
    printf("4 - imprimir todas as OS\n");
    printf("5 - filtrar OS (por prioridade)\n");
    printf("0 - sair\n");
    printf("escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      item = criaItem();
      insereItemPorPrioridade(lst, item);
      free(item);
      break;
    case 2:
      printf("informe a OS a excluir: ");
      scanf("%d", &id_os);
      removeItem(lst, id_os);
      break;
    case 3:
      printf("informe a OS a buscar: ");
      scanf("%d", &id_os);
      buscarOS(lst, id_os);
      break;
    case 4:
      printf("\nOS cadastradas:\n");
      imprimeLista(lst);
      break;
    case 5:
      printf("informe a prioridade do filtro: ");
      scanf("%d", &prioridade);
      lstFiltrada = filtrarOS(lst, prioridade);
      printf("\nresultado do filtrarOS:\n");
      imprimeLista(lstFiltrada);
      liberaLista(lstFiltrada);
      break;
    case 0:
      liberaLista(lst);
      printf("saindo\n");
      break;
    default:
      printf("opcao invalida\n");
    }
  } while (opcao != 0);

  return 0;
}

#include "rafaelMercadoPreso.h"
#include <stdio.h>

int main() {

  RafaelMercadoPreso *rmp = criaRMP();
  int opcao;

  printf("\nsistema de encomendas\n");
  do {
    printf("\n1. inserir encomenda");
    printf("\n2. registrar tentativa de entrega"); // ja ta embutido a conclusao
    printf("\n3. consultar encomendas pendentes (com filtro por cep)");
    printf("\n4. consultar encomendas entregues (com filtro por cep)");
    printf("\n0. sair\n");

    printf("opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1: {
      insereInicioLista(rmp);
      break;
    }
    case 2: {
      Celula *c;
      c = tentativaEntregaItem(rmp);
      if (c != NULL) {
        concluirEntrega(rmp, c);
      }
      break;
    }
    case 3: {
      int cep;
      printf("informe valor do filtro de cep (0 para ignorar): ");
      scanf("%d", &cep);
      filtrarCep(rmp, cep, 0);
      break;
    }
    case 4: {
      int cep;
      printf("informe valor do filtro de cep (0 para ignorar): ");
      scanf("%d", &cep);
      filtrarCep(rmp, cep, 1);
      break;
    }
    };
  } while (opcao != 0);

  liberaRMP(rmp);

  return 0;
}

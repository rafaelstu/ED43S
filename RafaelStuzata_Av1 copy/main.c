#include "rafaelMercadoPreso.h"
#include <stdio.h>

int main() {

  RafaelMercadoPreso *rmp = criaRMP();
  int opcao;
  Celula *c;
  printf("\nsistema de encomendas\n");
  do {
    printf("\n1. inserir encomenda");
    printf("\n2. registrar tentativa de entrega frustrada");
    printf("\n3. concluir entrega");
    printf("\n4. consultar encomendas pendentes (com filtro por cep)");
    printf("\n5. consultar encomendas entregues (com filtro por cep)");
    printf("\n0. sair\n");

    printf("opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1: {
      insere(rmp);
      break;
    }
    case 2: {

      insereFrustrado(rmp, desenfileira(rmp));

      break;
    }
    case 3: {
      concluirEntrega(rmp, desenfileira(rmp));
      break;
    }
    case 4: {
      int cep;
      printf("informe valor do filtro de cep (0 para ignorar): ");
      scanf("%d", &cep);
      filtrarCep(rmp, cep, 0);
      break;
    }
    case 5: {
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

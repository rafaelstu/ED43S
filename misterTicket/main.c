#include "ArvoreLLRB.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  ArvLLRB *raiz = cria_ArvLLRB();
  int opcao, res;
  char info[33];

  printf("\n========== MONITORAMENTO DE INGRESSOS ==========\n");
  do {
    printf("\n1. incluir lote");
    printf("\n2. atualizar lote");
    printf("\n3. consultar evento");
    printf("\n4. buscar ingressos por faixa de preco");
    printf("\n5. imprimir arvore em ordem");
    printf("\n6. imprimir informacoes dos nos da arvore em ordem");
    printf("\n0. sair\n");
    printf("opcao: ");
    scanf("%d", &opcao);
    setbuf(stdin, NULL);

    switch (opcao) {
    case 1: {
      criaLote(raiz);
      break;
    }
    case 2: {
      atualizaLote(raiz);
      break;
    }
    case 3: {
      printf("artista/evento: ");
      setbuf(stdin, NULL);
      scanf(" %32[^\n]", info);
      setbuf(stdin, NULL);

      res = consulta_ArvLLRB(raiz, info);
      if (res == 0)
        printf("evento nao encontrado\n");
      break;
    }
    case 4: {
      criaFaixaPreco(raiz);
      break;
    }
    case 5: {
      printf("\narvore em ordem:\n");
      emOrdem_ArvLLRB(raiz, 0, "");
      break;
    }
    case 6: {
      printf("\ninformacoes dos nos em ordem:\n");
      emOrdem_NoArvLLRB(raiz);
      break;
    }
    }
  } while (opcao != 0);

  printf("\neventos em ordem:\n");
  if (estaVazia_ArvLLRB(raiz))
    printf("arvore vazia\n");
  else {
    emOrdem_ArvLLRB(raiz, 0, "");
    emOrdem_NoArvLLRB(raiz);
  }

  libera_ArvLLRB(raiz);

  return 0;
}

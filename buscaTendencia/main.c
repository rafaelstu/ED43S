#include "ArvoreAVL.h"
#include <stdio.h>

int main() {
  NoArvAVL *avl = cria_ArvAVL();
  int opcao, res;
  char hashtag[50];
  long long visualizacoes;

  printf("\n========== BUSCA DE TENDENCIAS ==========\n");
  do {
    printf("\n1. incluir hashtag");
    printf("\n2. remover hashtag");
    printf("\n3. consultar hashtag");
    printf("\n4. simular engajamento");
    printf("\n5. consultar tendencias por intervalo de datas");
    printf("\n6. imprimir hashtags em ordem");
    printf("\n0. sair\n");
    printf("opcao: ");
    scanf("%d", &opcao);
    setbuf(stdin, NULL);

    switch (opcao) {
    case 1: {
      criaHashtag(avl);
      break;
    }
    case 2: {
      printf("hashtag: ");
      scanf(" %49[^\n]", hashtag);
      setbuf(stdin, NULL);

      res = remove_ArvAVL(avl, hashtag);
      if (res == 1)
        printf("hashtag removida\n");
      break;
    }
    case 3: {
      printf("hashtag: ");
      scanf(" %49[^\n]", hashtag);
      setbuf(stdin, NULL);

      res = consulta_ArvAVL(avl, hashtag);
      if (res == 0)
        printf("hashtag nao encontrada\n");
      break;
    }
    case 4: {
      printf("hashtag: ");
      scanf(" %49[^\n]", hashtag);
      setbuf(stdin, NULL);
      printf("visualizacoes a adicionar: ");
      scanf("%lld", &visualizacoes);
      setbuf(stdin, NULL);

      res = simularEngajamento(avl, hashtag, visualizacoes);
      if (res == 0)
        printf("hashtag nao encontrada\n");
      break;
    }
    case 5: {
      criaIntervaloTendencia(avl);
      break;
    }
    case 6: {
      printf("\nhashtags em ordem:\n");
      emOrdem_NoArvAVL(avl, "");
      break;
    }
    }
  } while (opcao != 0);

  printf("\nhashtags em ordem:\n");
  if (estaVazia_ArvAVL(avl))
    printf("arvore vazia\n");
  else {
    emOrdem_ArvAVL(avl, "");
    emOrdem_NoArvAVL(avl, "");
  }

  libera_ArvAVL(avl);

  return 0;
}

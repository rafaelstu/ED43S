#include "ArvoreAVL.h"
#include <stdio.h>

int main() {
  NoArvAVL *avl = cria_ArvAVL();
  int opcao, res;
  char nickname[33];

  printf("\n========== SISTEMA DE BANIMENTO ==========\n");
  do {
    printf("\n1. incluir denuncia");
    printf("\n2. remover jogador");
    printf("\n3. consultar jogador");
    printf("\n4. consultar por intervalo de datas");
    printf("\n5. imprimir arvore em ordem");
    printf("\n6. imprimir informacoes dos nos da arvore em ordem");
    printf("\n0. sair\n");
    printf("opcao: ");
    scanf("%d", &opcao);
    setbuf(stdin, NULL);

    switch (opcao) {
    case 1: {
      criaReport(avl);
      break;
    }
    case 2: {
      printf("nickname: ");
      scanf(" %32[^\n]", nickname);
      setbuf(stdin, NULL);

      res = remove_ArvAVL(avl, nickname);
      if (res == 1)
        printf("jogador removido\n");
      break;
    }
    case 3: {
      printf("nickname: ");
      scanf(" %32[^\n]", nickname);
      setbuf(stdin, NULL);

      res = consulta_ArvAVL(avl, nickname);
      if (res == 0)
        printf("jogador nao encontrado\n");
      break;
    }
    case 4: {
      criaIntervalo(avl);
      break;
    }
    case 5: {
      printf("\narvore em ordem:\n");
      emOrdem_ArvAVL(avl, "");
      break;
    }
    case 6: {
      printf("\ninformacoes dos nos em ordem:\n");
      emOrdem_NoArvAVL(avl, "");
      break;
    }
    }
  } while (opcao != 0);

  printf("\narvore final em ordem:\n");
  if (estaVazia_ArvAVL(avl))
    printf("arvore vazia\n");
  else {
    emOrdem_ArvAVL(avl, "");
    emOrdem_NoArvAVL(avl, "");
  }

  libera_ArvAVL(avl);

  return 0;
}

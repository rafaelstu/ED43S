#include "itemFilaEnc.h"
#include <stdio.h>

int main() {
  Fila *f;
  int vazia, chave;
  printf("criando fila encadeada vazia\n");
  f = criaFilaVazia();

  vazia = verificaFilaVazia(f);
  printf("fila vazia? %d\n", vazia);

  printf("\nadicionando o 1o item\n");
  chave = 1;
  enfileira(f, chave);

  vazia = verificaFilaVazia(f);
  printf("fila vazia? %d\n", vazia);

  printf("\nadicionando o 2o item\n");
  chave = 2;
  enfileira(f, chave);

  printf("\nadicionando o 3o item\n");
  chave = 3;
  enfileira(f, chave);

  printf("\nadicionando o 4o item\n");
  chave = 4;
  enfileira(f, chave);

  printf("\nadicionando o 5o item\n");
  chave = 5;
  enfileira(f, chave);

  printf("\nadicionando o 6o item\n");
  chave = 6;
  enfileira(f, chave);

  printf("\nitens da fila\n");
  imprimeFila(f);

  printf("\nremovendo os dois primeiros itens da fila\n");
  desenfileira(f);
  desenfileira(f);
  imprimeFila(f);

  liberaFila(f);

  return 0;
}

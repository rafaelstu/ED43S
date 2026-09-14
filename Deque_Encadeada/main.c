#include "itemDequeEnc.h"
#include <stdio.h>


int main() {

  Deque *dq;

  int vazia, chave;

  printf("Criando deque vazia.\n");
  dq = cria_Deque();

  vazia = verificaDequeVazia(dq);
  printf("Deque vazia? %d\n", vazia);

  printf("\nAdicionando o 1o item (2) no inicio.\n");
  chave = 2;
  insereInicio_Deque(dq, chave);
  vazia = verificaDequeVazia(dq);
  printf("Deque vazia? %d\n", vazia);

  printf("\nAdicionando o 2o item (11) no fim.\n");
  chave = 11;
  insereFinal_Deque(dq, chave);

  printf("\nAdicionando o 3o item (8) no inicio.\n");
  chave = 8;
  insereInicio_Deque(dq, chave);

  printf("\nAdicionando o 4o item (33) no fim.\n");
  chave = 33;
  insereFinal_Deque(dq, chave);

  printf("\nAdicionando o 5o item (5) no inicio.\n");
  chave = 5;
  insereInicio_Deque(dq, chave);

  printf("\nnAdicionando o 6o (6) item no fim.\n");
  chave = 6;
  insereFinal_Deque(dq, chave);

  printf("\nItens da deque: \n");
  imprime_Deque(dq);

  printf("\nRemovendo item do final.\n");
  removeFinal_Deque(dq);
  imprime_Deque(dq);

  printf("\nRemovendo item do inicio.\n");
  removeInicio_Deque(dq);
  imprime_Deque(dq);

  libera_Deque(dq);

  return 0;
}

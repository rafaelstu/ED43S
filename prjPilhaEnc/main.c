#include "itemPilhaEnc.h"
#include <stdio.h>

int main() {
  Pilha *p, *p2, *p3;
  int vazia, chave;

  // printf("criando pilha encadeada vazia\n");
  p = criaPilhaVazia();
  p2 = criaPilhaVazia();
  p3 = criaPilhaVazia();

  // vazia = verificaPilhaVazia(p);
  // printf("pilha vazia? %d\n", vazia);

  // printf("\nadicionando 1o item");
  chave = 1;
  empilha(p, chave);
  // printf("\nadicionando 2o item");
  chave = 2;
  empilha(p, chave);
  // printf("\nadicionando 3o item");
  chave = 3;
  empilha(p, chave);
  // printf("\nadicionando 4o item");
  chave = 4;
  empilha(p, chave);
  // printf("\nadicionando 5o item");
  chave = 5;
  empilha(p, chave);
  // printf("\nadicionando 6o item");
  chave = 6;
  empilha(p, chave);

  printf("\nitens da pilha\n");
  imprimePilha(p);

  // printf("removendo dois ultimos itens da pilha\n");
  // desempilha(p);
  // desempilha(p);

  separaPilha(p, p2, p3);
  printf("\nitens da pilha par\n");
  imprimePilha(p2);

  printf("\nitens da pilha impçar\n");
  imprimePilha(p3);

  liberaPilha(p);
  liberaPilha(p2);
  liberaPilha(p3);

  return 0;
}

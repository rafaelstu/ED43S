#include "itemFilaEnc.h"
#include "itemPilhaEnc.h"

int main() {

  Pilha *p;
  Fila *f;

  p = criaPilhaVazia();
  f = criaFilaVazia();

  empilha(p, 10);
  empilha(p, 20);
  enfileira(f, desempilha(p));
  empilha(p, 30);
  enfileira(f, 40);
  enfileira(f, desempilha(p));
  empilha(p, desenfileira(f));
  empilha(p, 50);
  enfileira(f, desempilha(p));
  empilha(p, desenfileira(f));

  printf("pilha\t");
  imprimePilha(p);
  printf("\nfila\t");
  imprimeFila(f);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

#include "itemFilaEnc.h"

struct item {
  int chave;
  // demais campos
};

struct celula {
  Item item;
  Celula *prox;
};

struct fila {
  Celula *ini;
  Celula *fim;
};

Fila *criaFilaVazia() {
  Fila *f = malloc(sizeof(Fila));
  f->ini = NULL;
  f->fim = NULL;

  return f;
}

void enfileira(Fila *f, int chave) {
  // cria novo item que vai ser no final da fila
  Item novo;
  novo.chave = chave;
  // cria nova celula que vai guardar o item
  Celula *nova = malloc(sizeof(Celula));
  nova->item = novo;
  nova->prox = NULL;

  if (verificaFilaVazia(f)) { // se esta vazia adiciona no inicio
    f->ini = nova;
  } else {
    f->fim->prox = nova;
  }
  f->fim = nova;
}

void imprimeFila(Fila *f) {
  Celula *aux = f->ini;
  while (aux != NULL) {
    printf("chave: %d\n", aux->item.chave);
    aux = aux->prox;
  }
}

void desenfileira(Fila *f) {
  if (verificaFilaVazia(f)) {
    printf("\nerro: fila vazia");
    return;
  }
  Celula *remover = f->ini;
  f->ini = remover->prox;
  free(remover);

  if (verificaFilaVazia(f)) {
    f->fim = NULL; // se ficou vazia, fim aponta para NULL
  }
}

// retorna 1 se a fila esta vazia, 0 se nao esta
int verificaFilaVazia(Fila *f) { return f->ini == NULL; }

void liberaFila(Fila *f) {
  Celula *aux = f->ini;
  Celula *liberar;

  while (aux != NULL) {
    liberar = aux;
    aux = aux->prox;
    free(liberar);
  }

  free(f);
}

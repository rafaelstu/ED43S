#include "itemPilhaEnc.h"
#include <stdio.h>
#include <stdlib.h>

struct item {
  int chave;
  // demais campos
};

struct celula {
  Item item;
  Celula *prox; // armazena o endereço da próxima célula
};

struct pilha {
  Celula *topo;
};

Pilha *criaPilhaVazia() {
  Pilha *p = malloc(sizeof(Pilha));
  p->topo = NULL;
  return p;
}

void empilha(Pilha *p, int chave) {
  // cria novo item que vai ser guardado na Pilha
  Item novo;
  novo.chave = chave;
  // cria nova célula que vai guardar o item
  Celula *nova = malloc(sizeof(Celula));
  nova->item = novo;
  // inserção no início: a próxima célula é aquela que era a primeira
  nova->prox = p->topo;
  // a primeira agora passa a ser a nova célula
  p->topo = nova;
}

void imprimePilha(Pilha *p) {
  Celula *aux;
  for (aux = p->topo; aux != NULL; aux = aux->prox) {
    printf("Chave: %d\n", aux->item.chave);
    // demais campos
  }
}

void desempilha(Pilha *p) {
  if (verificaPilhaVazia(p)) {
    printf("\nerro pilha vazia!");
    return;
  }

  Celula *rm = p->topo; // remove  celula do topo
  p->topo = rm->prox;
  free(rm);
}

// retorna 1 se a Pilha esta vazia ou 0 se nao esta
int verificaPilhaVazia(Pilha *p) { return p->topo == NULL; }

void liberaPilha(Pilha *p) {
  Celula *aux = p->topo;
  Celula *liberar;
  while (aux != NULL) {
    liberar = aux;
    aux = aux->prox;
    free(liberar); // libera uma a uma, as células da memória
  }
  free(p); // libera a Pilha da memória
}

void separaPilha(Pilha *p1, Pilha *p2, Pilha *p3) {
  Celula *aux, *par, *impar;
  aux = p1->topo;

  while (aux != NULL) {

    if (aux->item.chave % 2 == 0) {
      empilha(p2, aux->item.chave);
    } else {
      empilha(p3, aux->item.chave);
    }

    aux = aux->prox;
  }
}

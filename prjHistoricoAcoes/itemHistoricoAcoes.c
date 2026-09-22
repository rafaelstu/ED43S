#include "itemHistoricoAcoes.h"
#include <stdio.h>
#include <stdlib.h>

struct item {
  int idAcao;
  char tipoAcao[40];
  int camada;
  char cor[10];
  char formato[10];
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

Item *criaItem() {
  Item *novo = malloc(sizeof(Item));

  printf("informe o id da acao: ");
  scanf("%d", &novo->idAcao);
  printf("informe o tipo da acao: ");
  scanf(" %39[^\n]", novo->tipoAcao);
  printf("informe a camada: ");
  scanf("%d", &novo->camada);
  printf("informe a cor (ex: #ff0000): ");
  scanf(" %9[^\n]", novo->cor);
  printf("informe o formato (ex: svg, png, pdf): ");
  scanf(" %9[^\n]", novo->formato);

  return novo;
}

void empilha(Pilha *p, Item *item) {
  // cria nova célula que vai guardar o item
  Celula *nova = malloc(sizeof(Celula));
  nova->item = *item;
  // inserção no topo: a próxima célula é aquela que era o topo
  nova->prox = p->topo;
  // o topo agora passa a ser a nova célula
  p->topo = nova;
}

void imprimeItem(Item *item) {
  printf("id da acao: %d\n", item->idAcao);
  printf("tipo: %s\n", item->tipoAcao);
  printf("camada: %d\n", item->camada);
  printf("cor: %s\n", item->cor);
  printf("formato: %s\n", item->formato);
}

void imprimePilha(Pilha *p) {
  Celula *aux;
  if (verificaPilhaVazia(p)) {
    printf("historico vazio\n");
    return;
  }
  for (aux = p->topo; aux != NULL; aux = aux->prox) {
    imprimeItem(&aux->item);
    printf("\n");
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

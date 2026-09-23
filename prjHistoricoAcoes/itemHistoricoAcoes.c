#include "itemHistoricoAcoes.h"
#include <stdio.h>
#include <stdlib.h>

struct item {
  int idAcao;
  char formaObjeto[30];
  int posX;
  int posY;
  int escala;
  char cor[10];
  int preenchido;
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
  setbuf(stdin, NULL);
  printf("informe a forma do objeto: ");
  scanf(" %29[^\n]", novo->formaObjeto);
  setbuf(stdin, NULL);
  printf("informe a posicao x: ");
  scanf("%d", &novo->posX);
  setbuf(stdin, NULL);
  printf("informe a posicao y: ");
  scanf("%d", &novo->posY);
  setbuf(stdin, NULL);
  printf("informe a escala: ");
  scanf("%d", &novo->escala);
  setbuf(stdin, NULL);
  printf("informe a cor (ex: #ff0000): ");
  scanf(" %9[^\n]", novo->cor);
  setbuf(stdin, NULL);
  printf("informe se e preenchido (0 nao, 1 sim): ");
  scanf("%d", &novo->preenchido);

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
  printf("forma do objeto: %s\n", item->formaObjeto);
  printf("posicao x: %d\n", item->posX);
  printf("posicao y: %d\n", item->posY);
  printf("escala: %d\n", item->escala);
  printf("cor: %s\n", item->cor);
  printf("preenchido: %d\n", item->preenchido);
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

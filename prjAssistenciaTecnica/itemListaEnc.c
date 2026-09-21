#include "itemListaEnc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
  int ano, mes, dia;
};

struct item {
  int id_os;
  Data data;
  int prioridade;
  char descricao[100];
  char tecnico[50];
  int qtdVolumes;
};

struct celula {
  Item item;
  Celula *prox;
};

struct lista {
  Celula *primeira;
};

Lista *criaListaVazia() {
  Lista *lst = malloc(sizeof(Lista));
  lst->primeira = NULL;
  return lst;
}

Item *criaItem() {
  Item *novo = malloc(sizeof(Item));

  printf("informe a OS: ");
  scanf("%d", &novo->id_os);
  printf("informe a data (dd/mm/aaaa): ");
  scanf("%02d/%02d/%04d", &novo->data.dia, &novo->data.mes, &novo->data.ano);
  setbuf(stdin, NULL);
  printf("informe a prioridade: ");
  scanf("%d", &novo->prioridade);
  setbuf(stdin, NULL);
  printf("informe a descricao: ");
  scanf(" %99[^\n]s", novo->descricao);
  setbuf(stdin, NULL);
  printf("informe o tecnico: ");
  scanf(" %49[^\n]s", novo->tecnico);
  setbuf(stdin, NULL);
  printf("informe a quantidade de volumes: ");
  scanf("%d", &novo->qtdVolumes);

  return novo;
}

void insereFimItem(Lista *lst, Item item) {
  Celula *nova = malloc(sizeof(Celula));
  nova->item = item;
  nova->prox = NULL;
  if (verificaListaVazia(lst)) {
    lst->primeira = nova;
  } else {
    Celula *ultima = lst->primeira;
    while (ultima->prox != NULL) {
      ultima = ultima->prox;
    }
    ultima->prox = nova;
  }
}

void imprimeItem(Item *item) {
  printf("os: %d\n", item->id_os);
  printf("data: %02d/%02d/%04d\n", item->data.dia, item->data.mes,
         item->data.ano);
  printf("prioridade: %d\n", item->prioridade);
  printf("descricao: %s\n", item->descricao);
  printf("tecnico: %s\n", item->tecnico);
  printf("volumes: %d\n", item->qtdVolumes);
}

void insereItemPorPrioridade(Lista *lst, Item *item) {
  // impede inserção de OS com identificação já existente
  if (buscaPorChave(lst, item->id_os) != NULL) {
    printf("erro: ja existe uma OS com a identificacao %d\n", item->id_os);
    return;
  }

  // cria a nova célula que vai guardar o item
  Celula *nova = malloc(sizeof(Celula));
  nova->item = *item;

  // procura a posição: lista ordenada de forma decrescente pela prioridade
  Celula *ant = NULL;
  Celula *atual = lst->primeira;
  while (atual != NULL && atual->item.prioridade >= item->prioridade) {
    ant = atual;
    atual = atual->prox;
  }

  if (ant == NULL) { // inserção no início
    nova->prox = lst->primeira;
    lst->primeira = nova;
  } else { // inserção no meio ou no fim
    nova->prox = atual;
    ant->prox = nova;
  }
}

void imprimeLista(Lista *lst) {
  Celula *aux;
  if (verificaListaVazia(lst)) {
    printf("lista vazia\n");
    return;
  }
  for (aux = lst->primeira; aux != NULL; aux = aux->prox) {
    imprimeItem(&aux->item);
    printf("\n");
  }
}

Celula *buscaPorChave(Lista *lst, int chave) {
  Celula *aux = lst->primeira;
  while (aux != NULL && aux->item.id_os != chave) {
    aux = aux->prox;
  }
  return aux;
}

void removeItem(Lista *lst, int id_os) {
  Celula *aux = lst->primeira;
  Celula *anterior;

  while (aux != NULL && aux->item.id_os != id_os) {
    anterior = aux; // guarda a célula anterior
    aux = aux->prox;
  }
  if (aux == NULL) {
    printf("os %d nao encontrada\n", id_os);
    return;
  }
  if (aux == lst->primeira) { // remove do início
    lst->primeira = aux->prox;
  } else {
    anterior->prox = aux->prox;
  }
  free(aux);
}

// retorna 1 se a lista esta vazia ou 0 se nao esta
int verificaListaVazia(Lista *lst) { return lst->primeira == NULL; }

void liberaLista(Lista *lst) {
  Celula *aux = lst->primeira;
  Celula *liberar;
  while (aux != NULL) {
    liberar = aux;
    aux = aux->prox;
    free(liberar); // libera uma a uma, as células da memória
  }
  free(lst); // libera a lista da memória
}

Lista *filtrarOS(Lista *lst, int prioridade) {
  Lista *nova = criaListaVazia();
  Celula *aux;
  for (aux = lst->primeira; aux != NULL; aux = aux->prox) {
    if (aux->item.prioridade == prioridade) {
      insereFimItem(nova, aux->item);
    }
  }
  return nova;
}

void buscarOS(Lista *lst, int id_os) {
  Celula *aux = buscaPorChave(lst, id_os);
  if (aux == NULL) {
    printf("os %d nao encontrada\n", id_os);
  } else {
    imprimeItem(&aux->item);
  }
}

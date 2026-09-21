#include "itemListaEnc.h"
#include <stdio.h>
#include <stdlib.h>

struct data {
  int ano, mes, dia;
};

struct item {
  int id_os;
  Data data;
  int prioridade;
  char *descricao;
  char *tecnico;
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
  Item *novo;

  printf("informe a OS: ");
  scanf("%d", &novo->id_os);
  printf("informe a data: ");
  scanf("%02d/%02d/%04d", &novo->data.dia, &novo->data.mes, &novo->data.ano);
  printf("informe a prioridade: ");
  scanf("%d", &novo->prioridade);

  return novo;
}

void insereItemPorPrioridade(Lista *lst, Item *item) {
  Celula *aux = buscaPorChave(lst, chaveAnt);
  if (aux != NULL) {
    // cria novo item que vai ser guardado na lista

    // cria a nova célula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = *item;
    // inserção no meio
    nova->prox =
        aux->prox;    // aponta pra o próximo que era apontado pela anterior
    aux->prox = nova; // a anterior passa a apontar para a nova
  } else {
    printf("item informado não existe\n");
  }
}

void imprimeLista(Lista *lst) {
  Celula *aux;
  for (aux = lst->primeira; aux != NULL; aux = aux->prox) {
    printf("os: %d\n", aux->item.id_os);
    printf("data: %02d/%02d/%04d\n", aux->item.data.dia, aux->item.data.mes,
           aux->item.data.ano);
    printf("prioridade: %d", aux->item.prioridade);
  }
}

// Celula *buscaPorChave(Lista *lst, int chave) {
//   Celula *aux = lst->primeira;
//   while (aux != NULL && aux->item.chave != chave) {
//     aux = aux->prox;
//   }
//   return aux;
// }

// void removeItem(Lista *lst, int x) {
//   Celula *aux = lst->primeira;
//   Celula *anterior;

//   while (aux != NULL && aux->item.chave != x) {
//     anterior = aux; // guarda a célula anterior
//     aux = aux->prox;
//   }
//   if (aux == NULL) {
//     printf("item nao encontrado\n");
//     return;
//   }
//   if (aux == lst->primeira) { // remove do início
//     lst->primeira = aux->prox;
//   } else {
//     anterior->prox = aux->prox;
//   }
//   free(aux);
// }

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

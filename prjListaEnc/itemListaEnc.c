#include "itemListaEnc.h"
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

struct lista {
  Celula *primeira;
};

Lista *criaListaVazia() {
  Lista *lst = malloc(sizeof(Lista));
  lst->primeira = NULL;
  return lst;
}

void insereInicioLista(Lista *lst, int chave) {
  // cria novo item que vai ser guardado na lista
  Item novo;
  novo.chave = chave;
  // cria nova célula que vai guardar o item
  Celula *nova = malloc(sizeof(Celula));
  nova->item = novo;
  // inserção no início: a próxima célula é aquela que era a primeira
  nova->prox = lst->primeira;
  // a primeira agora passa a ser a nova célula
  lst->primeira = nova;
}

void insereFimLista(Lista *lst, int chave) {
  // cria novo item que vai ser guardado na lista
  Item novo;
  novo.chave = chave;
  // cria nova célula que vai guardar o item
  Celula *nova = malloc(sizeof(Celula));
  nova->item = novo;
  // inserção no final
  nova->prox = NULL; // a nova célula será a última, então aponta para NULL
  if (verificaListaVazia(
          lst)) { // se a lista está vazia essa também é a primeira
    lst->primeira = nova;
  } else { // se não esta vazia, qem era a última aponta para a nova célula
    Celula *ultima;
    ultima = lst->primeira;
    while (ultima->prox != NULL) {
      ultima = ultima->prox;
    }
    ultima->prox = nova; // após a última célula, insere a nova
  }
}

void insereMeioLista(Lista *lst, int chave, int chaveAnt) {
  Celula *aux = buscaPorChave(lst, chaveAnt);
  if (aux != NULL) {
    // cria novo item que vai ser guardado na lista
    Item novo;
    novo.chave = chave;
    // cria a nova célula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    // inserção no meio
    nova->prox =
        aux->prox;    // aponta pra o próximo que era apontado pela anterior
    aux->prox = nova; // a anterior passa a apontar para a nova
  } else {
    printf("item informado não existe\n");
  }
}

void insereOrdenando(Lista *lst1, Lista *lst2) {
  Celula *aux = lst1->primeira;
  Celula *auxOrd;
  Celula *ant;

  if (verificaListaVazia(lst2)) {
    insereInicioLista(lst2, aux->item.chave);

    auxOrd = lst2->primeira;
    ant = lst2->primeira;
    aux = aux->prox;
  }

  while (aux != NULL) {
    for (auxOrd = lst2->primeira; auxOrd != NULL; auxOrd = auxOrd->prox) {
      if (auxOrd->item.chave > aux->item.chave) {
        if (auxOrd == lst2->primeira) {
          insereInicioLista(lst2, aux->item.chave);
          break;
        } else {
          insereMeioLista(lst2, aux->item.chave, ant->item.chave);
          break;
        }
      } else {
        if (auxOrd->prox == NULL) {
          insereFimLista(lst2, aux->item.chave);
          break;
        }
      }
      ant = auxOrd;
    }

    aux = aux->prox;
  }
}

void imprimeLista(Lista *lst) {
  Celula *aux;
  for (aux = lst->primeira; aux != NULL; aux = aux->prox) {
    printf("Chave: %d\n", aux->item.chave);
    // demais campos
  }
}

Celula *buscaPorChave(Lista *lst, int chave) {
  Celula *aux = lst->primeira;
  while (aux != NULL && aux->item.chave != chave) {
    aux = aux->prox;
  }
  return aux;
}

void removeItem(Lista *lst, int x) {
  Celula *aux = lst->primeira;
  Celula *anterior;

  while (aux != NULL && aux->item.chave != x) {
    anterior = aux; // guarda a célula anterior
    aux = aux->prox;
  }
  if (aux == NULL) {
    printf("item nao encontrado\n");
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

void juntaLista(Lista *lst1, Lista *lst2) {
  Celula *aux = lst1->primeira;
  if (lst1->primeira == NULL) {
    lst1->primeira = lst2->primeira;
  } else {
    Celula *aux = lst1->primeira;
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = lst2->primeira;
  }
}

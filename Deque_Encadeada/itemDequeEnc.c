#include "itemDequeEnc.h" //inclui os Protótipos
#include <stdio.h>
#include <stdlib.h>

struct item {
  int chave;
  // Demais campos
};

struct celula {
  Item item;
  Celula *prox;
};

struct deque {
  Celula *ini;
  Celula *fim;
};

Deque *cria_Deque() {
  Deque *dq = (Deque *)malloc(sizeof(Deque));
  if (dq != NULL) {
    dq->ini = NULL;
    dq->fim = NULL;
  }
  return dq;
}

int verificaDequeVazia(Deque *dq) { return (dq->ini == NULL); }

void insereFinal_Deque(Deque *dq, int chave) {
  // cria novo item que vai ser guardado na Deque
  Item novo;
  novo.chave = chave;
  // cria nova célula que vai guardar o item
  Celula *nova = malloc(sizeof(Celula));
  nova->item = novo;
  if (verificaDequeVazia(dq)) // se está vazia adiciona no início
  {
    // no->ant = NULL;
    nova->prox = dq->ini;
    dq->ini = nova;
  } else {
    // senão aciciona no final
    // no->ant = dq->final;
    // inserção no final, a nova célula aponta para NULL
    nova->prox = NULL;
    dq->fim->prox = nova;
  }
  dq->fim = nova;
}

void insereInicio_Deque(Deque *dq, int chave) {
  // cria novo item que vai ser guardado na Deque
  Item novo;
  novo.chave = chave;
  // cria nova célula que vai guardar o item
  Celula *nova = malloc(sizeof(Celula));
  nova->item = novo;
  nova->prox = dq->ini;
  if (verificaDequeVazia(dq)) // se está vazia fim será igual a ini
  {
    dq->fim = nova;
  }
  dq->ini = nova;
}

void removeInicio_Deque(Deque *dq) {
  if (verificaDequeVazia(dq)) {
    printf("Erro: Deque vazia!\n");
    return;
  }

  Celula *remover = dq->ini;
  dq->ini = remover->prox;
  free(remover);
  if (verificaDequeVazia(dq)) // se ficou vazia, fim aponta para NULL
    dq->fim = NULL;
}

void removeFinal_Deque(Deque *dq) {
  if (verificaDequeVazia(dq)) {
    printf("Erro: Deque vazia!\n");
    return;
  }
  Celula *remover = dq->fim;

  if (remover == dq->ini) // remover o primeiro e unico elemento?
  {
    dq->ini = NULL;
    dq->fim = NULL;
  } else {
    Celula *ultimo = dq->ini;
    while (ultimo->prox != dq->fim) {
      ultimo = ultimo->prox;
    }

    ultimo->prox = NULL;
    dq->fim = ultimo;
  }
  free(remover);
}

void imprime_Deque(Deque *dq) {
  Celula *aux = dq->ini;
  while (aux != NULL) {
    printf("Chave: %d\n", aux->item.chave);
    aux = aux->prox;
  }
}

void libera_Deque(Deque *dq) {
  Celula *aux = dq->ini;
  Celula *liberar;
  while (aux != NULL) {
    liberar = aux;
    aux = aux->prox;
    free(liberar);
  }
  free(dq);
}

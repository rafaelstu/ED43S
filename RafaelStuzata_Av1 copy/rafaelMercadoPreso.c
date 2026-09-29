#include "rafaelMercadoPreso.h"
#include <stdio.h>
#include <stdlib.h>

struct item {
  int id_enc;
  int cep;
  int tentativas;
  char nome[50];
  float peso;
};

struct celula {
  Item item;
  Celula *prox; // armazena o endereço da próxima célula
};

struct fila {
  Celula *ini;
  Celula *fim;
};

struct lista {
  Celula *primeira;
};

struct pilha {
  Celula *topo;
};

struct rafaelMercadoPreso { // a) justifique estrutura escolhida

  Fila *f; // entra antes sai antes
  Lista *l;
  Pilha *p; // entregas concluidas - pilha
            // historico de entregas exibe do mais recente ao mais antigo
};

Fila *criaFilaVazia() {
  Fila *f = malloc(sizeof(Fila));
  f->ini = NULL;
  f->fim = NULL;

  return f;
}
int verificaFilaVazia(Fila *f) { return f->ini == NULL; }

Lista *criaListaVazia() {
  Lista *lst = malloc(sizeof(Lista));
  lst->primeira = NULL;
  return lst;
}
int verificaListaVazia(Lista *lst) { return lst->primeira == NULL; }

Pilha *criaPilhaVazia() {
  Pilha *p = malloc(sizeof(Pilha));
  p->topo = NULL;
  return p;
}
int verificaPilhaVazia(Pilha *p) { return p->topo == NULL; }

RafaelMercadoPreso *criaRMP() {
  RafaelMercadoPreso *rMP = malloc(sizeof(RafaelMercadoPreso));
  rMP->l = criaListaVazia();
  rMP->f = criaFilaVazia();
  rMP->p = criaPilhaVazia();

  return rMP;
}

Item *criaItem() {
  Item *novo = malloc(sizeof(Item));

  novo->tentativas = 0;
  printf("informe o id da encomenda: ");
  scanf("%d", &novo->id_enc);
  setbuf(stdin, NULL);
  printf("informe o cep: ");
  scanf("%d", &novo->cep);
  setbuf(stdin, NULL);
  printf("informe o nome do destinatario: ");
  scanf(" %49[^\n]", novo->nome);
  setbuf(stdin, NULL);
  printf("informe o peso (kg): ");
  scanf("%f", &novo->peso);

  return novo;
}

// sempre no inicio pq tanto faz a posição e é mais rapido
void insereInicioLista(RafaelMercadoPreso *rMP) {
  Celula *nova = malloc(sizeof(Celula));
  nova->item = *criaItem();
  nova->prox = rMP->l->primeira;
  rMP->l->primeira = nova;
}

void insere(RafaelMercadoPreso *rMP) {

  Celula *nova = malloc(sizeof(Celula));
  nova->item = *criaItem();
  nova->prox = NULL;

  if (verificaFilaVazia(rMP->f)) { // se esta vazia adiciona no inicio
    rMP->f->ini = nova;
  } else {
    rMP->f->fim->prox = nova;
  }
  rMP->f->fim = nova;
}

void insereFrustrado(RafaelMercadoPreso *rMP, Celula *c) {

  c->prox = NULL;

  if (verificaFilaVazia(rMP->f)) { // se esta vazia adiciona no inicio
    rMP->f->ini = c;
  } else {
    rMP->f->fim->prox = c;
  }
  rMP->f->fim = c;
}

Celula *desenfileira(RafaelMercadoPreso *rMP) {
  if (verificaFilaVazia(rMP->f)) {
    printf("\nerro: fila vazia");
    return NULL;
  }
  Celula *remover = rMP->f->ini;
  rMP->f->ini = remover->prox;

  if (verificaFilaVazia(rMP->f)) {
    rMP->f->fim = NULL; // se ficou vazia, fim aponta para NULL
  }

  return remover;
}

void concluirEntrega(RafaelMercadoPreso *rMP, Celula *celula) {
  celula->prox = rMP->p->topo;
  rMP->p->topo = celula;
}

int conseguiuEntregar() {
  int entregue;
  printf("a encomenda foi entregue? (sim: 1, não: 0) ");
  scanf("%d", &entregue);

  return entregue;
}

// Celula *tentativaEntregaItem(RafaelMercadoPreso *rMP) {
//   Celula *aux = rMP->l->primeira;
//   Celula *anterior;
//   int id_enc;
//
//   printf("qual o id da encomenda? ");
//   scanf("%d", &id_enc);
//
//   while (aux != NULL && aux->item.id_enc != id_enc) {
//     anterior = aux;
//     aux = aux->prox;
//   }
//   if (aux == NULL) {
//     printf("item nao encontrado\n");
//     return NULL;
//   }
//
//   int entregue = conseguiuEntregar();
//
//   if (entregue == 0) {
//     aux->item.tentativas++;
//     return NULL;
//   }
//
//   if (aux == rMP->l->primeira) {
//     rMP->l->primeira = aux->prox;
//   } else {
//     anterior->prox = aux->prox;
//   }
//
//   return aux;
// }

void imprimeItem(Item *item) {
  printf("id encomenda: %d\n", item->id_enc);
  printf("cep: %d\n", item->cep);
  printf("nome: %s\n", item->nome);
  printf("peso (kg): %.3f\n", item->peso);
  printf("tentativas de entrega: %d\n", item->tentativas);
}

void filtrarCep(RafaelMercadoPreso *rMP, int cep, int origem) {

  Celula *aux;
  int total = 0;

  if (origem == 0) {
    for (aux = rMP->f->ini; aux != NULL; aux = aux->prox) {
      if (cep == 0 || aux->item.cep == cep) {
        total++;
        printf("\n");
        imprimeItem(&aux->item);
      }
    }
  }
  if (origem == 1) {
    for (aux = rMP->p->topo; aux != NULL; aux = aux->prox) {
      if (cep == 0 || aux->item.cep == cep) {
        total++;
        printf("\n");
        imprimeItem(&aux->item);
      }
    }
  }

  printf("total de itens: %d\n", total);
}

void liberaPilha(Pilha *p) {
  Celula *aux = p->topo;
  Celula *liberar;
  while (aux != NULL) {
    liberar = aux;
    aux = aux->prox;
    free(liberar);
  }
  free(p);
}

void liberaLista(Lista *lst) {
  Celula *aux = lst->primeira;
  Celula *liberar;
  while (aux != NULL) {
    liberar = aux;
    aux = aux->prox;
    free(liberar);
  }
  free(lst);
}

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

void liberaRMP(RafaelMercadoPreso *rMP) {
  liberaLista(rMP->l);
  liberaPilha(rMP->p);
  liberaFila(rMP->f);
  free(rMP);
}

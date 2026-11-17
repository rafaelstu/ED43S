#include "ArvoreLLRB.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct no_arvore {
  char info[33];
  char setor[33];
  double preco_atual;
  int qtd_disp;
  struct no_arvore *esq; // ponteiro para a subarvore da esquerda
  struct no_arvore *dir; // ponteiro para a subarvore da direita
  time_t atualizacao_lote;
  int cor;
};

ArvLLRB *cria_ArvLLRB() {
  ArvLLRB *raiz = (ArvLLRB *)malloc(sizeof(ArvLLRB));
  if (raiz != NULL) {
    *raiz = NULL;
  }
  return raiz;
}

// Função recursiva que libera todos os nós filhos a partir de um nó raiz
void libera_NO(struct no_arvore *no) {
  if (no == NULL)
    return;
  libera_NO(no->esq);
  libera_NO(no->dir);
  free(no);
  no = NULL;
}

// Libera a árvore red-black após liberar todos os nós
void libera_ArvLLRB(ArvLLRB *raiz) {
  if (raiz == NULL)
    return;
  libera_NO(*raiz); // libera cada nó
  free(raiz);       // libera a raiz
}

void imprimeCor(int cor) {
  if (cor == RED)
    printf("[Vermelho]");
  else
    printf("[Preto]");
}

void imprime_NO(struct no_arvore *no) {
  printf("\nEvento: %s\n", no->info);
  printf("Setor: %s\n", no->setor);
  printf("Preco atual: %.2f\n", no->preco_atual);
  printf("Quantidade disponivel: %d\n", no->qtd_disp);
  printf("Ultima atualizacao de lote: %s", ctime(&no->atualizacao_lote));
  printf("Cor: ");
  imprimeCor(no->cor);
  printf("\n");
}

time_t leDataHora() {
  struct tm tempo = {0};
  scanf("%d/%d/%d %d:%d:%d", &tempo.tm_mday, &tempo.tm_mon, &tempo.tm_year,
        &tempo.tm_hour, &tempo.tm_min, &tempo.tm_sec);
  setbuf(stdin, NULL);
  tempo.tm_mon -= 1;
  tempo.tm_year -= 1900;
  tempo.tm_isdst = -1;
  return mktime(&tempo);
}

// Retorna 1 se encontrou o valor procurado, ou 0 se não encontrou
int consulta_ArvLLRB(ArvLLRB *raiz, char valor[33]) {
  if (raiz == NULL)
    return 0;
  struct no_arvore *atual = *raiz;
  while (atual != NULL) {
    if (strcmp(valor, atual->info) == 0) {
      imprime_NO(atual);
      return 1;
    }
    if (strcmp(valor, atual->info) > 0)
      atual = atual->dir;
    else
      atual = atual->esq;
  }
  return 0;
}
// =================================
// ROTAÇÃO
// =================================
struct no_arvore *rotacionaEsquerda(struct no_arvore *A) {
  printf(".Rotacao a esquerda - no %s desce e o filho direito %s sobe\n",
         A->info, A->dir->info);
  struct no_arvore *B = A->dir;
  A->dir = B->esq;
  B->esq = A;
  B->cor = A->cor;
  A->cor = RED;
  return B;
}

struct no_arvore *rotacionaDireita(struct no_arvore *A) {
  printf(".Rotacao a direita - no %s desce e o filho esquerdo %s sobe\n",
         A->info, A->esq->info);
  struct no_arvore *B = A->esq;
  A->esq = B->dir;
  B->dir = A;
  B->cor = A->cor;
  A->cor = RED;
  return B;
}
// =================================
// PROPRIEDADES
// =================================
int cor(struct no_arvore *H) {
  if (H == NULL)
    return BLACK;
  else
    return H->cor;
}

void trocaCor(struct no_arvore *H) {
  printf(".Troca de cor - no %s e seus filhos invertem a cor\n", H->info);
  H->cor = !H->cor;
  if (H->esq != NULL)
    H->esq->cor = !H->esq->cor;
  if (H->dir != NULL)
    H->dir->cor = !H->dir->cor;
}

struct no_arvore *criaNo(char info[33], char setor[33], double preco_atual,
                         int qtd_disp, time_t atualizacao_lote) {
  struct no_arvore *novo;

  novo = (struct no_arvore *)malloc(sizeof(struct no_arvore));
  if (novo == NULL)
    return NULL;

  strcpy(novo->info, info);
  strcpy(novo->setor, setor);
  novo->preco_atual = preco_atual;
  novo->qtd_disp = qtd_disp;
  novo->atualizacao_lote = atualizacao_lote;
  novo->cor = RED;
  novo->esq = NULL;
  novo->dir = NULL;
  return novo;
}

// =================================
// INSERCAO
// =================================
struct no_arvore *insereNO(struct no_arvore *H, char valor[33], char setor[33],
                           double preco_atual, int qtd_disp,
                           time_t atualizacao_lote, int *resp) {
  if (H == NULL) {
    struct no_arvore *novo =
        criaNo(valor, setor, preco_atual, qtd_disp, atualizacao_lote);
    if (novo == NULL) {
      *resp = 0;
      return NULL;
    }
    *resp = 1;
    return novo;
  }
  // continuação
  if (strcmp(valor, H->info) == 0) { // Valor duplicado
    H->preco_atual = preco_atual;
    H->qtd_disp += qtd_disp;
    H->atualizacao_lote = atualizacao_lote;
    *resp = 2;
  } else {
    if (strcmp(valor, H->info) < 0)
      H->esq = insereNO(H->esq, valor, setor, preco_atual, qtd_disp,
                        atualizacao_lote, resp);
    else
      H->dir = insereNO(H->dir, valor, setor, preco_atual, qtd_disp,
                        atualizacao_lote, resp);
  }

  // nó Vermelho é sempre filho à esquerda
  if (cor(H->dir) == RED && cor(H->esq) == BLACK) {
    printf("Violacao: no %s tem filho vermelho a direita (%s)\n", H->info,
           H->dir->info);
    H = rotacionaEsquerda(H);
  }

  // Filho e Neto são vermelhos
  // Filho vira pai de 2 nós vermelhos
  if (cor(H->esq) == RED && cor(H->esq->esq) == RED) {
    printf("Violacao: dois vermelhos seguidos a esquerda de %s (%s e %s)\n",
           H->info, H->esq->info, H->esq->esq->info);
    H = rotacionaDireita(H);
  }

  // 2 filhos Vermelhos: troca cor!
  if (cor(H->esq) == RED && cor(H->dir) == RED) {
    printf("Violacao: no %s tem dois filhos vermelhos (%s e %s)\n", H->info,
           H->esq->info, H->dir->info);
    trocaCor(H);
  }

  return H;
}

int insere_ArvLLRB(ArvLLRB *raiz, char valor[33], char setor[33],
                   double preco_atual, int qtd_disp, time_t atualizacao_lote) {
  int resp;
  // Função responsável pela busca do local de inserção do nó
  *raiz = insereNO(*raiz, valor, setor, preco_atual, qtd_disp, atualizacao_lote,
                   &resp);
  if ((*raiz) != NULL)
    (*raiz)->cor = BLACK;

  return resp;
}

void criaLote(ArvLLRB *raiz) {
  char info[33], setor[33];
  double preco_atual;
  int qtd_disp, res;
  time_t atualizacao_lote;

  printf("artista/evento: ");
  scanf(" %32[^\n]", info);
  setbuf(stdin, NULL);
  printf("setor: ");
  scanf(" %32[^\n]", setor);
  setbuf(stdin, NULL);
  printf("preco atual: ");
  scanf("%lf", &preco_atual);
  setbuf(stdin, NULL);
  printf("quantidade disponivel: ");
  scanf("%d", &qtd_disp);
  setbuf(stdin, NULL);
  printf("data/hora de atualizacao (dd/mm/aaaa hh:mm:ss): ");
  atualizacao_lote = leDataHora();

  res = insere_ArvLLRB(raiz, info, setor, preco_atual, qtd_disp,
                       atualizacao_lote);
  if (res == 0)
    printf("erro ao inserir lote\n");
  else if (res == 2)
    printf("evento ja cadastrado: preco atualizado e quantidade somada ao "
           "estoque\n");
}

int atualiza_ArvLLRB(ArvLLRB *raiz, char valor[33], double preco_atual,
                     int qtd_disp, time_t atualizacao_lote) {
  if (raiz == NULL)
    return 0;

  struct no_arvore *atual = *raiz;
  while (atual != NULL) {
    int cmp = strcmp(valor, atual->info);
    if (cmp == 0) {
      atual->preco_atual = preco_atual;
      atual->qtd_disp = qtd_disp;
      atual->atualizacao_lote = atualizacao_lote;
      printf("lote atualizado\n");
      imprime_NO(atual);
      return 1;
    }
    if (cmp > 0)
      atual = atual->dir;
    else
      atual = atual->esq;
  }
  return 0;
}

void atualizaLote(ArvLLRB *raiz) {
  char info[33];
  double preco_atual;
  int qtd_disp, res;
  time_t atualizacao_lote;

  printf("artista/evento: ");
  scanf(" %32[^\n]", info);
  setbuf(stdin, NULL);
  printf("novo preco atual: ");
  scanf("%lf", &preco_atual);
  setbuf(stdin, NULL);
  printf("nova quantidade disponivel: ");
  scanf("%d", &qtd_disp);
  setbuf(stdin, NULL);
  printf("data/hora de atualizacao (dd/mm/aaaa hh:mm:ss): ");
  atualizacao_lote = leDataHora();

  res = atualiza_ArvLLRB(raiz, info, preco_atual, qtd_disp, atualizacao_lote);
  if (res == 0)
    printf("evento nao encontrado\n");
}

int buscaFaixaPreco_ArvLLRB(ArvLLRB *raiz, double minimo, double maximo) {
  if (raiz == NULL || *raiz == NULL)
    return 0;

  int qtd = buscaFaixaPreco_ArvLLRB(&((*raiz)->esq), minimo, maximo);

  if ((*raiz)->preco_atual >= minimo && (*raiz)->preco_atual <= maximo) {
    imprime_NO(*raiz);
    qtd++;
  }

  qtd += buscaFaixaPreco_ArvLLRB(&((*raiz)->dir), minimo, maximo);
  return qtd;
}

void criaFaixaPreco(ArvLLRB *raiz) {
  double minimo, maximo;
  int qtd;

  printf("preco minimo: ");
  scanf("%lf", &minimo);
  setbuf(stdin, NULL);
  printf("preco maximo: ");
  scanf("%lf", &maximo);
  setbuf(stdin, NULL);

  printf("\ningressos na faixa de preco:\n");
  qtd = buscaFaixaPreco_ArvLLRB(raiz, minimo, maximo);
  if (qtd == 0)
    printf("nenhum ingresso encontrado na faixa de preco\n");
  else
    printf("\ntotal de ingressos na faixa de preco: %d\n", qtd);
}
// =================================
// REMOÇÃO
// =================================
struct no_arvore *balancear(struct no_arvore *H) {
  // nó Vermelho é sempre filho à esquerda
  if (cor(H->dir) == RED) {
    printf("Violacao: no %s tem filho vermelho a direita (%s)\n", H->info,
           H->dir->info);
    H = rotacionaEsquerda(H);
  }

  // Filho da esquerda e neto da esquerda são vermelhos
  if (H->esq != NULL && cor(H->esq) == RED && cor(H->esq->esq) == RED) {
    printf("Violacao: dois vermelhos seguidos a esquerda de %s (%s e %s)\n",
           H->info, H->esq->info, H->esq->esq->info);
    H = rotacionaDireita(H);
  }

  // 2 filhos Vermelhos: troca cor!
  if (cor(H->esq) == RED && cor(H->dir) == RED) {
    printf("Violacao: no %s tem dois filhos vermelhos (%s e %s)\n", H->info,
           H->esq->info, H->dir->info);
    trocaCor(H);
  }

  return H;
}

struct no_arvore *move2EsqRED(struct no_arvore *H) {
  trocaCor(H);
  if (cor(H->dir->esq) == RED) {
    H->dir = rotacionaDireita(H->dir);
    H = rotacionaEsquerda(H);
    trocaCor(H);
  }
  return H;
}

struct no_arvore *move2DirRED(struct no_arvore *H) {
  trocaCor(H);
  if (cor(H->esq->esq) == RED) {
    H = rotacionaDireita(H);
    trocaCor(H);
  }
  return H;
}

struct no_arvore *removerMenor(struct no_arvore *H) {
  if (H->esq == NULL) {
    free(H);
    return NULL;
  }
  if (cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK)
    H = move2EsqRED(H);

  H->esq = removerMenor(H->esq);
  return balancear(H);
}

struct no_arvore *procuraMenor(struct no_arvore *atual) {
  struct no_arvore *no1 = atual;
  struct no_arvore *no2 = atual->esq;
  while (no2 != NULL) {
    no1 = no2;
    no2 = no2->esq;
  }
  return no1;
}

struct no_arvore *remove_NO(struct no_arvore *H, char valor[33]) {
  int cmp = strcmp(valor, H->info);

  if (cmp < 0) {
    if (cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK)
      H = move2EsqRED(H);

    H->esq = remove_NO(H->esq, valor);
  } else {
    if (cor(H->esq) == RED)
      H = rotacionaDireita(H);

    if (cmp == 0 && (H->dir == NULL)) {
      free(H);
      return NULL;
    }

    if (cor(H->dir) == BLACK && cor(H->dir->esq) == BLACK)
      H = move2DirRED(H);

    if (cmp == 0) {
      struct no_arvore *x = procuraMenor(H->dir);
      strcpy(H->info, x->info);
      strcpy(H->setor, x->setor);
      H->preco_atual = x->preco_atual;
      H->qtd_disp = x->qtd_disp;
      H->atualizacao_lote = x->atualizacao_lote;
      H->dir = removerMenor(H->dir);
    } else
      H->dir = remove_NO(H->dir, valor);
  }
  return balancear(H);
}

int remove_ArvLLRB(ArvLLRB *raiz, char valor[33]) {
  if (consulta_ArvLLRB(raiz, valor)) {
    struct no_arvore *h = *raiz;
    // Função responsável pela busca do nó a ser removido
    *raiz = remove_NO(h, valor);
    if (*raiz != NULL)
      (*raiz)->cor = BLACK;
    return 1;
  } else
    return 0;
}
// =================================
// PROPRIEDADES ÁRVORE
// =================================
int estaVazia_ArvLLRB(ArvLLRB *raiz) {
  if (raiz == NULL)
    return 1;
  if (*raiz == NULL)
    return 1;
  return 0;
}

// Retorna a quantidade de nós a partir de uma raiz
int totalNO_ArvLLRB(ArvLLRB *raiz) {
  if (raiz == NULL)
    return 0;
  if (*raiz == NULL)
    return 0;

  int alt_esq = totalNO_ArvLLRB(&((*raiz)->esq));
  int alt_dir = totalNO_ArvLLRB(&((*raiz)->dir));
  return (alt_esq + alt_dir + 1);
}

// Mostra a altura da árvore
int altura_ArvLLRB(ArvLLRB *raiz) {
  if (raiz == NULL)
    return 0;
  if (*raiz == NULL)
    return 0;
  int alt_esq = altura_ArvLLRB(&((*raiz)->esq));
  int alt_dir = altura_ArvLLRB(&((*raiz)->dir));
  if (alt_esq > alt_dir)
    return (alt_esq + 1);
  else
    return (alt_dir + 1);
}
// =================================
// PERCURSO
// =================================
void posOrdem_ArvLLRB(ArvLLRB *raiz, int H) {
  if (raiz == NULL)
    return;

  if (*raiz != NULL) {
    posOrdem_ArvLLRB(&((*raiz)->esq), H + 1);
    posOrdem_ArvLLRB(&((*raiz)->dir), H + 1);

    if ((*raiz)->cor == RED)
      printf("Chave: %s - [Vermelho] - Nivel(%d) \n", (*raiz)->info, H);
    else
      printf("Chave: %s - [Preto] - Nivel(%d) \n", (*raiz)->info, H);
  }
}

void emOrdem_ArvLLRB(ArvLLRB *raiz, int H, char *pai) {
  if (raiz == NULL)
    return;

  if (*raiz != NULL) {
    emOrdem_ArvLLRB(&((*raiz)->esq), H + 1, (*raiz)->info);

    if ((*raiz)->cor == RED)
      printf("Chave: %s - [Vermelho] - Nivel(%d) - Pai: %s\n", (*raiz)->info, H,
             pai);
    else
      printf("Chave: %s - [Preto] - Nivel(%d) - Pai: %s\n", (*raiz)->info, H,
             pai);

    emOrdem_ArvLLRB(&((*raiz)->dir), H + 1, (*raiz)->info);
  }
}

void emOrdem_NoArvLLRB(ArvLLRB *raiz) {
  if (raiz == NULL)
    return;

  if (*raiz != NULL) {
    emOrdem_NoArvLLRB(&((*raiz)->esq));
    imprime_NO(*raiz);
    emOrdem_NoArvLLRB(&((*raiz)->dir));
  }
}

void preOrdem_ArvLLRB(ArvLLRB *raiz, int H) {
  if (raiz == NULL)
    return;

  if (*raiz != NULL) {
    if ((*raiz)->cor == RED)
      printf("Chave: %s - [Vermelho] - Nivel(%d) \n", (*raiz)->info, H);
    else
      printf("Chave: %s - [Preto] - Nivel(%d) \n", (*raiz)->info, H);

    preOrdem_ArvLLRB(&((*raiz)->esq), H + 1);
    preOrdem_ArvLLRB(&((*raiz)->dir), H + 1);
  }
}

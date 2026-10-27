#include "ArvoreAVL.h" //inclui os Protótipos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no_arvore {
  char info[50];
  char categoria[33];
  int tendencia;
  long long visualizacoes;
  time_t instante;
  int altura;
  struct no_arvore *esq;
  struct no_arvore *dir;
};

NoArvAVL *cria_ArvAVL() {
  NoArvAVL *raiz = (NoArvAVL *)malloc(sizeof(NoArvAVL));
  if (raiz != NULL)
    *raiz = NULL;
  return raiz;
}

void libera_NO(struct no_arvore *no) {
  if (no == NULL)
    return;
  libera_NO(no->esq);
  libera_NO(no->dir);
  free(no);
  no = NULL;
}

void libera_ArvAVL(NoArvAVL *raiz) {
  if (raiz == NULL)
    return;
  libera_NO(*raiz); // libera cada nó
  free(raiz);       // libera a raiz
}

int altura_NO(struct no_arvore *no) {
  if (no == NULL)
    return -1;
  else
    return no->altura;
}

int fatorBalanceamento_NO(struct no_arvore *no) {
  return labs(altura_NO(no->esq) - altura_NO(no->dir));
}

int maior(int x, int y) {
  if (x > y)
    return x;
  else
    return y;
}

int hashtagViralizou(long long visualizacoes, time_t instante) {
  double tempo_decorrido = difftime(time(NULL), instante);
  if (visualizacoes > LIMITE_VIRAL && tempo_decorrido >= 0 &&
      tempo_decorrido < VINTE_QUATRO_HORAS)
    return 1;
  return 0;
}

void imprimeTendencia(int tendencia) {
  if (tendencia)
    printf("sim");
  else
    printf("nao");
}

void imprime_NO(struct no_arvore *no) {
  printf("\nHashtag: %s\n", no->info);
  printf("Categoria: %s\n", no->categoria);
  printf("Tendencia: ");
  imprimeTendencia(no->tendencia);
  printf("\nVisualizacoes: %lld\n", no->visualizacoes);
  printf("Instante de criacao: %s", ctime(&no->instante));
}

int estaVazia_ArvAVL(NoArvAVL *raiz) {
  if (raiz == NULL)
    return 1;
  if (*raiz == NULL)
    return 1;
  return 0;
}

int totalNO_ArvAVL(NoArvAVL *raiz) {
  if (raiz == NULL)
    return 0;
  if (*raiz == NULL)
    return 0;
  int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
  int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
  return (alt_esq + alt_dir + 1);
}

int altura_ArvAVL(NoArvAVL *raiz) {
  if (raiz == NULL)
    return 0;
  if (*raiz == NULL)
    return 0;
  int alt_esq = altura_ArvAVL(&((*raiz)->esq));
  int alt_dir = altura_ArvAVL(&((*raiz)->dir));
  if (alt_esq > alt_dir)
    return (alt_esq + 1);
  else
    return (alt_dir + 1);
}

void preOrdem_ArvAVL(NoArvAVL *raiz, char *pai) {
  if (raiz == NULL)
    return;
  if (*raiz != NULL) {
    printf("Chave: %s - Altura(%d) - Pai: %s fb(%d)\n", (*raiz)->info,
           altura_NO(*raiz), pai, fatorBalanceamento_NO(*raiz));
    preOrdem_ArvAVL(&((*raiz)->esq), (*raiz)->info);
    preOrdem_ArvAVL(&((*raiz)->dir), (*raiz)->info);
  }
}

void emOrdem_ArvAVL(NoArvAVL *raiz, char *pai) {
  if (raiz == NULL)
    return;
  if (*raiz != NULL) {
    emOrdem_ArvAVL(&((*raiz)->esq), (*raiz)->info);
    printf("Chave: %s - Altura(%d) - Pai: %s fb(%d)\n", (*raiz)->info,
           altura_NO(*raiz), pai, fatorBalanceamento_NO(*raiz));
    emOrdem_ArvAVL(&((*raiz)->dir), (*raiz)->info);
  }
}

void emOrdem_NoArvAVL(NoArvAVL *raiz, char *pai) {
  (void)pai;
  if (raiz == NULL)
    return;
  if (*raiz != NULL) {
    emOrdem_NoArvAVL(&((*raiz)->esq), (*raiz)->info);
    imprime_NO(*raiz);
    emOrdem_NoArvAVL(&((*raiz)->dir), (*raiz)->info);
  }
}

void posOrdem_ArvAVL(NoArvAVL *raiz, char *pai) {
  if (raiz == NULL)
    return;
  if (*raiz != NULL) {
    posOrdem_ArvAVL(&((*raiz)->esq), (*raiz)->info);
    posOrdem_ArvAVL(&((*raiz)->dir), (*raiz)->info);
    printf("Chave: %s - Altura(%d) - Pai: %s fb(%d)\n", (*raiz)->info,
           altura_NO(*raiz), pai, fatorBalanceamento_NO(*raiz));
  }
}

int consulta_ArvAVL(NoArvAVL *raiz, char *valor) {
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

//=================================
void RotacaoLL(NoArvAVL *A) { // LL
  printf(".RotacaoLL - Hashtag %s com FB = %d\n", (*A)->info,
         fatorBalanceamento_NO(*A));
  printf("hashtag %s viralizou: ajustando altura da arvore para manter busca "
         "instantanea\n",
         (*A)->info);
  struct no_arvore *B;
  B = (*A)->esq;
  (*A)->esq = B->dir;
  B->dir = *A;
  (*A)->altura = maior(altura_NO((*A)->esq), altura_NO((*A)->dir)) + 1;
  B->altura = maior(altura_NO(B->esq), (*A)->altura) + 1;
  *A = B;
}

void RotacaoRR(NoArvAVL *A) { // RR
  printf(".RotacaoRR - Hashtag %s com FB = %d\n", (*A)->info,
         fatorBalanceamento_NO(*A));
  printf("hashtag %s viralizou: ajustando altura da arvore para manter busca "
         "instantanea\n",
         (*A)->info);
  struct no_arvore *B;
  B = (*A)->dir;
  (*A)->dir = B->esq;
  B->esq = (*A);
  (*A)->altura = maior(altura_NO((*A)->esq), altura_NO((*A)->dir)) + 1;
  B->altura = maior(altura_NO(B->dir), (*A)->altura) + 1;
  (*A) = B;
}

void RotacaoLR(NoArvAVL *A) { // LR
  printf(".RotacaoLR - Hashtag %s com FB = %d\n", (*A)->info,
         fatorBalanceamento_NO(*A));
  printf("hashtag %s viralizou: ajustando altura da arvore para manter busca "
         "instantanea\n",
         (*A)->info);
  RotacaoRR(&(*A)->esq);
  RotacaoLL(A);
}

void RotacaoRL(NoArvAVL *A) { // RL
  printf(".RotacaoRL - Hashtag %s com FB = %d\n", (*A)->info,
         fatorBalanceamento_NO(*A));
  printf("hashtag %s viralizou: ajustando altura da arvore para manter busca "
         "instantanea\n",
         (*A)->info);
  RotacaoLL(&(*A)->dir);
  RotacaoRR(A);
}

int insere_ArvAVL(NoArvAVL *raiz, char *valor, char *categoria,
                  long long visualizacoes, time_t instante) {
  int res;
  if (*raiz == NULL) { // árvore vazia ou nó folha
    struct no_arvore *novo;
    novo = (struct no_arvore *)malloc(sizeof(struct no_arvore));
    if (novo == NULL)
      return 0;

    strcpy(novo->info, valor);
    strcpy(novo->categoria, categoria);
    novo->visualizacoes = visualizacoes;
    novo->instante = instante;
    novo->tendencia = hashtagViralizou(visualizacoes, instante);
    novo->altura = 0;
    novo->esq = NULL;
    novo->dir = NULL;
    *raiz = novo;

    if (novo->tendencia)
      printf("hashtag %s marcada como tendencia: mais de 1 milhao de "
             "visualizacoes em menos de 24 horas\n",
             novo->info);
    return 1;
  }

  struct no_arvore *atual = *raiz;
  if (strcmp(valor, atual->info) < 0) {
    if ((res = insere_ArvAVL(&(atual->esq), valor, categoria, visualizacoes,
                             instante)) == 1) {
      if (fatorBalanceamento_NO(atual) >= 2) {
        if (strcmp(valor, (*raiz)->esq->info) < 0) {
          RotacaoLL(raiz);
        } else {
          RotacaoLR(raiz);
        }
      }
    }
  } else {
    if (strcmp(valor, atual->info) > 0) {
      if ((res = insere_ArvAVL(&(atual->dir), valor, categoria, visualizacoes,
                               instante)) == 1) {
        if (fatorBalanceamento_NO(atual) >= 2) {
          if (strcmp((*raiz)->dir->info, valor) < 0) {
            RotacaoRR(raiz);
          } else {
            RotacaoRL(raiz);
          }
        }
      }
    } else {
      printf("hashtag ja cadastrada!!\n");
      return 2;
    }
  }

  atual->altura = maior(altura_NO(atual->esq), altura_NO(atual->dir)) + 1;

  return res;
}

void criaHashtag(NoArvAVL *raiz) {
  char hashtag[50], categoria[33];
  long long visualizacoes;
  int res;
  struct tm tempo = {0};
  time_t instante;

  printf("hashtag: ");
  scanf(" %49[^\n]", hashtag);
  setbuf(stdin, NULL);
  printf("categoria: ");
  scanf(" %32[^\n]", categoria);
  setbuf(stdin, NULL);
  printf("visualizacoes: ");
  scanf("%lld", &visualizacoes);
  setbuf(stdin, NULL);
  printf("data/hora de criacao (dd/mm/aaaa hh:mm:ss): ");
  scanf("%d/%d/%d %d:%d:%d", &tempo.tm_mday, &tempo.tm_mon, &tempo.tm_year,
        &tempo.tm_hour, &tempo.tm_min, &tempo.tm_sec);
  setbuf(stdin, NULL);
  tempo.tm_mon -= 1;
  tempo.tm_year -= 1900;
  instante = mktime(&tempo);

  res = insere_ArvAVL(raiz, hashtag, categoria, visualizacoes, instante);
  if (res == 0)
    printf("erro ao inserir hashtag\n");
}

int simularEngajamento(NoArvAVL *raiz, char *valor, long long visualizacoes) {
  if (raiz == NULL)
    return 0;

  struct no_arvore *atual = *raiz;
  while (atual != NULL) {
    int cmp = strcmp(valor, atual->info);
    if (cmp == 0) {
      atual->visualizacoes += visualizacoes;
      if (!atual->tendencia &&
          hashtagViralizou(atual->visualizacoes, atual->instante)) {
        atual->tendencia = 1;
        printf("hashtag %s viralizou: ajustando altura da arvore para manter "
               "busca instantanea\n",
               atual->info);
      }
      printf("engajamento simulado. visualizacoes de %s: %lld\n", atual->info,
             atual->visualizacoes);
      return 1;
    }
    if (cmp > 0)
      atual = atual->dir;
    else
      atual = atual->esq;
  }
  return 0;
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

int remove_ArvAVL(NoArvAVL *raiz, char *valor) {
  if (*raiz == NULL) { // valor não existe
    printf("hashtag não existe!!\n");
    return 0;
  }
  int res;
  int cmp = strcmp(valor, (*raiz)->info);
  if (cmp < 0) {
    if ((res = remove_ArvAVL(&(*raiz)->esq, valor)) == 1) {
      if (fatorBalanceamento_NO(*raiz) >= 2) {
        if (altura_NO((*raiz)->dir->esq) <= altura_NO((*raiz)->dir->dir))
          RotacaoRR(raiz);
        else
          RotacaoRL(raiz);
      }
    }
  } else if (cmp > 0) {
    if ((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1) {
      if (fatorBalanceamento_NO(*raiz) >= 2) {
        if (altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq))
          RotacaoLL(raiz);
        else
          RotacaoLR(raiz);
      }
    }
  } else {
    if (((*raiz)->esq == NULL ||
         (*raiz)->dir == NULL)) { // nó tem 1 filho ou nenhum
      struct no_arvore *oldNode = (*raiz);
      if ((*raiz)->esq != NULL)
        *raiz = (*raiz)->esq;
      else
        *raiz = (*raiz)->dir;
      free(oldNode);
    } else { // nó tem 2 filhos
      struct no_arvore *temp = procuraMenor((*raiz)->dir);
      strcpy((*raiz)->info, temp->info);
      strcpy((*raiz)->categoria, temp->categoria);
      (*raiz)->tendencia = temp->tendencia;
      (*raiz)->visualizacoes = temp->visualizacoes;
      (*raiz)->instante = temp->instante;
      remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);
      if (fatorBalanceamento_NO(*raiz) >= 2) {
        if (altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq))
          RotacaoLL(raiz);
        else
          RotacaoLR(raiz);
      }
    }
    if (*raiz != NULL)
      (*raiz)->altura =
          maior(altura_NO((*raiz)->esq), altura_NO((*raiz)->dir)) + 1;
    return 1;
  }

  (*raiz)->altura = maior(altura_NO((*raiz)->esq), altura_NO((*raiz)->dir)) + 1;

  return res;
}

int buscaTendencias_ArvAVL(NoArvAVL *raiz, time_t inicio, time_t fim) {
  if (raiz == NULL || *raiz == NULL)
    return 0;

  int qtd = buscaTendencias_ArvAVL(&((*raiz)->esq), inicio, fim);

  if ((*raiz)->tendencia && (*raiz)->instante >= inicio &&
      (*raiz)->instante <= fim) {
    imprime_NO(*raiz);
    qtd++;
  }

  qtd += buscaTendencias_ArvAVL(&((*raiz)->dir), inicio, fim);
  return qtd;
}

void criaIntervaloTendencia(NoArvAVL *raiz) {
  struct tm tempoInicio = {0};
  struct tm tempoFim = {0};
  time_t inicio, fim;
  int qtd;

  printf("data/hora inicial (dd/mm/aaaa hh:mm:ss): ");
  scanf("%d/%d/%d %d:%d:%d", &tempoInicio.tm_mday, &tempoInicio.tm_mon,
        &tempoInicio.tm_year, &tempoInicio.tm_hour, &tempoInicio.tm_min,
        &tempoInicio.tm_sec);
  setbuf(stdin, NULL);
  tempoInicio.tm_mon -= 1;
  tempoInicio.tm_year -= 1900;
  inicio = mktime(&tempoInicio);

  printf("data/hora final (dd/mm/aaaa hh:mm:ss): ");
  scanf("%d/%d/%d %d:%d:%d", &tempoFim.tm_mday, &tempoFim.tm_mon,
        &tempoFim.tm_year, &tempoFim.tm_hour, &tempoFim.tm_min,
        &tempoFim.tm_sec);
  setbuf(stdin, NULL);
  tempoFim.tm_mon -= 1;
  tempoFim.tm_year -= 1900;
  fim = mktime(&tempoFim);

  printf("\nhashtags em tendencia no intervalo:\n");
  qtd = buscaTendencias_ArvAVL(raiz, inicio, fim);
  if (qtd == 0)
    printf("nenhuma hashtag em tendencia encontrada\n");
  else
    printf("\ntotal de hashtags em tendencia: %d\n", qtd);
}

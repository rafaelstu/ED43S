#include <time.h>

#define LIMITE_VIRAL 1000000
#define VINTE_QUATRO_HORAS (24 * 60 * 60)

typedef struct no_arvore *NoArvAVL;

NoArvAVL *cria_ArvAVL();
void libera_ArvAVL(NoArvAVL *raiz);
int insere_ArvAVL(NoArvAVL *raiz, char *valor, char *categoria,
                  long long visualizacoes, time_t instante);
void criaHashtag(NoArvAVL *raiz);
int remove_ArvAVL(NoArvAVL *raiz, char *valor);
int estaVazia_ArvAVL(NoArvAVL *raiz);
int altura_ArvAVL(NoArvAVL *raiz);
int totalNO_ArvAVL(NoArvAVL *raiz);
int consulta_ArvAVL(NoArvAVL *raiz, char *valor);
int simularEngajamento(NoArvAVL *raiz, char *valor, long long visualizacoes);
int buscaTendencias_ArvAVL(NoArvAVL *raiz, time_t inicio, time_t fim);
void criaIntervaloTendencia(NoArvAVL *raiz);
void preOrdem_ArvAVL(NoArvAVL *raiz, char *pai);
void emOrdem_ArvAVL(NoArvAVL *raiz, char *pai);
void emOrdem_NoArvAVL(NoArvAVL *raiz, char *pai);
void posOrdem_ArvAVL(NoArvAVL *raiz, char *pai);

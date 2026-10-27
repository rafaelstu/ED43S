#include <time.h>

typedef struct no_arvore *NoArvAVL;

NoArvAVL *cria_ArvAVL();
void libera_ArvAVL(NoArvAVL *raiz);
int insere_ArvAVL(NoArvAVL *raiz, char *valor, char *motivo, int confianca,
                  time_t t_info);
void criaReport(NoArvAVL *raiz);
int remove_ArvAVL(NoArvAVL *raiz, char *valor);
int estaVazia_ArvAVL(NoArvAVL *raiz);
int altura_ArvAVL(NoArvAVL *raiz);
int totalNO_ArvAVL(NoArvAVL *raiz);
int consulta_ArvAVL(NoArvAVL *raiz, char *valor);
int buscaIntervalo_ArvAVL(NoArvAVL *raiz, time_t inicio, time_t fim);
void criaIntervalo(NoArvAVL *raiz);
void preOrdem_ArvAVL(NoArvAVL *raiz, char *pai);
void emOrdem_ArvAVL(NoArvAVL *raiz, char *pai);
void emOrdem_NoArvAVL(NoArvAVL *raiz, char *pai);
void posOrdem_ArvAVL(NoArvAVL *raiz, char *pai);

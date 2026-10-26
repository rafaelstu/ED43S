
typedef struct no_arvore *NoArvAVL;

NoArvAVL *cria_ArvAVL();
void libera_ArvAVL(NoArvAVL *raiz);
int insere_ArvAVL(NoArvAVL *raiz, char *valor);
int remove_ArvAVL(NoArvAVL *raiz, char *valor);
int estaVazia_ArvAVL(NoArvAVL *raiz);
int altura_ArvAVL(NoArvAVL *raiz);
int totalNO_ArvAVL(NoArvAVL *raiz);
int consulta_ArvAVL(NoArvAVL *raiz, char *valor);
void preOrdem_ArvAVL(NoArvAVL *raiz, char *pai);
void emOrdem_ArvAVL(NoArvAVL *raiz, char *pai);
void posOrdem_ArvAVL(NoArvAVL *raiz, char *pai);

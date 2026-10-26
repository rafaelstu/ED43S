
typedef struct no_arvore* NoArvAVL;

NoArvAVL* cria_ArvAVL();
void libera_ArvAVL(NoArvAVL *raiz);
int insere_ArvAVL(NoArvAVL *raiz, int data);
int remove_ArvAVL(NoArvAVL *raiz, int valor);
int estaVazia_ArvAVL(NoArvAVL *raiz);
int altura_ArvAVL(NoArvAVL *raiz);
int totalNO_ArvAVL(NoArvAVL *raiz);
int consulta_ArvAVL(NoArvAVL *raiz, int valor);
void preOrdem_ArvAVL(NoArvAVL *raiz, int pai);
void emOrdem_ArvAVL(NoArvAVL *raiz, int pai);
void posOrdem_ArvAVL(NoArvAVL *raiz, int pai);

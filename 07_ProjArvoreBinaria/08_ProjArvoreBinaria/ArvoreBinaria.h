typedef struct no_arvore* NoArvBin;

NoArvBin* cria_ArvBin();
void libera_NO(struct no_arvore* no);
void libera_ArvBin(NoArvBin* raiz);
int insere_ArvBin(NoArvBin* raiz, int valor);
struct no_arvore* remove_atual(struct no_arvore* atual);
int remove_ArvBin(NoArvBin *raiz, int valor);
int estaVazia_ArvBin(NoArvBin *raiz);
int totalNO_ArvBin(NoArvBin *raiz);
int altura_ArvBin(NoArvBin *raiz);
int consulta_ArvBin(NoArvBin *raiz, int valor);
void preOrdem_ArvBin(NoArvBin *raiz);
void emOrdem_ArvBin(NoArvBin *raiz);
void posOrdem_ArvBin(NoArvBin *raiz);

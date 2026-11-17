#include <time.h>

#define RED 1
#define BLACK 0

typedef struct no_arvore* ArvLLRB;

ArvLLRB* cria_ArvLLRB();
void libera_ArvLLRB(ArvLLRB* raiz);
int insere_ArvLLRB(ArvLLRB* raiz, char valor[33], char setor[33],
                   double preco_atual, int qtd_disp, time_t atualizacao_lote);
void criaLote(ArvLLRB *raiz);
int atualiza_ArvLLRB(ArvLLRB *raiz, char valor[33], double preco_atual,
                     int qtd_disp, time_t atualizacao_lote);
void atualizaLote(ArvLLRB *raiz);
int buscaFaixaPreco_ArvLLRB(ArvLLRB *raiz, double minimo, double maximo);
void criaFaixaPreco(ArvLLRB *raiz);
int remove_ArvLLRB(ArvLLRB *raiz, char valor[33]);
int estaVazia_ArvLLRB(ArvLLRB *raiz);
int totalNO_ArvLLRB(ArvLLRB *raiz);
int altura_ArvLLRB(ArvLLRB *raiz);
int consulta_ArvLLRB(ArvLLRB *raiz, char valor[33]);
void preOrdem_ArvLLRB(ArvLLRB *raiz, int H);
void emOrdem_ArvLLRB(ArvLLRB *raiz, int H, char *pai);
void emOrdem_NoArvLLRB(ArvLLRB *raiz);
void posOrdem_ArvLLRB(ArvLLRB *raiz, int H);

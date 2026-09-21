typedef struct data Data;
typedef struct item Item;
typedef struct celula Celula;
typedef struct lista Lista;

Lista *criaListaVazia();

void insereItemPorPrioridade(Lista *lst, Item *item);

Item *criaItem();

void imprimeLista(Lista *lst);
void removeItem(Lista *lst, int id_os);
void liberaLista(Lista *lst);

Celula *buscaPorChave(Lista *lst, int chave);
int verificaListaVazia(Lista *lst);

Lista *filtrarOS(Lista *lst, int prioridade);
void buscarOS(Lista *lst, int id_os);

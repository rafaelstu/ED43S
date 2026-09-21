typedef struct data Data;
typedef struct item Item;
typedef struct celula Celula;
typedef struct lista Lista;

Lista *criaListaVazia();

void insereItemPorPrioridade(Lista *lst, Item *item);

Item *criaItem();

void imprimeLista(Lista *lst);
void removeItem(Lista *lst, int x);
void liberaLista(Lista *lst);

Celula *buscaPorChave(Lista *lst, int chave);
int verificaListaVazia(Lista *lst);

void juntaLista(Lista *lst1, Lista *lst2);
void insereOrdenando(Lista *lst1, Lista *lst2);

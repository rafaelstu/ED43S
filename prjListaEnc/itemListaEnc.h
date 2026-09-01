typedef struct item Item;
typedef struct celula Celula;
typedef struct lista Lista;

Lista *criaListaVazia();

void insereInicioLista(Lista *lst, int chave);
void insereFimLista(Lista *lst, int chave);
void insereMeioLista(Lista *lst, int chave, int chaveAnt);

void imprimeLista(Lista *lst);
void removeItem(Lista *lst, int x);
void liberaLista(Lista *lst);

Celula *buscaPorChave(Lista *lst, int chave);
int verificaListaVazia(Lista *lst);

void juntaLista(Lista *lst1, Lista *lst2);
void insereOrdenando(Lista *lst1, Lista *lst2);

typedef struct item Item;
typedef struct celula Celula;
typedef struct pilha Pilha;

Pilha *criaPilhaVazia();

Item *criaItem();
void empilha(Pilha *p, Item *item);

void imprimePilha(Pilha *p);
void desempilha(Pilha *p);
int verificaPilhaVazia(Pilha *p);
void liberaPilha(Pilha *p);

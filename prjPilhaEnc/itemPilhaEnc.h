typedef struct item Item;
typedef struct celula Celula;
typedef struct pilha Pilha;

Pilha *criaPilhaVazia();

void empilha(Pilha *p, int chave);
void imprimePilha(Pilha *p);
void desempilha(Pilha *p);
int verificaPilhaVazia(Pilha *p);
void liberaPilha(Pilha *p);

void separaPilha(Pilha *p1, Pilha *p2, Pilha *p3);

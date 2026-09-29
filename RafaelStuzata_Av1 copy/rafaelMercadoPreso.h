typedef struct item Item;
typedef struct celula Celula;
typedef struct lista Lista;
typedef struct fila Fila;
typedef struct pilha Pilha;
typedef struct rafaelMercadoPreso RafaelMercadoPreso;

RafaelMercadoPreso *criaRMP();
void concluirEntrega(RafaelMercadoPreso *rMP, Celula *celula);
Celula *tentativaEntregaItem(RafaelMercadoPreso *rMP);
void insereInicioLista(RafaelMercadoPreso *rMP);
void filtrarCep(RafaelMercadoPreso *rMP, int cep, int origem);
void liberaRMP(RafaelMercadoPreso *rMP);

void insere(RafaelMercadoPreso *rMP);
void insereFrustrado(RafaelMercadoPreso *rMP, Celula *c);
Celula *desenfileira(RafaelMercadoPreso *rMP);
void concluirEntrega(RafaelMercadoPreso *rMP, Celula *celula);
int conseguiuEntregar();

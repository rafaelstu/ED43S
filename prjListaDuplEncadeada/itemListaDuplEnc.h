#ifndef ITEMLISTADUPLENC_H_INCLUDED
#define ITEMLISTADUPLENC_H_INCLUDED

typedef struct item Item;
typedef struct listaDupl ListaDupl;
typedef struct celula Celula;

//Cria uma lista vazia
ListaDupl *criaListaDuplVazia();
void inserirInicio(ListaDupl *ld, int chave);
void inserirMeio(ListaDupl *ld, int chaveB, int chaveI);
void inserirFinal(ListaDupl *ld, int chave);
Celula *buscaChave(ListaDupl *ld, int chave);
void imprimeEsqDir(ListaDupl *ld);
void imprimeDirEsq(ListaDupl *ld);
void removePorChave(ListaDupl *ld, int chave);
int verificaListaDuplVazia(ListaDupl *ld);
void liberaListaDupl(ListaDupl *ld);

#endif // ITEMLISTADUPLENC_H_INCLUDED

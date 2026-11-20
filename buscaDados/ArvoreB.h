#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED

#include <time.h>

#define M 3
// M refere-se à ordem da árvore, ou seja, quantos filhos cada nó pode ter
// M-1 é o número máximo de chaves que um nó pode ter

typedef struct node Node;
typedef struct midia Midia;
typedef enum statusChave StatusChave;

Node *inserirNo(Node *raiz, char tag[33], int id, char caminho[100]);
StatusChave ins(Node *ptr, Midia chave, Midia *chaveIni, Node **novoNo);
void busca(Node *raiz, char chave[33]);
int buscaChave(Node *raiz, char chave[33], Midia *chaves_arr, int n);
Node *excluirNo(Node *raiz, char chave[33]);
StatusChave del(Node *raiz, Node *ptr, char chave[33]);
void imprime_arvore(Node *ptr, int nivel);
void imprime_no(Node *ptr);

#endif // ARVOREB_H_INCLUDED

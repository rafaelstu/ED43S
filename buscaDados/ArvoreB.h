#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED

#define M 3 //M refere-se à ordem da árvore, ou seja, quantos filhos cada nó pode ter
            //M-1 é o número máximo de chaves que um nó pode ter

typedef struct node Node;
typedef enum statusChave StatusChave;

Node * inserirNo(Node *raiz, int chave);
StatusChave ins(Node *ptr, int chave, int *chaveIni, Node **novoNo);
void busca(Node *raiz, int chave);
int buscaChave(Node *raiz, int chave, int *chaves_arr, int n);
Node* excluirNo(Node *raiz, int chave);
StatusChave del(Node *raiz, Node *ptr, int chave);
void imprime_arvore(Node *ptr, int nivel);
void imprime_no(Node *ptr);

#endif // ARVOREB_H_INCLUDED

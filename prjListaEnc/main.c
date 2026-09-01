#include "itemListaEnc.h"
#include <stdio.h>

int main() {
  Lista *lst, *lst2, *lstJuncao;
  int vazia, chave;

  printf("criando lista vazia\n");
  lst = criaListaVazia();
  lst2 = criaListaVazia();

  // vazia = verificaListaVazia(lst);
  // printf("Lista vazia? %d\n", vazia);

  // printf("Adicionando o 1º item\n");
  chave = 1;
  insereInicioLista(lst, chave);

  // vazia = verificaListaVazia(lst);
  // printf("Lista vazia? %d\n", vazia);

  // printf("Adicionando o 2º item no fim\n");
  chave = 15;
  insereFimLista(lst, chave);

  // printf("Adicionando o 3º item no meio depois do 1º\n");
  chave = 3;
  insereMeioLista(lst, chave, 1);

  // printf("Adicionando o 4º item no fim\n");
  chave = 12;
  insereFimLista(lst, chave);

  // printf("Adicionando o 5º item inicio\n");
  chave = 32;
  insereInicioLista(lst, chave);

  // printf("Adicionando o 6º item inicio\n");
  chave = 99;
  insereInicioLista(lst, chave);

  printf("\nitens da lista 1:\n");
  imprimeLista(lst);

  insereOrdenando(lst, lst2);

  printf("\nitens da lista 2:\n");
  imprimeLista(lst2);

  liberaLista(lst);
  liberaLista(lst2);

  return 0;
}

#include "itemListaEnc.h"
#include <stdio.h>

int main() {
  Lista *lst;
  int vazia, chave;

  printf("criando lista vazia\n");
  lst = criaListaVazia();

  insereInicioLista(lst);

  imprimeLista(lst);

  liberaLista(lst);

  return 0;
}

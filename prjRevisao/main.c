#include <stdio.h>
#include <stdlib.h>

void funcaoSemRetornoESemParametro() {
  //
}

int funcaoComRetornoEParametro(int **n) { return 1; }

int main() {
  // variaveis
  int varInt;       // armazena numeros inteiros
  char varChar;     // armazena 1 caractere
  double varDouble; // casas deicmais com mais precisão
  float varFloat;   // casas decimais com menos precisão
  // vetores
  char strNome[30];    // string - vetor de char
  int vetInteiros[10]; // posições de 0 a 9
  // matriz
  int matInt[4][5]; // matriz de 4 linhas e 5 colunas
  // posições 0 a 3 para linhas; 0 a 4 para colunas;

  // uso de ponteiros
  // definição
  int *pInt; // ponteiro de inteiro
  // atrbuicao:
  pInt = &varInt; // o ponteiro pInt recebe o edereço da variável varInt
  // & dá acesso ao endereço de uma variável
  // * dá acesso ao conteúdo de um ponteior

  // TAD - tipo abstrato de dados encapsulado
  // projeto com 3 arquivos
  // .h com typedefs, constantes e protótipos de função
  // .c com declaração de structs e implementação de funções
  // .c com função main que faz uso do TAD por meio de funções,
  // não há declaração direta de varáveis do tipo da struct na main

  printf("aapapja\n");

  return 0;
}

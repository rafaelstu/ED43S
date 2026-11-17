#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreB.h"

int main() {
        int chave;
        int opcao;
        char delimitador[] = "-";
        char *ptr;
        int valor;
        char l[1000];

        Node *raiz = NULL;

        printf("Criacao de Arvore-B de ordem %d, ou seja, nos com %d filhos, e no maximo %d chaves:\n", M, M, M - 1);
        while (1) {
                printf("\n1.Inserir\n");
                printf("2.Remover\n");
                printf("3.Buscar\n");
                printf("4.Imprimir arvore\n");
                printf("5.Sair do programa\n");
                printf("\nEscolha uma das opcoes do menu: ");
                scanf("%d", &opcao); //eatline();

                switch (opcao) {
                case 1:

                        raiz = NULL;
                        printf("\nDigite as chaves a serem inseridas, separadas por hifen (sem espaço).\n");
                        printf("Exemplo: 1-3-5-2-7-9-21-6\n");
                        scanf("%s", l);
                        //quebra a string de entrada
                        ptr = strtok(l, delimitador);
                        while(ptr != NULL) {
                            valor = atoi(ptr);
                            raiz = inserirNo(raiz, valor);
                            ptr = strtok(NULL, delimitador); //breaks string str into a series of tokens using the delimiter delim.
                        }
                        break;
                case 2:
                        printf("Informe a chave a ser removida: ");
                        scanf("%d", &chave); //eatline();
                        raiz = excluirNo(raiz, chave);
                        break;
                case 3:
                        printf("Informe a chave a ser procurada: ");
                        scanf("%d", &chave); //eatline();
                        busca(raiz, chave);
                        break;
                case 4:
//                        printf("Impressao da Arvore-B de ordem %d:\n", M);
                        printf("Printing the B-Tree of order %d:\n", M);
                        imprime_arvore(raiz, 0);
                        break;
                case 5:
                        free(raiz);
                        exit(1);
                default:
                        printf("Opcao invalida.\n");
                        break;
                }/*Fim switch*/
        }/*Fim while*/
        return 0;
}/*Fim main()*/

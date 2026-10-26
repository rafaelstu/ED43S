#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

int main(){
    NoArvAVL* avl;
    int res,i;
    //int N = 10, dados[10] = {50,25,10,5,7,3,30,20,8,15};
    //int N = 11, dados[11] = {50,25,10,5,5,7,3,30,20,8,15};
    int N = 10, dados[10] = {1,2,3,10,4,5,9,7,8,6};

    avl = cria_ArvAVL();
    printf("Inserindo dados: \n\n");
    for(i=0;i<N;i++){
        printf("\nInsere no %d: %d\n", i, dados[i]);
        res = insere_ArvAVL(avl,dados[i]);
    }
    printf("\n\n");

    printf("\nImpressao da arvore AVL - pre ordem:\n");
    preOrdem_ArvAVL(avl, -1);
    printf("\n\n");

    printf("\nRemocao do no com valor 6:\n");
    remove_ArvAVL(avl,6);

    printf("\nRemocao do no com valor 7:\n");
    remove_ArvAVL(avl,7);

    printf("\nImpressao da arvore AVL - em ordem:\n");
    emOrdem_ArvAVL(avl, -1);
    printf("\n\n");

    printf("\nImpressao da arvore AVL - pos ordem:\n");
    posOrdem_ArvAVL(avl, -1);
    printf("\n\n");


    libera_ArvAVL(avl);


    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreLLRB.h"

int main(){
    ArvLLRB * raiz = cria_ArvLLRB();

    int i, N = 7, val[7] ={20,15,30,85,50,21,70};
    printf("Inclusao dos valores 20,15,30,85,50,21,70. \n");
//    int i, N = 9, val[9] = {11,2,1,5,4,7,8,14,15};
//    printf("Inclusao dos valores 11,2,1,5,4,7,8,14,15. \n");
    //int i, N = 10, val[10] ={10,15,10,20,30,70,70,85,50,50};

    for(i=0; i< N; i++){
        if (insere_ArvLLRB(raiz,val[i]) == 0) {
            printf("Erro na insercao do valor: %d\n",val[i]);
        }
    }

    printf("\nTotal de nos da arvore: %d \n",totalNO_ArvLLRB(raiz));
    printf("Altura da arvore: %d \n",altura_ArvLLRB(raiz));
    printf("\nImpressao da arvore usando percurso em ordem:\n");
    emOrdem_ArvLLRB(raiz,0, -1);

    printf("\n\nRemocao da chave 50: \n\n");
    remove_ArvLLRB(raiz,50);
//    remove_ArvLLRB(raiz,20);
//    remove_ArvLLRB(raiz,30);

    printf("\nImpressao da arvore usando percurso em ordem:\n");
    emOrdem_ArvLLRB(raiz,0, -1);

    printf("\n\nRemocao da chave 1: \n\n");
    remove_ArvLLRB(raiz,1);

    printf("\nImpressao da arvore usando percurso em ordem:\n");
    emOrdem_ArvLLRB(raiz,0, -1);

    libera_ArvLLRB(raiz);

    return 0;
}

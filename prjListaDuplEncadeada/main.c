#include <stdio.h>
#include <stdlib.h>
#include "itemListaDuplEnc.h"

int main()
{
    ListaDupl *ld;
    int vazia, cheia, chave;

    printf("Criando lista duplamente encadeada vazia.\n");
    ld = criaListaDuplVazia();

    vazia = verificaListaDuplVazia(ld);
    printf("Lista vazia? %d\n", vazia);

    printf("\nAdicionando o 1o item. \n");
    chave = 1;
    inserirInicio(ld, chave);
    vazia = verificaListaDuplVazia(ld);
    printf("Lista vazia? %d\n", vazia);

    printf("\nAdicionando o 2o item. \n");
    chave = 2;
    inserirFinal(ld, chave);

    printf("\nAdicionando o 3o item. \n");
    chave = 3;
    inserirMeio(ld, 1, chave);

    printf("\nAdicionando o 4o item. \n");
    chave = 4;
    inserirFinal(ld, chave);

    printf("\nAdicionando o 5o item. \n");
    chave = 5;
    inserirInicio(ld, chave);

    printf("\nAdicionando o 6o item. \n");
    chave = 6;
    inserirInicio(ld, chave);

    printf("\nItens da lista (Esq para Dir):");
    imprimeEsqDir(ld);

    printf("\nRemovendo item com chave = 6.");
    removePorChave(ld, 6);

    printf("\nItens da lista (Esq para Dir):");
    imprimeEsqDir(ld);

    printf("\nRemovendo item com chave = 3.");
    removePorChave(ld, 3);

    printf("\nItens da lista (Dir para Esq):");
    imprimeDirEsq(ld);

    liberaListaDupl(ld);

    return 0;
}














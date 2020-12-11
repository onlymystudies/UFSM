// Problema 4
// Considere uma árvore binária de busca que armazena .valores inteiros. Nesta estrutura, pode ocorrer repetições
// de um mesmo valor. Assim, os valores associados aos nós da sub-árvore à esquerda são menores que o valor
// associado à raiz e os valores dos nós da sub-árvore à direita são maiores ou iguais. O tipo que representa
// um nó da arvore é dado por:
#include <stdio.h>
#include <stdlib.h>

struct arv{
    int info;
    struct arv *esq;
    struct arv *dir;
};
typedef struct arv Arv;

Arv *cria(int info, Arv *esq, Arv *dir) {
    Arv *novo = (Arv *) malloc(sizeof(Arv));
    novo->info = info;
    novo->esq = esq;
    novo->dir = dir;
    return novo;
}

void imprime(Arv *arv) {
    if (arv) {
        printf("%d ", arv->info);
        imprime(arv->esq);
        imprime(arv->dir);
    }
}

int busca(Arv *arv, int info) {
    if (!arv)
        return 0;
    else
        return arv->info == info || busca(arv->esq, info) || busca(arv->dir, info);
}

int ocorrenciasx (Arv* a, int x) {
    if (!a)
        return 0;
    else if (a->info == x)
        return ocorrenciasx(a->esq, x) + ocorrenciasx(a->dir, x) + 1;
    else
        return ocorrenciasx(a->esq, x) || ocorrenciasx(a->dir, x);
}

int imprime_folhas (Arv* a) {
    if (!a)
        return 0;
    else
        printf("%d ",a->info);
    return imprime_folhas(a->dir) || imprime_folhas(a->esq);
}

int main(void) {
    Arv *arv1 = cria(1, NULL, NULL);
    Arv *arv2 = cria(2, NULL, arv1);
    Arv *arv3 = cria(3, NULL, NULL);
    Arv *arv4 = cria(4, NULL, NULL);
    Arv *arv5 = cria(5, arv3, arv4);
    Arv *arv = cria(6, arv2, arv5);

    imprime(arv);
    puts("");

    int buscaArvore = 6;
    if (busca(arv, buscaArvore) > 0) // A
        printf("%d encontrado\n", buscaArvore);
    else
        printf("%d nao encontrado\n", buscaArvore);

    if (ocorrenciasx(arv, buscaArvore) > 0) // B
        printf("%d ocorrencias de %d\n", ocorrenciasx(arv, buscaArvore), buscaArvore);
    else
        printf("nenhuma ocorrencia de %d\n", buscaArvore);

    imprime_folhas(arv); // C

    puts("");
    system("pause");
    return 0;
}

/* Problema 9
 * Escreva uma função que, dada uma árvore, retorne a quantidade de nós que não são folhas, isto é, nós que
 * possuem pelo menos uma subárvore. Essa função deve ter o protótipo abaixo:
 * int intermediarios (ArvGen * a);
 */
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

int intermediarios (Arv * a) {
    if (!a)
        return 0;
    if (a->esq)
        return 1 + intermediarios(a->esq) + intermediarios(a->dir);
    if (a->dir)
        return 1 + intermediarios(a->dir) + intermediarios(a->esq);
    return 0;
}

int main(void) {
    Arv *arv1 = cria(1, NULL, NULL);
    Arv *arv2 = cria(2, NULL, arv1);
    Arv *arv3 = cria(3, NULL, NULL);
    Arv *arv4 = cria(4, NULL, NULL);
    Arv *arv5 = cria(5, arv3, arv4);
    Arv *arv = cria(6, arv2, arv5);
    printf("folhas: %d", intermediarios (arv));
    puts("");
    system("pause");
    return 0;
}

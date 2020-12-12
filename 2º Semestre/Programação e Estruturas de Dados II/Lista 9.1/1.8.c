/* Problema 8
 * Implemente uma função que retorne a quantidade de folhas de uma árvore com número variável de filhos.
 * Essa função deve obedecer ao protótipo:
 * int folhas (ArvGen* a);
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

int folhas (Arv* a) {
    if (!a)
        return 0;
    else
        return 1 + folhas(a->esq) + folhas(a->dir);
}

int main(void) {
    Arv *arv1 = cria(1, NULL, NULL);
    Arv *arv2 = cria(2, NULL, arv1);
    Arv *arv3 = cria(3, NULL, NULL);
    Arv *arv4 = cria(4, NULL, NULL);
    Arv *arv5 = cria(5, arv3, arv4);
    Arv *arv = cria(6, arv2, arv5);
    printf("folhas: %d", folhas (arv));
    puts("");
    system("pause");
    return 0;
}

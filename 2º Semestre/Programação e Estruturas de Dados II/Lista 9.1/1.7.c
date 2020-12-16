/* Problema 7
 * Escreva uma função com o protótipo
 * int igual(ArvGen*a, ArvGen*b);
 * para testar se duas árvores são iguais.
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

int igual (Arv* a, Arv* b) {
    if (!a && !b || a->info != b->info)
        return 0;
    else
        return a->info == b->info + igual(a->esq, b->esq) + igual(a->dir, b->dir);
}

int main(void) {
    Arv *arv1 = cria(1, NULL, NULL);
    Arv *arv2 = cria(2, NULL, arv1);
    Arv *arv3 = cria(3, NULL, NULL);
    Arv *arv4 = cria(4, NULL, NULL);
    Arv *arv5 = cria(5, arv3, arv4);
    Arv *arv = cria(6, arv2, arv5);

    Arv *b1 = cria(1, NULL, NULL);
    Arv *b2 = cria(2, NULL, b1);
    Arv *b3 = cria(3, NULL, NULL);
    Arv *b4 = cria(4, NULL, NULL);
    Arv *b5 = cria(5, b3, b4);
    Arv *b = cria(6, b2, b5);

    if (igual(arv, b) > 0)
        printf("igual\n");
    else
        printf("nao igual\n");

    puts("");
    system("pause");
    return 0;
}

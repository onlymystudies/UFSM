/* Problema 6
 * Escreva uma função com o protótipo
 * ArvGen* copia(ArvGen*a);
 * para criar dinamicamente uma cópia da árvore.
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

Arv* copia(Arv *arv) {
    Arv *arvCopia = (Arv *) malloc(sizeof(Arv));
    if (arv) {
        arvCopia = cria(arv->info, arv->esq, arv->dir);
        copia(arv->esq);
        copia(arv->dir);
    }
    return arvCopia;
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

    Arv *arvCopia = copia(arv);
    imprime(arvCopia);

    puts("");
    system("pause");
    return 0;
}

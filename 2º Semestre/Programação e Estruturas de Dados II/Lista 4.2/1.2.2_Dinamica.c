#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int valor;
    struct lista *proximo;
}Lista;

Lista *cria(void) {
    return NULL;
}

Lista *insere(Lista *lista, int valor) {
    Lista *novo = (Lista *) malloc(sizeof(Lista));
    novo->valor = valor;
    novo->proximo = lista;
    return novo;
}

void imprime(Lista *lista) {
    Lista *p;
    for (p = lista; p != NULL; p = p->proximo) {
        printf("valor %d\n", p->valor);
    }
}

Lista *intercalar(Lista *lista1, Lista *lista2) {
    Lista *lista3 = cria();

    for (int i = 0; ; ++i) {
        if (lista1 != NULL) {
            if (i % 2 == 0) {
                lista3 = insere(lista3, lista1->valor);
                lista1 = lista1->proximo;
            } else if (lista2 != NULL) {
                lista3 = insere(lista3, lista2->valor);
                lista2 = lista2->proximo;
            }
        } else if (lista2 != NULL) {
            lista3 = insere(lista3, lista2->valor);
            lista2 = lista2->proximo;
        }
        if (lista1 == NULL && lista2 == NULL)
            break;
    }

    return lista3;
}

int main(void) {
    Lista *bergamota = cria();
    bergamota = insere(bergamota, 1);
    bergamota = insere(bergamota, 2);
    bergamota = insere(bergamota, 3);
    bergamota = insere(bergamota, 10);
    bergamota = insere(bergamota, 11);
    bergamota = insere(bergamota, 11);

    Lista *kiwi = cria();
    kiwi = insere(kiwi, 4);
    kiwi = insere(kiwi, 5);
    kiwi = insere(kiwi, 6);

    Lista *limao = intercalar(bergamota, kiwi);
    imprime(limao);
    system("pause");
}
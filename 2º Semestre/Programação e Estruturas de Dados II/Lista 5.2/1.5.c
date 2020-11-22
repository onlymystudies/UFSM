#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    struct lista *anterior;
    int valor;
    struct lista *proximo;
}Lista;

Lista *cria(void) {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    lista->proximo = NULL;
    lista->anterior = NULL;
    return lista;
}

void insere(Lista *lista, int valor) {
    Lista *novo = (Lista *) malloc(sizeof(Lista));
    novo->valor = valor;
    novo->proximo = lista->proximo;
    novo->anterior = NULL;
    if (lista != NULL)
        lista->anterior = novo;
    lista->proximo = novo;
}

void imprime(Lista *lista) {
    Lista *p;
    for (p = lista->proximo; p != NULL; p = p->proximo)
        printf("valor %d\n", p->valor);
}

Lista *unir(Lista *listaA, Lista *listaB) {
    Lista *listaC = cria();
    listaA = listaA->proximo;
    listaB = listaB->proximo;
    while (listaB != NULL) {
        insere(listaC, listaB->valor);
        listaB = listaB->proximo;
    }
    while (listaA != NULL) {
        insere(listaC, listaA->valor);
        listaA = listaA->proximo;
    }
    return listaC;
}

Lista *intersecao(Lista *listaA, Lista *listaB) {
    Lista *listaC = cria();
    listaA = listaA->proximo;
    listaB = listaB->proximo;
    for (int i = 0; ; ++i) {
        if (listaA == NULL && listaB == NULL)
            break;
        if (i % 2 == 0) {
            if (listaA != NULL) {
                insere(listaC, listaA->valor);
                listaA = listaA->proximo;
            } else {
                insere(listaC, listaB->valor);
                listaB = listaB->proximo;
            }
        }
        if (i % 2 == 1) {
            if (listaB != NULL) {
                insere(listaC, listaB->valor);
                listaB = listaB->proximo;
            } else {
                insere(listaC, listaA->valor);
                listaA = listaA->proximo;
            }
        }
    }
    return listaC;
}

Lista *diferenca(Lista *listaA, Lista *listaB) {
    Lista *listaC = cria();
    listaA = listaA->proximo;
    listaB = listaB->proximo;
    Lista *C = listaC->proximo;
    int igual = 0;

    while (listaB != NULL) {
        while (C != NULL) {
            if (listaB->valor == C->valor) {
                igual++;
                break;
            }
            C = C->proximo;
        }
        if (igual == 0)
            insere(listaC, listaB->valor);
        listaB = listaB->proximo;
        C = listaC;
        igual = 0;
    }

    while (listaA != NULL) {
        while (C != NULL) {
            if (listaA->valor == C->valor) {
                igual++;
                break;
            }
            C = C->proximo;
        }
        if (igual == 0)
            insere(listaC, listaA->valor);
        listaA = listaA->proximo;
        C = listaC;
        igual = 0;
    }

    return listaC;
}

Lista *soma(Lista *listaA, Lista *listaB) {
    listaA = listaA->proximo;
    listaB = listaB->proximo;
    Lista *listaC = cria();
    while (listaA != NULL && listaB != NULL) {
        if (listaA != NULL) {
            if (listaB != NULL) {
                insere(listaC, listaA->valor + listaB->valor);
                listaB = listaB->proximo;
                listaA = listaA->proximo;
            }
            else {
                insere(listaC, listaA->valor);
                listaA = listaA->proximo;
            }
        }
        else {
            insere(listaC, listaB->valor);
            listaB = listaB->proximo;
        }
    }
    return listaC;
}

int main(void) {
    Lista *lista = cria();
    insere(lista, 1);
    insere(lista, 2);
    insere(lista, 3);
    insere(lista, 4);
    insere(lista, 5);

    Lista *listaB = cria();
    insere(listaB, 6);
    insere(listaB, 7);
    insere(listaB, 8);
    insere(listaB, 9);
    insere(listaB, 10);

    Lista *listaUnida = unir(lista, listaB);

    Lista *listaInterseccionada = intersecao(lista, listaB);

    Lista *listaDiferente = diferenca(lista, listaB);

    Lista *listaSoma = soma(lista, listaB);

    imprime(listaSoma);
    system("pause");
}
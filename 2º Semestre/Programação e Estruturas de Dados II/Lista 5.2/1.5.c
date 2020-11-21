#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    struct lista *proximo;
    int valor;
    struct lista *anterior;
}Lista;

Lista *cria(void) {
    return NULL;
}

Lista *insere(Lista *lista, int valor) {
    Lista *novo = (Lista *) malloc(sizeof(Lista));
    novo->valor = valor;
    novo->proximo = lista;
    novo->anterior = NULL;
    if (lista != NULL)
        lista->anterior = novo;
    return novo;
}

void imprime(Lista *lista) {
    while (lista != NULL) {
        printf("valor: %d\n", lista->valor);
        lista = lista->proximo;
    }
}

Lista *unir(Lista *listaA, Lista *listaB) {
    Lista *listaC = cria();
    while (listaA != NULL) {
        listaC = insere(listaC, listaA->valor);
        listaA = listaA->proximo;
    }
    while (listaB != NULL) {
        listaC = insere(listaC, listaB->valor);
        listaB = listaB->proximo;
    }
    return listaC;
}

Lista *intersecao(Lista *listaA, Lista *listaB) {
    Lista *listaC = cria();
    for (int i = 0; ; ++i) {
        if (listaA == NULL && listaB == NULL)
            break;
        if (i % 2 == 0) {
            if (listaA != NULL) {
                listaC = insere(listaC, listaA->valor);
                listaA = listaA->proximo;
            } else {
                listaC = insere(listaC, listaB->valor);
                listaB = listaB->proximo;
            }
        }
        if (i % 2 == 1) {
            if (listaB != NULL) {
                listaC = insere(listaC, listaB->valor);
                listaB = listaB->proximo;
            } else {
                listaC = insere(listaC, listaA->valor);
                listaA = listaA->proximo;
            }
        }
    }
    return listaC;
}

Lista *diferenca(Lista *listaA, Lista *listaB) {
    Lista *listaC = cria();
    Lista *C = listaC;
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
            listaC = insere(listaC, listaB->valor);
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
            listaC = insere(listaC, listaA->valor);
        listaA = listaA->proximo;
        C = listaC;
        igual = 0;
    }

    return listaC;
}

Lista *soma(Lista *listaA, Lista *listaB) {
    Lista *listaC = cria();
    while (listaA != NULL && listaB != NULL) {
        if (listaA != NULL) {
            if (listaB != NULL) {
                listaC = insere(listaC, listaA->valor + listaB->valor);
                listaB = listaB->proximo;
                listaA = listaA->proximo;
            }
            else {
                listaC = insere(listaC, listaA->valor);
                listaA = listaA->proximo;
            }
        }
        else {
            listaC = insere(listaC, listaB->valor);
            listaB = listaB->proximo;
        }
    }
    return listaC;
}

int main(void) {
    Lista *lista = cria();
    lista = insere(lista, 1);
    lista = insere(lista, 2);
    lista = insere(lista, 3);
    lista = insere(lista, 4);
    lista = insere(lista, 5);

    Lista *listaB = cria();
    listaB = insere(listaB, 5);
    listaB = insere(listaB, 6);
    listaB = insere(listaB, 7);
    listaB = insere(listaB, 8);
    listaB = insere(listaB, 9);

    Lista *listaUnida = unir(lista, listaB);
    Lista *listaIntersecao = intersecao(lista, listaB);
    Lista *listaDiferente = diferenca(lista, listaB);
    Lista *listaSoma = soma(lista, listaB);
    imprime(listaSoma);
    system("pause");
}
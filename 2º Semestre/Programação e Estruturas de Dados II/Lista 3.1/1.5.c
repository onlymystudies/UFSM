#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    struct lista *anterior;
    int valor;
    struct lista *proximo;
}Lista;

Lista *insere(Lista *lista, int valor) {
    Lista *novo = (Lista *) malloc(sizeof(Lista));
    novo->valor = valor;
    novo->proximo = lista;
    novo->anterior = NULL;
    if (lista != NULL)
        lista->anterior = novo;
    return novo;
}

Lista *insere_ordenado(Lista *lista, int valor) {
    Lista *novo = (Lista *) malloc(sizeof(Lista));
    Lista *valor_anterior = NULL;
    Lista *p = lista;

    while (p != NULL && p->valor < valor) {
        valor_anterior = p;
        p = p->proximo;
    }

    if (valor_anterior == NULL) {
        novo->valor = valor;
        novo->proximo = lista;
    } else {
        novo->valor = valor;
        novo->anterior = valor_anterior;
        novo->proximo = valor_anterior->proximo;
        valor_anterior->proximo->anterior = novo;
        valor_anterior->proximo = novo;
    }
    return novo;
}

void imprime(Lista *lista) {
    Lista *p;
    for (p = lista; p != NULL; p = p->proximo)
        printf("%d\n", p->valor);
}

int main(void) {
    Lista *lista = NULL;
    lista = insere_ordenado(lista, 5);
    lista = insere_ordenado(lista, 4);
    lista = insere_ordenado(lista, 2);
    lista = insere_ordenado(lista, 1);
    lista = insere_ordenado(lista, 3);
    imprime(lista);
    system("pause");
}
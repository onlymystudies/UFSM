#include <stdlib.h>
#include <stdio.h>
#include "ListaCircularDuplamenteEncadeada.h"

Lista *cria_lista(int valor) {
    Lista *list = (Lista *) malloc(sizeof(Lista));
    list->valor = valor;
    list->proximo = list->anterior = list;
    return list;
}

void destroir_lista(Lista **list) {
    Lista *auxiliar = *list;
    if (auxiliar != NULL) {
        free(auxiliar);
        *list = NULL;
    }
}

Lista_c *cria_lista_c() {
    Lista_c *list_c = (Lista_c *) malloc(sizeof(Lista_c));
    list_c->inicio = list_c->fim = NULL;
    return list_c;
}

int lista_vazia(Lista_c *list_c) {
    return (list_c->inicio == NULL);
}

void insere_lista_inicio(Lista_c *list_c, int valor) {
    Lista *list = cria_lista(valor);
    if (lista_vazia(list_c)) {
        list_c->inicio = list;
        list_c->fim = list;
    } else {
        list->proximo = list_c->inicio;
        list_c->inicio->anterior = list;
        list_c->inicio = list;
        //
        list_c->inicio->anterior = list_c->fim;
        list_c->fim->proximo = list_c->inicio;

    }
}

void insere_lista_fim(Lista_c *list_c, int valor) {
    if (lista_vazia(list_c)) {
        insere_lista_inicio(list_c, valor);
    }
    else {
        Lista *list = cria_lista(valor);
        list_c->fim->proximo = list;
        list->anterior = list_c->fim;
        list_c->fim = list;
        //
        list_c->inicio->anterior = list_c->fim;
        list_c->fim->proximo = list_c->inicio;
    }
}

void imprime_lista(Lista_c *list_c) {
    if (lista_vazia(list_c)) {
        printf("Lista: NULL");
    } else {
        Lista *list = list_c->inicio;
        printf("Lista:\n");
        do {
            printf("%d;\n", list->valor);
            list = list->proximo;
        } while (list != list_c->inicio);
        printf("Fim.\n");
    }
}

void remove_lista(Lista_c *list_c, int valor) {
    if (!lista_vazia(list_c)) {
        Lista *list = list_c->inicio;
        if (list_c->inicio->valor == valor) {
            if (list_c->inicio == list_c->fim) {
                list_c->inicio = list_c->fim = NULL;
            } else {
                list_c->inicio = list->proximo;
                //
                list_c->inicio->anterior = list_c->fim;
                list_c->fim->proximo = list_c->inicio;
            }
            free(list);
        } else {
            list = list->proximo;
            while (list != list_c->inicio) {
                if (list->valor == valor) {
                    list->proximo = list->proximo;
                    list->proximo->anterior = list->anterior;
                    if (list_c->fim == list) {
                        list_c->fim = list->anterior;
                    }
                    free(list);
                    break;
                } else {
                    list = list->proximo;
                }
            }
        }
    }
}
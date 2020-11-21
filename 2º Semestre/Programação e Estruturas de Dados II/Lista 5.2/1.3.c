/* Problema 3
 * Considere uma coleção de nomes de sites da web e seus respectivos links na Internet armazenados através de
 * uma lista simplesmente encadeada. Escreva a respectiva estrutura e um método que, dado o nome de um site,
 * busque o seu link correspondente na lista e ao mesmo tempo mova o nó que contém o nome buscado para o
 * início da lista, de forma que ele possa ser encontrado mais rapidamente na próxima vez que for buscado.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
    char nome[64];
    char link[128];
    struct lista *proximo;
}Lista;

Lista *cria(void) {
    return NULL;
}

Lista *insere(Lista *lista, char *nome, char *link) {
    Lista *novo = (Lista *) malloc(sizeof(Lista));
    strcpy(novo->nome, nome);
    strcpy(novo->link, link);
    novo->proximo = lista;
    return novo;
}

void imprime(Lista *lista) {
    printf("Lista:\n");
    while (lista != NULL) {
        printf("Site: %s\n", lista->nome);
        printf("Link: %s\n", lista->link);
        lista = lista->proximo;
    }
    printf("Fim!\n");
}

Lista *busca(Lista *lista, char *nome) {
    Lista *p = lista;
    Lista *ant;
    while (strcmp(p->nome, nome) != 0) {
        ant = p;
        p = p->proximo;
    }
    printf("Site: %s\n", p->nome);
    printf("Link: %s\n", p->link);
    if (p->proximo == NULL) {
        p->proximo = lista;
        ant->proximo = NULL;
    }
    else if (p != lista) {
        puts("b");
        lista->proximo = p->proximo;
        p->proximo = lista;
    }

    return p;
}

int main(void) {
    Lista *lista = cria();
    lista = insere(lista, "Google", "www.google.com");
    lista = insere(lista, "wikipedia", "www.wikipedia.com");
    lista = insere(lista, "Yahoo", "www.Yahoo.com");
    lista = busca(lista, "wikipedia");
    imprime(lista);
    system("pause");
}
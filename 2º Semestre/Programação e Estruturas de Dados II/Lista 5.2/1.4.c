#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    struct no *proximo;
    int chave;
    char nome[64];
    struct no *anterior;
}No;

typedef struct lista {
    No *inicio;
    No *fim;
}Lista;

Lista *criaLista() {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    lista->inicio = lista->fim = NULL;
    return lista;
}

No *criaNo(int chave, char *nome) {
    No *novo = (No *) malloc(sizeof(No));
    novo->chave = chave;
    strcpy(novo->nome, nome);
    novo->proximo = novo->anterior = novo;
    return novo;
}

int listaVazia(Lista *lista) {
    return (lista->inicio == NULL);
}

void insereInicio(Lista *lista, int chave, char *nome) {
    No *novo = criaNo(chave, nome);
    if (listaVazia(lista)) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        novo->proximo = lista->inicio;
        lista->inicio->anterior = novo;
        lista->inicio = novo;
        lista->inicio->anterior = lista->fim;
        lista->fim->proximo = lista->inicio;
    }
}

void insereFinal(Lista *lista, int chave, char *nome) {
    if (listaVazia(lista)) {
        insereInicio(lista, chave, nome);
    }
    else {
        No *no = criaNo(chave, nome);
        lista->fim->proximo = no;
        no->anterior = lista->fim;
        lista->fim = no;
        lista->inicio->anterior = lista->fim;
        lista->fim->proximo = lista->inicio;
    }
}

void imprimeLista(Lista *lista) {
    No *no = lista->inicio;
    printf("Lista:\n");
    while (1) {
        printf("Nome %s\n", no->nome);
        printf("Chave %d\n", no->chave);
        if (no == lista->inicio->anterior)
            break;
        no = no->proximo;
    }
    printf("Fim.\n");
}

void buscarValor(Lista *lista, int chave) {
    No *no;
    for (no = lista->inicio;  ; no = no->proximo) {
        if (no->chave == chave) {
            printf("Nome %s\n", no->nome);
            printf("Chave %d\n", no->chave);
            break;
        }
    }
}

void insereOrdenado(Lista *lista, int chave, char *nome) {
    No *no = criaNo(chave, nome);
    No *ant = NULL;
    No *p = lista->inicio;

    while (p->chave > chave) {
        ant = p;
        p = p->proximo;
        if (p == lista->inicio)
            break;
    }

    if (ant == NULL) {
        no->proximo = lista->inicio;
        no->anterior = lista->fim;
        if (lista->inicio != lista->fim)
            lista->inicio->anterior = no;
        lista->inicio = no;
    } else {
        no->proximo = ant->proximo;
        no->anterior = ant;
        if (no->proximo != lista->fim)
            ant->proximo->anterior = no;
        ant->proximo = no;
    }
}

int main(void) {
    char nome1[] = "leonardo1";
    char nome2[] = "leonardo2";
    char nome3[] = "leonardo3";
    char nome4[] = "leonardo4";
    char nome5[] = "prfdacerto";
    Lista *lista = criaLista();
    insereInicio(lista, 2, nome1);
    insereInicio(lista, 3, nome2);
    insereInicio(lista, 4, nome3);
    insereInicio(lista, 5, nome4);
    //buscarValor(lista, 1233);
    insereOrdenado(lista, 6, nome5);
    imprimeLista(lista);
    system("pause");
}
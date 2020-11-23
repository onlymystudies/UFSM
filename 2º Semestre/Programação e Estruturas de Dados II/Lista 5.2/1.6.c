#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listaDupla{
    struct listaDupla *anterior;
    char cidade[64];
    struct listaDupla *proximo;
}ListaDupla;

typedef struct lista{
    char rodovia[6];
    ListaDupla *infos;
    struct lista *proximo;
}Lista;

ListaDupla *criaLista(void) {
    ListaDupla *lista = (ListaDupla *) malloc(sizeof(ListaDupla));
    lista->proximo = NULL;
    lista->anterior = NULL;
    return lista;
}

Lista *cria(void) {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    lista->proximo = NULL;
    return lista;
}

void insereLista(Lista *lista, char *rodovia) {
    Lista *novo = (Lista *) malloc(sizeof(Lista));
    strcpy(novo->rodovia, rodovia);
    novo->infos = criaLista();
    novo->proximo = lista->proximo;
    lista->proximo = novo;
}

void insere(Lista *lista, char *cidade) {
    ListaDupla *novo = (ListaDupla *) malloc(sizeof(ListaDupla));
    strcpy(novo->cidade, cidade);
    novo->proximo = lista->proximo->infos->proximo;
    novo->anterior = NULL;
    if (lista->proximo->infos != NULL)
        lista->proximo->infos->anterior = novo;
    lista->proximo->infos->proximo = novo;
}

void imprime(Lista *lista) {
    Lista *p;
    ListaDupla *pl;
    for (p = lista->proximo; p != NULL; p = p->proximo) {
        printf("Rodovia %s\n", p->rodovia);
        for (pl = p->infos->proximo; pl != NULL; pl = pl->proximo)
            printf("Cidade %s\n", pl->cidade);
    }
}

int main(void) {
    Lista *lista = cria();
    insereLista(lista, "BR123");
    insere(lista, "Vacaria");
    insere(lista, "Bom Jesus");

    insereLista(lista, "BR456");
    insere(lista, "Porto Alegre");
    insere(lista, "Sao paulo");

    insereLista(lista, "BR789");
    insere(lista, "Carazinho");
    insere(lista, "Frederico");
    imprime(lista);
    system("pause");
}
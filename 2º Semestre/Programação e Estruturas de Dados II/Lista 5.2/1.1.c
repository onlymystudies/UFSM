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
    if (lista != NULL)
        printf("valor %d\n", lista->valor);
    else
        return;
    return imprime(lista->proximo);
}

Lista *a(Lista* lista) {
    Lista *listaNova = cria();
    Lista *l1 = lista;
    Lista *p;
    while (l1->proximo != NULL)
        l1 = l1->proximo;
    listaNova = insere(listaNova, l1->valor);
    for (p = lista; p->proximo != NULL; p = p->proximo)
        listaNova = insere(listaNova, p->valor);
    return listaNova;
}

Lista *b(Lista *lista) {
    Lista *listaNova = cria();
    int ln = lista->valor;
    while (lista->proximo != NULL)
        lista = lista->proximo;
    for (int i = 0; ln >= lista->valor; ++i)
        listaNova = insere(listaNova, ln--);
    return listaNova;
}

Lista *c(Lista* lista) {
    Lista *listaNova = cria();
    Lista *p;
    int ln = lista->valor;
    for (p = lista; p->proximo != NULL; p = p->proximo, ln--)
        listaNova = insere(listaNova, p->valor + ln);
    if (ln % 2 == 0)
        listaNova = insere(listaNova, ln/2 + ln/2 + 1);
    else
        listaNova = insere(listaNova, p->valor + ln);
    return listaNova;
}

int main(void) {
    Lista *lista = cria();
    lista = insere(lista, 1); //l1
    lista = insere(lista, 2); //l2
    lista = insere(lista, 3); //l3
    lista = insere(lista, 4); //l4
    lista = insere(lista, 5); //ln
    //imprime(lista);
    Lista *A = cria();
    A = a(lista);
    //imprime(A);
    Lista *B = cria();
    B = b(lista);
    //imprime(B);
    Lista *C = cria();
    C = c(lista);
    imprime(C);
    system("pause");
}
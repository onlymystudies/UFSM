/* Problema 5
 * Dada uma lista encadeada de caracteres formada por uma sequência alternada de letras e dígitos, construa um
 * método que retorne uma lista na qual as letras são mantidas na sequência original e os dígitos são colocados
 * na ordem inversa.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int caracter;
    struct no *proximo;
}No;

typedef struct lista{
    struct no *inicio;
    struct no *final;
}Lista;

typedef struct noPilha{
    int caracter;
    struct noPilha *proximo;
}NoPilha;

typedef struct Pilha{
    struct noPilha *topo;
}Pilha;

bool ehDigito(int caracter) {
    for (size_t i = 0; i < 10; ++i) {
        if (caracter == i)
            return true;
    }
    return false;
}

Pilha *criaPilha(void) {
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void inserePilha(Pilha *pilha, int caracter) {
    NoPilha *novo = (NoPilha *) malloc(sizeof(NoPilha));
    novo->caracter = caracter;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

Lista *cria(void) {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

void insere(Lista *lista, int caracter) {
    No *novo = (No *) malloc(sizeof(No));
    novo->caracter = caracter;
    novo->proximo = NULL;
    if (!lista->inicio)
        lista->inicio = novo;
    else
        lista->final->proximo = novo;
    lista->final = novo;
}

void imprimeDigitos(Pilha *pilha) {
    NoPilha *percorre = pilha->topo;
    while (percorre) {
        printf("%d\n", percorre->caracter);
        percorre = percorre->proximo;
    }
}

void imprimeLetras(Lista *lista) {
    Pilha *pilha = criaPilha();
    No *percorre = lista->inicio;
    while (percorre) {
        if (!ehDigito(percorre->caracter))
            printf("%c\n", percorre->caracter);
        else
            inserePilha(pilha, percorre->caracter);
        percorre = percorre->proximo;
    }
    imprimeDigitos(pilha);
}

int main(void) {
    Lista *lista = cria();
    insere(lista, 'a');
    insere(lista, 'b');
    insere(lista, 1);
    insere(lista, 'c');
    insere(lista, 2);
    insere(lista, 3);
    insere(lista, 'd');
    insere(lista, 4);
    imprimeLetras(lista);
    system("pause");
}

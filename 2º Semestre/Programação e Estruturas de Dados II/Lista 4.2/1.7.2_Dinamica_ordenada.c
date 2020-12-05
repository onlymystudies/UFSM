#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fila{
    int valor;
    struct fila *proximo;
}Fila;

typedef struct pilhaNo{
    char *nome;
    struct fila *fila;
    struct pilhaNo *proximo;
}PilhaNo;

typedef struct pilha{
    struct pilhaNo *topo;
}Pilha;

Pilha *cria(void) {
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

Fila *criaFila(void) {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    fila->proximo = NULL;
    return fila;
}

Fila *inserePilha(Pilha *pilha, char *nome) {
    PilhaNo *novo = (PilhaNo *) malloc(sizeof(Pilha));
    novo->nome = (char *) malloc(sizeof(char));
    Fila *fila = criaFila();
    strcpy(novo->nome, nome);
    novo->fila = fila;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
    return fila;
}

void insere(Fila *fila, int valor) {
    Fila *novo = (Fila *) malloc(sizeof(Fila));
    novo->valor = valor;
    novo->proximo = fila->proximo;
    fila->proximo = novo;
}

void insereOrdenado(Fila *fila, int valor) {
    Fila *novo = (Fila *) malloc(sizeof(Fila));
    Fila *percorre = fila->proximo;
    Fila *anterior = NULL;
    novo->valor = valor;

    while(percorre && percorre->valor > valor) {
        anterior = percorre;
        percorre = percorre->proximo;
    }

    if (!anterior) {
        novo->proximo = percorre;
        fila->proximo = novo;
    }
    else {
        novo->proximo = percorre;
        anterior->proximo = novo;
    }

}

void imprime(Pilha *pilha) {
    PilhaNo *percorre = pilha->topo;
    while (percorre) {
        printf("Pilha %s\n", percorre->nome);
        Fila *percorreFila = percorre->fila->proximo;
        while (percorreFila) {
            printf("Valor %d\n", percorreFila->valor);
            percorreFila = percorreFila->proximo;
        }
        percorre = percorre->proximo;
    }
}

int main(void) {
    Pilha *pilha = cria();
    Fila *fila1 = inserePilha(pilha, "Primeira");
    insere(fila1, 2);
    insere(fila1, 3);
    insere(fila1, 4);
    insereOrdenado(fila1, 1);
    insereOrdenado(fila1, 5);

    Fila *fila2 = inserePilha(pilha, "Segunda");
    insere(fila2, 7);
    insere(fila2, 8);
    insere(fila2, 9);
    insereOrdenado(fila2, 10);
    insereOrdenado(fila2, 6);

    imprime(pilha);
    system("pause");
}

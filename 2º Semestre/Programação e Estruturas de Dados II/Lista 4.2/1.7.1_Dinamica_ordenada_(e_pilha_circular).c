#include <stdio.h>
#include <stdlib.h>

typedef struct pilhaNo{
    struct pilhaNo *anterior;
    float valor;
    struct pilhaNo *proximo;
}PilhaNo;

typedef struct pilha{
    PilhaNo *inicio;
    PilhaNo *topo;
}Pilha;

typedef struct filaNo{
    Pilha *elemento;
    struct filaNo *proximo;
}FilaNo;

typedef struct fila{
    FilaNo *inicio;
    FilaNo *final;
}Fila;

void insereFila(Fila *fila);

PilhaNo *criaPilhaNo(void) {
    PilhaNo *pilhaNo = (PilhaNo *) malloc(sizeof(PilhaNo));
    pilhaNo->proximo = pilhaNo->anterior = NULL;
    return pilhaNo;
}

Pilha *criaPilha(void) {
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    pilha->topo = pilha->inicio = NULL;
    return pilha;
}

FilaNo *criaFilaNo(void) {
    FilaNo *filaNo = (FilaNo *) malloc(sizeof(FilaNo));
    filaNo->proximo = NULL;
    filaNo->elemento = NULL;
    return filaNo;
}

Fila *criaFila(void) {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    fila->inicio = fila->final = NULL;
    return fila;
}

void insereFila(Fila *fila) {
    FilaNo *novo = criaFilaNo();
    if (!fila->inicio)
        fila->inicio = novo;
    else
        novo->proximo = fila->final;
    fila->final = novo;
}

Pilha *insereNovaPilha(Fila *fila) {
    Pilha *pilha = criaPilha();
    insereFila(fila);
    fila->final->elemento = pilha;
    return pilha;
}

void inserePilha(Pilha *pilha, float valor) {
    PilhaNo *novo = criaPilhaNo();
    novo->valor = valor;
    if (pilha->inicio == NULL) {
        pilha->topo = novo;
        pilha->inicio = novo;
        pilha->inicio->proximo = pilha->topo;
        pilha->inicio->anterior = pilha->topo;
    }
    else {
        novo->proximo = pilha->inicio;
        novo->anterior = pilha->topo;
        pilha->topo->proximo = novo;
        pilha->topo = novo;
    }
}

void imprime(Fila *fila) {
    while (fila->final != NULL) {
        while (1) {
            printf("valor %.2f\n", fila->final->elemento->inicio->valor);
            if (fila->final->elemento->inicio == fila->final->elemento->topo)
                break;
            fila->final->elemento->inicio = fila->final->elemento->inicio->proximo;
        }
        fila->final = fila->final->proximo;
    }
}

void insereOrdenado(Pilha *pilha, float valor) {
    PilhaNo *p = pilha->inicio;
    PilhaNo *anterior = NULL;
    PilhaNo *novo = criaPilhaNo();
    novo->valor = valor;

    while (p->valor < valor) {
        printf("anterior %2.f\n", p->valor);
        anterior = p;
        if (p == pilha->topo)
            break;
        p = p->proximo;
    }

    if (anterior == NULL) {
        novo->proximo = pilha->inicio;
        novo->anterior = pilha->topo;
        pilha->inicio->anterior = novo;
        pilha->inicio = novo;
    }
    else {
        novo->proximo = anterior->proximo;
        novo->anterior = anterior;
        if (anterior == pilha->topo)
            pilha->topo = novo;
        anterior->proximo->anterior = novo;
        anterior->proximo = novo;
    }
}

int main(void) {
    Fila *fila = criaFila();

    Pilha *pilha1 = insereNovaPilha(fila);
    inserePilha(pilha1, 1);
    inserePilha(pilha1, 2);
    inserePilha(pilha1, 4);
    inserePilha(pilha1, 5);
    inserePilha(pilha1, 6);
    insereOrdenado(pilha1, 3);

    Pilha *pilha2 = insereNovaPilha(fila);
    inserePilha(pilha2, 7);
    inserePilha(pilha2, 8);
    inserePilha(pilha2, 9);
    inserePilha(pilha2, 10);
    inserePilha(pilha2, 11);
    insereOrdenado(pilha2, 6);

    imprime(fila);
    system("pause");
}
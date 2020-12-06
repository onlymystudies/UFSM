#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct fila{
    struct no *inicio;
    struct no *final;
}Fila;

Fila *cria(void) {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    fila->inicio = fila->final = NULL;
    return fila;
}

void insere(Fila *fila, int valor) {
    No *novo = (No *) malloc(sizeof(No));
    novo->valor = valor;
    if (!fila->inicio)
        fila->inicio = novo;
    else
        fila->final->proximo = novo;
    novo->proximo = fila->inicio;
    fila->final = novo;
}

void imprime(Fila *fila) {
    for (No *percorre = fila->inicio; ; percorre = percorre->proximo) {
        printf("valor %d\n", percorre->valor);
        if (percorre == fila->final)
            return;
    }
}

void mata(Fila *fila, int primeiro) {
    No *percorre = fila->inicio;
    No *anterior = NULL;
    int contador = 1;

    while (contador) {
        if (primeiro > 1 && anterior == percorre || primeiro <= 1 && percorre == fila->final)
            break;
        if (contador++ % primeiro == 0) {
            printf("Morreu %d\n", percorre->valor);
            if (anterior)
                anterior->proximo = percorre->proximo;
        }
        anterior = percorre;
        percorre = percorre->proximo;
    }

    printf("Sobreviveu %d\n", percorre->valor);
}

int main(void) {
    Fila *fila = cria();

    insere(fila, 1);
    insere(fila, 2);
    insere(fila, 3);
    insere(fila, 4);
    insere(fila, 5);
    insere(fila, 6);
    insere(fila, 7);
    insere(fila, 8);
    insere(fila, 9);
    insere(fila, 10);

    mata(fila, 3);
    //imprime(fila);

    system("pause");
}
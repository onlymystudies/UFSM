#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct info {
    int valor;
}Info;

typedef struct fila {
    int inicio;
    Info infos[MAX];
    int final;
}Fila;

Fila* cria(void) {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->inicio = 1;
    fila->final = 0;
    return fila;
}

void insere(Fila* fila, int valor) {
    fila->final++;
    if (fila->final == MAX)
        fila->final = 1;
    fila->infos[fila->final].valor = valor;
}

void imprime(Fila* fila) {
    for (size_t i = fila->inicio; i <= fila->final; i++) {
        printf("Valor %d\n", fila->infos[i].valor);
    }
}

void FuraFila(Fila* fila, int valor) {
    fila->inicio--;
    fila->infos[fila->inicio].valor = valor;
}

int main(void) {
    Fila *abobora = NULL;
    abobora = cria();
    insere(abobora, 2);
    insere(abobora, 3);
    insere(abobora, 4);
    FuraFila(abobora, 1);
    imprime(abobora);
    system("pause");
}

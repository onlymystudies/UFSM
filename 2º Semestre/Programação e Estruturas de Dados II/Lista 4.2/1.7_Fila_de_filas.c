/*Problema 7
 * Como você implementaria uma fila de pilhas? Uma pilha de filas? Uma fila de filas? Escreva rotinas apra
 * implementar as operações corretas para cada uma destas estruturas de dados.
 */
// FILA DE FILAS
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct informacoes {
    int valor;
}Info;

typedef struct filas {
    int inicio;
    int final;
    Info infos[MAX];
}Filas;

typedef struct fila {
    int inicio;
    int final;
    Filas filas[MAX];
}Fila;

Fila *cria_fila() {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    if (fila != NULL) {
        fila->inicio = fila->final = 0;
    }
    return fila;
}

void cria_fila_fila(Fila *fila) {
    fila->filas[fila->inicio].inicio = 0;
    fila->filas[fila->final].final = 0;
}

void remove_fila(Fila *fila) {
    fila->inicio = (fila->inicio + 1) % MAX;
}

void insere_fila(Fila *fila) {
    fila->final = (fila->final + 1) % MAX;
    cria_fila_fila(fila);
}

void remove_fila_fila(Fila *fila) {
    fila->filas[fila->inicio].inicio = (fila->filas[fila->inicio].inicio + 1) % MAX;
}

void insere_fila_fila(Fila *fila, int valor) {
    fila->filas[fila->final].final = (fila->filas[fila->final].final + 1) % MAX;
    fila->filas[fila->final].infos[fila->filas[fila->final].final].valor = valor;
}

void imprime_fila_fila(Fila *fila) {
    for (size_t i = 1; i <= fila->filas[fila->final].final; ++i) {
        printf("%d\n", fila->filas[fila->final].infos[i].valor);
    }
}

int main(void) {
    Fila *fila;
    fila = cria_fila();
    insere_fila(fila);
    insere_fila_fila(fila, 1);
    insere_fila_fila(fila, 2);
    imprime_fila_fila(fila);

    printf("Fila 2, fila:\n");
    insere_fila(fila);
    insere_fila_fila(fila, 3);
    insere_fila_fila(fila, 4);
    imprime_fila_fila(fila);

    printf("Fila 3, fila:\n");
    insere_fila(fila);
    insere_fila_fila(fila, 5);
    insere_fila_fila(fila, 6);
    imprime_fila_fila(fila);

    system("pause");
}

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct fila {
    int inicio;
    int final;
    int valor[TAM];
}Fila;

Fila *criaFila(void) {
    Fila *fila = malloc(sizeof(Fila));
    fila->inicio = fila->final = 0;
    return fila;
}

void insereFila(Fila *fila, int valor) {
    fila->valor[fila->final] = valor;
    fila->final++;
}

void retiraFila(Fila *fila) {
    fila->valor[fila->inicio];
    fila->inicio++;
}

int vaziaFila(Fila *fila) {
    if (fila->final == 0)
        return 0;
    else
        return 1;
}

void imprimeFila(Fila *fila) {
    for (int i = fila->inicio; i < fila->final; ++i) {
        printf("valor %d\n", fila->valor[i]);
    }
}

typedef struct pilha {
    int topo;
    int valor[TAM];
}Pilha;

Pilha *criaPilha(void) {
    Pilha *pilha = malloc(sizeof(Pilha));
    pilha->topo = 0;
    return pilha;
}

void inserePilha(Pilha *pilha, int valor) {
    pilha->topo++;
    pilha->valor[pilha->topo] = valor;
}

void retiraPilha(Pilha *pilha) {
    pilha->topo--;
}

int vaziaPilha(Pilha *pilha) {
    if (pilha->topo == 0)
        return 0;
    else
        return 1;
}

void inverterFila(Fila *fila) {
    if (vaziaFila(fila) == 0) {
        printf("Fila vazia\n");
        return;
    }
    Pilha *pilha = criaPilha();
    for (int i = 0; i < fila->final; ++i) {
        inserePilha(pilha, fila->valor[i]);
        retiraFila(fila);
    }
    for (int i = pilha->topo; i > 0; --i) {
        insereFila(fila, pilha->valor[i]);
    }
}

int main(void) {
    Fila *fila = criaFila();
    insereFila(fila, 1);
    insereFila(fila, 2);
    insereFila(fila, 3);
    insereFila(fila, 4);
    insereFila(fila, 5);
    puts("Fila antes:");
    imprimeFila(fila);
    inverterFila(fila);
    puts("Fila depois:");
    imprimeFila(fila);
    system("pause");
}
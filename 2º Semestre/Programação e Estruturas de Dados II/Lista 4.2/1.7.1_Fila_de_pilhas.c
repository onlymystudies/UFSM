/*Problema 7
 * Como você implementaria uma fila de pilhas? Uma pilha de filas? Uma fila de filas? Escreva rotinas apra
 * implementar as operações corretas para cada uma destas estruturas de dados.
 */
// FILA DE PILHAS
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct informacoes {
    int valor;
}Info;

typedef struct pilha {
    Info infos[MAX];
    int topo;
}Pilha;

typedef struct fila {
    int inicio;
    int final;
    Pilha pilha[MAX];
}Fila;

void cria_pilha_fila(Fila *fila) {
    fila->pilha[fila->final].topo = -1;
}

Fila *cria_fila() {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    if (fila != NULL) {
        fila->inicio = 0;
        fila->final = 0;
        cria_pilha_fila(fila);
    }
    return fila;
}

void insere_nova_pilha(Fila *fila) {
    fila->final++;
    cria_pilha_fila(fila);
}

void insere_fila_pilha(Fila *fila, int valor) {
    fila->pilha[fila->final].topo++;
    fila->pilha[fila->final].infos[fila->pilha[fila->final].topo].valor = valor;
}

void imprimi_fila(Fila *fila) {
    for (int i = fila->pilha[fila->final].topo; i > -1; --i) {
        printf("Posicao %d\n", i + 1);
        printf("Valor: %d\n", fila->pilha[fila->final].infos[i].valor);
    }
}

void remove_fila(Fila *fila) {
    fila->inicio = (fila->inicio + 1) % MAX;
}

int main(void) {
    Fila *fila;
    fila = cria_fila();

    insere_fila_pilha(fila, 1);
    insere_fila_pilha(fila, 2);
    insere_fila_pilha(fila, 3);
    insere_fila_pilha(fila, 4);
    insere_fila_pilha(fila, 5);
    imprimi_fila(fila);

    printf("nova pilha e nova posicao fila\n");
    insere_nova_pilha(fila);
    insere_fila_pilha(fila, 6);
    insere_fila_pilha(fila, 7);
    insere_fila_pilha(fila, 8);
    insere_fila_pilha(fila, 9);
    insere_fila_pilha(fila, 10);
    imprimi_fila(fila);
    system("pause");
}
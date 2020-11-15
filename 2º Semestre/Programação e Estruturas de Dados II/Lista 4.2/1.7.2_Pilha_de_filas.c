/* Problema 7
 * Como você implementaria uma fila de pilhas? Uma pilha de filas? Uma fila de filas? Escreva rotinas apra
 * implementar as operações corretas para cada uma destas estruturas de dados.
 */
// PILHA DE FILAS
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

typedef struct pilha {
    int topo;
    Filas filas[MAX];
}Pilha;

void cria_fila(Pilha *pilha) {
    pilha->filas[pilha->topo].final = 0;
    pilha->filas[pilha->topo].inicio = 0;
}

void cria_pilha(Pilha *pilha) {
    pilha->topo = 0;
    cria_fila(pilha);
}

void insere_pilha(Pilha *pilha) {
    pilha->topo++;
    cria_fila(pilha);
}

void insere_fila_pilha(Pilha *pilha, int valor) {
    pilha->filas[pilha->topo].final++;
    pilha->filas[pilha->topo].infos[pilha->filas[pilha->topo].final].valor = valor;
}

void remove_pilha(Pilha *pilha) {
    pilha->topo--;
}

void imprime_fila_pilha(Pilha *pilha) {
    for (int i = 1; i < pilha->filas[pilha->topo].final + 1; ++i) {
        printf("posicao pilha: %d posicao fila %d: valor :%d\n", pilha->topo, i, pilha->filas[pilha->topo].infos[i].valor);
    }
}

int main(void) {
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    cria_pilha(pilha);
    insere_fila_pilha(pilha, 1);
    insere_fila_pilha(pilha, 2);
    insere_fila_pilha(pilha, 3);
    insere_fila_pilha(pilha, 4);
    insere_fila_pilha(pilha, 5);
    imprime_fila_pilha(pilha);

    insere_pilha(pilha);
    insere_fila_pilha(pilha, 6);
    insere_fila_pilha(pilha, 7);
    insere_fila_pilha(pilha, 8);
    insere_fila_pilha(pilha, 9);
    insere_fila_pilha(pilha, 10);
    imprime_fila_pilha(pilha);

    system("pause");
}

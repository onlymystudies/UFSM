/* Problema 6
 * Implemente os métodos:
 * atribui: operação que atribui o elemento da linha i e da coluna j da matriz
 * libera: operação que libera a memória alocada para a matriz
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct matriz{
    int linhas;
    int colunas;
    float **valor;
}Matriz;

Matriz *cria(int linhas, int colunas) {
    Matriz *matriz = (Matriz *) malloc(sizeof(Matriz));
    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->valor = (float **) malloc(linhas * sizeof(float *));
    for (size_t i = 0; i < linhas; ++i)
        matriz->valor[i] = (float *) malloc(colunas * sizeof(float));
    return matriz;
}

void insere(Matriz *matriz, int linha, int coluna , float valor) {
    matriz->valor[linha][coluna] = valor;
}

void imprime(Matriz *matriz) {
    for (size_t linha = 0; linha < matriz->linhas; ++linha) {
        for (size_t coluna = 0; coluna < matriz->colunas; ++coluna)
            printf(" %.f", *(*(matriz->valor + linha) + coluna));
        printf("\n");
    }
}

void libera(Matriz *matriz) {
    for (size_t i = 0; i < matriz->linhas; ++i)
        free(matriz->valor[i]);
    free(matriz->valor);
    free(matriz);
}

int main(void) {
    Matriz *matriz = cria(5, 5);
    insere(matriz, 0, 0, 1);
    insere(matriz, 0, 1, 2);
    insere(matriz, 0, 2, 3);
    insere(matriz, 0, 3, 4);
    insere(matriz, 0, 4, 5);

    imprime(matriz);

    libera(matriz);

    system("pause");
}
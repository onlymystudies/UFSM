/* Problema 4
 * Escreva um código para representar uma matriz triangular inferior.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct matriz{
    int linhas;
    int colunas;
    float **valor;
}Matriz;

Matriz *cria(int linhas, int colunas) {
    register int triangular = colunas - 1;
    Matriz *matriz = (Matriz *) malloc(sizeof(Matriz));
    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->valor = (float **) malloc(linhas * sizeof(float *));
    for (register size_t i = 0; i < linhas; ++i) {
        matriz->valor[i] = (float *) malloc((colunas - triangular) * sizeof(float));
        triangular--;
    }
    return matriz;
}

void insere(Matriz *matriz, int linha, int coluna, float valor) {
    matriz->valor[linha][coluna] = valor;
}

void imprime(Matriz *matriz) {
    register int triangular = matriz->colunas - 1;
    for (register size_t linha = 0; linha < matriz->linhas; ++linha) {

        for (register size_t coluna = 0; coluna < matriz->linhas - triangular; ++coluna)
            printf(" %.f", matriz->valor[linha][coluna]);
        triangular--;
        printf("\n");
    }
}

void libera(Matriz *matriz) {
    for (register size_t i = 0; i < matriz->linhas; ++i)
        free(matriz->valor[i]);
    free(matriz->valor);
    free(matriz);
}

int main(void) {
    Matriz *matriz = cria(5, 5);
    insere(matriz, 0, 0, 1);

    insere(matriz, 1, 0, 1);
    insere(matriz, 1, 1, 1);

    insere(matriz, 2, 0, 1);
    insere(matriz, 2, 1, 1);
    insere(matriz, 2, 2, 1);

    insere(matriz, 3, 0, 1);
    insere(matriz, 3, 1, 1);
    insere(matriz, 3, 2, 1);
    insere(matriz, 3, 3, 1);

    insere(matriz, 4, 0, 1);
    insere(matriz, 4, 1, 1);
    insere(matriz, 4, 2, 1);
    insere(matriz, 4, 3, 1);
    insere(matriz, 4, 4, 1);

    imprime(matriz);
    libera(matriz);
    system("pause");
}
/* Problema 2
 * Implemente uma função que, dada uma matriz, crie dinamicamente a matriz transposta correspondente,
 * fazendo uso das operações básicas discutidas em aula.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct matriz{
    int linhas;
    int colunas;
    int **valor;
}Matriz;

Matriz *cria(int linhas, int colunas) {
    Matriz *matriz = (Matriz *) malloc(sizeof(Matriz));
    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->valor = (int **) malloc(linhas * sizeof(int *));
    for (size_t i = 0; i < linhas; ++i)
        matriz->valor[i] = (int *) malloc(colunas * sizeof(int));
    return matriz;
}

void insere(Matriz *matriz, int linha, int coluna, int valor) {
    matriz->valor[linha][coluna] = valor;
}

Matriz *transposta(Matriz *matriz) {
    int linhas = matriz->colunas;
    int colunas = matriz->linhas;
    Matriz *transposta = cria(linhas, colunas);
    for (size_t i = 0; i < colunas; ++i)
        for (size_t j = 0; j < linhas; ++j)
            insere(transposta, j, i, matriz->valor[i][j]);
    return transposta;
}

void imprime(Matriz *matriz) {
    for (int i = 0; i < matriz->linhas; ++i) {
        for (int j = 0; j < matriz->colunas; ++j)
            printf(" %d", matriz->valor[i][j]);
        printf("\n");
    }
}

int main(void) {
    Matriz *matriz = cria(3, 2);

    insere(matriz, 0, 0, 1);
    insere(matriz, 0, 1, 2);

    insere(matriz, 1, 0, 3);
    insere(matriz, 1, 1, 4);

    insere(matriz, 2, 0, 5);
    insere(matriz, 2, 1, 6);

    Matriz *matrizTransposta = transposta(matriz);

    imprime(matrizTransposta);
    imprime(matriz);
    system("pause");
}
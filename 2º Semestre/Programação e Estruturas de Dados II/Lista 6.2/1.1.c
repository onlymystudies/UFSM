/* Problema 1
 * Escreva um programa que faça uso das operações de matriz definidas em aula. Note que a estratégia de
 * implementação não deve alterar o uso das operações.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct matriz{
    int tamanho;
    int *valor;
}Matriz;

Matriz *cria(int tamanho) {
    Matriz *matriz = (Matriz *) malloc(sizeof(Matriz));
    matriz->tamanho = tamanho;
    matriz->valor = (int *) malloc((tamanho * (tamanho + 1) / 2) * sizeof(int));
    return matriz;
}

void insere(Matriz* matriz, int linha, int coluna, int valor) {
    int posicao;
    if (linha >= coluna)
        posicao = linha + coluna + linha;
    else
        posicao = linha + coluna;
    matriz->valor[posicao] = valor;
}

void imprime(Matriz *matriz) {
    for (size_t i = 0; i < matriz->tamanho * matriz->tamanho; ++i)
        printf(" %d", matriz->valor[i]);
}

int main(void) {
    Matriz *matriz = cria(2);
    insere(matriz, 0, 0, 1);
    insere(matriz, 0, 1, 2);

    insere(matriz, 1, 0, 3);
    insere(matriz, 1, 1, 4);
    imprime(matriz);
    system("pause");
}
/* Problema 7
 * Leia uma matriz 8x 8 e escreva o maior elemento da diagonal principal e a soma dos elementos da diagonal secundaria.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int maior_elemento_diagonal_p, deslocamento = 0, soma_diagonal_secundaria = 0;
    int **matriz = malloc(8 * sizeof(int *));
    for (int i = 0; i < 8; ++i)
        matriz[i] = malloc(8 * sizeof(int));


    for (int linha = 0; linha < 8; ++linha) {
        for (int coluna = 0; coluna < 8; ++coluna) {
            printf("Linha %d coluna %d\n", linha + 1, coluna + 1);
            scanf("%d", &matriz[linha][coluna]);
            system("cls");
        }
    }
    for (int linha = 0; linha < 8; ++linha) {
        for (int coluna = 0; coluna < 8; ++coluna) {
            if (linha == 0 && coluna == 0) maior_elemento_diagonal_p = matriz[linha][coluna];
            if (linha == coluna) if (matriz[linha][coluna] > maior_elemento_diagonal_p) maior_elemento_diagonal_p = matriz[linha][coluna];
        }
    }
    for (int linha = 0; linha < 8; ++linha) {
        for (int coluna = 0; coluna < 8; ++coluna) {
            if (coluna == 7 - deslocamento) soma_diagonal_secundaria += matriz[linha][coluna]; deslocamento++;
        }
    }

    printf("Maior elemento da diagonal principal: %d\n", maior_elemento_diagonal_p);
    printf("Soma dos elementos da diagonal secundaria: %d\n", soma_diagonal_secundaria);
    system("pause");
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int **matriz1 = malloc(2 * sizeof(int *));
    for (size_t i = 0; i < 2; i++)
        matriz1[i] = malloc(2 * sizeof(int));

    int **matriz2 = malloc(2 * sizeof(int *));
    for (size_t i = 0; i < 2; i++)
        matriz2[i] = malloc(2 * sizeof(int));


    printf("matriz 1\n");
    for (size_t linha = 0; linha < 2; linha++) {
        for (size_t coluna = 0; coluna < 2; coluna++) {
            printf("linha %d coluna %d\n", linha+1, coluna+1);
            scanf("%d", &matriz1[linha][coluna]);
        }
    }
    printf("matriz 2\n");
    for (size_t linha = 0; linha < 2; linha++) {
        for (size_t coluna = 0; coluna < 2; coluna++) {
            printf("linha %d coluna %d\n", linha+1, coluna+1);
            scanf("%d", &matriz2[linha][coluna]);
        }
    }
    printf("Valores da primeira que ocorrem em qualquer posicao da segunda\n");
    for (int linha = 0; linha < 2; ++linha) {
        for (int coluna = 0; coluna < 2; ++coluna) {
            for (int linha2 = 0; linha2 < 2; ++linha2) {
                for (int coluna2 = 0; coluna2 < 2; ++coluna2) {
                    if (matriz1[linha2][coluna2] == matriz2[linha][coluna]) {
                        printf("%d\n", matriz1[linha][coluna]);
                    }
                }
            }
        }
    }

    system("pause");
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int** matriz = malloc(5 * sizeof(int*));
    for (size_t i = 0; i < 5; i++) {
        matriz[i] = malloc(5 * sizeof(int));
    }

    for (size_t linha = 0; linha < 5; linha++) {
        for (size_t coluna = 0; coluna < 5; coluna++) {
            if (linha == coluna) {
                printf("linha %d, coluna %d\n", linha + 1, coluna + 1);
                scanf("%d", &matriz[linha][coluna]);
            } else {
                printf("linha %d, coluna %d\n", linha + 1, coluna + 1);
                scanf("%d", &matriz[coluna][linha]);
            }
        }
    }

    for (size_t linha = 0; linha < 5; linha++) {
        for (size_t coluna = 0; coluna < 5; coluna++) {
            printf("%d ", *(*(matriz + linha) + coluna));
        }
        printf("\n");
    }
    system("pause");
}
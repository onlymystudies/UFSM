#include <stdio.h>
#include <stdlib.h>

int main() {
    int diagonal_secundaria[6] = {5,4,3,2,1,0};
    int contador_colunas = 0, contador_linhas = 0;

    int** matriz = malloc(6 * sizeof(int*));
    for (size_t i = 0; i < 6; i++) {
        matriz[i] = malloc(6 * sizeof(int));
    }

    for (size_t linha = 0; linha < 6; linha++) {
        for (size_t coluna = 0; coluna < 6; coluna++) {
            printf("linha %d, coluna %d\n", linha + 1, coluna + 1);
            scanf("%d", &matriz[linha][coluna]);
            if (linha != coluna && coluna != diagonal_secundaria[contador_colunas + contador_linhas])
                if (matriz[linha][coluna] < 0)
                    matriz[linha][coluna] = 0;
        }
        contador_colunas = 0;
        contador_linhas++;
    }

    for (size_t linha = 0; linha < 6; linha++) {
        for (size_t coluna = 0; coluna < 6; coluna++) {
            printf("%d ", *(*(matriz + linha) + coluna));
        }
        printf("\n");
    }
    system("pause");
}
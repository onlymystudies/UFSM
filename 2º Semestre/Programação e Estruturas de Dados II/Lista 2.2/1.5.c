#include <stdio.h>
#include <stdlib.h>

int main() {
    int acima_diagonal[8] = {1,2,3,4,5,6,7,8};
    int contador_colunas = 0, contador_linhas = 0;

    int** matriz = malloc(8 * sizeof(int*));
    for (size_t i = 0; i < 8; i++) {
        matriz[i] = malloc(8 * sizeof(int));
    }

    for (size_t linha = 0; linha < 8; linha++) {
        for (size_t coluna = 0; coluna < 8; coluna++) {
            printf("linha %d, coluna %d\n", linha+1, coluna+1);
            scanf("%d", &matriz[linha][coluna]);
            if (coluna == acima_diagonal[contador_colunas + contador_linhas]) {
                if (acima_diagonal[contador_colunas + contador_linhas] == 8)
                    break;
                matriz[linha][coluna] = 0;
                contador_colunas++;
            }
        }
        contador_colunas = 0;
        contador_linhas++;
    }

    for (size_t linha = 0; linha < 8; linha++) {
        for (size_t coluna = 0; coluna < 8; coluna++) {
            printf("%d ", *(*(matriz + linha) + coluna));
        }
        printf("\n");
    }
    system("pause");
}

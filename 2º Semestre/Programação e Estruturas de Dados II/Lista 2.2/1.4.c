#include <stdio.h>
#include <stdlib.h>

int main() {
    int maior_valor, linha, coluna;

    int** matriz = malloc(3 * sizeof(int*));
    for (int i = 0; i < 3; ++i)
        matriz[i] = malloc(3 * sizeof(int));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("linha %d, coluna %d\n", i+1, j+1);
            scanf("%d", &matriz[i][j]);
            if (i == 0 && j == 0)
                maior_valor = matriz[i][j];
            if (matriz[i][j] > maior_valor) {
                maior_valor = matriz[i][j];
                linha = i;
                coluna = j;
            }
        }
    }

    printf("maior valor %d, linha %d, coluna %d\n", maior_valor, linha+1, coluna+1);
    system("pause");
}

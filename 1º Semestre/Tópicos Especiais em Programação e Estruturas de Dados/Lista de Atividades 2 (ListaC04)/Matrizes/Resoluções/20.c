#include <stdio.h>
#include <stdlib.h>

int main() {
    float soma = 0, media = 0;
    float **m;

    m = malloc(3 * sizeof(float *));

    for (int i = 0; i < 3; ++i) {
        m[i] = malloc(6 * sizeof(float));
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 6; ++j) {
            printf("Numero linha %d coluna %d:\n", i + 1, j + 1);
            scanf("%f", &m[i][j]);
        }
        system("cls");
    }

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 6; ++j) {
            if (i % 2 != 0) {
                soma += m[i][j]; // A
            }

            if (j == 2 || j == 4) {
                media += m[i][j]; // B
            }

            if (j == 6) {
                m[i][j] = m[i][1] + m[i][2]; // C
            }
        }

    system("cls");

    printf("Soma :%.2f\n", soma);

    printf("Media :%.2f\n", media/6);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 6; ++j) {
            printf("%.f  ", m[i][j]);
        }
        printf("\n");
    }

    system("pause");
}
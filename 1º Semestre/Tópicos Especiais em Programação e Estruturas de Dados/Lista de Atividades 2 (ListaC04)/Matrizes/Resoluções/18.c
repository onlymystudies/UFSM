#include <stdio.h>
#include <stdlib.h>

int main() {
    int w = 0;
    int **m;
    int vector[3] = {0,0,0};

    m = malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; ++i) {
        m[i] = malloc(3 * sizeof(int));
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("coluna %d:\n", i + 1);
            scanf("%d", &m[i][j]);
        }
        system("cls");
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            vector[i] += m[i][j];
        }
    }

    printf("vetor final:\n");
    while (w < 3) {
        printf("%d\n", vector[w]);
        w++;
    }

    system("pause");
}
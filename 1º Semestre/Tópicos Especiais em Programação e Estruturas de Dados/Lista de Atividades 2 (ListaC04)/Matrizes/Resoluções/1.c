#include <stdio.h>
#include <stdlib.h>

void one_bigger(int **matrix);
void main() {
    int **m; // pointer to pointer matrix

    m = malloc(4 * sizeof(int *));

    for(int i = 0; i < 4; i++) {
        m[i] = malloc(4 * sizeof(int));
    }

    for(int line = 0; line < 4; line++) {
        for(int column = 0; column < 4; column++) {
            printf("line %d column %d:\n", line + 1, column + 1);
            scanf("%d", &m[line][column]);
        }
    }

    one_bigger(m);
}
void one_bigger(int **matrix) {
    for (int i = 0; i < 4; i++) {
        for (int y = 0; y < 4; y++) {
            if (matrix[i][y] > 10) {
                printf("%d\n", matrix[i][y]);
            }
        }
    }

    free(matrix);
    system("pause");
}

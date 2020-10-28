#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void six_highest(int **matrix, int **matrix2);
void main() {
    int **m;
    m = malloc(4 * sizeof(int *));

    for(int i = 0; i < 4; i++) {
        m[i] = malloc(4 * sizeof(int));
    }

    for(int line = 0; line < 4; line++) {
        for(int column = 0; column < 4; column++) {
            printf("matrix 1 line %d column %d:\n", line + 1, column + 1);
            scanf("%d", &m[line][column]);
            BufferClear();
        }
    }

    int **m2;
    m2 = malloc(4 * sizeof(int *));

    for(int i = 0; i < 4; i++) {
        m2[i] = malloc(4 * sizeof(int));
    }

    for(int line = 0; line < 4; line++) {
        for(int column = 0; column < 4; column++) {
            printf("matrix 2 line %d column %d:\n", line + 1, column + 1);
            scanf("%d", &m2[line][column]);
            BufferClear();
        }
    }

    six_highest(m, m2);
}
void six_highest(int **matrix, int **matrix2) {
    int **high;
    high = malloc(4 * sizeof(int *));

    for(int i = 0; i < 4; i++) {
        high[i] = malloc(4 * sizeof(int));
    }

    for(int line = 0; line < 4; line++) {
        for(int column = 0; column < 4; column++) {
            if(matrix[line][column] > matrix2[line][column]) {
                high[line][column] = matrix[line][column];
            } else {
                high[line][column] = matrix2[line][column];
            }
        }
    }
    for(int line = 0; line < 4; line++) {
        for (int column = 0; column < 4; column++) {
            printf("%d ", *(*(high + line) + column)); // pointer
            //printf("%d ", high[line][column]); // subscribed
        }
        printf("\n");
    }

    free(high);
    free(matrix);
    free(matrix2);
    system("pause");
}

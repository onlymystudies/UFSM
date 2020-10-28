#include <stdio.h>
#include <stdlib.h>

void seven_print(int **matrix);
void main() {
    int **m;

    m = malloc(10 * sizeof(int *));

    for(int i = 0; i < 10; i++) {
        m[i] = malloc(10 * sizeof(int));
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(i < j) {
                m[i][j] = 2 * i + 7 * j - 2;
            }
            if(i == j) {
                m[i][j] = 3 * (i * i) - 1;
            }
            if(i > j) {
                m[i][j] = 4 * (i * i * i) - 5 * (j * j) + 1;
            }
        }
    }

    seven_print(m);
}
void seven_print(int **matrix) {
    for(int line = 0; line < 4; line++) {
        for (int column = 0; column < 4; column++) {
            printf("%d ", *(*(matrix + line) + column)); //pointer
            //printf("%d ", matrix[line][column]); // subscribed
        }
        printf("\n");
    }

    free(matrix);
    system("pause");
}

#include <stdio.h>
#include <stdlib.h>

void two_print(int **matrix);
void main() {
    int **m;

    m = malloc(5 * sizeof(int *));

    for(int i = 0; i < 5; i++) {
        m[i] = malloc(5 * sizeof(int));
    }

    for(int line = 0; line < 5; line++) {
        for(int column = 0; column < 5; column++) {
            if (line == column) {
                m[line][column] = 1;
            } else {
                m[line][column] = 0;
            }
        }
    }

    two_print(m);
}
void two_print(int **matrix) {
    for(int line = 0; line < 5; line++) {
        for (int column = 0; column < 5; column++) {
            printf("%d ", *(*(matrix + line) + column)); // pointer arithmetic
            //printf("%d ", matrix[line][column]); // // subscribed
        }
        printf("\n");
    }

    free(matrix);
    system("pause");
}

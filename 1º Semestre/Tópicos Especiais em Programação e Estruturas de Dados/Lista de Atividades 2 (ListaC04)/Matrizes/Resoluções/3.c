#include <stdio.h>
#include <stdlib.h>

void three_print(int **matrix);
void main() {
    int **m;
    m = malloc(4 * sizeof(int *));

    for(int i = 0; i < 4; i++) {
        m[i] = malloc(4 * sizeof(int));
    }

    for(int line = 0; line < 4; line++) {
        for(int column = 0; column < 4; column++) {
            m[line][column] = line + column;
        }
    }

    three_print(m);
}
void three_print(int **matrix) {
    for(int line = 0; line < 4; line++) {
        for (int column = 0; column < 4; column++) {
            printf("%d ", *(*(matrix + line) + column)); // pointer
            //printf("%d ", matrix[line][column]); // // subscribed

        }
        printf("\n");
    }

    free(matrix);
    system("pause");
}

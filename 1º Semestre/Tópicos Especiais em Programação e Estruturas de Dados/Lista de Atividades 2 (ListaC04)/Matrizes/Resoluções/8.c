#include <stdio.h>
#include <stdlib.h>

void eight_sum(int **matrix);
void main() {
    int **m;

    m = malloc(3 * sizeof(int *));

    for(int i = 0; i < 3; i++) {
        m[i] = malloc(3 * sizeof(int));
    }

    for(int line = 0; line < 3; line++) {
        for(int column = 0; column < 3; column++) {
            printf("line %d column %d:\n", line + 1, column + 1);
            scanf("%d", &m[line][column]);
        }
    }

    eight_sum(m);
}
void eight_sum(int **matrix) {
    int total = 0;

    for(int line = 0; line < 3; line++) {
        for(int column = 0; column < 3; column++) {
            if(line != column && line != 2 && matrix[line][column] != matrix[1][0]) {
                total += matrix[line][column];
            }
        }
    }

    for(int pline = 0; pline < 3; pline++) {
        for (int pcolumn = 0; pcolumn < 3; pcolumn++) {
            printf("%d ", matrix[pline][pcolumn]); // subscribed
            //printf("%d ", *(*(matrix + pline) + pcolumn)); // pointer
        }
        printf("\n");
    }

    printf("The sum of the values above the main diagonal is: %d\n", total);

    free(matrix);
    system("pause");
}

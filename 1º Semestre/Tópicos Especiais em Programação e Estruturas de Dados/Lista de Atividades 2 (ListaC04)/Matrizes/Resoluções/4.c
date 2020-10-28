#include <stdio.h>
#include <stdlib.h>

void four_printf(int **matrix);
void main() {
    int **m;
    int tline = 0;
    int tcolumn = 0;
    m = malloc(4 * sizeof(int *));

    for(int i = 0; i < 4; i++) {
        m[i] = malloc(4 * sizeof(int));
    }

    for(int line = 0; line < 4; line++) {
        for(int column = 0; column < 4; column++) {
            printf("line %d column %d value:\n", line + 1, column + 1);
            scanf("%d", &m[line][column]);
            if (line == 0 && column == 0) {
                tline = line;
                tcolumn = column;
            }
            if (m[line][column] > tline) {
                tline = line;
            }
            if (m[line][column] > tcolumn) {
                tcolumn = column;
            }
        }
    }

    printf("highest value position:\n");
    printf("line %d column %d\n\n", tline + 1, tcolumn + 1);

    four_printf(m);
}
void four_printf(int **matrix) {
    for(int line = 0; line < 4; line++) {
        for (int column = 0; column < 4; column++) {
            printf("%d ", *(*(matrix + line) + column)); // pointer
            //printf("%d ", matrix[line][column]); // subscribed
        }
        printf("\n");
    }

    free(matrix);
    system("pause");
}

#include <stdio.h>
#include <stdlib.h>

void thirteen_calc(int **matrix) {
    for (int pline = 0; pline < 4; pline++) {
        for (int pcolumn = 0; pcolumn < 4; pcolumn++) {
            //printf("%d ", matrix[pline][pcolumn]); // subscribed
            printf("%d ", *(*(matrix + pline) + pcolumn)); // pointer
        }
        printf("\n");
    }

    puts("\ntriangular:\n");

    for (int pline = 0; pline < 4; pline++) {
        for (int pcolumn = 0; pcolumn < 4; pcolumn++) {
            if (pline == 0 && pcolumn == 1) {
                matrix[pline][pcolumn] = 0;
            }
            if (pline == 0 && pcolumn == 2) {
                matrix[pline][pcolumn] = 0;
            }
            if (pline == 0 && pcolumn == 3) {
                matrix[pline][pcolumn] = 0;
            }
            if (pline == 1 && pcolumn == 2) {
                matrix[pline][pcolumn] = 0;
            }
            if (pline == 1 && pcolumn == 3) {
                matrix[pline][pcolumn] = 0;
            }
            if (pline == 2 && pcolumn == 3) {
                matrix[pline][pcolumn] = 0;
            }
        }
    }

    for (int pline = 0; pline < 4; pline++) {
        for (int pcolumn = 0; pcolumn < 4; pcolumn++) {
            //printf("%d ", matrix[pline][pcolumn]); // subscribed
            printf("%d ", *(*(matrix + pline) + pcolumn)); // pointer
        }
        printf("\n");
    }

    system("pause");
}

void main() {
    int **m;
    int number = 1;

    m = malloc(4 * sizeof(int *));

    for (int i = 0; i < 4; ++i) {
        m[i] = malloc(4 * sizeof(int));
    }

    for (int line = 0; line < 4; line++) {
        for (int column = 0; column < 4; column++) {
            m[line][column] = number;
            number++;
        }
        system("cls");
    }

    thirteen_calc(m);
}

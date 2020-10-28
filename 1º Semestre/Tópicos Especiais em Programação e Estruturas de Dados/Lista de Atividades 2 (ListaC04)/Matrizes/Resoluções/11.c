#include <stdio.h>
#include <stdlib.h>

void eleven_calc(int **matrix) {
    int total = 0;
    int column = 2;

    for (int line = 0; line < 3; line++) {
        total += matrix[line][column];
        column--;
    }

    for(int pline = 0; pline < 3; pline++) {
        for (int pcolumn = 0; pcolumn < 3; pcolumn++) {
            //printf("%d ", matrix[pline][pcolumn]); // subscribed
            printf("%d ", *(*(matrix + pline) + pcolumn)); // pointer
        }
        printf("\n");
    }

    printf("The total of the secondary diagonal line is: %d\n", total);
    system("pause");
}

void main() {
    int **m;

    m = malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; ++i) {
        m[i] = malloc(3 * sizeof(int));
    }

    for (int line = 0; line < 3; line++) {
        for (int column = 0; column < 3; column++) {
            printf("line %d column %d:\n", line + 1, column + 1);
            scanf("%d", &m[line][column]);
        }
        system("cls");
    }

    eleven_calc(m);
}

#include <stdio.h>
#include <stdlib.h>

void generate(int **matrix);
void print(int **matrix) {
    for (int pline = 0; pline < 5; pline++) {
        for (int pcolumn = 0; pcolumn < 5; pcolumn++) {
            //printf("%d ", matrix[pline][pcolumn]); // subscribed
            printf("%d ", *(*(matrix + pline) + pcolumn)); // pointer
        }
        printf("\n");
    }

    int new = 0;
    printf("[1] New generate\n");
    scanf("%d", &new);

    if (new != 0) {
        generate(matrix);
    }

    system("pause");
}
int number = 0;

void generate(int **matrix) {

    if (number == 100 || number > 100) {
        printf("Number exceeded\n");
        system("pause");
    }

    for (int line = 0; line < 5; line++) {
        for (int column = 0; column < 5; column++) {
            matrix[line][column] = number;
            number++;
        }
        system("cls");
    }

    print(matrix);
}

void main() {
    int **m;

    m = malloc(5 * sizeof(int *));

    for (int i = 0; i < 5; ++i) {
        m[i] = malloc(5 * sizeof(int));
    }

    generate(m);

    print(m);
}

#include <stdio.h>
#include <stdlib.h>

void five_print(int **matrix, int value);
void main() {
    int **m;
    int value;

    m = malloc(5 * sizeof(int *));

    for(int i = 0; i < 5; i++) {
        m[i] = malloc(5 * sizeof(int));
    }

    for(int line = 0; line < 5; line++) {
        for (int column = 0; column < 5; column++) {
            printf("line %d column %d value:\n", line + 1, column + 1);
            scanf("%d", &m[line][column]);
        }
    }

    printf("search value:\n");
    scanf("%d", &value);

    five_print(m, value);
}
void five_print(int **matrix, int value) {
    int pLine = 0, pColumn = 0;

    for(int sLine = 0; sLine < 5; sLine++) {
        for (int sColumn = 0; sColumn < 5; sColumn++) {
            if(matrix[sLine][sColumn] == value) {
                pLine++;
                pColumn++;
            }
        }
    }
    if(pLine == 0 && pColumn == 0){
        printf("value not found\n");
    } else {
        printf("the value is in the line %d column %d\n", pLine, pColumn);
    }

    free(matrix);
    system("pause");
}

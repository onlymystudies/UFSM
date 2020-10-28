#include <stdio.h>
#include <stdlib.h>

int main() {
    int **a;

    a = malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; ++i) {
        a[i] = malloc(3 * sizeof(int));
    }

    puts("Matriz A");
    for (int i = 0; i < 3; ++i) {
        printf("linha %d\n", i + 1);
        for (int j = 0; j < 3; ++j) {
            printf("coluna %d: \n", j + 1);
            scanf("%d", &a[i][j]);
        }
        system("cls");
    }

    system("cls");

    int **a2;

    a2 = malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; ++i) {
        a2[i] = malloc(3 * sizeof(int));
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            a2[i][j] = a[i][j] * a[i][j];
        }
    }

    system("cls");

    puts("Matriz A2");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d\t", a2[i][j]);
        }
        printf("\n");
    }

    system("pause");
}
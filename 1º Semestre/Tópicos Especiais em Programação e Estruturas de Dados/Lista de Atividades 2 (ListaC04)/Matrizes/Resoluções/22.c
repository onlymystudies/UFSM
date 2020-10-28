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

    int **b;

    b = malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; ++i) {
        b[i] = malloc(3 * sizeof(int));
    }

    puts("Matriz B");
    for (int i = 0; i < 3; ++i) {
        printf("linha %d\n", i + 1);
        for (int j = 0; j < 3; ++j) {
            printf("coluna %d: \n", j + 1);
            scanf("%d", &b[i][j]);
        }
        system("cls");
    }

    system("cls");

    int **c;

    c = malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; ++i) {
        c[i] = malloc(3 * sizeof(int));
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] * b[i][j];
        }
    }

    puts("Matriz C");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

    system("pause");
}
#include <stdio.h>
#include <stdlib.h>

int main() {

    int *v = malloc(10 * sizeof(int));
    int *v1 = malloc(10 * sizeof(int)); // impares
    int *v2 = malloc(10 * sizeof(int)); // pares

    int pares = 0, impares = 0;

    for (int j = 0; j < 10; ++j) {

        printf("Numero %d:\n", j + 1);
        scanf("%d", &v[j]);
    }

    system("cls");

    for (int i = 0; i < 10; i++) {

        if (v[i] % 2 == 0) {
            v2[i] = v[i];
            v1[i] = 0;

            ++pares;
        } else {
            v1[i] = v[i];
            v2[i] = 0;
            ++impares;
        }
    }

    puts("V1 IMPARES");
    for (int i = 0; i < 10; i++)
        if (v1[i] != 0)
            printf("%d\n", v1[i]);

    puts("V2 PARES");
    for (int i = 0; i < 10; i++)
        if (v2[i] != 0)
            printf("%d\n", v2[i]);

    system("pause");
}

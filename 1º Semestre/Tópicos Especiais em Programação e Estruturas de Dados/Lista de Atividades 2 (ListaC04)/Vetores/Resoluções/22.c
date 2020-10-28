#include <stdio.h>
#include <stdlib.h>

void twentytwo_vec(int *vector, int *vector2);
void main() {
    int i = 0;
    int *a = malloc(10 * sizeof(int));
    int *b = malloc(10 * sizeof(int));

    while (i < 10) {
        printf("vector 1, position %d value:\n", i + 1);
        scanf("%d", &a[i]);
        i++;
    }
    i = 0;
    while (i < 10) {
        printf("vector 2, position %d value:\n", i + 1);
        scanf("%d", &b[i]);
        i++;
    }

    twentytwo_vec(a, b);
}
void twentytwo_vec(int *vector, int *vector2) {
    int *v = malloc(10 * sizeof(int));
    int i = 0;

    while (i < 10) {
        if (i % 2 == 0) {
            v[i] = vector[i];
        } else {
            v[i] = vector2[i];
        }
        i++;
    }
    i = 0;
    while (i < 10) {
        printf("Value: %d\n", v[i]);
        //printf("Value: %d\n", *vector++);
        i++;
    }

    free(v);
    free(vector);
    free(vector2);
    system("pause");
}

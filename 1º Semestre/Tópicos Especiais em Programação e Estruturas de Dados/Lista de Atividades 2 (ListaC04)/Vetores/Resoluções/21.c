#include <stdio.h>
#include <stdlib.h>

void twentyone_sub(int *vector, int *vector2);
void main() {
    int i = 0;
    int *v = malloc(10 * sizeof(int));
    int *v2 = malloc(10 * sizeof(int));

    while (i < 10) {
        printf("vector 1, position %d value:\n", i + 1);
        scanf("%d", &v[i]);
        i++;
    }
    i = 0;
    while (i < 10) {
        printf("vector 2, position %d value:\n", i + 1);
        scanf("%d", &v2[i]);
        i++;
    }

    twentyone_sub(v, v2);
}
void twentyone_sub(int *vector, int *vector2) {
    int *c = malloc(10 * sizeof(int));
    int i = 0;

    while (i < 10) {
        c[i] = vector[i] - vector2[i];
        printf("value: %d\n", c[i]);
        //printf("value: %d\n", *c++)
        i++;
    }

    free(c);
    free(vector);
    free(vector2);
    system("pause");
}

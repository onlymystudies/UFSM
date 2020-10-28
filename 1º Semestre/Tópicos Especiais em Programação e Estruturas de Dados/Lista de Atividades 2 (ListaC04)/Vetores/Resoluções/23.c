#include <stdio.h>
#include <stdlib.h>

void twentythree_scalar(int *vector, int *vector2);
void main() {
    int i = 0;
    int *a = malloc(5 * sizeof(int));
    int *b = malloc(5 * sizeof(int));

    while (i < 5) {
        printf("vector 1, position %d value:\n", i + 1);
        scanf("%d", &a[i]);
        i++;
    }
    i = 0;
    while (i < 5) {
        printf("vector 2, position %d value:\n", i + 1);
        scanf("%d", &b[i]);
        i++;
    }

    twentythree_scalar(a, b);
}
void twentythree_scalar(int *vector, int *vector2) {
    int i = 0;
    int scalar = 0;

    while (i < 5) {
        scalar += vector[i] * vector2[i];
        i++;
    }

    i = 0;
    printf("vector 1:\n");
    while (i < 5) {
        printf("[");
        printf("%d", vector[i]);
        //printf("%d", *vector++);
        printf("]");
        i++;
    }
    i = 0;
    printf("\nvector 2:\n");
    while (i < 5) {
        printf("[");
        printf("%d", vector2[i]);
        //printf("%d", *vector2++);
        printf("]");
        i++;
    }

    printf("\nscalar product: %d\n", scalar);

    free(vector);
    free(vector2);
    system("pause");
}

#include <stdio.h>
#include <stdlib.h>

void six_bigger(int *vector);
void main() {
    int vector[10];
    int *v = vector;
    int i = 0;

    while(i < 10) {
        printf("%d value:\n", i+1);
        scanf("%d", &v[i]);
        i++;
    }

    six_bigger(v);
}
void six_lowest(int *vector) {
    int i = 0;
    int total = 0;

    while(i < 10) {
        if (i == 0) {
            total = vector[i];
        }
        if (vector[i] < total) {
            total = vector[i];
        }
        i++;
    }

    printf("Lowest number: %d\n", total);

    system("pause");
}
void six_bigger(int *vector) {
    int i = 0;
    int total = 0;

    while(i < 10) {
        if (i == 0) {
            total = vector[i];
        }
        if (vector[i] > total) {
            total = vector[i];
        }
        i++;
    }

    printf("Bigger number: %d\n", total);

    free(vector);
    six_lowest(vector);
}

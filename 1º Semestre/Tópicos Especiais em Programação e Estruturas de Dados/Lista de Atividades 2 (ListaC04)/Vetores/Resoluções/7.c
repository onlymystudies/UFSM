#include <stdio.h>
#include <stdlib.h>

void seven_bigger(int *vector);
void main() {
    int *v = (int *) malloc(10 * sizeof(int));
    int i = 0;

    while(i < 10) {
        printf("%d value:\n", i+1);
        scanf("%d", &v[i]);
        i++;
    }

    seven_bigger(v);
}
void seven_bigger(int *vector) {
    int i = 0;
    int total = 0;
    int position = 0;

    while(i < 10) {
        if (i == 0) {
            total = vector[i];
        }
        if (vector[i] > total) {
            total = vector[i];
            position = i;
        }
        i++;
    }

    printf("Vector:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", *vector++);
        //printf("%d", vector[i]);
    }
    printf("Biggest value %d in position %d\n", total, position + 1);

    free(vector);
    system("pause");
}

#include <stdio.h>
#include <stdlib.h>

void twelve_calc(int *vector);
void main() {
    int *v = malloc(5 * sizeof(int));
    int i = 0;

    while(i < 5) {
        printf("value %d:\n", i + 1);
        scanf("%d", &v[i]);
        i++;
    }

    twelve_calc(v);
}
void twelve_calc(int *vector) {
    int biggest = 0;
    int lowest = 0;
    int total = 0;
    int i = 0;

    while(i < 5) {
        if(i == 0) {
            biggest = vector[i];
            lowest = vector[i];
        }
        if(vector[i] > biggest) {
            biggest = vector[i];
        }
        if(vector[i] < lowest) {
            lowest = vector[i];
        }
        total += vector[i];
        i++;
    }

    printf("avg of values: %d\n", total / 5);
    printf("biggest number: %d\n", biggest);
    printf("lowest number: %d\n", lowest);

    free(vector);
    system("pause");
}

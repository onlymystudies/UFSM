#include <stdio.h>
#include <stdlib.h>

void thirteen_calc(int *vector);
void main() {
    int *v = malloc(5 * sizeof(int));
    int i = 0;

    while(i < 5) {
        printf("value %d:\n", i + 1);
        scanf("%d", &v[i]);
        i++;
    }

    thirteen_calc(v);
}
void thirteen_calc(int *vector) {
    int bposition = 0;
    int lposition = 0;
    int biggest = 0;
    int lowest = 0;
    int i = 0;

    while(i < 5) {
        if(i == 0) {
            biggest = vector[i];
            lowest = vector[i];
        }
        if(vector[i] > biggest) {
            biggest = vector[i];
            bposition = i;
        }
        if(vector[i] < lowest) {
            lowest = vector[i];
            lposition = i;
        }
        i++;
    }

    printf("biggest number is in position: %d\n", bposition + 1);
    printf("lowest number is in position: %d\n", lposition + 1);

    free(vector);
    system("pause");
}

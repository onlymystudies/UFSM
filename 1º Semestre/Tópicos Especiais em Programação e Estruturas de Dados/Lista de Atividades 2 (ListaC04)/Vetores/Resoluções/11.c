#include <stdio.h>
#include <stdlib.h>

void eleven_calc(int *vector);
void main() {
    int *v = malloc(10 * sizeof(int));
    int i;

    while(i < 10) {
        printf("value %d:\n", i + 1);
        scanf("%d", &v[i]);
        i++;
    }

    eleven_calc(v);
}
void eleven_calc(int *vector) {
    int i = 0;
    int positive = 0, negative = 0;

    while(i < 10) {
        if(vector[i] > 0) {
            positive += vector[i];
        } else {
            negative += 1;
        }
        i++;
    }

    printf("the sum of the positive number is %d and %d negative numbers\n", positive, negative);
    free(vector);
    system("pause");
}

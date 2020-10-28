#include <stdio.h>
#include <stdlib.h>

void twenty_print(int *vector);
void main() {
    int i = 0;
    int number;
    int *v = malloc(10 * sizeof(int));

    while (i < 10) {
        printf("value under 50 above 0:\n");
        scanf("%d", &number);
        if (number > 0 && number < 50) {
            v[i] = number;
        } else {
            printf("this number not correspond the specification");
        }
        i++;
    }

    twenty_print(v);
}
void twenty_print(int *vector) {
    int i = 0;

    while (i < 10) {
        printf("value: %d\n", vector[i]);
        //printf("value: %d\n", (*(vector+i)));
        i++;
    }

    free(vector);
    system("pause");
}

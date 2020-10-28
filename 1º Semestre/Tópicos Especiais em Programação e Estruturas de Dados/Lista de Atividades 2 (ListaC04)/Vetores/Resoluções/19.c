#include <stdio.h>
#include <stdlib.h>

void nineteen_print(int *vector);
void main() {
    int i = 0;
    int *v = malloc(50 * sizeof(int));

    while (i < 50) {
        v[i] = (i + 5 * i) % (i + 1);
        i++;
    }

    nineteen_print(v);
}
void nineteen_print(int *vector) {
    int i = 0;
    while (i < 50) {
        printf("value: %d\n", vector[i]);
        //printf("value: %d\n", (*(vector+i)));
        i++;
    }

    free(vector);
    system("Pause");
}

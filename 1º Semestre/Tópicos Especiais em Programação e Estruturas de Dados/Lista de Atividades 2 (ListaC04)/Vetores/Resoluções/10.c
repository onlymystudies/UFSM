#include <stdio.h>
#include <stdlib.h>

void ten_average(int *vector);
void main() {
    int *v = (int *) malloc(15 * sizeof(int));
    int i;

    while(i < 15) {
        printf("%d value:\n", i + 1);
        scanf("%d", &v[i]);
        i++;
    }

    ten_average(v);
}
void ten_average(int *vector) {
    int i = 0;
    int total = 0;

    do {
        total += vector[i];
        i++;
    } while(i != 15);

    printf("average: %d", total/15);
    free(vector);
    system("pause");
}

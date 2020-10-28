#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void five_pairs(int *vector);
void main() {
    int vector[10];
    int *v = vector;
    int i = 0;

    while(i < 10) {
        printf("%d value:\n", i+1);
        scanf("%d", &v[i]);
        i++;
    }

    five_pairs(v);
}
void five_pairs(int *vector) {
    int total = 0;
    int i = 0;

    while(i < 10) {
        if (vector[i] % 2 == 0) {
            total += 1;
        }
        i++;
    }

    printf("Total pairs: %d\n", total);
    free(vector);
    system("pause");
}

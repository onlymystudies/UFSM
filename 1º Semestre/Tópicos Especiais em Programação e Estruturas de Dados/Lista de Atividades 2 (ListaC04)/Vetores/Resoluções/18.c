#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void eighteen_multi(int *vector, int n);
void main() {
    int *v = malloc(10 * sizeof(int));
    int i = 0;
    int number;

    while(i < 10) {
        printf("value %d:\n", i + 1);
        scanf("%d", &v[i]);
        BufferClear();
        i++;
    }

    printf("number for the multiplication:\n");
    scanf("%d", &number);

    eighteen_multi(v, number);
}
void eighteen_multi(int *vector, int n) {
    int i = 0;
    while(i < 10) {
        vector[i] *= n;
        i++;
    }
    i = 0;
    while(i < 10) {
        printf("value: %d\n", (*(vector+i)));
        //printf("value: %d\n", vector[i]);
        i++;
    }

    free(vector);
    system("pause");
}

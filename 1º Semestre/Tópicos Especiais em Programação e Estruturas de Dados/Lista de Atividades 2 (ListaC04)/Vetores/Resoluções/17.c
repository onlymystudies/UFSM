#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void seventeen_alloca(int *vector);
void main() {
    int *v = malloc(10 * sizeof(int));
    int i = 0;

    while(i < 10) {
        printf("value %d:\n", i + 1);
        scanf("%d", &v[i]);
        BufferClear();
        i++;
    }

    seventeen_alloca(v);
}
void seventeen_alloca(int *vector) {
    int i = 0;

    while(i < 10) {
        if(vector[i] < 0) {
            vector[i] = 0;
        }
        printf("value: %d\n", (*(vector+i)));
        //printf("value: %d\n", vector[i]);
        i++;
    }

    free(vector);
    system("pause");
}

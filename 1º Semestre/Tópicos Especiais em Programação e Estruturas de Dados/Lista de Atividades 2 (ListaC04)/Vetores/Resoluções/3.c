#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void Three_square(int *vector);
void main() {
    int vector[10];
    int *v = vector;

    for (int i = 1; i <= 10; i++) {
        printf("Value %d:", i);
        scanf("%d", &v[i]);
        BufferClear();
    }

    Three_square(v);
}
void Three_print(int *vector, int *vector2) {
    int i = 1;
    int y = 1;

    printf("\nFirst vector:\n");
    while (i < 11) {
        printf("%d\n", vector[i]);
        i++;
    }

    printf("\nSecond vector:\n");
    while (y < 11) {
        printf("%d\n", vector2[y]);
        y++;
    }

    free(vector);
    system("pause");
}
void Three_square(int *vector) {
    int vector2[10];
    int *v = vector2;
    int i = 1;

    while(i < 11)
    {
        vector2[i] = vector[i] * vector[i];
        i++;
    }

    Three_print(vector, v);
}

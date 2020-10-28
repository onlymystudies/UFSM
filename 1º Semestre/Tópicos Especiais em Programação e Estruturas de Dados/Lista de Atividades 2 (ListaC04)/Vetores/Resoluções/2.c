#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void Two_print(int *vector);
void main() {
    int vector[6];
    int *v = vector;

    printf("Insert 6 values for the vector\n");
    for (int i = 0; i <= 5; i++) {
        printf("Value %d:\n", i+1);
        scanf("%d", &v[i]); // subscript notation; auto variable increment
        BufferClear();
    }

    Two_print(v);
}
void Two_print(int *vector) {
    printf("Values read:\n");

    for (int i = 0; i <= 5; i++) {
        printf("%d", vector[i]); // subscript notation; auto variable increment
        //printf("%d", *vector++); // pointer notation; pointer offset
    }

    free(vector);
    system("pause");
}

#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void One_B(int *vector);
void main() {
    int A[6] = {1, 0, 5, -2, -5, 7}; // (a)
    int *pA = A; // Para que & funcione, tens que declarar

    One_B(pA);
}
void One_D(int *vector) {
    for (int i = 0; i <= 5; i++) {
        //printf("%d\n", vector[i]); // subscript notation; auto variable increment
        printf("%d\n", *vector++); // pointer notation; pointer offset
    }

    free(vector);
    system("pause");
}
void One_C(int *vector) {
    vector[4] = 100;

    One_D(vector);
}
void One_B(int *vector) {
    int total = vector[0] + vector[1] + vector[5];

    printf("Vector sum of the position 0, 1 and 5: %d\n", total);

    One_C(vector);
}

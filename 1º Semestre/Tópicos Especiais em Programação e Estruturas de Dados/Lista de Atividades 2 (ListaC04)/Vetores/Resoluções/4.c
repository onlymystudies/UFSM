#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void four_values(int *vector);
void main() {
    int vector[8];
    int *v = vector;
    int i = 0;

    while(i < 8) {
        printf("%d value:\n", i+1);
        scanf("%d", &v[i]);
        //scanf("%d", &vector[i]);
        BufferClear();
        i++;
    }

    four_values(v);
}
void four_sum(int *vector, int *values) {
    int sum = 0;
    int value1 = values[0];
    int value2 = values[1];

    sum = vector[value1-1] + vector[value2-1];

    printf("The sum of positions %d and %d of the vector is: %d\n", value1, value2, sum);

    free(vector);
    system("pause");
}
void four_values(int *vector) {
    int values[1];
    int *v = values;

    printf("Insert first value for sum on position in vector:\n");
    scanf("%d", &v[0]);
    BufferClear();
    printf("Insert second value for sum on position in vector:\n");
    scanf("%d", &v[1]);
    BufferClear();

    four_sum(vector, v);
}

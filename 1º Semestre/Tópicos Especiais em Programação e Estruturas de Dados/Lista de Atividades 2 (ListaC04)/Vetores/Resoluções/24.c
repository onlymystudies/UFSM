#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void twentyfour_search(int *vector, int *vector2);
void main() {
    int *number = malloc(10 * sizeof(int));
    int *height = malloc(10 * sizeof(int));
    int i = 0;

    while (i < 10) {
        printf("student %d, number:\n", i + 1);
        scanf("%d", &number[i]);
        BufferClear();
        printf("student %d, height:\n", i + 1);
        scanf("%d", &height[i]);
        BufferClear();
        i++;
    }

    twentyfour_search(number , height);
}
void twentyfour_search(int *vector, int *vector2) {
    int i = 0;
    int higher;
    int hnumber;
    int lower;
    int lnumber;


    while (i < 10) {
        if (i == 0) {
            lower = vector2[i];
            higher = vector2[i];
        }

        if (vector2[i] > higher) {
            higher = vector2[i];
            hnumber = vector[i];
        }
        if (vector2[i] < lower) {
            lower = vector2[i];
            lnumber = vector[i];
        }

        i++;
    }


    printf("the higher student is %d, %d\n", hnumber, higher);
    printf("the lower student is %d, %d\n", lnumber, lower);

    free(vector);
    free(vector2);
    system("pause");
}

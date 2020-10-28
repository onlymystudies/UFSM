#include <stdio.h>
#include <stdlib.h>

void nine_reverse(int *vector);
void main() {
    int *v = (int *) malloc(6 * sizeof(int));
    int aux;
    int i = 0, y = 0;

    do {
        printf("%d value (only pairs):\n", y + 1);
        scanf("%d", &aux);
        if (aux % 2 == 0) {
            v[y] = aux;
            y++;
        } else {
            printf("this number is not pair\n");
        }
    } while(y != 6);

    nine_reverse(v);
}
void nine_reverse(int *vector) {
    int i = 5;

    printf("reverse vector:\n");
    while(i > -1) {
        printf("%d\n", (*(vector+i))); // pointer
        //printf("%d\n", vector[i]); // subscribed
        i--;
    }

    free(vector);
    system("pause");
}

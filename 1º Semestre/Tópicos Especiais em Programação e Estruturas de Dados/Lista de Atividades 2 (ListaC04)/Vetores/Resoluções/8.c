#include <stdio.h>
#include <stdlib.h>

void eight_reverse(int *vector);
void main() {
    int *v = (int *) malloc(6 * sizeof(int));
    int i = 0;

    while(i < 6) {
        printf("%d value:\n", i + 1);
        scanf("%d", &v[i]);
        i++;
    }

    eight_reverse(v);
}
void eight_reverse(int *vector) {
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

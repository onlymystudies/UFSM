#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void sixteen_direct(int *vector);
void sixteen_reverse(int *vector);
void main() {
    int i = 0;
    int menu;
    int *v = malloc(5 * sizeof(int));

    while (i < 5) {
        printf("vector value: %d\n", i + 1);
        scanf("%d", &v[i]);
        BufferClear();
        i++;
    }

    printf ("\n\t [1]  Direct Vector  [2]  Reverse Vector \n");
    printf ("\t [0]  Exit \n");
    scanf("%d", &menu);
    BufferClear();

    while (menu != 3) {
        switch (menu) {
            case 0:
                exit(0);
            case 1:
                sixteen_direct(v);
                break;
            case 2:
                sixteen_reverse(v);
                break;
            default:
                printf("invalid code");
        }
    }

}
void sixteen_reverse(int *vector) {
    int i = 4;
    while(i > -1) {
        printf("value: %d \n", vector[i]);
        //printf("value: %d \n", (*(vector+i)));
        i--;
    }

    free(vector);
    system("pause");
}
void sixteen_direct(int *vector) {
    int i = 0;
    while(i < 5) {
        printf("value: %d \n", vector[i]);
        //printf("value: %d \n", (*(vector+i)));
        i++;
    }

    free(vector);
    system("pause");
}

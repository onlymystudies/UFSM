#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void fourteen_calc(int *vector);
void main() {
    int *v = malloc(10 * sizeof(int));
    int i = 0;

    while(i < 10) {
        printf("value %d:\n", i + 1);
        scanf("%d", &v[i]);
        BufferClear();
        i++;
    }

    fourteen_calc(v);
}
void fourteen_calc(int *vector) {
    int j;
    for(int i = 0;  i < 10; i++) {
        for(j = i + 1; j < 10; j++){
            if(vector[i] == vector[j]) {
                if(vector[i] != vector[i-1]) {
                    printf("%d is a repeated number \n", vector[i]); // subscribed
                    //printf("%d is a repeated number \n", (*(vector+i))); // pointer
                }
            }
        }
    }

    free(vector);
    system("pause");
}

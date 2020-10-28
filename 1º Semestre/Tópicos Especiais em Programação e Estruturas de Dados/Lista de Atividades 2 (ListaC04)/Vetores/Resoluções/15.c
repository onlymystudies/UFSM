#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void fifteen_calc(int *vector);
void main() {
    int *v = malloc(20 * sizeof(int));
    int i = 0;

    while(i < 20) {
        printf("value %d:\n", i + 1);
        scanf("%d", &v[i]);
        BufferClear();
        i++;
    }

    fifteen_calc(v);
}
void fifteen_calc(int *vector) {
    int j;

    for(int i = 0;  i < 20; i++) {
        for(j = i + 1; j < 20; j++){
            if(vector[i] == vector[j]) {
                if(vector[i] != vector[i-1]) {
                    vector[i] = 0;
                }
            }
        }
    }

    for(int x = 0;  x < 20; x++) {
        if(vector[x] != 0) {
            printf("value: %d\n", vector[x]); // subscribed
            //printf("value: %d\n", (*(vector+x))); // pointer
        }
    }

    free(vector);
    system("pause");
}

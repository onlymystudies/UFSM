#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v = malloc(100 * sizeof(int));
    int number, i = 0;

    while (i < 100) {
        do {
            printf("%d Digite um numero:\n", i + 1);
            scanf("%d", &number);

            if (number % 7 != 0) {
                printf("O numero nao e multiplo de 7 ");
                if (number % 10 != 7) {
                    printf("e o numero nao termina com 7\n");
                } else {
                    printf("mas termina com 7\n");
                    v[i] = number;
                    i++;
                }
            }
            else {
                v[i] = number;
                i++;
            }

        } while (number % 7 != 0 || number % 10 != 7);
    }
    
    system("pause");
}

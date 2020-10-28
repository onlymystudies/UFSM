#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, coef = 0;

    printf("digite um inteiro n: \n");
    scanf("%d", &n);

    for (int i = 0; i < n + 1; i++){

        for (int j = 0; j < i; j++){
            if (i == 0 || j == 0)
                coef = 1;
            else
                coef = coef * ( i - j + 1) / j ;

            printf("%d ", coef);
        }

        printf("\n");
    }

    system("pause");
}

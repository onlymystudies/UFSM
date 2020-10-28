#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v = malloc(10 * sizeof(int));
    int resultado;

    for (int j = 0; j < 10; ++j) {
        printf("Numero %d:\n", j + 1);
        scanf("%d", &v[j]);
    }

    system("cls");

    for (int k = 0; k < 10; ++k) {
        resultado = 0;
        for (int i = 2; i <= v[k] / 2; i++) {
            if (v[k] % i == 0) {
                resultado++;
            }
        }
        if (resultado == 0) {
            printf("%d e um numero primo ", v[k]);
            printf("e esta na posicao %d\n", k);
        } else
            printf("%d nao e um numero primo\n", v[k]);
    }

    system("pause");
}

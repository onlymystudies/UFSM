#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n= 10, m = 0;
    double soma = 1;
    int *v = malloc(n * sizeof(int));

    for (int j = 0; j < n; ++j) {
        printf("Valor %d\n", j + 1);
        scanf("%d", &v[j]);
        m += v[j]; // media
        soma += pow(v[j] - m, 2); // soma
    }

    printf("desvio padrao %f\n", sqrt(soma / n));

    system("pause");
}

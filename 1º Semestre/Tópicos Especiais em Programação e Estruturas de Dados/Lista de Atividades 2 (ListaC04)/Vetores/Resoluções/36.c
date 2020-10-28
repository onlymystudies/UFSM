#include <stdio.h>
#include <stdlib.h>

int main() {
    int w = 0;
    float aux;
    float *v = malloc(10 * sizeof(float));

    for (int i = 0; i < 10; ++i) {
        printf("Numero %d:\n", i + 1);
        scanf("%f", &v[i]);
    }

    for (int i = 0; i < 10; ++i) { // ORDENACAO
        for (int j = i; j < 10; ++j) {
            if (v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }

    system("cls");

    puts("vetor:");
    while (w < 10) {
        printf("%.2f\n", v[w]);
        w++;
    }

    system("pause");
}

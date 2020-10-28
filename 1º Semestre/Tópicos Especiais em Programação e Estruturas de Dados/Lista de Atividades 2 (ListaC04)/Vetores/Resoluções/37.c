#include <stdio.h>
#include <stdlib.h>

int main() {
    int w = 0;
    int aux;
    int *v = malloc(11 * sizeof(int));

    for (int i = 0; i < 11; ++i) {
        printf("Numero %d:\n", i + 1);
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < 6; ++i) { // ORDENACAO CRESCENTE
        for (int j = i; j < 6; ++j) {
            if (v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }

    for (int i = 6; i < 11; ++i) { // ORDENACAO DECRESCENTE
        for (int j = i; j < 11; ++j) {
            if (v[i] < v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }

    system("cls");

    puts("vetor:");
    while (w < 11) {
        printf("%d\n", v[w]);
        w++;
    }

    system("pause");
}

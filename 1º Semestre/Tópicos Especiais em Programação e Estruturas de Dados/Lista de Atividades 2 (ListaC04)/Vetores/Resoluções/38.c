#include <stdio.h>
#include <stdlib.h>

int main() {
    int w = 0;
    int aux;
    int *v = malloc(10 * sizeof(int));

    for (int i = 0; i < 10; ++i) {
        printf("Numero %d:\n", i + 1);
        scanf("%d", &v[i]);

        for (int f = 0; f < i; ++f) // ORDENACAO CRESCENTE
            for (int j = f; j < i + 1; ++j)
                if (v[f] > v[j]) {
                    aux = v[f];
                    v[f] = v[j];
                    v[j] = aux;
                }
    }

    system("cls");

    puts("vetor:");
    while (w < 10) {
        printf("%d\n", v[w]);
        w++;
    }

    system("pause");
}

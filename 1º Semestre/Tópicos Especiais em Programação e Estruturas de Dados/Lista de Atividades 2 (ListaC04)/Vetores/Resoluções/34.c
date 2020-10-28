#include <stdio.h>
#include <stdlib.h>

int main() {
    int l = 0, igual;
    int *v = malloc(10 * sizeof(int));

    for (int i = 0; i < 10; ++i) {
        do {
            igual = 0;

            printf("Numero %d:\n", i + 1);
            scanf("%d", &v[i]);

            if (i > 0)
                for (int j = 0; j < i; ++j) {
                    for (int k = j+1; k < i+1; ++k) {
                        if (v[j] == v[k]) {
                            igual++;
                        }
                    }
                }

            if (igual > 0)
                puts("Numero ja digitado");

        } while (igual > 0);
    }

    system("cls");

    puts("vetor:");
    while (l < 10) {
        printf("%d\n", v[l]);
        l++;
    }

    system("pause");
}

#include <stdio.h>
#include <stdlib.h>

int main() {

    int *v = malloc(10 * sizeof(int));
    int *v2 = malloc(10 * sizeof(int));
    int *v3 = malloc(20 * sizeof(int));

    for (int i = 0; i < 10; ++i) {
        printf("Numero %d:\n", i + 1);
        scanf("%d", &v[i]);

    }

    system("cls");

    puts("VETOR 2");
    for (int j = 0; j < 10; ++j) {
        printf("Numero %d:\n", j + 1);
        scanf("%d", &v2[j]);
    }

    int impar = 0, par = 0;

    for (int i = 0; i < 20; ++i) {
        if (i % 2 == 0) {
            v3[i] = v[par];
            par++;
        }
        else {
            v3[i] = v2[impar];
            impar++;
        }
    }

    for (int i = 0; i < 20; ++i) {
        for (int j = i + 1; j < 20; ++j) {
            if (v3[i] == v3[j])
                v3[i] = 0;
        }
    }

    system("cls");

    puts("VETOR 3");
    int i = 0;
    while (i < 20) {
        if (v3[i] != 0) {
            printf("%d\n", v3[i]);
        }
        i++;
    }

    system("pause");
}

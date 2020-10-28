#include <stdio.h>
#include <stdlib.h>

int main() {
    int j;
    int *v = malloc(15 * sizeof(int));

    for (int i = 0; i < 15; ++i) {
        printf("Numero %d:\n", i + 1);
        scanf("%d", &v[i]);
    }

    system("cls");

    for (int i = 0; i < 15; ++i) {
        if (v[i] == 0) {
            j = i;
            while (j < 14) {
                v[j] = v[j + 1];
                v[j + 1] = 0;
                j++;
            }
        }
    }

    j = 0;
    while (j < 15) {
        if (v[j] != 0) {
            printf("%d\n", v[j]);
        }
        j++;
    }

    system("pause");
}

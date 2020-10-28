#include <stdio.h>
#include <stdlib.h>

int main() {

    int aux = 0, uniao = 5;
    int a = 0;
    int *x = malloc(5 * sizeof(int));
    int *y = malloc(5 * sizeof(int));
    int vsoma[5];
    int vproduto[5];
    int vdiferenca[5] = {0,0,0,0,0};
    int vintersecao[5] = {0,0,0,0,0};
    int vuniao[10] = {0,0,0,0,0,0,0,0,0,0};

    for (int i = 0; i < 5; ++i) {
        printf("Numero %d:\n", i + 1);
        scanf("%d", &x[i]);

    }

    system("cls");

    puts("VETOR 2");
    for (int j = 0; j < 5; ++j) {
        printf("Numero %d:\n", j + 1);
        scanf("%d", &y[j]);
    }

    system("cls");

    for (int i = 0; i < 5; ++i) {
        vsoma[i] = x[i] + y[i]; // Soma entre x e y
        vproduto[i] = x[i] * y[i]; // Produto entre x e y
    }

    for (int i = 0; i < 5; ++i) { // Diferenca entre x e y
        for (int j = 0; j < 5; ++j) {
            if (x[i] != y[j])
                vdiferenca[i] = x[i];
            else
                vdiferenca[i] = 0;
        }
    }

    for (int i = 0; i < 5; ++i) { // Intersecao entre x e y
        for (int j = 0; j < 5; ++j) {
            if (x[i] == y[j])
                vintersecao[i] = x[i];
        }
    }

    for (int i = 0; i < 5; ++i) { // Uniao entre x e y
        vuniao[i] = x[i];
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (y[i] !=  x[j])
                vuniao[uniao] = y[i];
        }
        uniao++;
    }

    puts("Soma entre x e y:");
    while (a < 5) {
        printf("%d\n", vsoma[a]);
        a++;
    }

    a = 0;
    puts("Produto entre x e y:");
    while (a < 5) {
        printf("%d\n", vproduto[a]);
        a++;
    }

    a = 0;
    puts("Diferenca entre x e y:");
    while (a < 5) {
        if (vdiferenca[a] != 0) {
            printf("%d\n", vdiferenca[a]);
        }
        a++;
    }

    a = 0;
    puts("interesecao entre x e y:");
    while (a < 5) {
        if (vintersecao[a] != 0) {
            printf("%d\n", vintersecao[a]);
        }
        a++;
    }

    a = 0;
    puts("Uniao entre x e y:");
    while (a < 10) {
        if (vuniao[a] != 0) {
            printf("%d\n", vuniao[a]);
        }
        a++;
    }

    system("pause");
}

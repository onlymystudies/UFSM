#include <stdio.h>
#include <stdlib.h>

void menu(float **m, float **m2);

void d(float **m, float **m2) {
    system("cls");

    puts("matriz 1");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%.f\t", m[i][j]);
        }
        printf("\n");
    }

    puts("matriz 2");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%.f\t", m2[i][j]);
        }
        printf("\n");
    }

    int retorna;
    printf("[0] Retornar\n[1] Sair\n");
    scanf("%d", &retorna);
    if (retorna == 0)
        menu(m, m2);
    else
        exit(0);
}

void c(float **m, float **m2) {
    system("cls");

    float aux;

    puts("Constante para as duas matrizes");
    scanf("%f", &aux);

    m[0][0] = aux;
    m2[0][0] = aux;

    puts("Adicionado com sucesso!");

    int retorna;
    printf("[0] Retornar\n[1] Sair\n");
    scanf("%d", &retorna);
    if (retorna == 0)
        menu(m, m2);
    else
        exit(0);
}


void b(float **m, float **m2) {
    system("cls");

    float **m3;

    m3 = malloc(2 * sizeof(float *));

    for (int i = 0; i < 2; ++i) {
        m3[i] = malloc(2 * sizeof(float));
    }

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            m3[i][j] = m[i][j] - m2[i][j];

    puts("Subtraido com sucesso!");

    int retorna;
    printf("[0] Retornar\n[1] Sair\n");
    scanf("%d", &retorna);
    if (retorna == 0)
        menu(m, m2);
    else
        exit(0);
}

void a(float **m, float **m2) {
    system("cls");

    float **m3;

    m3 = malloc(2 * sizeof(float *));

    for (int i = 0; i < 2; ++i) {
        m3[i] = malloc(2 * sizeof(float));
    }

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            m3[i][j] = m[i][j] + m2[i][j];

    puts("Somado com sucesso!");

    int retorna;
    printf("[0] Retornar\n[1] Sair\n");
    scanf("%d", &retorna);
    if (retorna == 0)
        menu(m, m2);
    else
        exit(0);
}



void menu(float **m, float **m2) {
    system("cls");

    int menu = 0;

    puts("(1) Soma as duas matrizes");
    puts("(2) Subtrair a primeira matriz da segunda");
    puts("(3) Adicionar uma constante as duas matrizes");
    puts("(4) Imprimir as matrizes");
    scanf("%d", &menu);

    while (menu != 5) {
        switch (menu) {
            case 1:
                a(m, m2);
                break;
            case 2:
                b(m, m2);
                break;
            case 3:
                c(m, m2);
                break;
            case 4:
                d(m, m2);
                break;
            default:
                printf("Nao existe\n");
        }
    }

}

int main() {
    float **m;
    float **m2;

    m = malloc(2 * sizeof(float *));

    m2 = malloc(2 * sizeof(float *));

    for (int i = 0; i < 2; ++i) {
        m[i] = malloc(2 * sizeof(float));
    }

    for (int i = 0; i < 2; ++i) {
        m2[i] = malloc(2 * sizeof(float));
    }

    puts("Matriz 1:");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("Numero linha %d coluna %d:\n", i + 1, j + 1);
            scanf("%f", &m[i][j]);
        }
        system("cls");
    }

    puts("Matriz 2:");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("Numero linha %d coluna %d:\n", i + 1, j + 1);
            scanf("%f", &m2[i][j]);
        }
        system("cls");
    }

    menu(m, m2);
}
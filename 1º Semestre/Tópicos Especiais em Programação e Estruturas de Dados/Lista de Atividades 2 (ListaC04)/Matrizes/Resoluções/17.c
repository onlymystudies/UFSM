#include <stdio.h>
#include <stdlib.h>

int main() {
    int piornota, piornota1 = 0, piornota2 = 0, piornota3 = 0;
    int **m;

    m = malloc(10 * sizeof(int *)); // 10 alunos

    for (int i = 0; i < 10; ++i) {
        m[i] = malloc(3 * sizeof(int)); // 3 Provas
    }

    for (int i = 0; i < 10; ++i) {
        printf("Aluno: %d\n", i + 1);
        for (int j = 0; j < 3; ++j) {
            printf("Prova %d:\n", j + 1);
            scanf("%d", &m[i][j]);
        }
        system("cls");
    }

    for (int i = 0; i < 10; ++i) {
        piornota = 10;
        for (int j = 0; j < 3; ++j) {
            if (m[i][j] < piornota)
                piornota = m[i][j];
        }

        if (piornota == m[i][0]) {
            piornota1++;
        }

        if (piornota == m[i][1] && piornota != m[i][0]) {
            piornota2++;
        }

        if (piornota == m[i][2] && piornota != m[i][1] && piornota != m[i][0]) {
            piornota3++;
        }
    }

    printf("Piores notas na prova 1: %d aluno(s)\n", piornota1);
    printf("Piores notas na prova 2: %d aluno(s)\n", piornota2);
    printf("Piores notas na prova 3: %d aluno(s)\n", piornota3);

    system("pause");
}
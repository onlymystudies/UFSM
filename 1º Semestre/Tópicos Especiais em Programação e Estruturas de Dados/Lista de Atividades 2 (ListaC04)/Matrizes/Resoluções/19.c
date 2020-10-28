#include <stdio.h>
#include <stdlib.h>

int main() {
    int maiornota = 0, matricula, medianotasfinais = 0;
    int **m;

    m = malloc(5 * sizeof(int *));

    for (int i = 0; i < 5; ++i) {
        m[i] = malloc(4 * sizeof(int));
    }

    for (int i = 0; i < 5; ++i) {
        printf("Estudante %d\n", i + 1);
        puts("Numero de matricula:");
        scanf("%d", &m[i][0]);
        puts("Media das provas:");
        scanf("%d", &m[i][1]);
        puts("Media dos trabalhos:");
        scanf("%d", &m[i][2]);
        m[i][3] = (m[i][1] + m[i][2]) / 2;
        medianotasfinais += m[i][3];
        system("cls");
    }

    for (int i = 0; i < 5; ++i) {
        if (m[i][3] > maiornota) {
            maiornota = m[i][3];
            matricula = i;
        }
    }

    printf("Maior media final: %d\n", m[matricula][3]);
    printf("Matricula: %d\n", m[matricula][0]);
    printf("Soma media notas final: %d\n", medianotasfinais);
    system("pause");
}
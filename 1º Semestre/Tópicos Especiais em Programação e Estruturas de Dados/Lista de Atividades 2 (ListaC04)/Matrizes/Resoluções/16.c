#include <stdio.h>
#include <stdlib.h>

int main() {
    float resultado[3] = {0,0,0};
    float soma = 0;
    char matricula[3][64];
    char **m;
    char v[10] = {'a','b','c','d','e','a','b','c','d','e'};

    m = malloc(3 * sizeof(char *)); // 5 alunos

    for (int i = 0; i < 3; ++i) {
        m[i] = malloc(10 * sizeof(char)); // 10 questoes
    }

    for (int i = 0; i < 3; ++i) {
        printf("Aluno %d\n", i + 1);
        printf("Matricula:\n");
        scanf("%s", &matricula[i]);

        for (int j = 0; j < 10; ++j) {
            printf("Questao %d:\n", j + 1);
            scanf("%s", &m[i][j]);
        }
        system("cls");
    }

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 10; ++j)
            if (m[i][j] == v[j])
                resultado[i]++;

    for (int i = 0; i < 3; ++i) {
        printf("Aluno %d\n", i + 1);
        printf("Matricula %s\n", matricula[i]);
        puts("Respostas:");
        for (int j = 0; j < 10; ++j)
            printf("%c\n", m[i][j]);
        printf("%.2f pontos\n", resultado[i]);
        puts("===================");
    }

    for (int i = 0; i < 3; ++i)
        if (resultado[i] != 0)
            soma += resultado[i];

    printf("Percentual de aprovador: %.2f%%\n", (soma / 30) * 100);

    system("pause");
}
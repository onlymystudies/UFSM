#include <stdio.h>
#include <stdlib.h>

int main() {
    int resultado[5] = {0,0,0,0,0};

    char **m;
    char v[10] = {'a','b','c','d','a','b','c','d','a','b'};

    m = malloc(5 * sizeof(char *)); // 5 alunos

    for (int i = 0; i < 5; ++i) { // 10 questoes
        m[i] = malloc(10 * sizeof(char));
    }

    for (int i = 0; i < 5; ++i) {
        printf("Aluno %d\n", i + 1);
        for (int j = 0; j < 10; ++j) {
            printf("Questao %d:\n", j + 1);
            scanf("%s", &m[i][j]);
        }
        system("cls");
    }

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 10; ++j)
            if (m[i][j] == v[j])
                resultado[i]++;

    for (int i = 0; i < 5; ++i) {
        printf("Aluno %d\n", i + 1);
        printf("%d pontos\n", resultado[i]);
        puts("===================");
    }

    system("pause");
}
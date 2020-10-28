#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

struct aluno {
    char nome[64];
    int numero;
    char curso[64];
};
struct aluno al;

int main() {
    setlocale(LC_ALL, "ptb");

    for (int i = 0; i < 5; i++) {
        printf("Nome do aluno %d:\n", i + 1);
        gets(al.nome);

        printf("Número de matrícula %d:\n", i + 1);
        scanf("%d", &al.numero);
        limpar_buffer();

        printf("curso %d:\n", i + 1);
        gets(al.curso);
    }
    int y = 0;
    while (y < 5) {
        printf("Aluno %d\n", y + 1);
        printf("Nome: %s\n", al.nome);
        printf("Numero de matrícula: %d\n", al.numero);
        printf("Curso: %s\n", al.curso);
        y++;
    }

    system("pause");
}

/* Problema 1.1.7
 * Deseja-se fazer um levantamento a respeito da ausência de alunos a primeira prova de programação de computadores para cada uma das 14 turmas existentes.
 * Para cada turma é fornecido um conjunto de valores, sendo que os dois primeiros valores do conjunto corresponde a identificação da turma (A, B, C ...) e ao número de alunos matriculados, e os demais valores deste conjunto contém o número de matricula do aluno e a letra A ou P para o caso de o aluno estar ausente ou presente, respectivamente.
 * Fazer um algoritmo que:
 * a) para cada turma, calcule a porcentagem de ausência e escreva a identificação da turma e a porcentagem calculada.
 * b) determine e escreva quantas turmas tiveram porcentagem de ausência superior a 5%.
 */
#include <stdio.h>
#include <stdlib.h>
#include <cllib.h>
#include <mem.h>

int main() {
    int contador = 1, ausencia_superior5 = 0;

    typedef struct alunos{
        char numero_matricula[10],
                presenca[2];
    }cadastro;

    typedef struct turmas{
        int ausentes, presentes, numero_alunos;
        char identificacao[1];
        cadastro *aluno;
    }turma;
    turma *presenca = NULL;
    presenca = malloc(14 * sizeof(turma));
    for (int i = 0; i < 14; ++i) {
        presenca[i].aluno           = NULL;
        presenca[i].ausentes        = 0;
        presenca[i].presentes       = 0;
        presenca[i].numero_alunos   = 0;
    }

    for (int i = 0; i < 14; ++i) {
        printf("Turma:\n");
        fgets(presenca[i].identificacao, 1, stdin);
        fflush(stdin); clbuffer();
        printf("Aluno\n0 - Sair\n");
        do {
            presenca->aluno = (cadastro *) realloc(presenca->aluno, contador * sizeof(cadastro));  // alocao de memoriavel variavel e dinamica
            printf("Matricula:\n");
            fgets(presenca[i].aluno->numero_matricula, 10, stdin);
            fflush(stdin);
            printf("Presenca:\n");
            fgets(presenca[i].aluno->presenca, 1, stdin);
            fflush(stdin); clbuffer();
            presenca[i].numero_alunos++;
            contador++;
            if (strncmp (presenca[i].aluno->presenca, "a", 1) == 0) presenca[i].ausentes++;
            if (strncmp (presenca[i].aluno->presenca, "p", 1) == 0) presenca[i].presentes++;
        } while (strncmp (presenca[i].aluno->numero_matricula, "0", 1) != 0);
    }

    for (int i = 0; i < 14; ++i) {
        printf("Turma %s\n", presenca[i].identificacao);
        printf("Ausencia: %d%%\n", (presenca[i].ausentes * presenca[i].numero_alunos) / 100);
        if ((presenca[i].ausentes * presenca[i].numero_alunos) / 100 > 5) ausencia_superior5++;
    }
    printf("Quantidade de turmas com ausencia superir a 5%%: %d", ausencia_superior5);
    system("pause");
}
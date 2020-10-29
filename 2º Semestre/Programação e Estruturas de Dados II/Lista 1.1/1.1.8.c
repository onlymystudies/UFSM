/* Problema 1.1.8
 * Uma certa firma fez uma pesquisa de mercado para saber se as pessoas gostaram ou n�o de um novo produto lan�ado no mercado. Para isso, forneceu o sexo do entrevistado e sua resposta (sim ou n�o). Sabendo-se que foram entrevistados 2.000 pessoas, fazer um algoritmo que calcule e escreva:
 * a) o n�mero de pessoas que responderam sim
 * b) o n�mero de pessoas que responderam n�o
 * c) a porcentagem de pessoas do sexo feminino que responderam sim
 * d) a porcentagem de pessoas do sexo masculino que responderam n�o
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char sexo[10], opniao[4];
    int total_feminino = 0,
    total_masculino = 0,
    total_feminino_sim = 0,
    total_masculino_nao = 0,
    total_nao = 0,
    total_sim = 0;

    for (int i = 0; i < 2000; ++i) {
        printf("Sexo\n");
        fgets(sexo, 10, stdin);
        fflush(stdin);
        printf("Gostaram?\n");
        fgets(opniao, 3, stdin);
        fflush(stdin);
        if (strncmp (sexo, "feminino", 7) == 0) {
            total_feminino++;
            if (strncmp (opniao, "sim", 2) == 0) {
                total_feminino_sim++;
                total_sim++;
            } else {
                total_nao++;
            }
        }
        if (strncmp (sexo, "masculino", 8) == 0) {
            total_masculino++;
            if (strncmp (opniao, "nao", 2) == 0) {
                total_masculino_nao++;
                total_nao++;
            } else {
                total_sim++;
            }
        }
    }

    printf("a) o numero de pessoas que responderam sim: %d\n", total_sim);
    printf("b) o numero de pessoas que responderam nao: %d\n", total_nao);
    printf("c) a porcentagem de pessoas do sexo feminino que responderam sim: %d%%\n", (total_feminino_sim * 100) / total_feminino);
    printf("d) a porcentagem de pessoas do sexo masculino que responderam nao: %d%%\n", (total_masculino_nao * 100) / total_masculino);
    system("pause");
}
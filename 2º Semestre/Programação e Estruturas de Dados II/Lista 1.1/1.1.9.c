/* Problema 1.1.9
 * Foi feita uma pesquisa para determinar o índice de mortalidade infantil em certo período. Fazer um algoritmo que:
 * leia inicialmente o número de crianças nascidas no período
 * leia, em seguida, um número indeterminado de linhas, contendo, cada uma, o sexo de uma criança morta (masculino, feminino) e o número de meses de vida da criança. A última linha, que não entrará nos cálculos contem no lugar do sexo a palavra "vazio".
 * Determine e imprima:
 * a) a porcentagem de crianças mortas no período
 * b) a porcentagem de crianças do sexo masculino mortas no período
 * c) a porcentagem de crianças que viveram 24 meses ou menos no período
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clear_buffer() {
    int c; while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    float   quantidade_masculino   = 0,
            quantidade_feminino    = 0;
    int     quantidade_criancas    = 0,
            quantidade_meses       = 0,
            criancas_nascidas,
            meses,
            ano_inicial,
            ano_final;
    char    sexo[10];

    printf("Periodo\n");
    printf("Ano inicial:\n");
    scanf("%d", &ano_inicial);
    printf("Ano final:\n");
    scanf("%d", &ano_final);
    printf("Numero de criancas nascidas entre %d e %d:\n", ano_inicial, ano_final);
    scanf("%d", &criancas_nascidas);
    clear_buffer();
    printf("Criancas mortas :(\n");
    for (;;) {
        printf("Crianca %d\n", quantidade_criancas + 1);
        printf("Sexo:\n");
        fgets(sexo, sizeof sexo, stdin);
        fflush(stdin);
        if (strncmp (sexo, "vazio", 5)     == 0) break;
        if (strncmp (sexo, "masculino", 9) == 0) quantidade_masculino++;
        if (strncmp (sexo, "feminino",  8) == 0) quantidade_feminino++;
        printf("Meses de vida:\n");
        scanf("%d", &meses);
        clear_buffer();
        if (meses <= 24) quantidade_meses++;
        quantidade_criancas++;
    }

    printf("a) a porcentagem de criancas mortas no periodo: %d%%\n", (quantidade_criancas * criancas_nascidas) / 100);
    printf("b) a porcentagem de criancas do sexo masculino mortas no periodo: %.2f%%\n", (quantidade_masculino * (float) criancas_nascidas) / 100);
    printf("c) a porcentagem de crianças que viveram 24 meses ou menos no periodo: %d%%\n", (quantidade_meses * criancas_nascidas) / 100);
    system("pause");
}
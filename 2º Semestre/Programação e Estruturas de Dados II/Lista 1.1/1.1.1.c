/* Problema 1.1.1
 * Fazer um algoritmo que:
 * Leia um n�mero indeterminado de linhas contendo cada uma a idade de um indiv�duo.
 * A �ltima linha, que n�o entrar� nos c�lculos, cont�m o valor da idade igual a zero.
 * Calcule e escreva a idade m�dia deste grupo de indiv�duos.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int idade,
            individuos = 0,
            idade_soma = 0;

    do {
        printf("Idade:\n");
        scanf("%d", &idade);
        idade_soma += idade;
        individuos++;
    } while (idade != 0);

    printf("Idade media: %d\n", idade_soma / individuos);
    system("pause");
}
/* Problema 1.2.2
 * Fazer um algoritmo que:
 * Leia um número indeterminado de linhas contendo cada uma um número inteiro. A última linha, que não entrará nos cálculos, contém o valor do número igual a zero.
 * Calcule e escreva, para cada número válido, se este é ou não perfeito.
 * Número perfeito é aquele cuja soma de seus divisores, exceto ele próprio é igual ao número.
 * Exemplo: 6 é perfeito porque 1 + 2 + 3 = 6.
 */
#include <stdio.h>
#include <stdlib.h>

int recursao_perfeito() {
    int numero, soma_divisores = 0;

    printf("Numero:\n");
    scanf("%d", &numero);
    if (numero == 0) return 0;

    for(int i = 1; i < numero; i++)
        if (numero % i == 0)
            soma_divisores += i;
    if (soma_divisores == numero)
        printf("%d e um numero perfeito\n", numero);
    else
        printf("%d nao e um numero perfeito\n", numero);

    return recursao_perfeito();
}

int main() {
    recursao_perfeito();
    system("pause");
}
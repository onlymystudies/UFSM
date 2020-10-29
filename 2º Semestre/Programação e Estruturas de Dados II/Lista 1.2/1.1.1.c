/* Problema 1.2.1
 * Fazer um algoritmo que:
 * Leia um número indeterminado de linhas contendo cada uma um número inteiro.
 * A última linha, que não entrará nos cálculos, contém o valor do número igual a zero.
 * Calcule e escreva, para cada número válido, se este é ou não primo.
 */
#include <stdio.h>
#include <stdlib.h>

int recursao_primo();

int main() {
    recursao_primo();
    system("pause");
}

int recursao_primo() {
    int numero, resultado = 0;

    printf("Numero:\n");
    scanf("%d", &numero);
    if (numero == 0) return 0;
    for (int i = 2; i <= numero / 2; ++i) {
        if (numero % i == 0) {
            resultado++;
            break;
        }
    }

    if (resultado > 0) printf("%d nao e um numero primo\n", numero);
    else printf("%d e um numero primo\n", numero);
    return recursao_primo();
}
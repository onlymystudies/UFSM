/* Problema 1.2.3
 * Fazer um algoritmo que:
 * Leia um número indeterminado de linhas contendo cada uma um número inteiro.
 * A última linha, que não entrará nos cálculos, contém o valor do número igual a zero.
 * Calcule e escreva, para cada número válido, se este é ou não um quadrado perfeito.
 * Um número será quadrado perfeito quando respeitar a regra de formação: n2= a.
 * Nessa regra, n é qualquer número inteiro positivo e a é o número quadrado perfeito. Ex.:
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int recursao_quadrado_perfeito() {
    float numero;
    double quadrado;

    printf("Numero:\n");
    scanf("%f", &numero);
    if (numero == 0) return 0;

    quadrado = pow(numero, 2);
    if (fmod(quadrado, 2) == 1 || fmod(quadrado, 2) == 0)
        printf("%.1f e um quadrado perfeito\n", numero);
    else
        printf("%.1f nao e um quadrado perfeito\n", numero);
    return recursao_quadrado_perfeito();
}

int main() {
    recursao_quadrado_perfeito();
    system("pause");
}
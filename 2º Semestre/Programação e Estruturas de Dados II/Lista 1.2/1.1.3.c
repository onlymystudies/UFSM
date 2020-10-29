/* Problema 1.2.3
 * Fazer um algoritmo que:
 * Leia um n�mero indeterminado de linhas contendo cada uma um n�mero inteiro.
 * A �ltima linha, que n�o entrar� nos c�lculos, cont�m o valor do n�mero igual a zero.
 * Calcule e escreva, para cada n�mero v�lido, se este � ou n�o um quadrado perfeito.
 * Um n�mero ser� quadrado perfeito quando respeitar a regra de forma��o: n2= a.
 * Nessa regra, n � qualquer n�mero inteiro positivo e a � o n�mero quadrado perfeito. Ex.:
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
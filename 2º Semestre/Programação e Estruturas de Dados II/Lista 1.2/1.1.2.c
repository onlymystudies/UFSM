/* Problema 1.2.2
 * Fazer um algoritmo que:
 * Leia um n�mero indeterminado de linhas contendo cada uma um n�mero inteiro. A �ltima linha, que n�o entrar� nos c�lculos, cont�m o valor do n�mero igual a zero.
 * Calcule e escreva, para cada n�mero v�lido, se este � ou n�o perfeito.
 * N�mero perfeito � aquele cuja soma de seus divisores, exceto ele pr�prio � igual ao n�mero.
 * Exemplo: 6 � perfeito porque 1 + 2 + 3 = 6.
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
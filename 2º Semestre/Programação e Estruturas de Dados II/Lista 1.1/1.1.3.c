/* Problema 1.1.3
 * A conversão de graus Fahrenheit para centígrados é obtida por C := ( 5 / 9 ) * ( F - 32 );
 * Fazer um algoritmo que calcule e escreva uma tabela de centígrados em função de graus fahrenheit, que variam de 50 a 150 de 1 em 1.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    float F, C;

    for (int i = 50; i < 150; ++i)
        F = (float) i; C = ((float) 5 / 9) * (F - 32); printf("%.2f C\n", C);

    system("pause");
}
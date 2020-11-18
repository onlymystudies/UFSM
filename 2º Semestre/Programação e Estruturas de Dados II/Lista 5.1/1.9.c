/* Problema 9
 * Escreva uma função recursiva que determine quantas vezes um dígito K ocorre em um número natural N. Por exemplo,
 * o dígito 2 ocorre 3 vezes em 762021192.
 */
#include <stdio.h>
#include <stdlib.h>

int recContaNumRep(int N, int K, int soma) {
    int a = N % 10;
    if (a <= 0)
        return soma;
    if (a == K)
        soma++;
    return recContaNumRep(N /= 10, K, soma);
}

int main(void) {
    int N = 122333;
    int K = 3;
    printf("total de K (%d) digitos: %d\n", K, recContaNumRep(N, K, 0));
    system("pause");
}
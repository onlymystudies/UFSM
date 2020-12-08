/* Nome: Leonardo Zamboni Nunes 202012828
 * Codigo citado: FuncoesRecursivas.cpp aula 5
 *
 * (2,0 Pontos) Escreva um programa em C para encontrar a soma dos dígitos de um número
 * usando recursão. Ex.: Entrada: Insira qualquer número para encontrar a soma dos dígitos: 25;
 * Saída: A soma dos dígitos de 25 = 7.
 */
#include <stdio.h>
#include <stdlib.h>

int soma(int numero, int somaDigitos) {
    int resto = numero % 10;
    if (numero == 0)
        return somaDigitos;
    return soma(numero /= 10, somaDigitos += resto);
}

int main(void) {
    int numero;
    printf("entrada\n");
    scanf("%d", &numero);
    printf("soma e %d\n", soma(numero, 0));
    system("pause");
}
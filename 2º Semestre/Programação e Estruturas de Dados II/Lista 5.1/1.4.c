#include <stdio.h>
#include <stdlib.h>

int recSoma(int n, int soma) {
    if (n == 0)
        return soma;
    soma += n--;
    recSoma(n, soma);
}

int main(void) {
    int n = 10, soma = 0;
    printf("soma: %d\n", recSoma(n, soma));
    system("pause");
}
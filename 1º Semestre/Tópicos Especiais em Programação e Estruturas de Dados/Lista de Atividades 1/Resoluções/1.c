#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void limpa_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int quadrado(int aux);
int main()
{
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    typedef struct variaveis_problema1
    {
        int numero;
        int quadrado;
    }vars;
    vars variavel;

    printf("Insira qualquer n%cmero para o quadrado:\n", 250);
    scanf("%d", &variavel.numero);
    limpa_buffer();

    variavel.quadrado = quadrado(variavel.numero);

    printf("O quadrado de %d %c: %d\n", variavel.numero, 233, variavel.quadrado);

    getchar();
}
int quadrado(int aux)
{
    return aux*aux;
}

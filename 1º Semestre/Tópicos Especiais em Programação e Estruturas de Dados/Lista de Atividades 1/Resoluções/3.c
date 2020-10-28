#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void determinacao(int aux);
int main()
{
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    int numero;

    printf("Insira qualquer n%cmero:\n", 250);
    scanf("%d", &numero);

    determinacao(numero);
}
void determinacao(int aux)
{
    setlocale(LC_ALL, "Portuguese");

    if (aux % 2 == 0)
    {
        printf("O n%cmero %d %c par\n", 250, aux, 233);
    } else{
        printf("O n%cmero %d %c impar\n", 250, aux, 233);
    }

    getchar();
}

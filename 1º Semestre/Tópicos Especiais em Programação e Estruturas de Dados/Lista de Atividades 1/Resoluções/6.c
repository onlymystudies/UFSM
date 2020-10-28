#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void limpa_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int primo(int aux);
int main() {
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    int numero;
    int resultado;

    printf("Insira um n%cmero positivo:\n", 250);
    scanf("%d", &numero);
    limpa_buffer();

    resultado = primo(numero);

    if (resultado == 0)
    {
        printf("%d %c um n%cmero primo\n", numero, 233, 250);
    } else {
        printf("%d não %c um n%cmero primo\n", numero, 233, 250);
    }

    getchar();
}
int primo(int aux)
{
    int i;
    int resultado = 0;

    for (i = 2; i <= aux / 2; i++) {
        if (aux % i == 0)
        {
            resultado++;
            break;
        }
    }

    return resultado;
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void limpa_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void conversao(int aux);
char binario[7];
int main()
{
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    int numero;
    int x;

    printf("Escreva qualquer n%cmero decimal:\n", 250);
    scanf("%d", &numero);
    limpa_buffer();

    printf("O valor bin%crio %c:\n", 225, 233);

    conversao(numero);

    for (x = 0; x < 7; x++)
    {
        printf("%d", binario[x]);
    }

    getchar();
}
void conversao(int aux)
{
    int i;

    while(aux > 0)
    {
        binario[i] = aux % 2;
        i++;
        aux = aux / 2;
    }
}

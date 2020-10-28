#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void limpa_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int maior(int aux);
int main()
{
    system("cls");
    setlocale(LC_ALL, "Portuguese");
    int elementos;
    int maiornum;

    printf("Insira o n%cmero de elementos a serem armazenados na matriz:\n", 250);
    scanf("%d", &elementos);
    limpa_buffer();

    maiornum = maior(elementos);

    printf("O maior elemento do vetor %c: %d\n", 233, maiornum);
    getchar();
}
int maior(int aux)
{
    int vetor[aux];
    int i;
    int maiornum = 0;

    printf("Insira %d elementos no vetor\n", aux);

    for (i = 1; i <= aux; i++)
    {
        printf("Elemento %d:\n", i);
        scanf("%d", &vetor[i]);
        if (vetor[i] < maiornum)
        {
            maiornum = vetor[i];
        }
        limpa_buffer();
    }

    return maiornum;
}

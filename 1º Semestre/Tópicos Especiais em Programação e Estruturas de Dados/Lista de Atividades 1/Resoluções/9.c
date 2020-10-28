#include <stdio.h>
#include <stdlib.h>

void limpa_buffer()
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}

int perfectnumbers(int aux, int aux2);
int main()
{
    system("cls");
    int minnumber, maxnumber;
    int result;

    printf("Insira o limite minimo de pesquisa de numeros perfeitos\n");
    scanf("%d", &minnumber);
    limpa_buffer();

    printf("Insira o limite maximo de pesquisa de numeros perfeitos\n");
    scanf("%d", &maxnumber);
    limpa_buffer();

    result = perfectnumbers(minnumber, maxnumber);
}
int perfectnumbers(int aux, int aux2)
{
    int total = 0;

    for (int y = aux; y <= aux2; y++)
    {
        for (int i = 1; i < y; i++)
        {
            if (y % i == 0)
            {
                total += i;
            }
        }
        if (total == y)
        {
            printf("\nTOTAL %d", total);
        }
        total = 0;
    }
    getchar();
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void limpa_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int perfect(int aux);
int Armstrong(int aux);
int main()
{
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    int number;
    int result, result2;

    printf("Insira qualquer n%cmero:\n", 250);
    scanf("%d", &number);
    limpa_buffer();

    result = perfect(number);
    result2 = Armstrong(number);

    if (result == 1)
    {
        printf("O %d %c um n%cmero perfeito.\n", number, 233, 250);
    } else {
        printf("O %d nao %c um n%cmero perfeito.\n", number, 233, 250);
    }

    if (result2 == 1)
    {
        printf("O %d %c um n%cmero Armstrong.\n", number, 233, 250);
    } else {
        printf("O %d nao %c um n%cmero Armstrong.\n", number, 233, 250);
    }
    getchar();
}
int perfect(int aux)
{
    int i;
    int total = 0;

    for (i = 0; i <= aux; i++)
    {
        if (aux % i == 0)
        {
            total += i;
        }
    }

    if (total == aux)
    {
        return 1;
    } else {
        return 0;
    }
}
int Armstrong(int aux)
{
    int total = 0;
    int i = 0;

    int *v = (int*) malloc(aux * sizeof(int));

    while(aux > 0)
    {
        v[i] = aux % 10;
        aux = (aux / 10);
        i++;
    }

    v = (int*) realloc(v, i * sizeof(int));

    for (int y = i; y <= 0; y++)
    {
        total += v[y]  * v[y] * v[y];
    }
    free(v);

    if (total == aux)
    {
        return 1;
    } else {
        return 0;
    }
}

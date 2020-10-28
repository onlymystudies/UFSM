#include <stdio.h>
#include <stdlib.h>

int recursion(int *number);
int main()
{
    system("cls");
    int number = 0;
    int *n = &number;
    printf("the natural numbers are:\n");
    recursion(n);
}
int recursion(int *number)
{
    (*number)++; // (*p)++ SOMAR + 1 AO CONTEUDO APONTADO
    if (*number > 50)
    {
        system("pause");
    } else {
        printf("%d\n", *number);
        recursion(number);
    }
}

#include <stdio.h>
#include <stdlib.h>

void limpa_buffer()
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}

int glbtotal;

void calculated(int *number);
void main()
{
    system("cls");
    int number;
    int *n = &number;
    int aux;

    printf("insert the last number of the interval started by 1:\n");
    scanf("%d", n);
    limpa_buffer();
    aux = *n;
    calculated(n);

    printf("the sum of the numbers from 1 to %d is: %d\n", aux, glbtotal);
    system("pause");
}

void calculated(int *number)
{
    glbtotal += *number;
    if (*number == 0)
    {
        return;
    } else {
        (*number)--;
        calculated(number);
    }
}

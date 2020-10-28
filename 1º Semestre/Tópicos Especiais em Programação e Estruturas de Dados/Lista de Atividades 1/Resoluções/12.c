#include <stdio.h>
#include <stdlib.h>

void limpa_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int total(int *f, int *s);
int main()
{
    system("cls");
    int first, second;
    int *f = &first;
    int *s = &second;

    printf("insert the first number:\n");
    scanf("%d", f);
    limpa_buffer();

    printf("insert the second number:\n");
    scanf("%d", s);
    limpa_buffer();

    printf("sum of the insert numbers: %d\n", total(f, s)); // PASSAR PONTEIRO PARA FUNÇÃO
    system("pause");
}
int total(int *f, int *s)
{
    int aux = *f + *s;
    return (aux);
}

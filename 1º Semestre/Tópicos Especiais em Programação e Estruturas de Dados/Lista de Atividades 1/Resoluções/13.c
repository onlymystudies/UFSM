#include <stdio.h>
#include <stdlib.h>

void limpa_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int totalref(int *f, int *s);
int main()
{
    system("cls");
    int first, second;

    printf("insert the first number:\n");
    scanf("%d", &first);
    limpa_buffer();

    printf("insert the second number:\n");
    scanf("%d", &second);
    limpa_buffer();

    printf("the sum of %d and %d is: %d\n", first, second, totalref(&first, &second)); // PASSAR PONTEIRO PARA FUNÇÃO (REFERENCIA)
    system("pause");
}
int totalref(int *f, int *s)
{
    int aux = *f + *s;
    return (aux);
}

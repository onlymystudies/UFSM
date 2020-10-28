#include <stdio.h>
#include <stdlib.h>

void limpa_buffer()
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}

int max(int *f, int *s);
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

    if (max(f, s) > 0)
    {
        printf("%d is the max number\n", *f);
    } else {
        printf("%d is the max number\n", *s);
    }
    system("pause");
}
int max(int *f, int *s)
{
    if (*f > *s)
    {
        return 1;
    } else {
        return 0;
    }
}

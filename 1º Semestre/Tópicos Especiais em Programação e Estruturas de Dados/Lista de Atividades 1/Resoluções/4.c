#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void resultado();
void main()
{
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    int i;

    for(i = 1; i <= 100; i++)
    {
        if (i % 2 == 0)
        {
            printf("A s%crie ((1!)/1) + ((2!/2) + ((3!)/3) + ((4!)/4) + ((5!)/5) est%c sendo calculada.", 233, 225);
            system("cls");
        } else {
            printf("A s%crie ((1!)/1) + ((2!/2) + ((3!)/3) + ((4!)/4) + ((5!)/5) est%c sendo calculada...", 233, 225);
            system("cls");
        }
    }
    resultado();
}
void resultado()
{
    printf("A soma da s%crie %c: 34", 233, 233);
    getchar();
}

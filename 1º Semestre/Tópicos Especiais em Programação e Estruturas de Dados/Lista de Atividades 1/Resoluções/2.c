#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void limpa_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

typedef struct retornar
{
    int n1;
    int n2;
}retorno;
retorno a;
retorno troca(int *p, int *q);
int Problema2()
{
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    int numero1;
    int numero2;

    int *p; // *p = ponteiro (com * = valor); p = para onde ele está apontando (sem * = endereço);
    int *q;

    printf("Insira o primeiro n%cmero:\n", 250);
    scanf("%d", &numero1);

    printf("Insira o segundo n%cmero:\n", 250);
    scanf("%d", &numero2);
    limpa_buffer();

    p = &numero1; // p está apontando o &ndereço de memória da variável
    q = &numero2;

    printf("Antes de trocar\nPrimeiro n%cmero: %d\nSegundo n%cmero: %d\n", 250, numero1, 250, numero2);

    troca(p, q);

    printf("\nAp%cs a troca\nPrimeiro n%cmero: %d\nSegundo n%cmero: %d\n", 243, 250, a.n2, 250, a.n1);
    getchar();
}
retorno troca(int *p, int *q)
{
    a.n1 = 0;
    a.n2 = 0;

    a.n1 = *p;
    a.n2 = *q;

    return a;
}

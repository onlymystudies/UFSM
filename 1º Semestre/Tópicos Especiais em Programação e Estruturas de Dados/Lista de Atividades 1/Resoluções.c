#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void limpa_buffer()
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Problema 16
Escreva um programa em C para calcular a soma dos números de 1 a n usando recursão. */
int glbtotal;
void calculated(int *number);
int Problema16()
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

/* Problema 15
Escreva um programa em C para imprimir os primeiros 50 números naturais usando recursão. */
int recursion(int *number);
int Problema15()
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

/* Problema 14
Escreva um programa em C para encontrar o número máximo entre dois números usando um ponteiro. */
int max(int *f, int *s);
int Problema14()
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

/* Problema 13
Escreva um programa em C para adicionar números usando chamada por referência. */
int totalref(int *f, int *s);
int Problema13()
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

/* Problema 12
Escreva um programa em C para adicionar dois números usando ponteiros. */
int total(int *f, int *s);
int Problema12()
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

/* Problema 11
Escreva um programa em C para descobrir o máximo e o mínimo de alguns valores usando uma função
que retornará um array. */
typedef struct st
{
    int *small_big; // Poderia também ser um vetor sem tamanho v[] (Clion nao permite)
}st;
st vector;
st data(int value, int *v);
int Problema11()
{
    system("cls");
    int value = 0;
    int *v = (int*) malloc(64 * sizeof(int)); // cast (int*) considera malloc como inteiro
    vector.small_big = (int*) malloc(2 * sizeof(int));

    printf("Numero de valores que voce deseja inserir\n");
    scanf("%d", &value);
    limpa_buffer();

    printf("%d valores de entrada\n", value);
    for (int i = 1; i <= value; i++)
    {
        printf("%d:", i);
        scanf("%d", &v[i]);
        limpa_buffer();
    }
    v = (int*) realloc(v, (value + 1) * sizeof(int));

    data(value, v);

    printf("Numero de valores que voce deseja inseri: %d\n", value);
    printf("O valor minimo: %d\n", vector.small_big[1]);
    printf("O valor maximo: %d\n", vector.small_big[0]);
    free(v);
    free(vector.small_big);
    getchar(); // NUNCA MAIS USAR GETCHAR PARA PAUSAR (ele usa sujeira do buffer)
}
st data(int value, int *v)
{
    int small, big;

    for (int y = 1; y <= value; y++)
    {
        if (y == 1)
        {
            vector.small_big[1] = v[y];
            vector.small_big[0] = v[y];
        }
        if (v[y] > vector.small_big[0])
        {
            vector.small_big[0] = v[y];
        }
        if (v[y] < vector.small_big[1])
        {
            vector.small_big[1] = v[y];
        }
    }
    return vector;
}

/* Problema 10
Escreva um programa em C para verificar se duas cadeias de caracteres fornecidas são um anagrama. */
int checkAnagram(char *str1, char *str2);
int Problema10()
{
    system("cls");
    char str1[100], str2[100];
    printf("\n\n Function : whether two given strings are anagram :\n");
    printf("\n\n Example : pears and  spare, stone and tones :\n");
    printf("-------------------------------------------------------\n");
    printf(" Input the  first String : ");
    fgets(str1, sizeof str1, stdin);
    printf(" Input the  second String : ");
    fgets(str2, sizeof str2, stdin);

    if(checkAnagram(str1, str2) == 1)
    {
        str1[strlen(str1)-1] = '\0';
        str2[strlen(str2)-1] = '\0';
        printf(" %s and %s are Anagram.\n\n",str1,str2);
    }
    else
    {
        str1[strlen(str1)-1] = '\0';
        str2[strlen(str2)-1] = '\0';
        printf(" %s and %s are not Anagram.\n\n",str1,str2);
    }
    getchar();
}
int checkAnagram(char *str1, char *str2)
{
    int str1ChrCtr[256] = {0}, str2ChrCtr[256] = {0};
    int ctr;
    /* check the length of equality of Two Strings */
    if(strlen(str1) != strlen(str2))
    {
        return 0;
    }
    //count frequency of characters in str1
    for(ctr = 0; str1[ctr] != '\0'; ctr++)
    {
        str1ChrCtr[str1[ctr]]++;
    }
    //count frequency of characters in str2
    for(ctr = 0; str2[ctr] != '\0'; ctr++)
    {
        str2ChrCtr[str2[ctr]]++;
    }
    //compare character counts of both strings
    for(ctr = 0; ctr < 256; ctr++)
    {
        if(str1ChrCtr[ctr] != str2ChrCtr[ctr])
            return 0;
    }
    return 1;
}

/* Problema 9
Escreva um programa em C para imprimir todos os números perfeitos em um determinado intervalo usando
uma função. */
int perfectnumbers(int aux, int aux2);
int Problema9()
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

/* Problema 8
Escreva um programa em C para verificar números perfeitos e Armstrong usando funções. */
int perfect(int aux);
int Armstrong(int aux);
int Problema8()
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
    int n = 0;
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

/* Problema 7
Escreva um programa em C para obter o maior elemento de uma matriz usando uma função. */
int maior(int aux);
int Problema7()
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

/* Problema 6
Escreva um programa em C para verificar se um número é primo ou não usando a função */
int primo(int aux);
int Problema6() {
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    int numero;
    int resultado;

    printf("Insira um n%cmero positivo:\n", 250);
    scanf("%d", &numero);
    limpa_buffer();

    resultado = primo(numero);

    if (resultado == 0)
    {
        printf("%d %c um n%cmero primo\n", numero, 233, 250);
    } else {
        printf("%d não %c um n%cmero primo\n", numero, 233, 250);
    }

    getchar();
}
int primo(int aux)
{
    int i;
    int resultado = 0;

    for (i = 2; i <= aux / 2; i++) {
        if (aux % i == 0)
        {
            resultado++;
            break;
        }
    }

    return resultado;
}

/* Problema 5
Escreva um programa em C para converter o número decimal em número binário usando uma função. */
void conversao(int aux);
char binario[7];
int Problema5()
{
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    int numero;
    int x;

    printf("Escreva qualquer n%cmero decimal:\n", 250);
    scanf("%d", &numero);
    limpa_buffer();

    printf("O valor bin%crio %c:\n", 225, 233);

    conversao(numero);

    for (x = 0; x < 7; x++)
    {
        printf("%d", binario[x]);
    }

    getchar();
}
void conversao(int aux)
{
    int i;

    while(aux > 0)
    {
        binario[i] = aux % 2;
        i++;
        aux = aux / 2;
    }
}

/* Problema 4
Escreva um programa em C para encontrar a soma da série 1! / 1 + 2! / 2 + 3! / 3 + 4! / 4 + 5! / 5 usando
uma função. */
void resultado();
void Problema4()
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
    setlocale(LC_ALL, "Portuguese");
    printf("A soma da s%crie %c: 34", 233, 233);
    getchar();
}

/* Problema 3
Escreva um programa em C para verificar se um determinado número é par ou ímpar usando uma função. */
void determinacao(int aux);
int Problema3()
{
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    int numero;

    printf("Insira qualquer n%cmero:\n", 250);
    scanf("%d", &numero);

    determinacao(numero);
}
void determinacao(int aux)
{
    setlocale(LC_ALL, "Portuguese");

    if (aux % 2 == 0)
    {
        printf("O n%cmero %d %c par\n", 250, aux, 233);
    } else{
        printf("O n%cmero %d %c impar\n", 250, aux, 233);
    }

    getchar();
}

/* Problema 2
Escreva um programa em C para trocar dois números usando uma função. Considere “void troca(int *p, int
*q)”. */
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

/* Problema 1
Escreva um programa em C para encontrar o quadrado de um número qualquer usando uma função. */
int quadrado(int aux);
int Problema1()
{
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    typedef struct variaveis_problema1
    {
        int numero;
        int quadrado;
    }vars;
    vars variavel;

    printf("Insira qualquer n%cmero para o quadrado:\n", 250);
    scanf("%d", &variavel.numero);
    limpa_buffer();

    variavel.quadrado = quadrado(variavel.numero);

    printf("O quadrado de %d %c: %d\n", variavel.numero, 233, variavel.quadrado);

    getchar();
}
int quadrado(int aux)
{
    return aux*aux;
}

/* Activities lobby */
int main()
{
    int menu;

    printf("=======================================================");
    printf("\n   Special Topics in Programming and Data Structures\n");
    printf("\t\t    Week 1 List 1\n");
    printf("=======================================================");
    printf ("\n\t [1]  Activity 1  [2]  Activity 2 \n");
    printf ("\t [3]  Activity 3  [4]  Activity 4 \n");
    printf ("\t [5]  Activity 5  [6]  Activity 6 \n");
    printf ("\t [7]  Activity 7  [8]  Activity 8 \n");
    printf ("\t [9]  Activity 9  [10] Activity 10 \n");
    printf ("\t [11] Activity 11 [12] Activity 12 \n");
    printf ("\t [13] Activity 13 [14] Activity 14 \n");
    printf ("\t [15] Activity 15 [16] Activity 16 \n");
    printf ("\t [0] Exit\n\n");
    scanf ("%d", &menu);
    limpa_buffer();
    while(menu != 16)
    {
        switch(menu)
        {
            case 0:
                exit(0);
            case 1:
                Problema1();
                break;
            case 2:
                Problema2();
                break;
            case 3:
                Problema3();
                break;
            case 4:
                Problema4();
                break;
            case 5:
                Problema5();
                break;
            case 6:
                Problema6();
                break;
            case 7:
                Problema7();
                break;
            case 8:
                Problema8();
                break;
            case 9:
                Problema9();
                break;
            case 10:
                Problema10();
                break;
            case 11:
                Problema11();
                break;
            case 12:
                Problema12();
                break;
            case 13:
                Problema13();
                break;
            case 14:
                Problema14();
                break;
            case 15:
                Problema15();
                break;
            case 16:
                Problema16();
                break;
            default:
                printf("option doesn't exist");
        }
        while(menu != 0);
    }
}

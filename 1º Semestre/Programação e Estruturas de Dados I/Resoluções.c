/* Unidade 6
1) Escrever um algoritmo que lê um vetor qualquer de 10 posições e imprime todos os valores
iguais à 10, e suas respectivas posições neste vetor. */
#include <stdio.h>
#include <stdlib.h> // funcoes system
void limpa_buffer()
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF){}
    return;
}
main()
{
    typedef struct a
    {
        int i;
        int y;
    }aux;
    aux a;
    int vet[10];
    for (a.i = 0; a.i < 10; a.i++)
    {
        printf("Possicao %d\n", a.i+1);
        scanf("%d", &vet[a.i]);
    }
    limpa_buffer();
    system("cls");
    for (a.y = 0; a.y < 10; a.y++)
    {
        if (vet[a.y] == 10)
        {
            printf("Posicao %d igual a 10\n", a.y+1);
        }
    }
    system("pause");
}

/* 2) Escrever um algoritmo que lê um vetor V, de 15 posições, e conte quantos valores de V são
negativos. */
#include <stdio.h>
#include <locale.h>
main()
{
    typedef struct a
    {
        int i;
    }aux;
    aux a;
    int vetorV[15], contagem;
    for (a.i = 0; a.i < 15; a.i++)
    {
        printf("Valor %d do vetor\n", a.i+1);
        scanf("%d", &vetorV[a.i]);
        if (vetorV[a.i] < 0)
        {
            contagem = contagem + 1;
        }
    }
    printf("%d sao negativos\n", contagem);
    system("pause");
}

/* 3) Escrever um algoritmo que lê um vetor X de 20 posições. Substitua a seguir todos os valores
nulos (iguais a zero) de X por 1. No final, imprima o vetor X modificado */
#include <stdio.h>
#include <locale.h>
main()
{
    typedef struct a
    {
        int i;
        int y;
    }aux;
    aux a;
    int vetorX[20];
    for (a.i = 0; a.i < 20; a.i++)
    {
        printf("Valor %d do vetor\n", a.i+1);
        scanf("%d", &vetorX[a.i]);
        if (vetorX[a.i] == 0)
        {
            vetorX[a.i] = 1;
        }
    }
    printf("Vetor modificado\n");
    for (a.y = 0; a.y < 20; a.y++)
    {
        printf("%d\n", vetorX[a.y]);
    }
    system("pause");
}

/* 4) Escrever um algoritmo que lê um vetor C de 50 posições. Encontrar o maior e o menor
elemento do vetor C e imprimi-los, juntamente com suas posições no vetor */
#include <stdio.h>
#include <locale.h>
main()
{
    typedef struct a
    {
        int i;
        int maior;
        int menor;
        int posicaomenor;
        int posicaomaior;
    }aux;
    aux a;
    int vetorN[50];
    for (a.i = 0; a.i < 50; a.i++)
    {
        printf("Valor %d do vetor\n", a.i+1);
        scanf("%d", &vetorN[a.i]);
        if (a.i == 0)
        {
            a.maior = vetorN[a.i];
            a.menor = vetorN[a.i];
        }
        if (vetorN[a.i] > a.maior)
        {
            a.maior = vetorN[a.i];
            a.posicaomaior = a.i;
        }
        if (vetorN[a.i] < a.menor)
        {
            a.menor = vetorN[a.i];
            a.posicaomenor = a.i;
        }
    }
    printf("Maior valor %d esta na posicao %d\n", a.maior,
           a.posicaomaior+1);
    printf("Manor valor %d esta na posicao %d\n", a.menor,
           a.posicaomenor+1);
    system("pause");
}

/* 5) Escrever um algoritmo que lê um vetor N de 20 posições. Trocar o 1o elemento com o
último, o 2o com o penúltimo, o 3º com o antepenúltimo e assim sucessivamente, até trocar o
10o elemento com o 11o. Escrever o vetor N modificado. (Observação: as trocas devem ser
realizadas no próprio vetor, não utilizar vetores auxiliares) */
#include <stdio.h>
#include <locale.h>
main()
{
    typedef struct a
    {
        int i;
        int y;
        int j;
    }aux;
    aux a;
    a.i = 20;
    int vetorN[20] =
            {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    for (a.y = 0; a.y < 20; a.y++)
    {
        vetorN[a.i] = vetorN[a.y];
        a.i--;
    }
    printf("Vetor modificado\n");
    for (a.j = 0; a.j < 20; a.j++)
    {
        printf("%d\n", vetorN[a.j]);
    }
    system("pause");
}

/* 6) Escrever um algoritmo que leia 10 nomes de clientes e 10 saldos bancários e imprima os
nomes dos clientes que tiverem saldo inferior a R$100,00. São necessários dois vetores. */
#include <stdio.h>
#include <locale.h>
void limpa_buffer()
{
    int c = 0;
    while((c = getchar()) != '\n' && c != EOF){}
    return;
}
main()
{
    typedef struct a
    {
        int i;
        int y;
    }aux;
    aux a;
    char nome[10][128];
    int salario[10];
    for (a.i = 0; a.i < 10; a.i++)
    {
        printf("Nome do cliente %d:\n", a.i+1);
        scanf("%s", &nome[a.i]);
        limpa_buffer();
        printf("Saldo do cliente %d:\n", a.i+1);
        scanf("%d", &salario[a.i]);
    }

    system("cls");
    for (a.y = 0; a.y < 10; a.y++)
    {
        if (salario[a.y] < 100)
        {
            printf("Cliente %s saldo inferior a R$ 100,00\n",
                   nome[a.y]);
        }
    }
    system("pause");
}

/* 7) Escrever um algoritmo que leia um vetor S(25) e compacte este vetor, retirando dele todos
os valores repetidos. Imprimir o vetor antes de ser compactado e após a compactação */
#include <stdio.h>
#include <locale.h>
main()
{
    typedef struct a
    {
        int i;
        int y;
        int x;
    }aux;
    aux a;
    int vetorS[25];
    for (a.i = 0; a.i < 5; a.i++)
    {
        printf("Valor vetor %d\n", a.i+1);
        scanf("%d", &vetorS[a.i]);
    }
    system("cls");
    printf("Vetor antes da compactacao:\n");
    for (a.y = 0; a.y < 5; a.y++)
    {
        printf("%d", vetorS[a.y]);
    }
    if (vetorS[2] == vetorS[1])
    {
        vetorS[2] = 0;
    }
    if ((vetorS[3] == vetorS[2]) || (vetorS[3] == vetorS[1]))
    {
        vetorS[3] = 0;
    }
    if ((vetorS[4] == vetorS[3]) || (vetorS[4] == vetorS[2]) ||
        (vetorS[4] == vetorS[1]))
    {
        vetorS[4] = 0;
    }
    if ((vetorS[5] == vetorS[4]) || (vetorS[5] == vetorS[3]) ||
        (vetorS[5] == vetorS[2]) || (vetorS[5] == vetorS[1]))
    {
        vetorS[5] = 0;
    }
    printf("\nVetor depois da compactacao:\n");
    for (a.x = 0; a.x < 5; a.x++)
    {
        if (vetorS[a.x] != 0)
        {
            printf("%d\n", vetorS[a.x]);
        }
    }
    system("pause");

/* 8) Escrever um algoritmo que leia nome e nota de um aluno para uma turma de 20 alunos. Ao
final, imprima a média das notas da turma, o nome do aluno que obteve a nota mais alta e o
nome do aluno que obteve a nota mais baixa. São necessários dois vetores para realizar este
exercício. */
#include <stdio.h>
#include <locale.h>
#include <string.h>
    void limpa_buffer()
    {
        int c = 0;
        while((c = getchar()) != '\n' && c != EOF){}
        return;
    }
    main() {
        typedef struct a {
            int i;
            int maior;
            int menor;
            int soma;
            char nomemenor[64];
            char nomemaior[64];
        } aux;
        aux a;
        char nome[20][64];
        int nota[20];
        for (a.i = 0; a.i < 5; a.i++)
        {
            printf("Nome do aluno numero %d\n", a.i+1);
            scanf("%s", &nome[a.i]);
            limpa_buffer();
            printf("Nota do aluno numero %d\n", a.i+1);
            scanf("%d", &nota[a.i]);
            limpa_buffer();
            if (a.i == 0) // JBURNLEY13 VIU O QUE MEUS OLHOS NAO VEEM (a
                atribuição tava errada)
            {
                a.maior = nota[a.i];
                a.menor = nota[a.i];
            }
            if (nota[a.i] > a.maior)
            {
                a.maior = nota[a.i];
                strcpy(a.nomemaior, nome[a.i]);
            }
            if (nota[a.i] < a.menor)
            {
                a.menor = nota[a.i];
                strcpy(a.nomemenor, nome[a.i]);
            }

            a.soma = a.soma + nota[a.i];
        }
        system("cls");
        printf("Media dos alunos: %d\n", a.soma/5);
        printf("Aluno com maior nota: %s\n", a.nomemaior);
        printf("Nota: %d\n", a.maior);
        printf("Aluno com menor nota: %s\n", a.nomemenor);
        printf("Nota: %d\n", a.menor);
        system("pause");
    }

/* 9) Escrever um algoritmo que leia 100 números inteiros, distribua os números lidos em dois
vetores, sendo um para números pares e outro para números ímpares. No final do algoritmo,
escreva os vetores. */
#include <stdio.h>
#include <locale.h>
    main()
    {
        typedef struct a
        {
            int i;
            int y;
            int j;
            int num;
        }aux;
        aux a;
        int vetPar[5];
        int vetImpar[5];
        for (a.i = 0; a.i < 5; a.i++)
        {
            printf("Numeros %d:\n", a.i+1);
            scanf("%d", &a.num);
            if (a.num % 2 == 0) // FINDOX8 SALVOU O EXERCICIO (atribuição
                de notas depois de dar entrada obvio)
            {
                vetPar[a.i] = a.num;
                vetImpar[a.i] = 0;
            } else {
                vetImpar[a.i] = a.num;
                vetPar[a.i] = 0;
            }
        }
        system("cls");
        printf("Vetor Par\n");
        for (a.y = 0; a.y < 5; a.y++)
        {
            if (vetPar[a.y] != 0)
            {
                printf("%d\n", vetPar[a.y]);
            }
        }
        printf("Vetor Impar\n");
        for (a.j = 0; a.j < 5; a.j++)
        {
            if (vetImpar[a.j] != 0)
            {
                printf("%d\n", vetImpar[a.j]);
            }
        }
        system("pause");
    }

/* 10) (Adaptado de LOPES; GARCIA, 2002) Escrever um algoritmo que leia dois vetores de 25
posições cada um. A seguir, criar um terceiro vetor, intercalando os dados dos dois vetores.
Este terceiro vetor deve ser impresso no final. Exemplo: */
#include <stdio.h>
#include <locale.h>
    main()
    {
        typedef struct a {
            int i;
            int y;
        } findox8;
        findox8 a;
        int vetor1[5] = {1,2,3,4,5};
        int vetor2[5] = {6,7,8,9,10};
        int vetor3[10];
        for (a.i = 0; a.i < 5; a.i++) // "INS" muda o tracinho
        {
            if (vetor1[a.i] % 2 == 0)
            {
                vetor3[a.i] = vetor2[a.i];
            }
            else{
                vetor3[a.i] = vetor1[a.i];
            }
        }
        printf("Vetor final\n");
        for (a.y = 0; a.y < 5; a.y++)
        {
            printf("%d\n", vetor3[a.y]);
        }
        system("pause");
    }
/* FIM DA LIVE 25/06/2020
   TEMPO DE LIVE: 5:30:20
   HORÁRIO DE BRASÍLIA 21:32 */

/* 11) Escrever um algoritmo que leia 2 vetores X(10) e Y(10) e os escreva. Criar, a seguir: – um
vetor contendo a união de X com Y (todos os elementos de X e os elementos de Y que não
estejam em X); – um vetor contendo a diferença entre X e Y (todos os elementos de X que não
existam em Y); – um vetor contendo o produto entre X e Y (multiplicação de cada elemento de
X com o elemento de mesma posição em Y); – um vetor contendo a intersecção entre X e Y
(valores que aparecem nos dois vetores). */
#include <stdio.h>
#include <locale.h>
    void limpa_buffer()
    {
        int c = 0;
        while ((c = getchar()) != '\n' && c != EOF){}
        return;
    }
    main()
    {
        typedef struct a
        {
            int i;
            int y;
            int x;
            int j;
            int t;
            int l;
            int h;
            int a;
            int b;
            int c;
            int d;
            int f;
        }aux;
        aux a;
        int vetX[5];
        int vetY[5];
        int vetU[10];
        int vetM[5];
        int vetI[5];
        for (a.i = 0; a.i < 5; a.i++)
        {
            printf("Valor %d vetor X\n", a.i+1);
            scanf("%d", &vetX[a.i]);
            limpa_buffer();
        }
        for (a.y = 0; a.y < 5; a.y++)
        {
            printf("Valor %d vetor Y\n", a.y+1);
            scanf("%d", &vetY[a.y]);
        }
        system("cls");
        printf("Vetor X\n");
        for (a.l = 0; a.l < 5; a.l++)
        {
            printf("%d\n", vetX[a.l]);
        }
        printf("Vetor Y\n");
        for (a.h = 0; a.h < 5; a.h++)
        {
            printf("%d\n", vetY[a.h]);
        }
        for (a.x = 0; a.x < 5; a.x++)
        {
            vetU[a.x] = vetX[a.x];
        }
        a.t = 5;
        for (a.j = 0; a.j < 5; a.j++)
        {
            if (vetY[a.j] != vetX[1])
            {
                if (vetY[a.j] != vetX[2])
                {
                    if (vetY[a.j] != vetX[3])
                    {
                        if (vetY[a.j] != vetX[4])
                        {
                            if (vetY[a.j] != vetX[5])
                            {
                                vetU[a.t] = vetY[a.j];
                                a.t++;
                            }
                        }
                    }
                }
            }
        }
        printf("Vetor Unido\n");
        for (a.c = 0; a.c < 10; a.c++)
        {
            printf("%d\n", vetU[a.c]);
        }
        for (a.a = 0; a.a < 5; a.a++)
        {
            vetM[a.a] = vetX[a.a] * vetY[a.a];
        }
        printf("Vetor Multiplicado\n");
        for (a.d = 0; a.d < 5; a.d++)
        {
            printf("%d\n", vetM[a.d]);
        }
        for (a.b = 0; a.b < 5; a.b++)
        {
            if (vetX[a.b] % 2 == 0)
            {
                vetI[a.b] = vetY[a.b];
            } else {
                vetI[a.b] = vetX[a.b];
            }
        }
        printf("Vetor Interscecao\n");
        for (a.f = 0; a.f < 5; a.f++)
        {
            printf("%d\n", vetI[a.f]);
        }
        system("pause");
    }

/* 12) Escrever um algoritmo que leia um vetor com 20 valores. Após a leitura calcular e escrever
a soma de todos os valores do vetor */
#include <stdio.h>
#include <locale.h>
    main()
    {
        typedef struct a
        {
            int i;
            int y;
            int soma;
        }aux;
        aux a;
        int vet[5];
        for (a.i = 0; a.i < 5; a.i++)
        {
            printf("valor %d no vetor\n", a.i+1);
            scanf("%d", &vet[a.i]);
        }
        system("cls");
        for (a.y = 0; a.y < 5; a.y++)
        {
            a.soma = a.soma + vet[a.y];
        }
        printf("Soma de todos os valores do vetor: %d\n", a.soma);
        system("pause");
    }

/* 13) Escrever um algoritmo que permita o gerenciamento de reservas numa casa de
espetáculos. Existem 30 mesas, cada uma com 5 lugares disponíveis. O algoritmo deve permitir
que o usuário escolha a mesa desejada (de 1 a 30) e indique a quantidade de lugares 
necessários. O algoritmo deve informar se a reserva foi ou não realizada. O algoritmo deve ser
encerrado quando o usuário digitar o número da mesa igual a zero (Adaptado de loPEs; gArCiA, 2002). */
#include <stdio.h>
#include <locale.h>
    void limpa_buffer()
    {
        int c = 0;
        while((c = getchar()) != '\n' && c != EOF){}
        return;
    }
    main() {
        typedef struct a {
            int i;
            int lugares;
        } aux;
        aux a;
        int vetmesas[30];
        for (a.i = 0; a.i < 30; a.i++)
        {
            printf("Escolha a mesa desejadaa\n");
            scanf("%d", &vetmesas[a.i]);
            limpa_buffer();
            if (vetmesas[a.i] == 0)
            {
                exit(0);
            }
            printf("Numero de lugares\n");
            scanf("%d", &a.lugares);
            printf("Rserva realizada com sucesso\n");
            printf("Mesa %d, %d lugares.\n", vetmesas[a.i], a.lugares);
            system("pause");
        }
    }

/* 14) Em um concurso público foram aprovados 50 candidatos. Escrever um algoritmo que
armazene os nomes dos candidatos aprovados em um vetor e, num segundo vetor, a nota
obtida no concurso. Ordenar os vetores de acordo com a nota obtida (em ordem decrescente).
Escrever os dois vetores no final, apresentando os nomes dos candidatos na ordem de
chamada para ocuparem as vagas disponibilizadas no concurso. */
#include <stdio.h>
#include <locale.h>
#include <string.h>
    void limpa_buffer()
    {
        int c = 0;
        while((c = getchar()) != '\n' && c != EOF){}
        return;
    }
    main() {
        typedef struct a {
            int i;
            int y;
            int x;
            int n;
            int aux;
            char aux2[64];
            int lugares;
        } aux;
        aux a;
        char nome[5][64];
        int nota[5];
        for (a.i = 0; a.i < 5; a.i++)
        {
            printf("Nome numero %d:\n", a.i+1);
            scanf("%s", &nome[a.i]);
            limpa_buffer();
            printf("Nota numero %d:\n", a.i+1);
            scanf("%d", &nota[a.i]);
        }
        for (a.y = 0; a.y < 5; a.y++)
        {
            for (a.x = a.y+1; a.x < 5; a.x++)
            {
                if (nota[a.y] < nota[a.x])
                {
                    a.aux = nota[a.y];
                    nota[a.y] = nota[a.x];
                    nota[a.x] = a.aux;
                    strcpy(a.aux2, nome[a.y]);
                    strcpy(nome[a.y], nome[a.x]);
                    strcpy(nome[a.x], a.aux2);
                }
            }
        }
        for (a.n = 0; a.n < 4; a.n++)
        {
            printf("%d lugar %s %d\n", a.n+1, nome[a.n], nota[a.n]);
        }
        system("pause");
    }
    
/* FIM DA LIVE 27/06/2020
TEMPO DE LIVE: 2:14:43
HORÁRIO DE BRASÍLIA 03:14 */

/* 15) Escrever um algoritmo que realize a manutenção de um controle de estoque de uma loja
que possui 10 tipos de produtos em estoque. O controle de estoque utilizará três vetores: 1
vetor para armazenar os códigos dos produtos, 1 vetor para armazenar a descrição (nome) dos
produtos e 1 vetor para armazenar a quantidade atual de cada produto. O algoritmo deve
apresentar ao usuário as seguintes opções: */
#include <stdio.h>
#include <locale.h>
    struct global
    {
        int vetCod[5];
        char vetNome[5][64];
        int vetQuant[5];
    }global;
    void limpa_buffer()
    {
        int c = 0;
        while((c = getchar()) != '\n' && c != EOF){}
        return;
    }
    void cadastro_de_entrada()
    {
        system("cls");
        struct a
        {
            int i;
        }aux;
        for (aux.i = 0; aux.i < 5; aux.i++)
        {
            printf("Codigo do produto\n");
            scanf("%d", &global.vetCod[aux.i]);
            limpa_buffer();
            printf("Nome do produto\n");
            scanf("%c", &global.vetNome[aux.i]);
            limpa_buffer();
            printf("Quantidade atual");
            scanf("%d", &global.vetQuant[aux.i]);
            limpa_buffer();
            printf("Produto %c cadastrado com sucesso",
                   global.vetNome[aux.i]);
            return;
        }
    }
    void entrada_de_novas_quantidades()
    {
        system("cls");
        struct a
        {
            int a;
            int i;
            int quant;
        }aux;
        printf("Codigo do produto\n");
        scanf("%d", &aux.a);
        limpa_buffer();
        for (aux.i = 0; aux.i < 5; aux.i++)
        {
            if (aux.a == global.vetCod[aux.i])
            {
                printf("Produto cadastrado\n");
                printf("Quatidade %d\n", global.vetQuant[aux.i]);
                printf("Quatidade a ser acrescentada\n");
                scanf("%d", &aux.quant);
                global.vetQuant[aux.i] = global.vetQuant[aux.i] +
                                         aux.quant;
            } else {
                printf("Produto nao cadastrado\n");
                return;
            }
        }
    }
    void saida_de_produtos()
    {
        system("cls");
        struct a
        {
            int a;
            int i;
            int quant;
        }aux;
        printf("Codigo do produto\n");
        scanf("%d", &aux.a);
        limpa_buffer();
        for (aux.i = 0; aux.i < 5; aux.i++)
        {
            if (aux.a == global.vetCod[aux.i]) {
                printf("Produto cadastrado\n");
                printf("Quatidade %d\n", global.vetQuant[aux.i]);
                printf("Quatidade a ser subtraida\n");
                scanf("%d", &aux.quant);
                if (aux.quant >= global.vetQuant[aux.i]) {
                    global.vetQuant[aux.i] = global.vetQuant[aux.i] -
                                             aux.quant;
                } else {
                    printf("Quantidade insuficiente no estoque\n");
                }
            } else {
                printf("Produto nao cadastrado\n");
                return;
            }
        }
    }
    void relatorio()
    {
        struct a
        {
            int i;
        }aux;
        printf("Relatorio dos produtos no estoque\n");
        for (aux.i = 0; aux.i < 5; aux.i++)
        {
            if ((global.vetCod[aux.i] != 0) && (global.vetQuant[aux.i] !=
                                                0))
            {
                printf("Codigo %c\nNome %c\nQuantidade %d",
                       global.vetCod[aux.i], global.vetNome[aux.i], global.vetQuant[aux.i]);
            }
        }
    }
    main()
    {
        struct a
        {
            int menu;
        }aux;
        printf("[1] Entrada com dados no estoque\n");
        printf("[2] Entrada de produtos no estoque\n");
        printf("[3] Saida de produtos no estoque\n");
        printf("[4] Relatorio\n");
        printf("[5] Sair\n");
        scanf("%d", &aux.menu);
        limpa_buffer();
        while(aux.menu != 5)
        {
            switch(aux.menu)
            {
                case 1:
                    cadastro_de_entrada();
                    break;
                case 2:
                    entrada_de_novas_quantidades();
                    break;
                case 3:
                    saida_de_produtos();
                    break;
                case 4:
                    relatorio();
                    break;
                case 5:
                    exit(0);
                default:
                    system("cls");
                    printf("Opcao inexistente\n");
            }
            while (aux.menu != 5);
        }
    }

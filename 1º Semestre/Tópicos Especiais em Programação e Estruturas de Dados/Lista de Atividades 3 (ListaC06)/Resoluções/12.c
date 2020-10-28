#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

typedef struct jogador1{
    char naipe[10];
    int valor;
}jogador1;
jogador1 jgd1[5];

typedef struct jogador2{
    char naipe[10];
    int valor;
}jogador2;
jogador2 jgd2[5];

char naipe1(int i) {
    int aux = rand() % 3;

    char naipe1[] = {"copas"};
    char naipe2[] = {"espadas"};
    char naipe3[] = {"paus"};
    char naipe4[] = {"ouro"};

    if (aux == 0) {
        strcpy(jgd1[i].naipe, naipe1);
    }
    if (aux == 1) {
        strcpy(jgd1[i].naipe, naipe2);
    }
    if (aux == 2) {
        strcpy(jgd1[i].naipe, naipe3);
    }
    if (aux == 3) {
        strcpy(jgd1[i].naipe, naipe4);
    }
}

char naipe2(int i) {
    int aux = rand() % 3;

    char naipe1[] = {"copas"};
    char naipe2[] = {"espadas"};
    char naipe3[] = {"paus"};
    char naipe4[] = {"ouro"};

    if (aux == 0) {
        strcpy(jgd2[i].naipe, naipe1);
    }
    if (aux == 1) {
        strcpy(jgd2[i].naipe, naipe2);
    }
    if (aux == 2) {
        strcpy(jgd2[i].naipe, naipe3);
    }
    if (aux == 3) {
        strcpy(jgd2[i].naipe, naipe4);
    }
}

void main() {
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            jgd1[i].valor = rand() % 13;
            naipe1(i);
        } else {
            jgd2[i].valor = rand() % 13;
            naipe2(i);
        }
    }

    puts("jogador 1:");
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            puts("------------");
            printf("Carta %d\n", i + 1);
            printf("Naipe %s\n", jgd1[i].naipe);
            printf("Valor %d\n", jgd1[i].valor);
        }
    }
    puts("============================");
    puts("jogador 2:");
    for (int y = 0; y < 10; ++y) {
        if (y % 2 != 0) {
            puts("------------");
            printf("Carta %d\n", y + 1);
            printf("Naipe %s\n", jgd2[y].naipe);
            printf("Valor %d\n", jgd2[y].valor);
        }
    }
    puts("============================");
    system("pause");
}

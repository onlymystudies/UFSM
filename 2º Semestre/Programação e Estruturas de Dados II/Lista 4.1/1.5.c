/* Problema 5
 * Construa um programa utilizando uma pilha que resolva o seguinte problema: armazene as placas dos carros
 * (apenas os números) que estão estacionados numa estreita rua sem saída. Dado uma placa verifique se o carro
 * está estacionado na rua. Caso esteja, informe a sequência de carros que deverá ser retirada para que o carro
 * em questão consiga sair.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3

typedef struct {
    char placa[5];
}Infos;

typedef struct {
    Infos info[MAX];
    int topo;
}Pilha;

void pilha_inicia(Pilha *p) {
    p->topo = -1;
}

int pilha_cheia(Pilha *p) {
    if (p->topo == MAX - 1)
        return 1;
    else
        return 0;
}

void pilha_insere(Pilha *p, char placa[5]) {
    if (pilha_cheia(p) == 1)
        printf("ERROR: Strack overflow\n");
    else {
        p->topo++;
        strcpy(p->info[p->topo].placa, placa);
    }
}

int main() {
    char placa[5], placa_pesquisar[5];
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    pilha_inicia(p);

    printf("Placas dos carros estacionados\n");
    for (int i = 0; i < 3; ++i) {
        printf("Placa %d:\n", i+1);
        fgets(placa, 5, stdin);
        pilha_insere(p , placa);
        fflush(stdin);
    }

    printf("Placa do carro:\n");
    fgets(placa_pesquisar, 5, stdin);
    fflush(stdin);

    printf("Sequencia de carros que devera ser retirada para que o carro em questao consiga sair:\n");
    for (int i = 0; i < MAX; ++i) {
        if (strcmp(placa_pesquisar, p->info[i].placa) == 0) {
            printf("Seu carro\n");
            break;
        } else {
            printf("placa %s\n", p->info[i].placa);
        }
    }

    system("pause");
}
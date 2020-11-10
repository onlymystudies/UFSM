/* Problema 3
 * Escreva uma função que receba como parâmetro duas pilhas e verifique se elas são iguais. Duas pilhas são
 * iguais se possuem os mesmos elementos, na mesma ordem.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 3

typedef struct {
    int valor;
}Infos;
Infos aux;

typedef struct {
    Infos info[MAX];
    int topo;
}Pilha;

void pilha_inicia(Pilha *p) {
    p->topo = -1;
}

int pilha_vazia(Pilha *p) {
    if (p->topo == -1)
        return 1;
    else
        return 0;
}

int pilha_cheia(Pilha *p) {
    if (p->topo == MAX - 1)
        return 1;
    else
        return 0;
}

void pilha_insere(Pilha *p, int valor) {
    if (pilha_cheia(p) == 1)
        printf("ERROR: Strack overflow\n");
    else {
        p->topo++;
        p->info[p->topo].valor = valor;
    }
}

Pilha *pilha_remove(Pilha *p) {
    if (pilha_vazia(p) == 1)
        printf("ERROR: Pilha vazia\n");
    else
        p->topo--;
    printf("Removido\n");
    printf("Valor: %d\n", aux.valor);
    return p;
}

void *pilha_imprimi(Pilha *p) {
    for (int i = p->topo; i > -1; --i) {
        printf("Posicao %d\n", i + 1);
        printf("Valor: %d\n", p->info[i].valor);
    }
}

Pilha *pilha_zera(Pilha *p) {
    p->topo = - 1;
    return p;
}

void pilha_maior(Pilha *p) {
    int maior;
    for (int i = p->topo; i > -1; --i) {
        if (i == p->topo)
            maior = p->info[i].valor;
        if (p->info[i].valor > maior)
            maior = p->info[i].valor;
    }
    printf("Maior elemento: %d\n", maior);
}

void pilha_compara(Pilha *p, Pilha *p2) {
    int contador = 0;
    for (int i = 0; i < MAX; ++i) {
        if (p->info[i].valor ==  p2->info[i].valor)
            contador++;
    }
    if (contador == MAX)
        printf("As duas pilhas sao iguais\n");
    else
        printf("As duas pilhas nao sao iguais\n");
}

int main() {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    pilha_inicia(p);
    pilha_insere(p, 1);
    pilha_insere(p, 2);
    pilha_insere(p, 3);

    Pilha *p2 = (Pilha *) malloc(sizeof(Pilha));
    pilha_inicia(p2);
    pilha_insere(p2, 1);
    pilha_insere(p2, 3);
    pilha_insere(p2, 3);

    pilha_compara(p, p2);
    system("pause");
}
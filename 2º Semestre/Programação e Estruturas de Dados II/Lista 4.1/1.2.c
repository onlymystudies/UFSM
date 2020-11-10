/*Problema 2
 * Escrever uma função que receba como parâmetro uma pilha. A função deve retornar o maior elemento da
 * pilha. A passagem deve ser por valor ou referência?
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

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
// Passagem por referência
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

int main() {
    int valor;
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    pilha_inicia(p);
    for (;;) {
        printf("Valor para pilha:\n");
        scanf("%d", &valor);
        if (valor == 0)
            break;
        else
            pilha_insere(p , valor);
    }
    pilha_maior(p);
    system("pause");
}
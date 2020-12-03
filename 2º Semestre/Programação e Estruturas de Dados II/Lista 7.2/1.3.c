/* Problema 3
 * Utilizando somente operações de empilhar e desempilhar, escreva um programa que remove um item com
 * chave c fornecida pelo usuário da pilha. Ao final da execução da função, a pilha deve ser igual à original,
 * exceto pela ausência do item removido.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct pilhaNo {
    int chave;
    int valor;
    struct pilhaNo *proximo;
}PilhaNo;

typedef struct pilha {
    struct pilhaNo *topo;
}Pilha;

Pilha *cria(void) {
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void empilha(Pilha *pilha, int chave, int valor) {
    PilhaNo *novo = (PilhaNo *) malloc(sizeof(PilhaNo));
    novo->valor = valor;
    novo->chave = chave;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

void imprime(Pilha *pilha) {
    PilhaNo *percorre = pilha->topo;
    while (percorre) {
        printf("chave %d\n", percorre->chave);
        printf("valor %d\n", percorre->valor);
        percorre = percorre->proximo;
    }
}

void desempilhar(Pilha *pilha, int chave) {
    PilhaNo *percorre = pilha->topo;
    PilhaNo *anterior = NULL;
    while (percorre) {
        if (percorre->chave == chave)
            break;
        anterior = percorre;
        percorre = percorre->proximo;
    }

    if (!percorre->proximo)
        anterior->proximo = NULL;
    else if (percorre == pilha->topo)
        pilha->topo = percorre->proximo;
    else
        anterior->proximo = percorre->proximo;
}

int main(void) {
    Pilha *pilha = cria();
    empilha(pilha, 123, 1);
    empilha(pilha, 345, 2);
    empilha(pilha, 678, 3);
    desempilhar(pilha, 123);
    imprime(pilha);
    system("pause");
}
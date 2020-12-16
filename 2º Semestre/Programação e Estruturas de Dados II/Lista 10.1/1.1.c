/* Problema 1
 * Escreva um programa que utilize as funções de árvore binária de busca mostradas anteriormente.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    int valor;
    struct arvore *esquerda;
    struct arvore *direita;
}Arvore;

Arvore *insere (Arvore *arvore, int valor) {
    if (!arvore) {
        arvore = (Arvore *)malloc(sizeof(Arvore));
        arvore->valor = valor;
        arvore->esquerda = arvore->direita = NULL;
    }
    else if (valor < arvore->valor)
        arvore->esquerda = insere(arvore->esquerda, valor);
    else
        arvore->direita = insere(arvore->direita, valor);
    return arvore;
}

Arvore *retira (Arvore *arvore, int valor) {
    if (!arvore)
        return NULL;
    else if (arvore->valor > valor)
        arvore->esquerda = retira(arvore->esquerda, valor);
    else if (arvore->valor < valor)
        arvore->direita = retira(arvore->direita, valor);
    else {
        if (!arvore->esquerda && !arvore->direita) {
            free (arvore);
            arvore = NULL;
        }
        else if (!arvore->esquerda) {
            Arvore* retira = arvore;
            arvore = arvore->direita;
            free (retira);
        }
        else if (!arvore->direita) {
            Arvore* retira = arvore;
            arvore = arvore->esquerda;
            free (retira);
        }
        else {
            Arvore* troca = arvore->esquerda;
            while (troca->direita)
                troca = troca->direita;
            arvore->valor = troca->valor;
            troca->valor = valor;
            arvore->esquerda = retira(arvore->esquerda, valor);
        }
    }
    return arvore;
}

Arvore *busca (Arvore* arvore, int valor) {
    if (!arvore)
        return NULL;
    else if (arvore->valor > valor)
        return busca (arvore->esquerda, valor);
    else if (arvore->valor < valor)
        return busca (arvore->direita, valor);
    else
        return arvore;
}

void imprime(Arvore *arvore) {
    if (arvore) {
        imprime(arvore->esquerda);
        printf("%d ", arvore->valor);
        imprime(arvore->direita);
    }
}

int main(void) {
    Arvore *arvore = NULL;
    arvore = insere(arvore, 6);
    arvore = insere(arvore, 8);
    arvore = insere(arvore, 2);
    arvore = insere(arvore, 1);
    arvore = insere(arvore, 4);
    arvore = insere(arvore, 3);
    imprime(arvore);
    puts("");

    printf("retorno: ");
    Arvore *retorno = busca(arvore, 8);
    imprime(retorno);
    puts("");

    printf("retira: ");
    arvore = retira(arvore, 6);
    imprime(arvore);
    puts("");

    system("pause");
}
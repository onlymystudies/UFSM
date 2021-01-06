/* Problema 2
 * Crie uma versão de “abp.c” que suporte strings (char *nome;).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore{
    char *nome;
    struct arvore *esquerda;
    struct arvore *direita;
}Arvore;

Arvore *insere (Arvore *arvore, char *nome) {
    if (!arvore) {
        arvore = (Arvore *)malloc(sizeof(Arvore));
        arvore->nome = nome;
        arvore->esquerda = arvore->direita = NULL;
    }
    else if (strcmp(arvore->nome, nome) < 0)
        arvore->esquerda = insere(arvore->esquerda, nome);
    else
        arvore->direita = insere(arvore->direita, nome);
    return arvore;
}

Arvore *retira (Arvore *arvore, char *nome) {
    if (!arvore)
        return NULL;
    else if (strcmp(arvore->nome, nome) < 0)
        arvore->esquerda = retira(arvore->esquerda, nome);
    else if (strcmp(arvore->nome, nome) > 0)
        arvore->direita = retira(arvore->direita, nome);
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
            arvore->nome = troca->nome;
            troca->nome = nome;
            arvore->esquerda = retira(arvore->esquerda, nome);
        }
    }
    return arvore;
}

Arvore *busca (Arvore* arvore, char *nome) {
    if (!arvore)
        return NULL;
    else if (strcmp(arvore->nome, nome) < 0)
        return busca (arvore->esquerda, nome);
    else if (strcmp(arvore->nome, nome) > 0)
        return busca (arvore->direita, nome);
    else
        return arvore;
}

void imprime(Arvore *arvore) {
    if (arvore) {
        imprime(arvore->esquerda);
        printf("%s ", arvore->nome);
        imprime(arvore->direita);
    }
}

int main(void) {
    Arvore *arvore = NULL;
    arvore = insere(arvore, "a");
    arvore = insere(arvore, "b");
    arvore = insere(arvore, "c");
    arvore = insere(arvore, "d");
    arvore = insere(arvore, "e");
    arvore = insere(arvore, "f");
    imprime(arvore);
    puts("");

    printf("retorno: ");
    Arvore *retorno = busca(arvore, "f");
    imprime(retorno);
    puts("");

    printf("retira: ");
    arvore = retira(arvore, "f");
    imprime(arvore);
    puts("");

    system("pause");
}
/* Problema 5
 * Realize, na árvore dada, a inserção das chaves 65, 70, 38, 44, 49 e 42, atualizando o fator de
 * equilíbrio dos nós a cada inserção. Quando necessário, indique o nó desregulado e a rotação utilizada
 * para regulá-lo. Redesenhe a árvore a cada passo.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    int valor;
    int balanceamento;
    struct arvore *esquerda;
    struct arvore *direita;
}Arvore;

void imprime(Arvore *arvore);

int altura(Arvore* arvore) {
    if (!arvore) return 0;
    int alturaEsquerda  =   altura(arvore->esquerda);
    int alturaDireita   =   altura(arvore->direita);
    return alturaEsquerda > alturaDireita ? alturaEsquerda + 1 : alturaDireita + 1;
}

Arvore *cria(int valor, Arvore *esquerda, Arvore *direita) {
    Arvore *arvore          =   (Arvore *) malloc(sizeof(Arvore));
    arvore->valor           =   valor;
    arvore->balanceamento   =   altura(direita) - altura(esquerda);
    arvore->esquerda        =   esquerda;
    arvore->direita         =   direita;
    return arvore;
}

void ll(Arvore **arvore) {
    printf("no %d rotacao LL\n", (*arvore)->valor);
    Arvore *b           =   *arvore;
    Arvore *a           =   b->esquerda;
    b->esquerda         =   a->direita;
    a->direita          =   b;
    a->balanceamento    =   0;
    b->balanceamento    =   0;
    *arvore             =   a;
}

void rr(Arvore **arvore) {
    printf("no %d rotacao RR\n", (*arvore)->valor);
    Arvore *a           =   *arvore;
    Arvore *b           =   a->direita;
    a->direita          =   b->esquerda;
    b->esquerda         =   a;
    a->balanceamento    =   0;
    b->balanceamento    =   0;
    *arvore             =   b;
}

void lr(Arvore **arvore) {
    printf("no %d rotacao LR\n", (*arvore)->valor);
    Arvore *c       =   *arvore;
    Arvore *a       =   c->esquerda;
    Arvore *b       =   a->direita;
    c->esquerda     =   b->direita;
    a->direita      =   b->esquerda;
    b->esquerda     =   a;
    b->direita      =   c;
    switch(b->balanceamento) {
        case -1:
            a->balanceamento = 0;
            c->balanceamento = 1;
            break;
        case 0:
            a->balanceamento = 0;
            c->balanceamento = 0;
            break;
        case +1:
            a->balanceamento = -1;
            c->balanceamento = 0;
            break;
    }
    b->balanceamento    =   0;
    *arvore             =   b;
}

void rl(Arvore **arvore) {
    printf("no %d rotacao RL\n", (*arvore)->valor);
    Arvore *a           =   *arvore;
    Arvore *b           =   *arvore;
    Arvore *c           =   *arvore;
    c->esquerda         =   b->direita;
    a->direita          =   b->esquerda;
    b->esquerda         =   a;
    b->direita          =   c;
    switch(b->balanceamento) {
        case -1:
            a->balanceamento = 0;
            c->balanceamento = 1;
            break;
        case 0:
            a->balanceamento = 0;
            c->balanceamento = 0;
            break;
        case +1:
            a->balanceamento = -1;
            c->balanceamento = 0;
            break;
    }
    b->balanceamento    =   0;
    *arvore             =   b;
}

int insere(Arvore **arvore, int valor, int *cresceu) {
    if (!*arvore) {
        *arvore = cria(valor, NULL, NULL);
        *cresceu = 1;
        return 1;
    }

    if (valor == (*arvore)->valor) return 0;

    if (valor < (*arvore)->valor) {
        if (insere(&(*arvore)->esquerda, valor, cresceu)) {
            if (*cresceu) {
                switch ((*arvore)->balanceamento) {
                    case -1:
                        if ((*arvore)->esquerda->balanceamento == -1)
                            ll(arvore);
                        else
                            lr(arvore);
                        *cresceu = 0;
                        break;
                    case  0: (*arvore)->balanceamento = -1; *cresceu = 1; break;
                    case +1: (*arvore)->balanceamento =  0; *cresceu = 0; break;
                }
            }
            return 1;
        }
        else return 0;
    }

    if (insere(&(*arvore)->direita, valor, cresceu)) {
        if (*cresceu) {
            switch((*arvore)->balanceamento) {
                case -1: (*arvore)->balanceamento =  0; *cresceu = 0; break;
                case  0: (*arvore)->balanceamento = +1; *cresceu = 1; break;
                case +1:
                    if ((*arvore)->direita->balanceamento == +1)
                        rr(arvore);
                    else
                        rl(arvore);
                    *cresceu = 0;
                    break;
            }
        }
        return 1;
    }
    else return 0;
}

void imprime(Arvore *arvore) {
    if (arvore) {
        imprime(arvore->esquerda);
        printf("%d(%d) ", arvore->valor, arvore->balanceamento);
        imprime(arvore->direita);
    }
}

int main(void) {
    int cresceu;
    Arvore *arvore = NULL;

    arvore = cria(20, NULL, NULL);
    insere(&arvore, 30, &cresceu);
    insere(&arvore, 35, &cresceu);
    insere(&arvore, 40, &cresceu);
    insere(&arvore, 46, &cresceu);
    insere(&arvore, 48, &cresceu);
    insere(&arvore, 50, &cresceu);
    insere(&arvore, 55, &cresceu);
    insere(&arvore, 61, &cresceu);
    puts("");
    insere(&arvore, 65, &cresceu);
    printf("65-> ");    imprime(arvore);    puts("");
    insere(&arvore, 70, &cresceu);
    printf("70-> ");    imprime(arvore);    puts("");
    insere(&arvore, 38, &cresceu);
    printf("38-> ");    imprime(arvore);    puts("");
    insere(&arvore, 44, &cresceu);
    printf("44-> ");    imprime(arvore);    puts("");
    insere(&arvore, 49, &cresceu);
    printf("49-> ");    imprime(arvore);    puts("");
    insere(&arvore, 42, &cresceu);
    printf("42-> ");    imprime(arvore);    puts("");

    system("pause");
    return 0;
}
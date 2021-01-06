/* Aula 9b - Lista 9.1b de exercícios de Programação e Estruturas de Dados II */
#include <stdio.h>
#include <stdlib.h>

/* Problema 1
Teste os códigos dados com os exemplos das lâminas. */
typedef struct arvore{
    int valor;
    int balanceamento;
    struct arvore *esquerda;
    struct arvore *direita;
}Arvore;

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
    Arvore *b           =   *arvore;
    Arvore *a           =   b->esquerda;
    b->esquerda         =   a->direita;
    a->direita          =   b;
    a->balanceamento    =   0;
    b->balanceamento    =   0;
    *arvore             =   a;
}

void rr(Arvore **arvore) {
    Arvore *a           =   *arvore;
    Arvore *b           =   a->direita;
    a->direita          =   b->esquerda;
    b->esquerda         =   a;
    a->balanceamento    =   0;
    b->balanceamento    =   0;
    *arvore             =   b;
}

void lr(Arvore **arvore) {
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

/* Problema 2
Crie funções para localizar o menor e o maior valor em uma AVL. */
void maiorMenor(Arvore *arvore) {
    Arvore *maior = arvore;
    Arvore *menor = arvore;

    while (maior->direita) maior  = maior->direita;
    while (menor->esquerda) menor = menor->esquerda;

    printf("maior %d menor %d", maior->valor, menor->valor);
}

/* Problema 3
Implemente a função “imprime_alt()” para AVL. */
void imprime_alt(Arvore *arvore) {
    if (arvore) {
        printf("<");
        printf("%d", arvore->valor);
        imprime_alt(arvore->esquerda);
        printf(">");
        printf("<");
        imprime_alt(arvore->direita);
        printf(">");
    }
}

/* Problema 4
Implemente um programa que diga se as árvores abaixo são binárias de busca: */
int verificaBusca(Arvore *arvore) {
    Arvore *percorre = arvore;

    while (percorre) {
        if (percorre->valor < arvore->valor) return 0;
        else percorre = percorre->direita;
    }
    return 1;
}

int main(void) {
    int cresceu;
    Arvore *arvore = NULL;

    arvore = cria(1, NULL, NULL);
    insere(&arvore, 2, &cresceu);
    insere(&arvore, 3, &cresceu);
    insere(&arvore, 4, &cresceu);
    insere(&arvore, 5, &cresceu);
    insere(&arvore, 6, &cresceu);
    insere(&arvore, 7, &cresceu);
    insere(&arvore, 8, &cresceu);
    insere(&arvore, 9, &cresceu);
    insere(&arvore, 10, &cresceu);
    imprime(arvore);            puts("");
    maiorMenor(arvore);         puts("");
    imprime_alt(arvore);        puts("");
    if (verificaBusca(arvore))  printf("arvore binaria de busca\n");
    else                        printf("arvore nao binaria de busca\n");
    system("pause");
    return 0;
}
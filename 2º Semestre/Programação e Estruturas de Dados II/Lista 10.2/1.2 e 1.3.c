/* Aula 10 - Lista 10.1 de exercícios de Programação e Estruturas de Dados II */
#include <stdio.h>
#include <stdlib.h>

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

Arvore *criaAVL(int valor, Arvore *esquerda, Arvore *direita) {
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

int insereAVL(Arvore **arvore, int valor, int *cresceu) {
    if (!*arvore) {
        *arvore = criaAVL(valor, NULL, NULL);
        *cresceu = 1;
        return 1;
    }

    if (valor == (*arvore)->valor) return 0;

    if (valor < (*arvore)->valor) {
        if (insereAVL(&(*arvore)->esquerda, valor, cresceu)) {
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

    if (insereAVL(&(*arvore)->direita, valor, cresceu)) {
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

Arvore *insereNaria(Arvore *filho, Arvore *irmao, int valor) {
    Arvore *arvore      =   (Arvore *) malloc(sizeof(Arvore));
    arvore->valor       =   valor;
    arvore->direita     =   filho;
    arvore->esquerda    =   irmao;
    return arvore;
}

Arvore *insereBinario(Arvore *esquerda, Arvore *direita, int valor) {
    Arvore *arvore      =   (Arvore *) malloc(sizeof(Arvore));
    arvore->valor       =   valor;
    arvore->esquerda    =   esquerda;
    arvore->direita     =   direita;
    return arvore;
}

Arvore *insereABP(Arvore *arvore, int valor) {
    if (!arvore) {
        arvore = (Arvore *) malloc(sizeof(Arvore));
        arvore->valor = valor;
        arvore->esquerda = arvore->direita = NULL;
    }
    else if (arvore->valor > valor)
        arvore->esquerda = insereABP(arvore->esquerda, valor);
    else
        arvore->direita = insereABP(arvore->direita, valor);
    return arvore;
}

void imprime(Arvore *arvore) {
    if (arvore) {
        printf("%d ", arvore->valor);
        imprime(arvore->esquerda);
        imprime(arvore->direita);
    }
}

void imprimeAVL(Arvore *arvore) {
    if (arvore) {
        imprimeAVL(arvore->esquerda);
        printf("%d(%d) ", arvore->valor, arvore->balanceamento);
        imprimeAVL(arvore->direita);
    }
}

Arvore *nariaParaBinaria(Arvore *naria, Arvore *binaria) {
    if (naria) {
        binaria = insereBinario(naria->esquerda, naria->direita, naria->valor);
        nariaParaBinaria(naria->esquerda, binaria);
        nariaParaBinaria(naria->direita, binaria);
    }
    return binaria;
}

Arvore *binariaParaABP(Arvore *binaria, Arvore *ABP) {
    if (binaria) {
        ABP = insereABP(ABP, binaria->valor);
        binariaParaABP(binaria->esquerda, ABP);
        binariaParaABP(binaria->direita, ABP);
    }
    return ABP;
}

Arvore *ABPParaAVL(Arvore *ABP, Arvore *AVL, int cresceu) {
    if (ABP) {
        insereAVL(&AVL, ABP->valor, &cresceu);
        ABPParaAVL(ABP->esquerda, AVL, cresceu);
        ABPParaAVL(ABP->direita, AVL, cresceu);
    }
    return AVL;
}

int main(void) {
    Arvore *node5           =       insereNaria(NULL, NULL, 5);
    Arvore *node4           =       insereNaria(NULL, node5, 4);
    Arvore *node3           =       insereNaria(node4, NULL, 3);
    Arvore *node2           =       insereNaria(NULL, node3, 2);
    Arvore *arvoreNaria     =       insereNaria(node2, NULL, 1);
    printf("Naria\t");      imprime(arvoreNaria);
    puts("");
    /* Problema 2
    Implementar o código para transformar uma árvore genérica (n-ária) em binária e, em seguida, em ABP. */
    Arvore *arvoreBinaria   =       NULL;
    arvoreBinaria           =       nariaParaBinaria(arvoreNaria, arvoreBinaria);
    printf("Binaria\t");    imprime(arvoreBinaria);
    puts("");

    Arvore *ABP             =       NULL;
    ABP                     =       binariaParaABP(arvoreBinaria, ABP);
    printf("ABP\t");        imprime(ABP);
    puts("");
    /* Problema 3
    Complementar o código da questão anterior, a fim de transformar a ABP em uma AVL. */
    int cresceu = 0;
    Arvore *AVL             =       criaAVL(2, NULL, NULL); /* nao sei pq mas só funcinou quando inciado com o valor 2 */
    AVL                     =       ABPParaAVL(ABP, AVL, cresceu);
    printf("AVL\t");        imprimeAVL(AVL);
    puts("");

    system("pause");
    return 0;
}
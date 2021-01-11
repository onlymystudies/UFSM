/* Problema 6
 * Inserir as chaves 9, 8, 7, 6, 1, 2, 3, 4, 5 em uma árvore AVL desenhando a árvore após cada
 * inserção. Exclua as chaves 6 e 8, desenhando a árvore após cada inserção e exclusão.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    int valor;
    int altura;
    struct arvore *esquerda;
    struct arvore *direita;
}Arvore;

int altura(Arvore *arvore) {
    return arvore ? arvore->altura : -1;
}

int fatorBalanceamento(Arvore *arvore) {
    return labs(altura(arvore->esquerda) - altura(arvore->direita));
}

int maior(int x, int y) {
    return x > y ? x : y;
}

void LL(Arvore **arvore) {
    Arvore *node;
    node                =   (*arvore)->esquerda;
    (*arvore)->esquerda =   node->direita;
    node->direita       =   *arvore;
    (*arvore)->altura   =   maior(altura((*arvore)->esquerda), altura((*arvore)->esquerda)) + 1;
    node->altura        =   maior(altura(node->esquerda), (*arvore)->altura) + 1;
    *arvore             =   node;
}

void RR(Arvore **arvore) {
    Arvore *node;
    node                =   (*arvore)->direita;
    (*arvore)->direita  =   node->esquerda;
    node->esquerda      =   (*arvore);
    (*arvore)->altura   =   maior(altura((*arvore)->esquerda), altura((*arvore)->direita)) + 1;
    node->altura        =   maior(altura(node->direita), (*arvore)->altura) + 1;
    *arvore             =   node;
}

void LR(Arvore **arvore) {
    RR(&(*arvore)->esquerda);   LL(arvore);
}

void RL(Arvore **arvore) {
    LL(&(*arvore)->direita);    RR(arvore);
}

int insere(Arvore **arvore, int valor) {
    Arvore *atual = *arvore;
    int resultado;

    if (!*arvore) {
        Arvore *novo    =   (Arvore *) malloc(sizeof(Arvore));
        novo->valor     =   valor;
        novo->altura    =   0;
        novo->esquerda  =   novo->direita = NULL;
        *arvore         =   novo;
        return 1;
    }

    if (valor < atual->valor) {
        resultado = insere(&(atual->esquerda), valor);
        if (resultado == 1) {
            if (fatorBalanceamento(atual) >= 2) {
                if (valor < (*arvore)->esquerda->valor)
                    LL(arvore);
                else
                    LR(arvore);
            }
        }
    }
    else {
        if (valor > atual->valor) {
            resultado = insere(&(atual->direita), valor);
            if (resultado == 1) {
                if (fatorBalanceamento(atual) >= 2) {
                    if ((*arvore)->direita->valor < valor)
                        RR(arvore);
                    else
                        RL(arvore);

                }
            }
        }
        else return 0;
    }
    atual->altura = maior(altura(atual->esquerda), altura(atual->direita)) + 1;

    return resultado;
}

void imprime(Arvore *arvore) {
    if (arvore) {
        imprime(arvore->esquerda);
        printf("%d ", arvore->valor);
        imprime(arvore->direita);
    }
}

Arvore *procuraMenor(Arvore *arvore) {
    Arvore *node1 = arvore;
    Arvore *node2 = arvore->esquerda;
    while (node2) {
        node1 = node2;
        node2 = node2->esquerda;
    }
    return node1;
}

int retira(Arvore **arvore, int valor) {
    int resultado;

    if (!*arvore) return 0;

    if (valor < (*arvore)->valor) {
        resultado = retira(&(*arvore)->esquerda, valor);
        if (resultado == 1) {
            if (fatorBalanceamento(*arvore) >= 2) {
                if (altura((*arvore)->direita->esquerda) <= altura((*arvore)->direita->direita))
                    RR(arvore);
                else
                    RL(arvore);
            }
        }
    }

    if ((*arvore)->valor < valor) {
        resultado = retira(&(*arvore)->direita, valor);
        if (resultado == 1) {
            if (fatorBalanceamento(*arvore) >= 2) {
                if (altura((*arvore)->esquerda->direita) <= altura((*arvore)->esquerda->esquerda))
                    LL(arvore);
                else
                    LR(arvore);
            }
        }
    }

    if ((*arvore)->valor == valor) {
        if (!(*arvore)->esquerda || !(*arvore)->direita) {
            Arvore *oldNode = *arvore;
            if ((*arvore)->esquerda)
                *arvore = (*arvore)->esquerda;
            else
                *arvore = (*arvore)->direita;
            free(oldNode);
        }
        else {
            Arvore *temp = procuraMenor((*arvore)->direita);
            (*arvore)->valor = temp->valor;
            retira(&(*arvore)->direita, (*arvore)->valor);
            if (fatorBalanceamento(*arvore) >= 2) {
                if (altura((*arvore)->esquerda->direita) <= altura((*arvore)->esquerda->esquerda))
                    LL(arvore);
                else
                    LR(arvore);
            }
        }
        return 1;
    }

    return resultado;
}

int main(void) {
    Arvore *arvore = NULL;
    insere(&arvore, 9);
    imprime(arvore);    puts("");
    insere(&arvore, 8);
    imprime(arvore);    puts("");
    insere(&arvore, 7);
    imprime(arvore);    puts("");
    insere(&arvore, 6);
    imprime(arvore);    puts("");
    insere(&arvore, 1);
    imprime(arvore);    puts("");
    insere(&arvore, 2);
    imprime(arvore);    puts("");
    insere(&arvore, 3);
    imprime(arvore);    puts("");
    insere(&arvore, 4);
    imprime(arvore);    puts("");
    insere(&arvore, 5);
    imprime(arvore);    puts("");
    retira(&arvore, 6);
    imprime(arvore);    puts("");
    retira(&arvore, 8);
    imprime(arvore);    puts("");
    system("pause");
    return 0;
}
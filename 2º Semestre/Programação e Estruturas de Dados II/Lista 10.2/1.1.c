/* Problema 1
 * Implementar o código proposto por José Augusto Baranauskas, testando os exemplos dados em sua apostila
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct arvore{
    int valor;
    int balanceamento;
    struct arvore *esquerda;
    struct arvore *direita;
}Arvore;

Arvore *LL(Arvore *arvore) {
    Arvore *auxB = arvore->esquerda;
    arvore->esquerda = auxB->direita;
    auxB->direita = arvore;
    return auxB;
}

Arvore *RR(Arvore *arvore) {
    Arvore *auxB = arvore->direita;
    arvore->direita = auxB->esquerda;
    auxB->esquerda = arvore;
    return auxB;
}

Arvore *LR(Arvore *arvore) {
    Arvore *auxB = arvore->esquerda;
    Arvore *auxC = auxB->direita;
    auxB->direita = auxC->esquerda;
    auxC->esquerda = auxB;
    arvore->esquerda = auxC->direita;
    auxC->direita = arvore;
    return auxC;
}

Arvore *RL(Arvore *arvore) {
    Arvore *auxB = arvore->direita;
    Arvore *auxC = auxB->esquerda;
    auxB->esquerda = auxC->direita;
    auxC->direita = auxB;
    arvore->direita = auxC->esquerda;
    auxC->esquerda = arvore;
    return auxC;
}

Arvore *insere(Arvore *arvore, int valor, bool altura) {
    Arvore *auxB;
    if (!arvore) {
        Arvore *novo = (Arvore *) malloc(sizeof(Arvore));
        altura = true;
        novo->valor = valor;
        novo->balanceamento = 0;
        novo->esquerda = novo->direita = NULL;
        return novo;
    }
    else if (valor < arvore->valor) {
        arvore->esquerda = insere(arvore->esquerda, valor, altura);
        if (altura) {
            switch (arvore->balanceamento) {
                case -1: arvore->balanceamento = 0; altura = false; break;
                case 0: arvore->balanceamento = +1; break;
                case +1: auxB = arvore->esquerda;
                    if (auxB->balanceamento == +1)
                        arvore = LL(arvore);
                    else
                        arvore = LR(arvore);
                    arvore->balanceamento = 0;
                    altura = false;
            }
        }
    }
    else if (valor > arvore->valor) {
        arvore->direita = insere(arvore->direita, valor, altura);
        if (altura) {
            switch (arvore->balanceamento) {
                case +1: arvore->balanceamento = 0; altura = false; break;
                case 0: arvore->balanceamento = -1; break;
                case -1: auxB = arvore->direita;
                    if (auxB->balanceamento == -1)
                        arvore = RR(arvore);
                    else
                        arvore = RL(arvore);
                    arvore->balanceamento = 0;
                    altura = false;
            }
        }
    }
    return arvore;
}

void imprime(Arvore *arvore) {
    if (arvore) {
        imprime(arvore->esquerda);
        printf("%d\n", arvore->valor);
        imprime(arvore->direita);
    }
}

int main(void) {
    Arvore *arvore = NULL;
    arvore = insere(arvore, 1, false);
    arvore = insere(arvore, 2, false);
    arvore = insere(arvore, 3, false);
    arvore = insere(arvore, 4, false);
    arvore = insere(arvore, 5, false);
    arvore = insere(arvore, 6, false);
    arvore = insere(arvore, 7, false);
    arvore = insere(arvore, 8, false);
    arvore = insere(arvore, 9, false);
    arvore = insere(arvore, 10, false);
    imprime(arvore);
    system("pause");
    return 0;
}
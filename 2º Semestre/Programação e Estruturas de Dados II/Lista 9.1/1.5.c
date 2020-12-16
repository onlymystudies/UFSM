#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    char operador;
    float valor;
    struct arvore *esquerda, *direita;
}Arvore;

Arvore *criaFolha(float valor, Arvore *esquerda, Arvore *direita) {
    Arvore *novo = (Arvore *) malloc(sizeof(Arvore));
    novo->valor = valor;
    novo->esquerda = esquerda;
    novo->direita = direita;
    return novo;
}

Arvore *criaOperador(char operador, Arvore *esquerda, Arvore *direita) {
    Arvore *novo = (Arvore *) malloc(sizeof(Arvore));
    novo->operador = operador;
    novo->esquerda = esquerda;
    novo->direita = direita;
    return novo;
}

void imprime(Arvore *arvore) {
    if (arvore) {
        imprime(arvore->esquerda);
        imprime(arvore->direita);
        if (arvore->valor < 0)
            printf("%c ", arvore->operador);
        else
            printf("%.f ", arvore->valor);
    }
}

float operacoes(Arvore *arvore) {
    if (arvore->operador == '-')
        return arvore->esquerda->valor - arvore->direita->valor;
    if (arvore->operador == '+')
        return arvore->esquerda->valor + arvore->direita->valor;
    if (arvore->operador == '*')
        return arvore->esquerda->valor * arvore->direita->valor;
    return 0;
}

float avalia(Arvore *arvore) {
    float esquerda, direita, resultado;
    if (!arvore->esquerda && !arvore->direita) {
        return arvore->valor;
    }
    else {
        esquerda = avalia(arvore->esquerda);
        direita = avalia(arvore->direita);
        switch(arvore->operador) {
            case '+': resultado = esquerda + direita; break;
            case '-': resultado = esquerda - direita; break;
            case '*': resultado = esquerda * direita; break;
            case '/': resultado = esquerda / direita; break;
        }
        return resultado;
    }
}

int main(void) {
    Arvore *arv1 = criaFolha(6, NULL, NULL);
    Arvore *arv2 = criaFolha(3, NULL, NULL);
    Arvore *arv3 = criaFolha(4, NULL, NULL);
    Arvore *arv4 = criaFolha(1, NULL, NULL);
    Arvore *arv5 = criaFolha(5, NULL, NULL);
    Arvore *arv6 = criaOperador('-', arv1, arv2);
    Arvore *arv7 = criaOperador('+', arv3, arv4);
    Arvore *arv8 = criaOperador('*', arv6, arv7);
    Arvore *arv = criaOperador('+', arv8, arv5);
    imprime(arv); // a
    printf("= %.f\n", avalia(arv)); // b
    system("pause");
}
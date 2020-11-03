#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto {
    int x,
        y;
};

int soma(Ponto *p) {
    return p->x + p->y;
}

int subtracao(Ponto *p) {
    return p->x - p->y;
}

Ponto *armazenar(float x, float y) {
    Ponto *vetor = (Ponto *) malloc(sizeof(Ponto));
    if (vetor == NULL) {
        printf("Memória insuficiente!\n");
        system("pause");
    }
    vetor->x = x;
    vetor->y = y;
    return vetor;
}

void libera(Ponto *vetor) {
    free(vetor);
}

float distancia(Ponto *ponto1, Ponto *ponto2) {
    float distancia = sqrt(pow(ponto1->x - ponto2->x, 2) + pow(ponto2->y - ponto1->y, 2));
    return distancia;
}
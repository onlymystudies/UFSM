#include <stdio.h>
#include <stdlib.h>
#define TAM 2

int recSomaVetor(int *vet, int soma, size_t pos) {
    if (pos == TAM)
        return soma;
    soma += vet[pos];
    return recSomaVetor(vet, soma, pos+=1);
}

int Soma(int *vet) {
    return recSomaVetor(vet, 0, 0);
}

int main(void) {
    int vet[TAM] = {1,2};
    printf("soma: %d\n", Soma(vet));
    system("pause");
}
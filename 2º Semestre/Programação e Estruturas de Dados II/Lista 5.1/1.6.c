#include <stdio.h>
#include <stdlib.h>
#define TAM 4

int recInverter(int *vet, size_t posicao) {
    if (posicao == TAM / 2)
        return *vet;
    int aux = vet[TAM - posicao - 1];
    vet[TAM - posicao - 1] = vet[posicao];
    vet[posicao] = aux;
    return recInverter(vet, posicao+=1);
}

int main(void) {
    int vet[TAM] = {1,2,3,4};
    recInverter(vet, 0);
    for (int i = 0; i < TAM; ++i) {
        printf("%d\n", vet[i]);
    }
    system("pause");
}

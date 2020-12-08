/* Nome: Leonardo Zamboni Nunes 202012828
 * (2,0 Pontos) Escreva um programa em C para converter um array de forma que dobre o valor e
 * substitua o próximo número por 0 se o elemento atual e o próximo forem iguais e reorganize o
 * vetor de forma que todos os 0s sejam deslocados para o final. Ex.: array original: 0 5 5 5 0 0 9
 * 9 0 15; array modificado: 10 5 18 15 0 0 0 0 0 0. Considere a função main() dada abaixo.
 */
#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void AtualizaeReorganizarArray(int *vetor) {
    int aux;

    for (size_t i = 0; i < TAM; ++i) {
        for (size_t j = i + 1; j < TAM; ++j) {
            if (vetor[i] == vetor[j]) {
                vetor[i] *= 2;
                vetor[j] = 0;
                break;
            }
        }
    }
    for (size_t y = 0; y < TAM; ++y) {
        for (size_t x = 0; x < TAM; ++x) {
            if (vetor[y] > vetor[x]) {
                aux = vetor[y];
                vetor[y] = vetor[x];
                vetor[x] = aux;
            }
        }
    }
}

void MostraArray(int *vetor) {
    for (size_t i = 0; i < TAM; ++i)
        printf("%d ", vetor[i]);
    printf("\n");
}

int main(void) {
    int vetor[TAM] = {1,2,2,4,5,5,7,8,9,10};
    printf("vetor original\n");
    MostraArray(vetor);
    printf("depois\n");
    AtualizaeReorganizarArray(vetor);
    MostraArray(vetor);
    system("pause");
}
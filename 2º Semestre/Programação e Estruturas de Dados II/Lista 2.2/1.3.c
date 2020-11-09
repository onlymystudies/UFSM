#include <stdio.h>
#include <stdlib.h>

int main() {
    int valor, armazena_posicao = 0;
    int vetor[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    printf("Valor x qualquer\n");
    scanf("%d", &valor);

    for (int i = 0; i < 20; ++i) {
        if (vetor[i] == valor) {
            armazena_posicao = i;
            break;
        }
    }

    if (armazena_posicao != -1)
        printf("Encontrado na posicao %d\n", armazena_posicao+1);
    else
        printf("Nao foi encontrado no vetor\n");
    system("pause");
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int participantes, contador = 1, contador_teste = 1;

    printf("Numero de participantes da festa\n");
    scanf("%d", &participantes);
    int vetor[participantes];

    for (int i = 0; i < participantes; ++i) {
        printf("Ingresso:\n");
        scanf("%d", &vetor[i]);
        if (vetor[i] == 0) break;
    }
    for (int i = 0; i < participantes; ++i) {
        if (vetor[i] == contador) {
            printf("Teste %d\n%d\n", contador_teste, vetor[i]);
            contador_teste++;
        }
        contador++;
    }

    system("pause");
}
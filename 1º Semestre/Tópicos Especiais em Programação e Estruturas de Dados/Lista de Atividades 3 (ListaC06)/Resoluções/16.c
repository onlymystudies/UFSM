#include <stdio.h>
#include <stdlib.h>
#include "github.com/leozamboni/C/include/stbuffer.h"

struct datas {
    int dia,
            mes,
            ano;
}datas;

typedef struct agenda {
    char compromisso[60];
    struct datas data[5];
}agenda;

int main() {
    agenda *vetor = malloc(5 * sizeof(agenda));

    int M,
            A;

    for (int i = 0; i < 5; ++i) {
        printf("Compromisso %d", i + 1);
        fgets(vetor[i].compromisso, 60, stdin);
        fflush(stdin);

        puts("Dia, mes e ano:");
        scanf("%d %d %d", &vetor[i].data[i].dia, &vetor[i].data[i].mes, &vetor[i].data[i].ano);
        system("cls");
        clearbuffer();
    }

    puts("Mes:");
    scanf("%d", &M);
    puts("Ano:");
    scanf("%d", &A);

    for (int i = 0; i < M; ++i) {
        if (vetor[i].data[i].mes == M) {
            printf("Compromisso: %s", vetor[i].compromisso);
            printf("Dia: %d\nMes: %d\nAno: %d\n", vetor[i].data[i].dia, vetor[i].data[i].mes, vetor[i].data[i].ano);
        }
    }

    system("pause");
}

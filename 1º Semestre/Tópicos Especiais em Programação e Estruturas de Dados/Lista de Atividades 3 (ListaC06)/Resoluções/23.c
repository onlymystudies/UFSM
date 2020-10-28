#include <stdio.h>
#include <stdlib.h>
#include "github.com/leozamboni/stbuffer.h"

typedef struct data {
    int dia,
            mes,
            ano;
}dma;

int main() {
    dma *v = malloc(2 * sizeof(dma));

    for (int i = 0; i < 2; ++i) {
        do {
            puts("Dia:");
            scanf("%d", &v[i].dia);
            clearbuffer();
            if (v[i].dia > 31 || v[i].dia < 0)
                puts("Dia invalido");
        } while (v[i].dia > 31 || v[i].dia < 0);

        do {
            puts("Mes:");
            scanf("%d", &v[i].mes);
            clearbuffer();
            if (v[i].mes > 12 || v[i].mes < 0) {
                puts("Mes invalido");
            }
        } while (v[i].mes > 12 || v[i].mes < 0);

        puts("Ano:");
        scanf("%d", &v[i].ano);
        clearbuffer();

        system("cls");
    }

    int dia, mes, ano;
    dia = v[0].dia - v[1].dia;
    mes = v[0].mes - v[1].mes;
    ano = v[0].ano - v[1].ano;
    if (dia < 0) {
        dia *= -1;
    }
    if (mes < 0) {
        mes *= -1;
    }
    if (ano < 0) {
        ano *= -1;
    }
    printf("%d dia(s), %d mes(es) e %d ano(s) decorrerem entre as duas datas\n", dia, mes, ano);

    system("pause");
}
#include <stdio.h>
#include <stdlib.h>
#include "github.com/leozamboni/C/include/stbuffer.h"

struct movimentacoes {
    char codigo[64],
            origem[64],
            destinho[64];
};
typedef struct movimentacoes voos;

struct locais {
    unsigned int codigo,
            quantidadeentra,
            quantidadesai;
};
typedef struct locais aeroportos;

int main() {
    voos *v = malloc(2 * sizeof(voos));
    aeroportos *v2 = malloc(5 * sizeof(aeroportos));

    for (int i = 0; i < 5; ++i) {
        printf("Voo %d\n", i + 1);
        puts("Codigo:");
        fgets(v[i].codigo, 63, stdin);
        fflush(stdin);

        puts("Origem");
        fgets(v[i].origem, 63, stdin);
        fflush(stdin);

        puts("Destino");
        fgets(v[i].destinho, 63, stdin);
        fflush(stdin);;
        system("cls");
    }

    int aux = 0;
    for (int i = 0; i < 2; ++i) {
        do {
            printf("Aeroportos %d\n", i + 1);
            puts("Codigo:");
            scanf("%d", &v2[i].codigo);
            clearbuffer();
            if (v2[i].codigo > 0) {
                aux++;
            } else {
                puts("Codigo invalido");
            }
        } while (aux > 0);

        puts("Voos que saem:");
        scanf("%d", &v2[i].quantidadesai);
        clearbuffer();

        puts("Voos que entra:");
        scanf("%d", &v2[i].quantidadeentra);
        clearbuffer();
        system("cls");
    }

    system("pause");
}

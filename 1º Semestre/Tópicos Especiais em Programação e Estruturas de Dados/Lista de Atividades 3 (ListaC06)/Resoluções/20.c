#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "github.com/leozamboni/C/include/stbuffer.h"

struct ingredientes {
    char nome[25];
    int quantidade;
};
typedef struct ingredientes ingre;

struct receitas {
    char nome[25];
    int quant_ingre;
};
typedef struct receitas receita;

int main() {
    char nome[64];
    int aux = 0;
    receita *v = malloc(5 * sizeof(receita));

    ingre **m = malloc(5 * sizeof(ingre *));
    for (int k = 0; k < 5; ++k) {
        m[k] = malloc(10 * sizeof(ingre));
    }

    for (int i = 0; i < 5; ++i) {
        printf("Receita %d\n", i + 1);
        puts("Nome:");
        fgets(v[i].nome, 24, stdin);
        fflush(stdin);
        do {
            puts("Quantidade de Ingredientes:");
            scanf("%d", &v[i].quant_ingre);
            clearbuffer();
            if (v[i].quant_ingre > 10) {
                puts("Numero de ingredientes nao suportado");
            } else {
                aux++;
            }
        } while (aux < 0);

        for (int j = 0; j < v[i].quant_ingre; ++j) {
            printf("Ingrediente %d\n", j + 1);
            puts("Nome:");
            fgets(m[i][j].nome, 24, stdin);
            fflush(stdin);

            puts("Quantidade:");
            scanf("%d", &m[i][j].quantidade);
            clearbuffer();
            system("cls");
        }
        system("cls");
    }

    puts("Nome:");
    fgets(nome, 63, stdin);
    for (int j = 0; j < 5; ++j)
        if (strcmp (nome, v[j].nome) == 0) {
            printf("Nome: %s", v[j].nome);
            if (v[j].quant_ingre != 0) {
                puts("Ingredientes:");
                for (int i = 0; i < v[j].quant_ingre; ++i) {
                    printf("Nome: %s", m[j][i].nome);
                    printf("Quantidade: %d\n", m[j][i].quantidade);
                    puts("==================");
                }
            }
        } else {
            puts("Receita não encontrada :(");
        }

    system("pause");
}

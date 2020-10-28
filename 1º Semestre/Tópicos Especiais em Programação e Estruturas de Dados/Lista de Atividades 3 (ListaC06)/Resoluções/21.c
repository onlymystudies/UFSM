#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "github.com/leozamboni/C/include/stbuffer.h"

struct filmes {
    char
            nome[25],
            ano[4];
    float
            duracao;
};
typedef struct filmes film;

struct diretores {
    char nome[20];
    int quantfilmes;
};
typedef struct diretores dire;

int main() {
    char nome[64];
    int aux = 0;
    dire *v = malloc(5 * sizeof(dire));

    film **m = malloc(5 * sizeof(film *));
    for (int k = 0; k < 5; ++k) {
        m[k] = malloc(10 * sizeof(film));
    }

    for (int i = 0; i < 5; ++i) {
        printf("Diretor %d\n", i + 1);
        puts("Nome:");
        fgets(v[i].nome, 19, stdin);
        fflush(stdin);
        do {
            puts("Quantidade de filmes:");
            scanf("%d", &v[i].quantfilmes);
            clearbuffer();
            if (v[i].quantfilmes > 10) {
                puts("Numero de filmes nao suportado");
            } else {
                aux++;
            }
        } while (aux < 0);

        for (int j = 0; j < v[i].quantfilmes; ++j) {
            printf("Filme %d\n", j + 1);
            puts("Nome:");
            fgets(m[i][j].nome, 24, stdin);
            fflush(stdin);

            puts("Ano:");
            fgets(m[i][j].ano, 4, stdin);
            fflush(stdin);

            puts("Duracao:");
            scanf("%f", &m[i][j].duracao);
            fflush(stdin);
            system("cls");
        }
        system("cls");
    }

    puts("Nome:");
    fgets(nome, 63, stdin);
    for (int j = 0; j < 5; ++j)
        if (strcmp (nome, v[j].nome) == 0) {
            printf("Nome: %s", v[j].nome);
            if (v[j].quantfilmes != 0) {
                puts("Filmes:");
                for (int i = 0; i < v[j].quantfilmes; ++i) {
                    printf("Nome: %s", m[j][i].nome);
                    printf("Ano: %s\n", m[j][i].ano);
                    printf("Duracao: %.2f\n", m[j][i].duracao);
                    puts("==================");
                }
            }
        } else {
            puts("Filmes inexistentes");
        }

    system("pause");
}

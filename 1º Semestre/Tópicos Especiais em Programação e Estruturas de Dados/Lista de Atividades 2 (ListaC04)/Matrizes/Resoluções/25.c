#include <stdio.h>
#include <stdlib.h>

int posicao(int **a);
int valores(int **a);
void nova_jogada(int **a);

struct posicao {
    int linha;
    int coluna;
}p;

void colocar(int **a, int aux) {
    a[p.linha][p.coluna] = aux;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    nova_jogada(a);
}

void nova_jogada(int **a) {
    int new;
    printf("[1] Nova jogada\n[0] Sair\n");
    scanf("%d", &new);
    if (new == 1)
        posicao(a);
    else
        exit(0);
}

int valores(int **a) {
    int aux;
    puts("[-1] X");
    puts("[1] O");
    scanf("%d", &aux);

    colocar(a, aux);
}

int posicao(int **a) {
    puts("Linha:");
    scanf("%d", &p.linha);

    puts("Coluna:");
    scanf("%d", &p.coluna);

    valores(a);
}

int main() {
    int **a;

    a = malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; ++i) {
        a[i] = malloc(3 * sizeof(int));
    }

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            a[i][j] = 0;

    posicao(a);

    system("pause");
}
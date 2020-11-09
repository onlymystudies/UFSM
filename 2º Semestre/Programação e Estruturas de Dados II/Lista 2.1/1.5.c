#include "matriz.h"

int main() {
    int Linhas, Colunas;
    printf("Linhas:\n");
    scanf("%d", &Linhas);
    printf("Colunas:\n");
    scanf("%d", &Colunas);

    Matriz *mat = cria(Linhas, Colunas);
    Matriz *mattrans = cria(Colunas, Linhas);

    for (int l = 0; l < linhas(mat); ++l) {
        for (int c = 0; c < colunas(mat); ++c) {
            atribui(mattrans, c, l, acessa(mat, l, c));
        }
    }

    libera(mat);
    libera(mattrans);
    system("pause");
}
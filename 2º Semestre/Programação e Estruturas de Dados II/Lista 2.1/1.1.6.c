#include "matriz.h"

int main() {
    float valor;
    float valor_maior, valor_menor;

    Matriz *mat = cria(1, 3);
    Matriz *matordena = cria(1, 3);

    for (int k = 0; k < 3; ++k) {
        printf("Valor %d:\n", k + 1);
        scanf("%f", &valor);
        atribui(mat, 0, k, valor);
    }

    for (int k = 0; k < 3; ++k) {
        if (k == 0) {
            valor_maior = acessa(mat, 0, 2);
            atribui(matordena, 0, 2, valor_maior);
            valor_menor = acessa(mat, 0, 2);
            atribui(matordena, 0, 0, valor_menor);
        }
        if (acessa(mat, 0, k) > valor_maior) {
            valor_maior = acessa(mat, 0, k);
            atribui(matordena, 0, 2, valor_maior);
        }
        if (acessa(mat, 0, k) < valor_menor) {
            valor_menor = acessa(mat, 0, k);
            atribui(matordena, 0, 0, valor_menor);
        }
        if (acessa(mat, 0, k) < valor_maior && acessa(mat, 0, k) > valor_menor)
            atribui(matordena, 0, 1, acessa(mat, 0, k));
    }

    printf("Crescente\n");
    for (int k = 0; k < 3; ++k)
        printf("%.0f\n", acessa(matordena, 0, k));
    printf("Decrescente\n");
    for (int k = 2; k > -1; --k)
        printf("%.0f\n", acessa(matordena, 0, k));
    libera(mat);
    libera(matordena);
    system("pause");
}
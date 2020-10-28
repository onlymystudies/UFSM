#include <stdio.h>
#include <stdlib.h>

typedef struct carros {
    char marca[15];
    char ano;
    float preco;
}carros;

int main() {
    carros *car = malloc(5 * sizeof(carros));
    float valor;

    for (int i = 0; i < 5; ++i) {
        printf("Carro %d\n", i + 1);
        puts("Marca:");
        fgets(car[i].marca, 15, stdin);
        puts("Ano:");
        scanf("%s", &car[i].ano);
        puts("Preco:");
        scanf("%f", &car[i].preco);
        fflush(stdin);
        system("cls");
    }

    puts("Valor:");
    scanf("%f", &valor);
    system("cls");

    for (int i = 0; i < 5; ++i) {
        if (car[i].preco < valor) {
            printf("Carro %d\n", i + 1);
            printf("Marca: %s", car[i].marca);
            printf("Ano: %c\n", car[i].ano);
            printf("Preco: %.2f\n", car[i].preco);
            puts("================");
        }
    }

    system("pause");
}
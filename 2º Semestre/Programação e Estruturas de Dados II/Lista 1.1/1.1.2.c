/* Problema 1.1.2
 * Tem-se um conjunto de dados contendo a altura e o sexo (masculino, feminino) de 50 pessoas.
 * Fazer um algoritmo que calcule e escreva:
 * a maior e a menor altura do grupo
 * a média de altura das mulheres
 * número de homens
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_buffer() {
    int c; while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int     quantidade_masculino = 0;
    float   altura_feminino      = 0,
            maior_altura,
            menor_altura,
            altura;
    char    sexo[10];

    for (int i = 0; i < 50; ++i) {
        printf("Pessoa %d\n", i + 1);
        printf("Sexo:\n");
        fgets(sexo, 10, stdin);
        fflush(stdin);
        printf("Altura:\n");
        scanf("%f", &altura);
        clear_buffer();
        if (i == 0) menor_altura = altura; maior_altura = altura;
        if (altura > maior_altura) maior_altura = altura;
        if (altura < menor_altura) menor_altura = altura;
        if (strncmp (sexo, "masculino", 9) == 0) quantidade_masculino++;
        if (strncmp (sexo, "feminino",  8) == 0) altura_feminino += altura;
    }

    printf("Maior altura: %.2f\n", maior_altura);
    printf("Menor altura: %.2f\n", menor_altura);
    printf("Media altura feminina: %.2f\n", altura_feminino / 50);
    printf("Numero de homens: %d\n", quantidade_masculino);
    system("pause");
}
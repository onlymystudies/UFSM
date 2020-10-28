/* Problema 1.1.5
 * Supondo que a população de um pais A seja da ordem de 90.000.000 de habitantes com uma taxa anual de crescimento de 3% e que a população de um pais B seja,
 * aproximadamente, de 200.000.000 de habitantes com uma taxa anual de crescimento de 1,5%, fazer um algoritmo que calcule e escreva o número de anos necessários para que a população do pais A
 * ultrapasse ou iguale a população do pais B, mantidas essas taxas de crescimento.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int pais_A  = 90000000, // 3% = 2.700.000
        pais_B  = 200000000, // 1,5% = 3.000.000
        anos    = 0;

    for (;;) {
        pais_A += 2700000;
        pais_B += 3000000;
        if (pais_A > pais_B) break;
        anos++;
    }

    printf("O tempo necessario para o pais A ultrapassar ou igualar a populacao do pais B foi de %d anos\n", anos);
    system("pause");
}
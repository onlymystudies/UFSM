/* Problema 1.1.6
 * Um determinado material radioativo perde metade de sua massa a cada 50 segundos. Dada a massa inicial, em gramas, fazer um algoritmo que determine o tempo necessário para que essa massa se torne menor do que 0,5 grama.
 * Escreva a massa inicial, a massa final e o tempo calculado em horas, minutos e segundos.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int     material_radioativo     =   1000000000, // gramas
            perde_massa             =   50,
            tempo                   =   0,
            minutos                 =   0,
            segundos                =   0,
            horas                   =   0;

    do {
        if (tempo == perde_massa) {
            material_radioativo /= 2;
            perde_massa += 50;
        }
        if (segundos == 60) {
            minutos++;
            segundos = 0;
        }
        if (minutos == 60) {
            horas++;
            minutos = 0;
        }
        segundos++;
        tempo++;
    } while (material_radioativo > 0.5);

    printf("Horas: %d minutos: %d segundos: %d\n", horas, minutos, segundos);
    system("pause");
}
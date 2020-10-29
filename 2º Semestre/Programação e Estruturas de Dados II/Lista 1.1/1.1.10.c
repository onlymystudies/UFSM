/* Problema 1.1.10
 * Foi feita uma pesquisa de audi�ncia de canal de TV em v�rias casas de uma certa cidade, num determinado dia.
 * Para cada casa visitada, � fornecido o n�mero do canal (4,5,7,12) e o n�mero de pessoas que o estavam assistindo naquela casa.
 * Se a televis�o estivesse desligada, nada era anotado, ou seja, esta casa n�o entrava na pesquisa.
 * Fazer um algoritmo que:
 * leia um n�mero indeterminado de dados, sendo que o flag corresponde ao n�mero
 * de canal igual a zero.
 * calcule a porcentagem de audi�ncia para cada emissora
 * escreva o n�mero do canal e a sua respectiva porcentagem.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int tv, canal, pessoas_assistindo, total_assistindo = 0;
    int canal4 = 0, canal5 = 0, canal7 = 0, canal12 = 0;

    while (1) {
        printf("1 - TV Ligada\n0 - TV Desligada\n");
        scanf("%d", &tv);
        if (tv != 0) {
            printf("Canal\n");
            scanf("%d", &canal);
            if (canal == 0) break;
            printf("Numero de pessoas assistindo\n");
            scanf("%d", &pessoas_assistindo);
            total_assistindo += pessoas_assistindo;
            if (canal == 4) canal4 += pessoas_assistindo;
            if (canal == 5) canal5 += pessoas_assistindo;
            if (canal == 7) canal7 += pessoas_assistindo;
            if (canal == 12) canal12 += pessoas_assistindo;
        }
    }

    printf("4: %d%%\n", (canal4 * 100) / total_assistindo);
    printf("5: %d%%\n", (canal5 * 100) / total_assistindo);
    printf("7: %d%%\n", (canal7 * 100) / total_assistindo);
    printf("12: %d%%\n", (canal12 * 100) / total_assistindo);
    system("pause");
}
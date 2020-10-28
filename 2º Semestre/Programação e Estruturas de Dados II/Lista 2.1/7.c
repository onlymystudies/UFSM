/* Problema 7
 * Repita o procedimento anterior, mas para um vetor de tamanho indeterminado.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numeros        = NULL,
            *mais_numeros   = NULL;
    int contador        = 0,
            entrada,
            ordenar, ordenar_aux;

    printf("0 - Sair\n");
    do {
        printf("Valor: %d\n", contador + 1);
        scanf("%d", &entrada);
        contador++;
        mais_numeros = (int *) realloc(numeros, contador * sizeof(int));
        if (mais_numeros != NULL) numeros = mais_numeros; numeros[contador - 1] = entrada;
    } while (entrada != 0);
    // Insertion Sort
    for (int i = 0; i < contador; ++i) {
        ordenar = i;
        while ((ordenar != 0) && numeros[ordenar] > numeros[ordenar - 1]) {
            ordenar_aux = numeros[ordenar];
            numeros[ordenar] = numeros[ordenar - 1];
            numeros[ordenar - 1] = ordenar_aux;
            ordenar--;
        }
    }

    printf("Crescente:\n");
    for (int i = contador - 1; i > 0; --i) printf("%d\n", numeros[i]);
    printf("Decrescente:\n");
    for (int i = 0; i < contador; ++i) printf("%d\n", numeros[i]);
    system("pause");
}
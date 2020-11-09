/* Problema 1
 * Leia uma palavra e verifique se é um palíndromo, isto é, se sua leitura,
 * a partir de qualquer direção, sempre apresenta a mesma sequência.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *vetor = (char *) malloc(sizeof(char));
    int contador = 0;
    printf("Palavra:\n");
    scanf("%s", vetor);

    for (unsigned int i = strlen(vetor); i > 0; --i) {
        if (contador == strlen(vetor)/2)
            break;
        if (vetor[contador] == vetor[i])
            contador++;
    }
    if (contador == strlen(vetor)/2)
        printf("%s e um palindromo\n", vetor);
    else
        printf("%s nao e um palindromo\n", vetor);
    system("pause");
}

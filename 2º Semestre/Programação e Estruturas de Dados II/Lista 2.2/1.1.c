/* Problema 1
 * Leia uma palavra e verifique se � um pal�ndromo, isto �, se sua leitura,
 * a partir de qualquer dire��o, sempre apresenta a mesma sequ�ncia.
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

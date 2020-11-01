/* Implemente um código que gere o Triângulo de Pascal para n linhas e que permita testar a validade de um
 * dado Triângulo através da validação de suas propriedades.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void validar(int numero, int **matriz) {
    printf("1) Todas as linhas tem o numero 1 como seu primeiro e ultimo elemento.\n");
    int primeiro_valido = 0, ultimo_valido = 0;
    for (int linha = 0; linha < numero; linha++) {
        for (int coluna = 0; coluna <= linha; coluna++) {
            if (matriz[linha][0] == 1)
                primeiro_valido++;
            if (matriz[linha][linha] == 1)
                ultimo_valido++;
        }
        if (primeiro_valido > 0 && ultimo_valido > 0)
            printf("Linha %d valida\n", linha);
        else
            printf("Linha %d nao valida\n", linha);
        primeiro_valido = 0;
        ultimo_valido = 0;
    }
    printf("2) O restante dos numeros de uma linha e formado pela adicao dos dois numeros mais proximos da linha acima.\n");
    int contador = 0, primeiro_proximo = 0, segundo_proximo = 0;
    for (int linha = 0; linha < numero; linha++) {
        for (int coluna = 0; coluna <= linha; coluna++) {
            if (linha > 1 && coluna > 0) {
                if (matriz[linha][coluna] == matriz[linha - contador][coluna - contador])
                    primeiro_proximo++;
                if (matriz[linha][coluna] == matriz[linha - contador + 1][coluna - contador + 1])
                    segundo_proximo++;
            }

            contador++;
        }
        if (linha > 1) {
            if (primeiro_proximo != 0 && segundo_proximo != 0)
                printf("Linha %d proximos valido\n", linha);
            else
                printf("Linha %d proximos invalido\n", linha);
        }
        contador = 0;
        primeiro_proximo = 0;
        segundo_proximo = 0;
    }
    printf("3) Os elementos de uma mesma linha equidistantes dos extremos tem valores iguais.\n");
    int equidistantes_iguais = 0;
    for (int linha = 0; linha < numero; linha++) {
        for (int coluna = 0; coluna <= linha; coluna++) {
            if (matriz[linha][0] == matriz[linha][linha])
                equidistantes_iguais++;
        }
        if (equidistantes_iguais != 0)
            printf("Linha %d equidistantes valido\n", linha);
        else
            printf("Linha %d equidistantes invalido\n", linha);
        equidistantes_iguais = 0;
    }
    printf("4) A soma dos elementos de uma linha de numerador (n) sera igual a 2n.\n");
    int soma = 0, potencia = 0;
    for (int linha = 0; linha < numero; linha++) {
        for (int coluna = 0; coluna <= linha; coluna++) {
            soma += matriz[linha][coluna];
        }
        if (soma == pow(2, potencia))
            printf("Linha %d potencia de 2 valido\n", linha);
        else
            printf("Linha %d potencia de 2 invalido\n", linha);
        potencia++;
        soma = 0;
    }

    return;
}

void preencher(int numero, int **matriz) {
    matriz[0][0] = 1;
    for (int i = 1; i < numero; i++) {
        matriz[i][0] = 1;
        matriz[i][i] = 1;
        for (int j = 1; j < i; j++) {
            matriz[i][j] = matriz[i-1][j] + matriz[i-1][j-1];
        }
    }

    return;
}

void imprimir(int numero, int **matriz) {
    for (int i = 0; i < numero; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%5d ", matriz[i][j]);
        }
        printf("\n");
    }

    return;
}

int main() {
    int numero, **matriz;

    printf("Numero de linhas\n");
    scanf("%d", &numero);
    matriz = (int **) malloc(numero*sizeof(int *));
    for (int i = 0; i < numero; i++) {
        matriz[i] = (int *) malloc((i+1)*sizeof(int));
    }
    if (numero <= 0) {
        return(1);
    }

    preencher(numero, matriz);
    validar(numero, matriz);
    imprimir(numero, matriz);
    system("pause");
}
#include <stdio.h>
#include <math.h>

float primeira_regra(float numero) {
    int raiz_quadrada = sqrt(numero);
    if (fmod(raiz_quadrada, 2) == 1 || fmod(raiz_quadrada, 2) == 0)
        printf("%.1f e uma raiz exata\n", numero);
    else
        printf("%.1f nao e uma raiz exata\n", numero);
    return numero;
}

float segunda_regra(float numero) {
    int nao_perfeito = 0;
    char ultimos_algarismos[] = "2378";
    for (int i = 0; i < 4; ++i) {
        if (numero == ultimos_algarismos[i]) {
            nao_perfeito++;
            break;
        }
    }
    if (nao_perfeito == 0)
        printf("%.1f e um numero perfeito\n", numero);
    else
        printf("%.1f nao e um numero perfeito\n", numero);
    return numero;
}

float terceira_regra(float numero) {
    int raiz;
    if ((int) numero % 2 == 0) {
        raiz = sqrt(numero);
        printf("%.1f e um quadradro perfeito\n", numero);
        printf("raiz quadrada %d\n", raiz);
    } else {
        printf("%.1f nao e um quadradro perfeito\n", numero);
    }
    return numero;
}

float quarta_regra(float numero) {
    int par = 0;
    for (int i = 0; i < numero; i += 2) {
        if (numero / 4 == i)
            par++;
    }
    if (par == 0)
        printf("%.1f nao e um numero par\n", numero);
    else
        printf("%.1f e um numero par\n", numero);
    return numero;
}

float quinta_regra(float numero) {
    int impar = 0;
    for (int i = -1; i < numero; i += 2) {
        if (numero / 2 == i)
            impar++;
    }
    if (impar == 0) {
        printf("%.1f nao e um numero impar\n", numero);
        printf("raiz %.1f\n", sqrt(numero));
    }
    else {
        printf("%.1f e um numero impar\n", numero);
        printf("raiz %.1f\n", sqrt(numero));
    }
    return numero;
}

float sexta_regra(float numero) {
    int impar = 0;
    for (int i = -1; i < numero; i += 2) {
        if (numero / 2 == i)
            impar++;
    }
    if (impar == 0 || (int) numero % 2 == 0) {
        if ((int) numero % 8 == 1)
            printf("%.1f e um quadrado perfeito impar\n", numero);
        else
            printf("%.1f nao e um quadrado perfeito impar\n", numero);
    }
    else {
        printf("%.1f e um numero impar\n", numero);
        printf("raiz %.1f\n", sqrt(numero));
    }
    return numero;
}
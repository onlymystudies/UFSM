// Matriz simetrica com vetor simples

// Usando um vetor simples para armazenar os elementos da matriz, dimensionamos o vetor
// com apenas s elementos. A estrutura que representa a matriz pode ser dada por:

#include <stdio.h>
#include <stdlib.h>

struct matsim {
    int dim; /* matriz obrigatoriamente quadrada */
    float* v;
};

typedef struct matsim MatSim;

// Uma fun??o para criar uma matriz sim?trica pode ser dada por:

MatSim* cria (int n)
{
    int s = n*(n+1)/2;
    MatSim* mat = (MatSim*) malloc(sizeof(MatSim));
    mat->dim = n;
    mat->v = (float*) malloc(s*sizeof(float));
    return mat;
}

// O acesso aos elementos da matriz deve ser feito como se estiv?ssemos representando a
// matriz inteira. Se for um acesso a um elemento acima da diagonal (i<j), o valor de retorno
// ? o elemento sim?trico da parte inferior, que est? devidamente representado. O
// endere?amento de um elemento da parte inferior da matriz ? feito saltando-se os elementos
// das linhas superiores. Assim, se desejarmos acessar um elemento da quinta linha (i=4),
// devemos saltar 1+2+3+4 elementos, isto ?, devemos saltar 1+2+...+i elementos, ou seja,
// i*(i+1)/2 elementos. Depois, usamos o ?ndice j para acessar a coluna.

float acessa (MatSim* mat, int i, int j)
{
    int k; /* ?ndice do elemento no vetor */
    if (i<0 || i>=mat->dim || j<0 || j>=mat->dim) {
        printf("Acesso inv?lido!\n");
        exit(1);
    }
    if (i>=j)
        k = i*(i+1)/2 + j;
    else
        k = j*(j+1)/2 + i;
    return mat->v[k];
}

void atribui(MatSim* mat, int i, int j, float v) {
    int k;
    if (i >= j)
        k = i * (i + 1) / 2 + j;
    else
        k = j * (j + 1) / 2 + i;
    mat->v[k] = v;
}

void libera(MatSim *mat) {
    free(mat->v);
    free(mat);
}


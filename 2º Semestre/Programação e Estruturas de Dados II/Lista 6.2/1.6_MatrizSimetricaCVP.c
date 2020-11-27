// Matriz sim�trica com vetor de ponteiros

// A estrat�gia de trabalhar com vetores de ponteiros para matrizes alocadas dinamicamente �
// muito adequada para a representa��o matrizes sim�tricas. Numa matriz sim�trica, para
// otimizar o uso da mem�ria, armazenamos apenas a parte triangular inferior da matriz. Isto
// significa que a primeira linha ser� representada por um vetor de um �nico elemento, a
// segunda linha ser� representada por um vetor de dois elementos e assim por diante. Como o
// uso de um vetor de ponteiros trata as linhas como vetores independentes, a adapta��o desta
// estrat�gia para matrizes sim�tricas fica simples.
// O tipo da matriz pode ser definido por:

#include <stdio.h>
#include <stdlib.h>

struct matsim {
    int dim;
    float** v;
};

typedef struct matsim MatSim;

// Para criar a matriz, basta alocarmos um n�mero vari�vel de elementos para cada linha. O
// c�digo abaixo ilustra uma poss�vel implementa��o:

MatSim* cria (int n)
{
    int i;
    MatSim* mat = (MatSim*) malloc(sizeof(MatSim));
    mat->dim = n;
    mat->v = (float**) malloc(n*sizeof(float*));
    for (i=0; i<n; i++)
        mat->v[i] = (float*) malloc((i+1)*sizeof(float));
    return mat;
}

// O acesso aos elementos � natural, desde que tenhamos o cuidado de n�o acessar elementos
// que n�o estejam explicitamente alocados (isto �, elementos com i<j).

float acessa (MatSim* mat, int i, int j)
{
    if (i<0 || i>=mat->dim || j<0 || j>=mat->dim) {
        printf("Acesso inv�lido!\n");
        exit(1);
    }
    if (i>=j)
        return mat->v[i][j];
    else
        return mat->v[j][i];
}

//  Finalmente, observamos que exatamente as mesmas t�cnicas poderiam ser usadas para
// representar uma matriz �triangular�, isto �, uma matriz cujos elementos acima (ou abaixo)
// da diagonal s�o todos nulos. Neste caso, a principal diferen�a seria na fun��o acessa, que
// teria como resultado o valor zero em um dos lados da diagonal, em vez acessar o valor
// sim�trico.

void atribui(MatSim *mat, int i, int j, float v) {
    mat->v[i][j] = v;
}

void libera(MatSim *mat) {
    for (size_t i = 0; i < mat->dim; ++i)
        free(mat->v[i]);
    free(mat->v);
    free(mat);
}
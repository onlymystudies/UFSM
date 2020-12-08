/* Nome: Leonardo Zamboni Nunes 202012828
 * Codigo referencia: MatrizSimetricaCPV.cpp
 *
 * (2,0 Pontos) Considerando o código “MatrizSimetricaCVP.c” (Matriz simétrica com vetor de
 * ponteiros), dado em aula, implemente:
 */
#include <stdio.h>
#include <stdlib.h>

struct matsim {
    int dim;
    float** v;
};

typedef struct matsim MatSim;

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

float acessa (MatSim* mat, int i, int j)
{
    if (i<0 || i>=mat->dim || j<0 || j>=mat->dim) {
        printf("Acesso invalido!\n");
        exit(1);
    }
    if (i>=j)
        return mat->v[i][j];
    else
        return mat->v[j][i];
}

void insere_numeros(MatSim* mat, int TAM, float numero) {
    float aux = -1, aux2 = 1;
    int triangular = TAM - 1;

    for (size_t i = 0; i < TAM; ++i)
        for (size_t j = 0; j < TAM; ++j)
            mat->v[i][j] = numero;

    for (size_t linha = 0; linha < TAM; ++linha) {
        for (size_t coluna = 0; coluna < TAM - triangular; ++coluna) {
            printf(" %.f", aux + aux2);
            aux2++;
        }
        aux2 = 1; aux += 10;
        triangular--;
        printf("\n");
    }
}

void mostra_matriz(MatSim* mat, int TAM) {
    for (size_t i = 0; i < TAM; ++i) {
        for (size_t j = 0; j < TAM; ++j)
            printf(" %f", acessa (mat, i, j));
        puts("");
    }
}

int main(void) {
    MatSim *matriz = cria(4);
    insere_numeros(matriz, 4, -1);
    puts("");
    mostra_matriz(matriz, 4);
    system("pause");
}
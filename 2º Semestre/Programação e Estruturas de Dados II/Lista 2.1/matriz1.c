// O arquivo matriz1.c apresenta a implementação através de vetor simples

#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include "matriz.h"

struct matriz {
	int lin;
	int col;
	float* v;
};

Matriz* cria (int m, int n) {
	Matriz* mat = (Matriz*) malloc(sizeof(Matriz));
	if (mat == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}
	mat->lin = m;
	mat->col = n;
	mat->v = (float*) malloc(m*n*sizeof(float));
	return mat;
}

void libera (Matriz* mat){
	free(mat->v);
	free(mat);
}

float acessa (Matriz* mat, int i, int j) {
	int k; /* índice do elemento no vetor */
	if (i<0 || i>=mat->lin || j<0 || j>=mat->col) {
		printf("Acesso inválido!\n");
		exit(1);
	}
	k = i*mat->col + j;
	return mat->v[k];
}

void atribui (Matriz* mat, int i, int j, float v) {
	int k; /* índice do elemento no vetor */
	if (i<0 || i>=mat->lin || j<0 || j>=mat->col) {
		printf("i = %d\n",i);
		printf("Atribuição inválida!\n");
		exit(1);
	}
	k = i*mat->col + j;
	mat->v[k] = v;
}

int linhas (Matriz* mat) {
	return mat->lin;
}

int colunas (Matriz* mat) {
	return mat->col;
}

Matriz *m;
int ordem, i, j;
float numero;

main() {
	puts("Ordem da matriz: ");
	scanf("%d",&ordem);
	m = cria (ordem, ordem);
	for(i=0; i<ordem; i++)
		for(j=0; j<ordem; j++) {
			printf("Entre c elemento [%d %d]", i, j);
			scanf("%f",&numero);
			// void atribui (Matriz* mat, int i, int j, float v) {
			atribui(m, i, j, numero);
		}
	printf("Numero de linhas da matriz %d\n", linhas(m));
	printf("Numero de colunas da matriz %d\n", colunas(m));
	puts("Elementos da matriz:");
	for(i=0; i<ordem; i++)
		for(j=0; j<ordem; j++) {
			printf("Elemento [%d %d] %f\n", i, j, acessa (m, i, j));
		}
	libera (m);
}

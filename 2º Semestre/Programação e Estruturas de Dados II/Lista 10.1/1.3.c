/* O TAD ABB deve implementar as seguintes funções:
 * NoABB *abb_cria();
 * NoABB *abb_insere(NoABB *a, int mat, char *nome, float media);
 * void abb_imprime(NoABB *a);
 * void abb_libera(NoABB *a);
 * void abb_alunoComMaiorMedia(NoABB *a);
 * int abb_contaAprovados(NoABB *a);
 * int abb_contaAprovados(NoABB *a);
 * int abb_contaIntervalo(NoABB *a, float min, float max);
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    int matricula;
    float media;
    char *nome;
}Aluno;

typedef struct arvore{
    Aluno *aluno;
    struct arvore *esquerda;
    struct arvore *direita;
}Arvore;

Arvore *abb_cria(void) {
    return NULL;
}

void abb_libera (Arvore *arvore) {
    Arvore *p = arvore->esquerda;
    while (p!=NULL) {
        Arvore *t = p->direita;
        abb_libera(p);
        p = t;
    }
    free(arvore->aluno);
    free(arvore);
}

void abb_imprime(Arvore *arvore) {
    if (arvore) {
        abb_imprime(arvore->esquerda);
        printf("matricula %d media %.1f nome %s\n", arvore->aluno->matricula, arvore->aluno->media, arvore->aluno->nome);
        abb_imprime(arvore->direita);
    }
}

Arvore *abb_insere (Arvore *arvore, int matricula, char *nome, float media) {
    if (!arvore) {
        arvore = (Arvore *) malloc(sizeof(Arvore));
        arvore->aluno = (Aluno *) malloc(sizeof(Aluno));
        arvore->aluno->matricula = matricula;
        arvore->aluno->media = media;
        arvore->aluno->nome = nome;
        arvore->esquerda = arvore->direita = NULL;
    }
    else if (arvore->aluno->media > media)
        arvore->esquerda = abb_insere(arvore->esquerda, matricula, nome, media);
    else
        arvore->direita = abb_insere(arvore->direita, matricula, nome, media);
    return arvore;
}

void abb_alunoComMaiorMedia(Arvore *arvore) {
    if (!arvore)
        return;
    else if (arvore->direita == NULL)
        printf("matricula %d media %.1f nome %s\n", arvore->aluno->matricula, arvore->aluno->media, arvore->aluno->nome);
    return abb_alunoComMaiorMedia(arvore->direita);
}

int abb_contaAprovados(Arvore *arvore) {
    if (arvore) {
        if (arvore->aluno->media >= 5)
            return 1 + abb_contaAprovados(arvore->direita) + abb_contaAprovados(arvore->esquerda);
        else
            return abb_contaAprovados(arvore->esquerda) + abb_contaAprovados(arvore->direita);
    }
    return 0;
}

void abb_imprimeAprovados(Arvore *arvore) {
    if (arvore) {
        if (arvore->aluno->media >= 5) {
            abb_imprimeAprovados(arvore->direita);
            printf("matricula %d media %.1f nome %s\n", arvore->aluno->matricula, arvore->aluno->media, arvore->aluno->nome);
            abb_imprimeAprovados(arvore->esquerda);
        }
        else {
            abb_imprimeAprovados(arvore->esquerda);
            abb_imprimeAprovados(arvore->direita);
        }
    }
}

int abb_contaIntervalo(Arvore *arvore, float minimo, float maximo) {
    if (arvore) {
        if (arvore->aluno->media >= minimo && arvore->aluno->media <= maximo)
            return 1 + abb_contaIntervalo(arvore->direita, minimo, maximo) + abb_contaIntervalo(arvore->esquerda, minimo, maximo);
        else
            return abb_contaIntervalo(arvore->esquerda, minimo, maximo) + abb_contaIntervalo(arvore->direita, minimo, maximo);
    }
    return 0;
}

int main(void) {
    Arvore *abb = abb_cria();
    abb = abb_insere(abb, 456124, "Pedro Duarte", 7.5);
    abb = abb_insere(abb, 453984, "Ana Silva", 8.8);
    abb = abb_insere(abb, 365597, "Joao Filho", 2.5);
    abb = abb_insere(abb, 687451, "Maria Gomes", 10.0);
    abb = abb_insere(abb, 364512, "Silvio Lins", 4.8);
    abb = abb_insere(abb, 984544, "Marcia Morais", 7.8);
    abb = abb_insere(abb, 698421, "Bruno Rodrigues", 2.0);
    abb = abb_insere(abb, 784512, "Thais Silva", 6.5);
    abb = abb_insere(abb, 694231, "Ricardo Costa", 9.5);
    abb = abb_insere(abb, 126411, "Julia Neves", 8.0);
    printf("Alunos em ordem crescente de media:\n");
    abb_imprime(abb);
    printf("\nAluno com maior media:\n");
    abb_alunoComMaiorMedia(abb);
    printf("\nNumero de alunos aprovados: %d\n", abb_contaAprovados(abb));
    printf("\nAlunos aprovados em ordem decrescente: \n");
    abb_imprimeAprovados(abb);
    printf("\nNumero de alunos entre 2.5 e 8.5: %d\n",
           abb_contaIntervalo(abb, 2.5, 8.5));
    system("pause");
    return 0;
}
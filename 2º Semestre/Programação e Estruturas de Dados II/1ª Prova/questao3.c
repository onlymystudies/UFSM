/* Nome: Leonardo Zamboni Nunes 202012828
 * Codigo referencia: FilaV.c
 *
 * Implemente “void insere_zeros (Fila2* f) {}”, que, ao percorrer a fila do início para o
 * fim, vai, para cada número par encontrado, inserir um zero no início da fila e, no sentido contrário,
 * para cada número primo encontrado, vai inserir um zero no fim. Ex.: fila original 3, 2, 1, 4, 5, 6; fila
 * modificada: 0, 0, 0, 6, 5, 4, 1, 2, 3, 0, 0, 0. Considere a função main() dada abaixo.
 */
#include <stdio.h>
#include <stdlib.h>

struct no2{
    float info;
    struct no2 *proximo;
    struct no2 *anterior;
};
typedef struct no2 No2;

struct fila2{
    No2 *inicio;
    No2 *final;
};
typedef struct fila2 Fila2;

Fila2 *cria(void) {
    Fila2 *fila = (Fila2 *) malloc(sizeof(Fila2));
    fila->inicio = fila->final = NULL;
    return fila;
}

void insereFinal(Fila2 *fila, float valor) {
    No2 *novo = (No2 *) malloc(sizeof(No2));
    novo->info = valor;
    novo->proximo = NULL;
    novo->anterior = fila->final;
    if (fila->final)
        fila->final->proximo = novo;
    if (!fila->inicio)
        fila->inicio = novo;
    fila->final = novo;
}

void insereInicio(Fila2 *fila, float valor) {
    No2 *novo = (No2 *) malloc(sizeof(No2));
    novo->info = valor;
    novo->proximo = fila->inicio;
    novo->anterior = NULL;
    if (fila->inicio)
        fila->inicio->anterior = novo;
    if (!fila->final)
        fila->final = novo;
    fila->inicio = novo;
}

void insere_zeros(Fila2 *fila) {
    No2 *percorre = fila->inicio;
    No2 *percorre2 = fila->inicio;

    while (percorre) {
        if ((int) percorre->info % 2 == 0)
            insereInicio(fila, 0);
        percorre = percorre->proximo;
    }

    while (percorre2) {
        for (size_t i = 0; i <= percorre2->info / 2; ++i) {
            if ((int) percorre2->info % i == 0) {
                insereFinal(fila, 0);
                break;
            }
        }
        percorre2 = percorre2->proximo;
    }
}

void imprime(Fila2 *fila) {
    No2 *percorre = fila->inicio;
    while (percorre) {
        printf("valor %.2f\n", percorre->info);
        percorre = percorre->proximo;
    }
}

int main(void) {
    Fila2 *fila = cria();
    insereInicio(fila, 1);
    insereInicio(fila, 2);
    insereInicio(fila, 3);
    insereFinal(fila, 4);
    insereFinal(fila, 5);
    insereFinal(fila, 6);
    imprime(fila);
    puts("|------Insere_Zeros--------|");
    insere_zeros(fila);
    imprime(fila);
    system("pause");
}
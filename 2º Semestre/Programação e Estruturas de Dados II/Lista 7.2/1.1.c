/* Problema 1
 * Flávio Josephus foi um historiador judeu famoso do primeiro século, no momento da destruição do Segundo
 * Templo. Durante a guerra judaico-romana, ele ficou preso em uma caverna com um grupo de 40 soldados
 * cercados pelos romanos. A lenda diz que eles preferiam o suicídio a serem capturados; então os judeus
 * decidiram formar um círculo e, procedendo à sua volta, para matar cada terceira pessoa restante até que
 * ninguém fosse deixado. Josephus, que não queria de morrer, rapidamente encontrou o local seguro no círculo
 * e assim permaneceu vivo.
 * Uma maneira simples de resolver este problema é utilizar a estrutura de dados fila e realizar uma simulação
 * para descobrir qual é a posição do último a morrer no círculo formado.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct filaNo{
    int valor;
    struct filaNo *proximo;
}FilaNo;

typedef struct fila{
    FilaNo *inicio;
    FilaNo *final;
}Fila;

Fila *cria(void) {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    fila->inicio = fila->final = NULL;
    return fila;
}

FilaNo *criaNo(int valor) {
    FilaNo *filaNo = (FilaNo *) malloc(sizeof(FilaNo));
    filaNo->valor = valor;
    filaNo->proximo = NULL;
    return filaNo;
}

void insere(Fila *fila, int valor) {
    FilaNo *novo = criaNo(valor);
    if (fila->inicio == NULL)
        fila->inicio = novo;
    else
        fila->final->proximo = novo;
    fila->final = novo;
    novo->proximo = fila->inicio;
}

void imprime(Fila *fila) {
    FilaNo *p = fila->inicio;
    puts("Fila");
    while (1) {
        printf("valor %d\n", p->valor);
        if (p == fila->final)
            break;
        p = p->proximo;
    }
    puts("Fim");
}

int tamanho(Fila *fila) {
    int contador = 0;
    FilaNo *p = fila->inicio;
    while (1) {
        p = p->proximo;
        contador++;
        if (p == fila->final->proximo)
            return contador;
    }
}

void matar(Fila *fila, int primeiro) {
    int intervalo = primeiro;
    FilaNo *anterior = NULL, *percorre = fila->inicio;

    for (size_t i = 1; ; ++i) {
        if (tamanho(fila) <= 1) break;
        if (i == primeiro) {
            primeiro += intervalo;
            if (percorre == fila->inicio)
                fila->inicio = percorre->proximo;
            if (percorre == fila->final)
                fila->final = anterior;
            if (anterior)
                anterior->proximo = percorre->proximo;
            printf("Morreu %d\n", percorre->valor);
        }
        anterior = percorre;
        percorre = percorre->proximo;
    }

    if (!anterior)
        printf("Morreu %d\n", percorre->valor);
    else
        printf("Sobreviveu %d\n", percorre->valor);
}

int main() {
    int pessoas, primeiro;
    Fila *fila = cria();

    printf("Numero de pessoas\n");
    scanf("%d", &pessoas);

    for (size_t i = 1; i <= pessoas; ++i)
        insere(fila, i);

    printf("Primeiro a morrer\n");
    scanf("%d", &primeiro);

    imprime(fila);

    matar(fila, primeiro);

    system("pause");
}
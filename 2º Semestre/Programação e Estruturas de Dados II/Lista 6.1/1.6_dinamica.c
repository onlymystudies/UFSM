#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cidades{
    struct cidades *anterior;
    char cidade[16];
    struct cidades *proximo;
}Cidades;

typedef struct lista{
    char rodovia[6];
    Cidades *cidades;
    struct lista *inicio;
    struct lista *final;
    struct lista *proximo;
}Lista;

Cidades *criaCidades(void) {
    Cidades *inicia = (Cidades *) malloc(sizeof(Cidades));
    inicia->anterior = inicia->proximo = NULL;
    return inicia;
}

Lista *cria(void) {
    Lista *inicia = (Lista *) malloc(sizeof(Lista));
    inicia->proximo = inicia->inicio = inicia->final = NULL;
    return inicia;
}

void insereRodovia(Lista *lista, char *rodovia) {
    Lista *novo = (Lista *) malloc(sizeof(Lista));
    strcpy(novo->rodovia, rodovia);
    novo->cidades = criaCidades();
    novo->proximo = lista->proximo;
    lista->proximo = novo;
    lista->final = novo;
    if (lista->inicio == NULL)
        lista->inicio = novo;
}

void insereCidade(Lista *lista, char *cidade) {
    Cidades *novo = (Cidades *) malloc(sizeof(Cidades));
    strcpy(novo->cidade, cidade);
    novo->proximo = lista->proximo->cidades->proximo;
    novo->anterior = NULL;
    if (lista->proximo->cidades != NULL)
        lista->proximo->cidades->anterior = novo;
    lista->proximo->cidades->proximo = novo;
}

void imprime(Lista *lista) {
    Lista *p;
    Cidades *pc;
    for (p = lista->proximo; p != NULL; p = p->proximo) {
        printf("Rodovia %s\n", p->rodovia);
        if (p->cidades != NULL)
            for (pc = p->cidades->proximo; pc != NULL; pc = pc->proximo)
                printf("Cidade %s\n", pc->cidade);
    }
}

void insereCidadeOrdem(Lista *lista, char *cidade) {
    Cidades *novo = (Cidades *) malloc(sizeof(Cidades));
    strcpy(novo->cidade, cidade);
    Cidades *p;
    for (p = lista->proximo->cidades; p->proximo != NULL; p = p->proximo)
        if (strcmp(p->proximo->cidade, cidade) <= 0)
            break;
    novo->proximo = NULL;
    novo->anterior = NULL;
    if (p != NULL)
        novo->anterior = p;
    if (p->proximo != NULL) {
        novo->proximo = p->proximo;
        p->proximo->anterior = novo;
    }
    p->proximo = novo;
}

Lista *rodoviasCidade(Lista *lista, char *cidade) {
    Lista *rodoviasCidade = cria();
    rodoviasCidade->cidades = NULL;
    Lista *p;
    Cidades *pc;
    for (p = lista->proximo; p != NULL; p = p->proximo) {
        for (pc = p->cidades->proximo; pc != NULL; pc = pc->proximo)
            if (strcmp(pc->cidade, cidade) == 0) {
                Lista *novo = (Lista *) malloc(sizeof(Lista));
                novo->cidades = NULL;
                strcpy(novo->rodovia, p->rodovia);
                novo->proximo = rodoviasCidade->proximo;
                rodoviasCidade->proximo = novo;
                break;
            }
    }
    return rodoviasCidade;
}

int Cruzamento(Lista *lista, char *rodovia1, char *rodovia2) {
    Lista *p1, *p2;
    Cidades *pc1, *pc2;
    for (p1 = lista->proximo; p1 != NULL; p1 = p1->proximo)
        if (strcmp(p1->rodovia, rodovia1) == 0)
            for (p2 = lista->proximo; p2 != NULL; p2 = p2->proximo)
                if (strcmp(p2->rodovia, rodovia2) == 0)
                    for (pc1 = p1->cidades->proximo; pc1 != NULL; pc1 = pc1->proximo)
                        for (pc2 = p2->cidades->proximo; pc2 != NULL; pc2 = pc2->proximo)
                            if (strcmp(pc1->cidade, pc2->cidade) == 0)
                                return 1;
    return 0;
}

int main(void) {
    Lista *lista = cria();
    insereRodovia(lista, "BR123");
    insereCidade(lista, "A");
    insereCidade(lista, "B");
    insereCidade(lista, "D");
    insereCidade(lista, "E");

    insereCidadeOrdem(lista, "C"); // B

    insereRodovia(lista, "BR456");
    insereCidade(lista, "F");
    insereCidade(lista, "G");
    insereCidade(lista, "H");
    insereCidade(lista, "C");

    Lista *listaCidades = rodoviasCidade(lista, "A"); // C

    if (Cruzamento(lista, "BR123", "BR456") == 0) // D
        printf("Nao cruza\n");
    else
        printf("Cruza\n");

    imprime(listaCidades);
    system("pause");
}
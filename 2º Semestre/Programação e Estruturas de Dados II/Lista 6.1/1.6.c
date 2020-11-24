#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10

typedef struct cidades{
    int anterior;
    char cidade[16];
    int proximo;
}Cidades;

typedef struct rodovias{
    char rodovia[6];
    Cidades cidades[TAM];
    int proximo;
}Rodovias;

typedef struct lista{
    int inicio;
    Rodovias rodovias[TAM];
    int final;
}Lista;

void criaCidades(Lista *lista) {
    lista->rodovias[lista->final].cidades[lista->rodovias[lista->final].proximo].proximo = 0;
    lista->rodovias[lista->final].cidades[lista->rodovias[lista->final].proximo].anterior = 0;
}

void criaRodovias(Lista *lista) {
    lista->rodovias[lista->final].proximo = 0;
    criaCidades(lista);
}

Lista *cria(void) {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    lista->inicio = lista->final = 0;
    criaRodovias(lista);
    return lista;
}

void insereRodovias(Lista *lista, char *rodovias) {
    lista->final++;
    strcpy(lista->rodovias[lista->final].rodovia, rodovias);
    criaRodovias(lista);
}

void insereCidades(Lista *lista, char *cidade) {
    lista->rodovias[lista->final].proximo++;
    lista->rodovias[lista->final].cidades[lista->rodovias->proximo].proximo++;
    strcpy(lista->rodovias[lista->final].cidades[lista->rodovias[lista->final].proximo].cidade, cidade);
}

void imprime(Lista *lista) {
    for (size_t i = 1; i <= lista->final; ++i) {
        printf("Rodovia %s\n", lista->rodovias[i].rodovia);
        for (size_t j = 1; j <= lista->rodovias[i].proximo; ++j) {
            printf("Cidades %s\n", lista->rodovias[i].cidades[j].cidade);
        }
        printf("\n");
    }
}

void insereCidadeOrdem(Lista *lista, char *rodovia, char *cidade) {
    for (size_t i = 1; i <= lista->final; ++i) {
        if (strcmp(lista->rodovias[i].rodovia, rodovia) == 0) {
            lista->rodovias[i].proximo++;
            for (size_t y = 1; y <= lista->rodovias[i].proximo; ++y) {
                if (strcmp(lista->rodovias[i].cidades[y].cidade, cidade) >= 0) {
                    for (size_t j = lista->rodovias[i].proximo; j > y; --j) {
                        strcpy(lista->rodovias[i].cidades[j].cidade,
                               lista->rodovias[i].cidades[j - 1].cidade);
                    }
                    strcpy(lista->rodovias[i].cidades[y].cidade, cidade);
                    return;
                }
            }
            strcpy(lista->rodovias[i].cidades[lista->rodovias[i].proximo].cidade, cidade);
        }
    }
}

Lista *rodoviasCidade(Lista *lista, char *cidade) {
    Lista *listaRodovias = cria();
    for (size_t i = 1; i <= lista->final; ++i)
        for (size_t j = 1; j <= lista->rodovias[i].proximo; ++j) {
            if (strcmp(lista->rodovias[i].cidades[j].cidade, cidade) == 0) {
                insereRodovias(listaRodovias, lista->rodovias[i].rodovia);
            }
        }
    return listaRodovias;
}

int cruzamento(Lista *lista, char *rodovia1, char *rodovia2) {
    for (size_t i = 1; i <= lista->final; ++i) {
        if (strcmp(lista->rodovias[i].rodovia, rodovia1) == 0) {
            for (size_t j = 1; j <= lista->final; ++j) {
                if (strcmp(lista->rodovias[j].rodovia, rodovia2) == 0) {
                    for (size_t y = 1; y <= lista->rodovias[i].proximo; ++y) {
                        for (size_t l = 1; l <= lista->rodovias[j].proximo; ++l) {
                            if (strcmp(lista->rodovias[i].cidades[y].cidade, lista->rodovias[j].cidades[l].cidade) == 0)
                                return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main(void) {
    Lista *lista = cria();
    insereRodovias(lista, "BR123");
    insereCidades(lista, "B");
    insereCidades(lista, "C");
    insereCidades(lista, "E");

    insereRodovias(lista, "BR456");
    insereCidades(lista, "L");
    insereCidades(lista, "L");
    insereCidades(lista, "I");

    insereCidadeOrdem(lista, "BR123", "D"); // B
    insereCidadeOrdem(lista, "BR123", "F");
    insereCidadeOrdem(lista, "BR123", "A");

    Lista *listaRodovias = rodoviasCidade(lista, "A"); // C

    int cruza = cruzamento(lista, "BR123", "BR456"); // D
    if (cruza == 0)
        printf("Nao cruza\n");
    else
        printf("Cruza\n");

    imprime(listaRodovias);
    system("pause");
}
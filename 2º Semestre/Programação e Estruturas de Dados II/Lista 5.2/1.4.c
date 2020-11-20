/* Problema 4
 * Escreva uma TAD que implemente uma lista circular ordenada duplamente encadeada que armazena em cada
 * nó uma chave inteira e um nome. As seguintes operações abaixo devem ser definidas:
 *
 * a) Buscar um nome dado o valor da chave;
 * b) Inserir um novo elemento na lista mantendo a ordem;
 * c) Remover um elemento da lista;
 * d) Imprimir os valores da lista;
 * e) Copiar uma lista l1 para uma lista l2;
 * f) Concatenar uma lista l1 com uma lista l2;
 * g) Intercalar l1 e l2;
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    struct no *proximo;
    int chave;
    char nome[64];
    struct no *anterior;
}No;

typedef struct lista {
    No *inicio;
    No *fim;
}Lista;

Lista *criaLista() {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    lista->inicio = lista->fim = NULL;
    return lista;
}

No *criaNo(int chave, char *nome) {
    No *novo = (No *) malloc(sizeof(No));
    novo->chave = chave;
    strcpy(novo->nome, nome);
    novo->proximo = novo->anterior = novo;
    return novo;
}

int listaVazia(Lista *lista) {
    return (lista->inicio == NULL);
}

void insereInicio(Lista *lista, int chave, char *nome) {
    No *novo = criaNo(chave, nome);
    if (listaVazia(lista)) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        novo->proximo = lista->inicio;
        lista->inicio->anterior = novo;
        lista->inicio = novo;
        lista->inicio->anterior = lista->fim;
        lista->fim->proximo = lista->inicio;
    }
}

void insereFinal(Lista *lista, int chave, char *nome) {
    if (listaVazia(lista)) {
        insereInicio(lista, chave, nome);
    }
    else {
        No *no = criaNo(chave, nome);
        lista->fim->proximo = no;
        no->anterior = lista->fim;
        lista->fim = no;
        lista->inicio->anterior = lista->fim;
        lista->fim->proximo = lista->inicio;
    }
}

void imprimeLista(Lista *lista) {
    No *no = lista->inicio;
    printf("Lista:\n");
    while (1) {
        printf("Nome %s\n", no->nome);
        printf("Chave %d\n", no->chave);
        if (no == lista->fim)
            break;
        no = no->proximo;
    }
    printf("Fim.\n");
}

void buscarValor(Lista *lista, int chave) {
    No *no;
    printf("Valor encontrado:\n");
    for (no = lista->inicio;  ; no = no->proximo) {
        if (no->chave == chave) {
            printf("Nome %s\n", no->nome);
            printf("Chave %d\n", no->chave);
            break;
        }
    }
}

void insereOrdenado(Lista *lista, int chave, char *nome) {
    No *no = criaNo(chave, nome);
    No *ant = NULL;
    No *p = lista->inicio;

    while (p->chave > chave) {
        ant = p;
        p = p->proximo;
        if (p == lista->inicio)
            break;
    }

    if (ant == NULL) {
        no->proximo = lista->inicio;
        no->anterior = lista->fim;
        if (lista->inicio != lista->fim)
            lista->inicio->anterior = no;
        lista->inicio = no;
    } else {
        no->proximo = ant->proximo;
        no->anterior = ant;
        if (no->proximo != lista->fim)
            ant->proximo->anterior = no;
        ant->proximo = no;
    }
}

void removeLista(Lista *lista, int chave) {
    No *no = lista->inicio;
    if (lista->inicio->chave == chave) {
        if (lista->inicio == lista->fim) {
            lista->inicio = lista->fim = NULL;
        } else {
            lista->inicio = no->proximo;
            lista->inicio->anterior = lista->fim;
            lista->fim->proximo = lista->inicio;
        }
        free(no);
    } else {
        for (no = lista->inicio;  ; no = no->proximo) {
            if (no->chave == chave) {
                no->proximo->anterior = no->anterior;
                no->anterior->proximo = no->proximo;
                if (lista->fim == no)
                    lista->fim = no->anterior;
                free(no);
                break;
            }
        }
    }
}

Lista *copiaLista(Lista *lista) {
    Lista *listaCopia = criaLista();
    No *no = lista->inicio;
    while (1) {
        insereInicio(listaCopia, no->chave, no->nome);
        if (no == lista->fim)
            break;
        no = no->proximo;
    }
    return listaCopia;
}

Lista *concatenarListas(Lista *lista1, Lista *lista2) {
    Lista *listaConcatenada = criaLista();
    No *no1 = lista1->inicio;
    No *no2 = lista2->inicio;
    while (1) {
        insereInicio(listaConcatenada, no1->chave, no1->nome);
        if (no1 == lista1->fim) {
            while (1) {
                insereInicio(listaConcatenada, no2->chave, no2->nome);
                if (no2 == lista2->fim)
                    break;
                no2 = no2->proximo;
            }
            break;
        }
        no1 = no1->proximo;
    }
    return listaConcatenada;
}

Lista *intercalarListas(Lista *lista1, Lista *lista2) {
    Lista *listaIntercalada = criaLista();
    No *no1 = lista1->inicio;
    No *no2 = lista2->inicio;
    int contador = 0;
    int terminaLoop1 = 0;
    int terminaLoop2 = 0;
    while (1) {
        if (terminaLoop1 + terminaLoop2 == 2)
            break;
        if (terminaLoop1 < 1) {
            if (contador % 2 == 0) {
                insereInicio(listaIntercalada, no1->chave, no1->nome);
                if (no1 == lista1->fim)
                    terminaLoop1++;
                no1 = no1->proximo;
            }
        }
        if (terminaLoop2 < 1) {
            if (contador % 2 == 1) {
                insereInicio(listaIntercalada, no2->chave, no2->nome);
                if (no2 == lista2->fim)
                    terminaLoop2++;
                no2 = no2->proximo;
            }
        } else {

        }
        contador++;
    }
    return listaIntercalada;
}

int main(void) {
    char nome1[] = "Primeirissimo Elemento";
    char nome2[] = "Segundissimo Elemento";
    char nome3[] = "Terceirissimoo Elemento";
    char nome4[] = "Quartissimo Elemento";
    char nome5[] = "Quintissimo Elemento";
    char nome6[] = "Sextissimo Elemento";
    Lista *lista = criaLista();
    insereInicio(lista, 1, nome1);
    insereInicio(lista, 2, nome2);
    insereInicio(lista, 3, nome3);
    insereInicio(lista, 4, nome4);
    insereInicio(lista, 5, nome5);
    buscarValor(lista, 2);
    printf("\n");
    insereOrdenado(lista, 6, nome6);
    removeLista(lista, 1);
    imprimeLista(lista);
    printf("\n");
    printf("Lista copiada:\n");
    Lista *listaCopia = copiaLista(lista);
    imprimeLista(listaCopia);
    printf("\n");
    printf("Lista e lista Copia concatenadas:\n");
    Lista *listaConcatenada = concatenarListas(lista, listaCopia);
    imprimeLista(listaConcatenada);
    printf("\n");
    printf("Lista e lista Copia intercaladas:\n");
    Lista *listaIntercalada = intercalarListas(lista, listaCopia);
    imprimeLista(listaIntercalada);
    system("pause");
}
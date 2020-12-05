/* Problema 2
 * Escreva um programa que recebe duas listas encadeadas de inteiros e efetue os seguintes passos:
 * a) Verifique se as listas estão ordenadas;
 * b) Ordene as listas, caso não estejam ordenadas;
 * c) Mescle os elementos da segunda lista na primeira, mantendo a ordenação na lista final.
 */
// O exercício que eu demorei 2 dias para fazer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct listaNo{
    struct listaNo *anterior;
    int valor;
    struct listaNo *proximo;
}ListaNo;

typedef struct lista {
    struct listaNo *inicio;
    struct listaNo *final;
}Lista;

Lista *cria(void) {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    lista->inicio = lista->final = NULL;
    return lista;
}

void insere(Lista *lista, int valor) {
    ListaNo *listaNo = (ListaNo *) malloc(sizeof(Lista));
    listaNo->valor = valor;

    if (!lista->inicio) {
        listaNo->proximo = NULL;
        listaNo->anterior = NULL;
        lista->inicio = listaNo;
        lista->final = listaNo;
    }
    else {
        listaNo->proximo = NULL;
        listaNo->anterior = lista->final;
        lista->final->proximo = listaNo;
        lista->final = listaNo;
    }
}

void imprime(Lista *lista) {
    ListaNo *percorre = lista->inicio;
    while (percorre) {
        printf("Valor %d\n", percorre->valor);
        percorre = percorre->proximo;
    }
}

void insereOrdenado(Lista *lista, int valor) {
    ListaNo *percorre = lista->inicio;
    ListaNo *anterior = NULL;
    ListaNo *novo = (ListaNo *) malloc(sizeof(ListaNo));
    novo->valor = valor;

    if (!lista->inicio) {
        insere(lista, valor);
        return;
    }

    while (percorre) {
        if (percorre->valor > valor)
            break;
        anterior = percorre;
        percorre = percorre->proximo;
    }

    if (!anterior) {
        novo->proximo = percorre;
        novo->anterior = NULL;
        percorre->anterior = novo;
        lista->inicio = novo;
    }
    else {
        novo->proximo = percorre;
        novo->anterior = anterior;
        anterior->proximo = novo;
        if (!percorre)
            lista->final = novo;
    }
}

bool verificaOrdenada(Lista *lista) {
    ListaNo *percorre = lista->inicio;

    while (percorre) {
        if (percorre->anterior && percorre->valor < percorre->anterior->valor)
            return false;
        percorre = percorre->proximo;
    }

    return true;
}

void ordenar(Lista *lista) {
    int valorAnterior;
    for (ListaNo *percorreAntes = lista->inicio; percorreAntes; percorreAntes = percorreAntes->proximo) {
        for (ListaNo *percorre = percorreAntes->proximo; percorre; percorre = percorre->proximo) {
            if (percorreAntes->valor > percorre->valor) {
                valorAnterior = percorreAntes->valor;
                percorreAntes->valor = percorre->valor;
                percorre->valor = valorAnterior;
            }
        }
    }
}

Lista *mesclar(Lista *lista1, Lista *lista2) {
    Lista *listaMesclada = cria();
    ListaNo *listaPrimeira = lista1->inicio;
    ListaNo *listaSegunda = lista2->inicio;

    for (size_t i = 0; ; ++i) {
        if (!listaPrimeira && !listaSegunda)
            return listaMesclada;
        if (listaPrimeira) {
            if (i % 2 == 0) {
                insereOrdenado(listaMesclada, listaPrimeira->valor);
                listaPrimeira = listaPrimeira->proximo;
            }
            else if (listaSegunda) {
                insereOrdenado(listaMesclada, listaSegunda->valor);
                listaSegunda = listaSegunda->proximo;
            }
        }
        else {
            insereOrdenado(listaMesclada, listaSegunda->valor);
            listaSegunda = listaSegunda->proximo;
        }
    }
}

int main(void) {
    Lista *lista1 = cria();
    insereOrdenado(lista1, 2);
    insereOrdenado(lista1, 1);
    insereOrdenado(lista1, 4);
    insereOrdenado(lista1, 3);

    imprime(lista1);

    if (verificaOrdenada(lista1))
        printf("Ordenada\n");
    else
        printf("Nao ordenada\n");

    Lista *lista2 = cria();
    insere(lista2, 5);
    insere(lista2, 7);
    insere(lista2, 6);
    insereOrdenado(lista2, 8);

    imprime(lista2);

    if (verificaOrdenada(lista2))
        printf("Ordenada\n");
    else {
        printf("Nao ordenada\n");
        ordenar(lista2);
    }

    imprime(lista2);

    if (verificaOrdenada(lista2))
        printf("Ordenada\n");
    else
        printf("Nao ordenada\n");

    puts("Lista Mesclada");
    Lista *listaMesclada = mesclar(lista1, lista2);
    insereOrdenado(listaMesclada, 10);
    insereOrdenado(listaMesclada, 9);

    imprime(listaMesclada);

    if (verificaOrdenada(listaMesclada))
        printf("Ordenada\n");
    else
        printf("Nao ordenada\n");

    system("pause");
}
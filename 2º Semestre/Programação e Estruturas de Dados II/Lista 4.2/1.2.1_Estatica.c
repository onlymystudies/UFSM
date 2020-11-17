#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct infos{
    int valor;
}Info;

typedef struct lista {
    int tamanho;
    Info infos[MAX];
}Lista;

Lista* cria(void) {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->tamanho = -1;
    return lista;
}

void insere(Lista *lista, int valor) {
    lista->tamanho++;
    lista->infos[lista->tamanho].valor= valor;
}

void imprime(Lista *lista) {
    for (size_t i = 0; i <= lista->tamanho; ++i)
        printf("valor %d\n", lista->infos[i].valor);
}

Lista* intercalar(Lista* lista1, Lista* lista2) {
    Lista* lista3 = (Lista*) malloc(sizeof(Lista));
    Lista* listaMaior;
    Lista* listaMenor;
    lista3->tamanho = (lista1->tamanho + lista2->tamanho) + 1;

    if (lista1->tamanho > lista2->tamanho) {
        listaMaior = lista1;
        listaMenor = lista2;
    }
    else {
        listaMaior = lista2;
        listaMenor = lista1;
    }

    int i, pos = 0;
    for (i = 0; ; ++i) {
        if (i % 2 == 0) {
            lista3->infos[i].valor = listaMenor->infos[pos].valor;
            pos++;
        }
        if (pos > listaMenor->tamanho)
            break;
    }
    pos = 0;
    for (int j = 0; ; ++j) {
        if (j <= i) {
            if (j % 2 == 1) {
                lista3->infos[j].valor = listaMaior->infos[pos].valor;
                pos++;
            }
        } else {
            lista3->infos[j].valor = listaMaior->infos[pos].valor;
            pos++;
        }
        if (pos > listaMaior->tamanho)
            break;
    }

    return lista3;
}

int main(void) {
    Lista* abacaxi = cria();
    insere(abacaxi, 1);
    insere(abacaxi, 2);
    insere(abacaxi, 3);
    insere(abacaxi, 4);
    insere(abacaxi, 5);
    insere(abacaxi, 6);
    insere(abacaxi, 7);

    Lista* maracuja = cria();
    insere(maracuja, 8);
    insere(maracuja, 9);
    insere(maracuja, 10);

    Lista* limao = intercalar(abacaxi, maracuja);
    imprime(limao);
    system("pause");
}
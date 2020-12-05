#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int valor;
    struct lista *proximo;
}Lista;

Lista *cria(void) {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    lista->proximo = NULL;
    return lista;
}

void insere(Lista *lista, int valor) {
    Lista *novo = (Lista *) malloc(sizeof(Lista));
    novo->valor = valor;
    novo->proximo = lista->proximo;
    lista->proximo = novo;
}

int verificarOrdenada(Lista *lista) {
    Lista *anterior = NULL;
    lista = lista->proximo;
    while (lista) {
        if (anterior && lista->valor > anterior->valor)
            return 0;
        anterior = lista;
        lista = lista->proximo;
    }
    return 1;
}

void ordena(Lista *lista) {
    int menorValor;
    for (Lista *percorre = lista->proximo; percorre; percorre = percorre->proximo)
        for (Lista *percorreProximo = percorre->proximo; percorreProximo; percorreProximo = percorreProximo->proximo) {
            if (percorre->valor < percorreProximo->valor) {
                menorValor = percorre->valor;
                percorre->valor = percorreProximo->valor;
                percorreProximo->valor = menorValor;
            }
        }
}

Lista *mesclar(Lista *listaA, Lista *listaB) {
    Lista *listaMesclada = cria();
    listaA = listaA->proximo; listaB = listaB->proximo;

    for (size_t i = 0; ; ++i) {
        if (!listaA && !listaB)
            break;
        if (i % 2 == 0) {
            if (listaA) {
                insere(listaMesclada, listaA->valor);
                listaA = listaA->proximo;
            }
            else {
                insere(listaMesclada, listaB->valor);
                listaB = listaB->proximo;
            }
        }
        else if (listaB) {
            insere(listaMesclada, listaB->valor);
            listaB = listaB->proximo;
        }
    }

    ordena(listaMesclada);
    return listaMesclada;
}

void imprime(Lista *lista) {
    lista = lista->proximo;
    puts("Lista:");
    while (lista) {
        printf("valor %d\n", lista->valor);
        lista = lista->proximo;
    }
    puts("Fim!");
}
int main(void) {
    Lista *lista = cria();
    insere(lista, 1);
    insere(lista, 2);
    insere(lista, 3);
    imprime(lista);

    if (verificarOrdenada(lista))
        puts("Ordenada");
    else
        puts("Nao ordenada");

    puts("\nListaB:");
    Lista *listaB = cria();
    insere(listaB, 4);
    insere(listaB, 6);
    insere(listaB, 5);
    imprime(listaB);

    if (verificarOrdenada(listaB))
        puts("Ordenada");
    else
        ordena(listaB);

    puts("\nListaB ordenada:");
    imprime(listaB);

    puts("\nListaC mesclada:");
    Lista *listaC = mesclar(lista, listaB);
    imprime(listaC);

    if (verificarOrdenada(listaC))
        puts("Ordenada");
    else
        puts("Nao ordenada");

    system("pause");
}
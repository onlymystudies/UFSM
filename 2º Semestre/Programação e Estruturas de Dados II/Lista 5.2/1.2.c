/* 2) Escreva uma TAD de lista de inteiros ordenada simplesmente encadeada
 * com as seguintes operações:
 * a) Verificar se um número pertence lista;
 * b) Inserir um novo elemento na lista mantendo a ordem;
 * c) Remover um elemento da lista;
 * d) Imprimir os valores da lista;
 * e) Copiar uma lista l1 para uma lista l2;
 * f) Concatenar uma lista l1 com uma lista l2;
 * g) Intercalar l1 e l2;
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int valor;
    struct lista *proximo;
}Lista;

Lista *cria(void) {
    return NULL;
}

Lista *insere(Lista *lista, int valor) {
    Lista *novo = (Lista *) malloc(sizeof(Lista));
    novo->valor = valor;
    novo->proximo = lista;
    return novo;
}

Lista *insereOrdenado(Lista *lista, int valor) {
    Lista *novo = (Lista *) malloc(sizeof(Lista));
    novo->valor = valor;
    Lista *p = lista;

    while (p->proximo != NULL) {
        if (p->proximo->valor < valor)
            break;
        else
            p = p->proximo;
    }

    if (p->proximo == NULL) {
        p->proximo = novo;
        novo->proximo = NULL;
    } else {
        if (p->valor < valor) {
            novo->proximo = p;
            lista = novo;
        } else {
            novo->proximo = p->proximo;
            p->proximo = novo;
        }
    }
    return lista;
}

void imprime(Lista *lista) {
    if (lista != NULL)
        printf("valor %d\n", lista->valor);
    else
        return;
    return imprime(lista->proximo);
}

Lista *verificar(Lista *lista, int valor) {
    Lista *p = lista;
    while (p != NULL) {
        if (p->valor == valor) {
            printf("valor %d pertence a lista\n", valor);
            return lista;
        } else {
            p = p->proximo;
        }
    }
    printf("valor %d nao pertence a lista\n", valor);
    return lista;
}

Lista *remover(Lista *lista, int valor) {
    Lista *p = lista;
    Lista *anterior = NULL;
    while (p != NULL) {
        if (p->valor == valor)
            break;
        else {
            anterior = p;
            p = p->proximo;
        }
    }
    if (anterior == NULL) {
        lista = lista->proximo;
    }else {
        anterior->proximo = p->proximo;
        free(p);
    }
    return lista;
}

Lista *copia(Lista *lista) {
    Lista *listaCopia = cria();
    Lista *p = lista;
    while (p != NULL) {
        listaCopia = insere(listaCopia, p->valor);
        p = p->proximo;
    }
    return listaCopia;
}

Lista *concatenar(Lista *lista1, Lista *lista2) {
    Lista *listaConcatenada = cria();
    Lista *p1 = lista1;
    Lista *p2 = lista2;
    while (p1 != NULL) {
        listaConcatenada = insere(listaConcatenada, p1->valor);
        p1 = p1->proximo;
    }
    while (p2 != NULL) {
        listaConcatenada = insere(listaConcatenada, p2->valor);
        p2 = p2->proximo;
    }
    return listaConcatenada;
}

Lista *intercalar(Lista *lista1, Lista *lista2) {
    Lista *listaIntercalada = cria();
    Lista *p1 = lista1;
    Lista *p2 = lista2;
    for ( int i = 0; ; i++) {
        if (p1 == NULL && p2 == NULL)
            break;
        if (i % 2 == 0) {
            if (p1 != NULL) {
                listaIntercalada = insere(listaIntercalada, p1->valor);
                p1 = p1->proximo;
            } else if (p2 != NULL) {
                listaIntercalada = insere(listaIntercalada, p2->valor);
                p2 = p2->proximo;
            }
        }
        if (i % 2 == 1) {
            if (p2 != NULL) {
                listaIntercalada = insere(listaIntercalada, p2->valor);
                p2 = p2->proximo;
            } else if (p1 != NULL) {
                listaIntercalada = insere(listaIntercalada, p1->valor);
                p1 = p1->proximo;
            }
        }
    }
    return listaIntercalada;
}

int main(void) {
    Lista *lista = cria();
    lista = insere(lista, 1);
    lista = insere(lista, 3);
    lista = verificar(lista, 2); // A
    lista = insereOrdenado(lista, 2); // B
    lista = remover(lista, 3); // C
    //imprime(lista); // D
    Lista *listaCopia = copia(lista); // E
    Lista *listaConcatenada = concatenar(lista, listaCopia); // F
    Lista *listaIntercalada = intercalar(listaCopia, listaConcatenada); // G
    imprime(listaIntercalada);
    system("pause");
}
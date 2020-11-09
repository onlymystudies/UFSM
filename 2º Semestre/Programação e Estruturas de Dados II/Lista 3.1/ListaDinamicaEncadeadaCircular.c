#include <stdlib.h>
#include "ListaDinamicaEncadeadaCircular.h"

typedef struct elemento {
    struct valores dados;
    struct elemento *prox;
}Elementos;

Lista* cria_lista() {
    Lista* l = (Lista *) malloc(sizeof(Lista));
    if (l != NULL)
        *l = NULL;
    return l;
}

void libera_lista(Lista* l) {
    if (l != NULL && (*l) != NULL) {
        Elementos *aux, *no = *l;
        while ((*l) != no->prox) {
            aux = no;
            no = no ->prox;
            free(aux);
        }
        free(no);
        free(l);
    }
}

int tamanho_lista(Lista *l) {
    if (l == NULL || (*l) == NULL)
        return 0;
    int contador = 0;
    Elementos* no = *l;
    do {
        contador++;
        no = no->prox;
    } while (no != (*l));
    return contador;
}

int lista_vazia(Lista *l) {
    if (l == NULL && (*l) == NULL)
        return 1;
    else
        return 0;
}

int remove_lista(Lista *l, int val) {
    if (l == NULL)
        return 0;
    if ((*l) == NULL)
        return 0;
    Elementos *no = *l;
    Elementos  *ant = no;
    no = no->prox;
    while (no != (*l) && no->dados.numeros != val) {
        ant = no;
        no = no->prox;
    }
    if (no == *l)
        return 0;
    ant->prox = no->prox;
    free(no);
    return 1;
}

int consulta_lista(Lista* l, int pos, struct valores *val) {
    if (l == NULL)
        return 0;
    Elementos *no = *l;
    int i = 1;
    while (no->prox != (*l) && i < pos) {
        no = no->prox;
        i++;
    }
    if (i != pos)
        return 0;
    else {
        *val = no->dados;
        return 1;
    }
}

int insere_lista_ordenada(Lista *l, struct valores val) {
    if (l == NULL)
        return 0;
    Elementos *no = (Elementos *) malloc(sizeof(Elementos));
    if (no == NULL)
        return 0;
    no->dados = val;
    if ((*l) == NULL) {
        *l = no;
        no->prox = no;
        return 1;
    } else {
        if ((*l)->dados.numeros > val.numeros) {
            Elementos *atual = *l;
            while (atual->prox != (*l)) {
                atual = atual->prox;
                no->prox = *l;
                atual->prox = no;
                *l = no;
                return 1;
            }
        }
        Elementos *ant = *l, *atual = (*l)->prox;
        while (atual != (*l) && atual->dados.numeros < val.numeros) {
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = no;
        no->prox = atual;
        }
    return 1;
}

int igual (Lista* l1, Lista* l2) {
    if (l1 == NULL || l2 == NULL)
        return 0;
    if ((*l1) == NULL || (*l2) == NULL)
        return 0;
    struct valores dados1, dados2;
    if (i < tamanho_lista(l1)) {
        consulta_lista(l1, i, &dados1);
        consulta_lista(l2, i, &dados2);
        if (dados1.numeros == dados2.numeros)
            igual_++;
        else
            nao_igual++;
        i++;
        igual(l1, l2);
    }

    i = 0;
    if (nao_igual != 0)
        printf("Listas nao sao igual\n");
    else
        printf("Listas sao iguais\n");
    return 1;
}

Lista* copia (Lista* l) {
    if (l == NULL)
        return 0;
    if ((*l) == NULL)
        return 0;
    Lista *l2;
    l2 = cria_lista();
    struct valores dados;

    if (i < tamanho_lista(l)) {
        consulta_lista(l, i, &dados);
        insere_lista_ordenada(l2, dados);
        i++;
        copia(l);
    }

    i = 0;
    return l2;
}
/* Problema 1
No código “ListaDeAdjacências.c”, dado em aula, implementar:
- void GRAPHremoveArc( Graph G, vertex v, vertex w); // implementar
- void GRAPHshow( Graph G); // implementar
- void GRAPHshowAll( Graph G); // implementar */
#include <stdio.h>
#include <stdlib.h>
// O vetor de listas de adjac�ncia de um grafo tem uma lista encadeada (= linked list) associada com cada
// v�rtice do grafo.  A lista associada com um v�rtice v cont�m todos os vizinhos de v.  Portanto, a lista
// do v�rtice v representa o leque de sa�da de v.   Por exemplo, eis o vetor de listas de adjac�ncia do grafo
//cujos arcos s�o  0-1 0-5 1-0 1-5 2-4 3-1 5-3 :

//0: 5 1
//1: 5 0
//2: 4
//3: 1
//4:
//5: 3

/* V�rtices de grafos s�o representados por objetos do tipo vertex. */
#define vertex int

// Na representa��o por listas de adjac�ncia, um grafo � representado por uma struct graph que cont�m o vetor
// de listas de adjac�ncia, o n�mero de v�rtices, e o n�mero de arcos do grafo:
/* REPRESENTA��O POR LISTAS DE ADJAC�NCIA: A estrutura graph representa um grafo. O campo adj � um ponteiro
para o vetor de listas de adjac�ncia, o campo V cont�m o n�mero de v�rtices e o campo A cont�m o n�mero de
arcos do grafo. */
typedef struct node *link;

struct graph {
    int V;
    int A;
    link *adj;
};

/* Um Graph � um ponteiro para um graph. */
typedef struct graph *Graph;

/* A lista de adjac�ncia de um v�rtice v � composta por n�s do tipo node. Cada n� da lista corresponde a um
arco e cont�m um vizinho w de v e o endere�o do n� seguinte da lista. Um link � um ponteiro para um node. */
struct node {
    vertex w;
    link next;
};

/* A fun��o NEWnode() recebe um v�rtice w e o endere�o next de um n� e devolve o endere�o a de um novo n�
tal que a->w == w e a->next == next. */
static link NEWnode( vertex w, link next) {
    link a = malloc( sizeof (struct node));
    a->w = w;
    a->next = next;
    return a;
}

/* REPRESENTA��O POR LISTAS DE ADJAC�NCIA: A fun��o GRAPHinit() constr�i um grafo com v�rtices 0 1 .. V-1
e nenhum arco. */
Graph GRAPHinit( int V) {
    vertex v;
    Graph G = malloc( sizeof *G);
    G->V = V;
    G->A = 0;
    G->adj = malloc( V * sizeof (link));
    for (v = 0; v < V; ++v)
        G->adj[v] = NULL;
    return G;
}
/* REPRESENTAcaO POR LISTAS DE ADJACeNCIA: A funcao GRAPHinsertArc() insere um arco v-w no grafo G.
A funcao sup�e que v e w sao distintos, positivos e menores que G->V. Se o grafo ja tem um arco v-w,
a funcao nao faz nada. */
void GRAPHinsertArc( Graph G, vertex v, vertex w) {
    link a;
    for (a = G->adj[v]; a != NULL; a = a->next)
        if (a->w == w) return;
    G->adj[v] = NEWnode( w, G->adj[v]);
    G->A++;
}

void GRAPHshow( Graph G) {
    size_t i = 0;
    while (i != G->V) {
        printf("%d: ", i);
        for (link a = G->adj[i]; a; a = a->next) {
            printf("%d ", a->w);
        }
        puts("");
        i++;
    }
}

void GRAPHshowAll( Graph G) {
    printf("   ");
    for (size_t i = 0; i != G->V; ++i)
        printf("%d ", i);
    puts("");

    for (size_t j = 0; j < G->V; ++j) {
        printf("%d: ", j);
        link a = G->adj[j];
        for (size_t i = 0; i < G->V; ++i) {
            if (a && a->w == i) {
                printf("1 ");
                a = a->next;
            }
            else
                printf("0 ");
        }
        puts("");
    }
}

void GRAPHremoveArc( Graph G, vertex v, vertex w) {
    link a;
    link anterior = NULL;
    for (a = G->adj[v]; a != NULL; a = a->next) {
        if (a->w == w)
            break;
        anterior = a;
    }
    if (anterior)
        anterior->next = a->next;
    else
        G->adj[v] = a->next;
    G->A--;
}

int main() {
//0: 5 1
//1: 5 0
//2: 4
//3: 1
//4:
//5: 3
    Graph G = GRAPHinit(6);
    GRAPHinsertArc(G, 0, 5);
    GRAPHinsertArc(G, 0, 1);
    GRAPHinsertArc(G, 1, 5);
    GRAPHinsertArc(G, 1, 0);
    GRAPHinsertArc(G, 2, 4);
    GRAPHinsertArc(G, 3, 1);
    GRAPHinsertArc(G, 5, 3);
    GRAPHshow(G);       puts("");
    GRAPHshowAll(G);    puts("");
    GRAPHremoveArc(G, 1, 5);
    GRAPHshow(G);       puts("");
    GRAPHshowAll(G);    puts("");
    system("pause");
    return 0;
    //void GRAPHremoveArc( Graph G, vertex v, vertex w); // implementar
    //void GRAPHshow( Graph G); // implementar
    //void GRAPHshowAll( Graph G); // implementar
}

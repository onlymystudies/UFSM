/* Problema 5 */
#include <stdio.h>
#include <stdlib.h>
#define vertex int

struct graph {
    int V; // Vertices
    int A; // Arestas
    int **adj;
};
typedef struct graph *Graph;

static int **MATRIXint( int r, int c, int val);

Graph GRAPHinit( int V) {
  Graph G = malloc( sizeof *G);
  G->V = V;
  G->A = 0;
  G->adj = MATRIXint( V, V, 0);
  return G;
}

static int **MATRIXint( int r, int c, int val) {
  int **m = malloc( r * sizeof (int *));
  vertex i, j; // do autor...
  for (i = 0; i < r; ++i)
    m[i] = malloc( c * sizeof (int));
  for (i = 0; i < r; ++i)
    for (j = 0; j < c; ++j)
      m[i][j] = val;
  return m;
}

void GRAPHinsertArc( Graph G, vertex v, vertex w) {
  if (G->adj[v][w] == 0) {
    G->adj[v][w] = 1;
    G->A++;
  }
}

void GRAPHremoveArc( Graph G, vertex v, vertex w) {
  if (G->adj[v][w] == 1) {
    G->adj[v][w] = 0;
    G->A--;
  }
}

int main(void) {
  Graph G = GRAPHinit(6);
  GRAPHinsertArc(G, 0, 1);
  GRAPHinsertArc(G, 0, 5);
  GRAPHinsertArc(G, 1, 0);
  GRAPHinsertArc(G, 1, 5);
  GRAPHinsertArc(G, 2, 4);
  GRAPHinsertArc(G, 3, 1);
  GRAPHinsertArc(G, 5, 1);
  return 0;
}

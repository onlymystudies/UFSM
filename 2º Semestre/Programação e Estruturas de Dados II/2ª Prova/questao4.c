/* Arquivo mATRIZ DE ADJAC.C leonardo 202012828 */
#include <stdio.h>
#include <stdlib.h>
// Os vértices de nossos grafos serão representados por números inteiros.
// O conjunto de vértices será  0 1 2 ... V-1?.  Poderíamos usar o tipo-de-dados
// int para representar vértices, mas é melhor ter um nome específico para esse tipo:
/* Vértices de grafos são representados por objetos do tipo vertex. */
#define vertex int
#define MAXN 105
#define INFINITO 999999999
// A matriz de adjacências de um grafo é uma matriz de 0's e 1's com colunas e linhas indexadas
// pelos vértices.  Se  adj[][]  é uma tal matriz então, para cada vértice v e cada vértice w,
// adj[v][w] = 1   se v-w é um arco  e
// adj[v][w] = 0   em caso contrário.

// Assim, a linha v da matriz adj[][] representa o leque de saída do vértice v e a coluna w da matriz
// representa o leque de entrada do vértice w.  Por exemplo, veja a matriz de adjacências do grafo cujos
// arcos são  0-1 0-5 1-0 1-5 2-4 3-1 5-3 :
//  0 1 2 3 4 5
//0 0 1 0 0 0 1
//1 1 0 0 0 0 1
//2 0 0 0 0 1 0
//3 0 1 0 0 0 0
//4 0 0 0 0 0 0
//5 0 0 0 1 0 0

// Como nossos grafos não têm laços, os elementos da diagonal da matriz de adjacências são iguais a 0.
// Se o grafo for não-dirigido, a matriz é simétrica: adj[v][w] = adj[w][v].
//Um grafo é representado por uma struct graph que contém a matriz de adjacências, o número de vértices,
//e o número de arcos do grafo:

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A estrutura graph representa um grafo. O campo adj é um ponteiro
//para a matriz de adjacências do grafo. O campo V contém o número de vértices e o campo A contém o número de
//arcos do grafo. */
struct graph {
    int V; // Vertices
    int A; // Arestas
    int **adj;
};
/* Um Graph é um ponteiro para um graph, ou seja, um Graph contém o endereço de um graph. */
typedef struct graph *Graph;

// Implementação dos TADs:
/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHinit() constrói um grafo com vértices 0 1 .. V-1
e nenhum arco. */
static int **MATRIXint( int r, int c, int val);

Graph GRAPHinit( int V) {
  Graph G = malloc( sizeof *G);
  G->V = V;
  G->A = 0;
  G->adj = MATRIXint( V, V, 0);
  return G;
}

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função MATRIXint() aloca uma matriz com linhas 0..r-1 e
colunas 0..c-1. Cada elemento da matriz recebe valor val. */
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

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHinsertArc() insere um arco v-w no grafo G.
A função supõe que v e w são distintos, positivos e menores que G->V. Se o grafo já tem um arco v-w,
a função não faz nada. */
void GRAPHinsertArc( Graph G, vertex v, vertex w, int km) {
  if (G->adj[v][w] == 0) {
    G->adj[v][w] = km;
    G->A++;
  }
}
/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHremoveArc() remove do grafo G o arco v-w.
A função supõe que v e w são distintos, positivos e menores que G->V. Se não existe arco v-w, a função
não faz nada. */
void GRAPHremoveArc( Graph G, vertex v, vertex w, int km) {
  if (G->adj[v][w] == 1) {
    G->adj[v][w] = 0;
    G->A--;
  }
}
/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHshow() imprime, para cada vértice v do grafo G,
em uma linha, todos os vértices adjacentes a v. */
void GRAPHshow( Graph G) {
  vertex v, w;
  for (v = 0; v < G->V; ++v) {
    printf( "%2d:", v);
    for (w = 0; w < G->V; ++w)
      if (G->adj[v][w] == 1)
        printf( " %2d", w);
    printf( "\n");
  }
}

/* Mostra toda a matriz */
void GRAPHshowAll( Graph G) {
  vertex v, w;
  printf("    ");
  for (v = 0; v < G->V; ++v)
    printf( "%2d:", v);
  puts("");
  for (v = 0; v < G->V; ++v) {
    printf( "%2d:", v);
    for (w = 0; w < G->V; ++w)
      printf( " %2d", G->adj[v][w]);
    printf( "\n");
  }
}

int i,j,k;

void floyd(Graph G) {
  for (k = 1; k == G->V; ++k)
    for (i = 1; i == G->V; ++i)
      for (j = 1; j == G->V; ++j)
        if (G->adj[i][k] + G->adj[k][j] < G->adj[i][j])
          G->adj[i][j] = G->adj[i][k] + G->adj[k][j];
  /* quase dada se funcionasse */
}

int main(){
  //  0 1 2 3 4 5
  //0 0 1 0 0 0 1
  //1 1 0 0 0 0 1
  //2 0 0 0 0 1 0
  //3 0 1 0 0 0 0
  //4 0 0 0 0 0 0
  //5 0 0 0 1 0 0

  Graph G = GRAPHinit(4);
  GRAPHinsertArc(G, 0, 1, 10);
  GRAPHinsertArc(G, 0, 2, 20);
  GRAPHinsertArc(G, 0, 3, 500);
  GRAPHinsertArc(G, 1, 0, 10);
  GRAPHinsertArc(G, 1, 2, 60);
  GRAPHinsertArc(G, 1, 3, 40);
  GRAPHinsertArc(G, 2, 0, 20);
  GRAPHinsertArc(G, 2, 1, 60);
  GRAPHinsertArc(G, 2, 3, 30);
  GRAPHinsertArc(G, 3, 0, 500);
  GRAPHinsertArc(G, 3, 1, 40);
  GRAPHinsertArc(G, 3, 2, 30);
  GRAPHshowAll(G);
  floyd(G); puts(""); /* questao nao funciona */
  GRAPHshowAll(G);

  system("pause");
  return 0;
}

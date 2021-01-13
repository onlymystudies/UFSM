// Busca em profundidade
// Fonte: https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/dfs.html
/* Problema 2
Considerando os códigos dados, implemente uma busca em profundidade DFS que numere (tempo inicial e
tempo final) e pinte os nodos de branco, cinza e preto, conforme realiza a busca. Considere o vídeo dado em
aula. */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
/* Vértices de grafos são representados por objetos do tipo vertex. */
#define vertex int
#define WHITE   "\e[0;97m"
#define GREY    "\e[0;37m"
#define BLACK   "\e[0;90m"
#define RESET   "\x1b[0m"

typedef struct node *link;

struct graph {
    int V;
    int A;
    link *adj;
};

typedef struct graph *Graph;

struct node {
    vertex w;
    link next;
};

static link NEWnode( vertex w, link next) {
    link a = malloc( sizeof (struct node));
    a->w = w;
    a->next = next;
    return a;
}

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

void GRAPHinsertArc( Graph G, vertex v, vertex w) {
    link a;
    for (a = G->adj[v]; a != NULL; a = a->next)
        if (a->w == w) return;
    G->adj[v] = NEWnode( w, G->adj[v]);
    G->A++;
}

// Busca DFS
// O algoritmo de busca DFS visita todos os vértices e todos os arcos do grafo numa determinada ordem e
// atribui um número a cada vértice: o k-ésimo vértice descoberto recebe o número k?.

// A função GRAPHdfs() abaixo é uma implementação do algoritmo.  A busca poderia começar por qualquer vértice,
// mas é natural começá-la pelo vértice 0.  A numeração dos vértices é registrada em um vetor  pre[]  indexado pelos vértices.

// Para simplificar o código, trataremos o vetor pre[] como variável global e suporemos que o número de vértices
// não passa de 1000.  (Veja abaixo o exercício Alocação dinâmica.) Também trataremos como variável global o contador cnt
// usada para a numeração:

static int cnt;
int pre[1000];

void dfsR( Graph G);
/* A função GRAPHdfs() faz uma busca em profundidade no grafo G. Ela atribui um número de ordem pre[x]
a cada vértice x de modo que o k-ésimo vértice descoberto receba o número de ordem k.  (Código inspirado
no programa 18.3 de Sedgewick.) */
void GRAPHdfs( Graph G)
{
    link a;
    for (size_t i = 0; i < G->V; ++i)
        for (a = G->adj[i]; a != NULL; a = a->next)
            printf(WHITE "%d WHITE\n" RESET, a->w);
    dfsR(G); // começa nova etapa
}

// A função GRAPHdfs() é apenas um invólucro; a busca propriamente dita é realizada pela função recursiva dfsR().
// Em geral, nem todos os vértices estão ao alcance do primeiro vértice visitado em GRAPHdfs(), e portanto a função dfsR()
// precisa ser invocada várias vezes por GRAPHdfs().  Cada uma dessas invocações define uma [!] etapa da busca.

/* A funçao dfsR() visita todos os vértices de G que podem ser alcançados a partir do vértice v sem passar por
vértices já descobertos. A função atribui cnt+k a pre[x] se x é o k-ésimo vértice descoberto. (O código supõe que G é
representado por listas de adjacência.) */
void dfsR( Graph G)
{
    printf("Tempo inicial %d\n", G->V);
    int tempoFinal = 0;
    for (size_t i = 0; i < G->V; ++i) {
        for (link a = G->adj[i]; a != NULL; a = a->next) {
            tempoFinal++;
            printf(GREY "%d GREY " RESET, a->w);
        }
        puts("");
        link b = G->adj[i];
        while (b) {
            printf(BLACK "%d BLACK " RESET, b->w);
            b = b->next;
        }
    }
    printf("Tempo final %d\n", G->V + tempoFinal);
}

int main() {
    DWORD mode;
    GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &mode);
    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), mode |= 0x0004);
// Por exemplo, eis o vetor de listas de adjacência do grafo
// cujos arcos são  0-1 0-5 1-0 1-5 2-4 3-1 5-3 :

//	0: 5 1
//	1: 5 0
//	2: 4
//	3: 1
//	4:
//	5: 3
//	Graph G = GRAPHinit(6);
//	GRAPHinsertArc(G, 0, 5);
//	GRAPHinsertArc(G, 0, 1);
//	GRAPHinsertArc(G, 1, 5);
//	GRAPHinsertArc(G, 1, 0);
//	GRAPHinsertArc(G, 2, 4);
//	GRAPHinsertArc(G, 3, 1);
//	GRAPHinsertArc(G, 5, 3);

// Exemplo A.  Considere o grafo G definido pelos arcos  0-1 1-2 1-3 2-4 2-5 .
// Veja a matriz de adjacências (com - no lugar de 0) e as listas de adjacência do grafo:

// - 1 - - - -    0:  1								0
// - - 1 1 - -    1:  2 3							1
// - - - - 1 1    2:  4 5						2		3
// - - - - - -    3:						4		5
// - - - - - -    4:
// - - - - - -    5:
    Graph G = GRAPHinit(6);
    GRAPHinsertArc(G, 0, 1);
    GRAPHinsertArc(G, 1, 2);
    GRAPHinsertArc(G, 1, 3);
    GRAPHinsertArc(G, 2, 4);
    GRAPHinsertArc(G, 2, 5);
    GRAPHdfs(G);
    system("pause");
    //void GRAPHremoveArc( Graph G, vertex v, vertex w); // implementar
    //void GRAPHshow( Graph G); // implementar
    //void GRAPHshowAll( Graph G); // implementar
}



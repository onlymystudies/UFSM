// Busca em largura
// Fonte: https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/bfs.html

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/* Vértices de grafos são representados por objetos do tipo vertex. */
#define vertex int

#define BLK     "\e[0;30m"
#define RED     "\e[0;31m"
#define GRN     "\e[0;32m"
#define YEL     "\e[0;33m"
#define BLU     "\e[0;34m"
#define MAG     "\e[0;35m"
#define CYN     "\e[0;36m"
#define GRY     "\e[0;37m"
#define WHT     "\e[0;97m"
#define WBLK    "\e[0;90m"
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

// Busca em largura
// Um algoritmo de busca é um algoritmo que percorre um grafo andando pelos arcos de um vértice a outro.
// Depois de visitar a ponta inicial de um arco, o algoritmo percorre o arco e visita sua ponta final.
// Cada arco é percorrido no máximo uma vez.
// Há muitas maneiras de organizar uma busca.  Cada estratégia de busca é caracterizada pela ordem em que os
// vértices são visitados. Essa estratégia está intimamente relacionada com os conceitos de distância e caminho mínimo.

// Algoritmo de busca em largura
// A busca em largura começa por um vértice, digamos s, especificado pelo usuário.  O algoritmo visita s,
// depois visita todos os vizinhos de s, depois todos os vizinhos dos vizinhos, e assim por diante.

// O algoritmo numera os vértices, em sequência, na ordem em que eles são descobertos (ou seja, visitados
// pela primeira vez).  Para fazer isso, o algoritmo usa uma fila (= queue) de vértices.  No começo de cada iteração,
// a fila contém vértices que já foram numerados mas têm vizinhos ainda não numerados.  O processo iterativo consiste
// no seguinte:

// enquanto a fila não estiver vazia
// 		retire um vértice v da fila
// 			para cada vizinho w de v
// 				se w não está numerado
// 					então numere w
// 						ponha w na fila
// No começo da primeira iteração, a fila contém o vértice s, com número 0, e nada mais.

// A fila de vértices é manipulada pelas funções auxiliares QUEUEinit(), QUEUEput(), QUEUEget(), QUEUEempty() e QUEUEfree().
// A primeira cria uma fila vazia, a segunda coloca um vértice na fila, a terceira tira um vértice da fila, a quarta
// verifica se a fila está vazia, e a última libera o espaço ocupado pela fila.
// A numeração dos vértices é registrada num vetor  num[]  indexado pelos vértices.  Se v é o k-ésimo vértice
// descoberto então num[v] recebe o valor k.

static int num[1000];

/* A função GRAPHbfs() implementa o algoritmo de busca em largura. Ela visita todos os vértices do grafo G
que estão ao alcance do vértice s e registra num vetor num[] a ordem em que os vértices são descobertos. Esta
versão da função supõe que o grafo G é representado por listas de adjacência.  (Código inspirado no programa
18.9 de Sedgewick.) */
int fila[1000], f_fila, r_fila;

int QUEUEget (void) {
    //printf("QUEUEget %d\n", fila[f_fila]);
    return fila[f_fila++];
}

void QUEUEput (int y) {
    //printf("QUEUEput %d\n", y);
    fila[r_fila++] = y;
}

int QUEUEempty (void) {
    if (f_fila > r_fila)
        return 0;
    return 1;
}

void QUEUEinit(int trash) {
    f_fila = 0;
    r_fila = 0;
}

void QUEUEfree(void) {
    f_fila = 0;
    r_fila = 0;
}

/* Problema 1
Considerando os códigos dados, implemente uma busca em largura BFS que numere (distância do pai) e pinte
os nodos de branco, cinza e preto, conforme realiza a busca. Considere o vídeo dado em aula. */
void GRAPHbfs( Graph G, vertex s)
{
    int cnt = 0;
    vertex v;
    for (v = 0; v < G->V; ++v)
        num[v] = -1;
    QUEUEinit( G->V);
    num[s] = cnt++; // descoberto!
    printf(WBLK " %d\n" RESET, num[s]);
    QUEUEput( s);

    while (QUEUEempty( ) != 0) {
        vertex v = QUEUEget( );
        link a;
        size_t distancia = 1;
        for (a = G->adj[v]; a != NULL; a = a->next)
            if (num[a->w] == -1) {
                num[a->w] = cnt++; // descoberto!
                if (distancia == 1)
                    printf(WBLK " %d(%d)\n" RESET, num[a->w], distancia);
                else
                    printf( " %d(%d)\n" , num[a->w], distancia);
                distancia++;
                QUEUEput( a->w);
            }
    }
    QUEUEfree( );
}

int main(void) {
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

// Exemplo A.  Considere o grafo G definido pelos arcos  0-2 0-3 0-4 1-2 1-4 2-4 3-4 3-5 4-5 5-1.  Suponha que os
// vértices estão em ordem crescente de nomes em cada lista de adjacência.  Submeta G à função GRAPHbfs() com
// segundo argumento 0.  Eis o estado da fila (coluna esquerda) e o estado do vetor num[] (coluna direita) no
// início de cada iteração:

//queue            0 1 2 3 4 5
//0                0 - - - - -
//  2 3 4          0 - 1 2 3 -						  >	2 <
//    3 4          0 - 1 2 3 -						 /	V  \1
//      4 5        0 - 1 2 3 4						0->	4 </
//        5        0 - 1 2 3 4						 \	^	5
//          1      0 5 1 2 3 4						  >	3
//                 0 5 1 2 3 4
    Graph G = GRAPHinit(6);
    GRAPHinsertArc(G, 0, 2);
    GRAPHinsertArc(G, 0, 3);
    GRAPHinsertArc(G, 0, 4);
    GRAPHinsertArc(G, 1, 2);
    GRAPHinsertArc(G, 1, 4);
    GRAPHinsertArc(G, 2, 4);
    GRAPHinsertArc(G, 3, 4);
    GRAPHinsertArc(G, 3, 5);
    GRAPHinsertArc(G, 4, 5);
    GRAPHinsertArc(G, 5, 1);
    GRAPHbfs(G, 0);             puts("");
    system("pause");
    return 0;
    //void GRAPHremoveArc( Graph G, vertex v, vertex w); // implementar
    //void GRAPHshow( Graph G); // implementar
    //void GRAPHshowAll( Graph G); // implementar
}



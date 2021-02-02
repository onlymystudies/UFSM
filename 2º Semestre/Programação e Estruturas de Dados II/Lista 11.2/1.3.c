/* Problema 3
Dados os códigos para a implementação do algoritmo de Dijkstra, implementar uma versão que calcule a
distância entre as cidades de FW e Porto Alegre, considerando as rotas em azul e cinza, mostradas no mapa
abaixo. O programa deve também informar a rota que passa por menos cidades e a rota com menor km.
Rubia: Frederico Westphalen; Palmeira; Panambi; Cruz Alta; Tapera; Espumoso; Soledade; Sarandi;
Carazinho; Passo Fundo; Marau; Guaporé; Lajeado; Canoas; Porto Alegre. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char *city;
    int vertex;
    double km;
    struct node *next;
}Node;

typedef struct graph{
    int numberOfCities;
    int numberOfEdges;
    struct node **adjacent;
}Graph;

Node *create(int vertex, char *city, Node *next, double km) {
  Node *new   =   (Node *) malloc(sizeof(Node));
  new->city   =   (char *) malloc(12 * sizeof(char));
  new->vertex =   vertex;
  strcpy(new->city, city);
  new->next   =   next;
  new->km     =   km;
  return new;
}

Graph *init(int numberOfCities) {
  Graph *graph            =   (Graph *) malloc(sizeof * graph);
  graph->numberOfCities   =   numberOfCities;
  graph->numberOfEdges    =   0;
  graph->adjacent         =   (Node **) malloc(numberOfCities * sizeof(Node *));
  for (size_t i = 0; i < graph->numberOfCities; ++i)
    graph->adjacent[i]  =   NULL;
  return graph;
}

void insert(Graph *graph, int vertexA, int vertexB, __attribute__((unused)) char *cityA, char *cityB, double km) {
  graph->adjacent[vertexA] = create(vertexB, cityB, graph->adjacent[vertexA], km);
  graph->numberOfEdges++;
}

//void GRAPHshow(Graph *G) {
//  size_t i = 0;
//  while (i != G->numberOfCities) {
//    printf("%d: ", i);
//    for (Node *a = G->adjacent[i]; a; a = a->next) {
//      printf("%s(%.2f) ", a->city, a->km);
//    }
//    puts("");
//    i++;
//  }
//}

//void GRAPHshowAll(Graph *G) {
//  printf("   ");
//  for (size_t i = 0; i != G->numberOfCities; ++i)
//    printf("%d ", i);
//  puts("");
//
//  for (size_t j = 0; j < G->numberOfCities; ++j) {
//    printf("%2d: ", j);
//    Node *a = G->adjacent[j];
//    for (size_t i = 0; i < G->numberOfCities; ++i) {
//      if (a && a->vertex == i) {
//        printf("1 ");
//        a = a->next;
//      }
//      else
//        printf("0 ");
//    }
//    puts("");
//  }
//}

//char *search(Graph *graph, int number) {
//  size_t i;
//  for (i = 0; i < graph->numberOfCities; ++i) {
//    for (Node *walk = graph->adjacent[i]; walk; walk = walk->next) {
//      if (walk->vertex == number) return walk->city;
//    }
//  }
//  return "Frederico";
//}

int menorRota = 1;

void dijkstra(Graph *graph, int vertex, int *prior, double *distance) {
  double ant = 10000;
  int visited[1000];
  for (size_t i = 0; i < graph->numberOfCities; ++i)
    prior[i] = -1,
    visited[i] = 0,
    distance[i] = 1000;
  prior[vertex] = vertex;
  distance[vertex] = 0;
  while (1) {
    double lowest = 1000;
    int aux;
    for (size_t i = 0; i < graph->numberOfCities; ++i) {
      if (visited[i]) continue;
      if (distance[i] < lowest) {
        lowest = distance[i];
        aux = i;
      }
    }
    if (lowest == 1000)
      break;
    for (Node *walk = graph->adjacent[aux]; walk; walk = walk->next) {
      if (visited[walk->vertex])
        continue;
      if (distance[aux] + walk->km < distance[walk->vertex]) {
        distance[walk->vertex] = distance[aux] + walk->km;
        if (distance[walk->vertex] < ant) {
          menorRota++;
        }
        ant = distance[walk->vertex];
        prior[walk->vertex] = aux;
      }
    }
    visited[aux] = 1;
  }
}

int main(void) {
  /* ordem do mais perto (ordenar numeros) */
  Graph *graph = init(15);
  insert(graph, 0, 1, "Frederico", "Palmeira", 66);
  insert(graph, 0, 2, "Frederico", "Sarandi", 88);
  insert(graph, 1, 3, "Palmeira", "Panambi", 51.5);
  insert(graph, 2, 4, "Sarandi", "Carazinho", 45);
  insert(graph, 3, 6, "Panambi", "Cruz Alta", 45.7);
  insert(graph, 4, 5, "Carazinho", "Passo Fundo", 48.1);
  insert(graph, 4, 10, "Carazinho", "Soledade", 76.7);
  insert(graph, 5, 7, "Passo Fundo", "Marau", 30.6);
  insert(graph, 6, 8, "Cruz Alta", "Tapera", 79.5);
  insert(graph, 7, 11, "Marau", "Guapore", 71.9);
  insert(graph, 8, 9, "Tapera", "Espumoso", 12);
  insert(graph, 9, 10, "Espumoso", "Soledade", 41.7);
  insert(graph, 10, 12, "Soledade", "Lajeado", 76.2);
  insert(graph, 11, 12, "Guapore", "Lajeado", 88.8);
  insert(graph, 12, 13, "Lajeado", "Canoas", 106.1);
  insert(graph, 13, 14, "Canoas", "Porto Alegre", 18.1);

  double distance[1000];
  int prior[1000];
  dijkstra(graph, 0, prior, distance);

//  for (size_t v = 1; v < graph->numberOfCities; ++v)
//    printf("de %s para %s %.2f km\n", search(graph, prior[v]), search(graph, v), distance[v]);

  printf("Distancia de Frederico ate Porto Alegre %.2f km\n", distance[graph->numberOfCities - 1]);
  printf("Distancia de menor km: %.2f\n", distance[graph->numberOfCities - 1]);
  printf("Rota com menor numero de cidades: %d\n", menorRota);
  system("pause");
  return 0;
}
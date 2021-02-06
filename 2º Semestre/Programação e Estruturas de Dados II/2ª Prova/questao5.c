/* Problema 5 Leonardo 202012828 arquivo: Dijkstra_v01 - OK.c */
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

void GRAPHshowAll(Graph *G) {
  printf("   ");
  for (size_t i = 0; i != G->numberOfCities; ++i)
    printf("%d ", i);
  puts("");

  for (size_t j = 0; j < G->numberOfCities; ++j) {
    printf("%2d: ", j);
    Node *a = G->adjacent[j];
    for (size_t i = 0; i < G->numberOfCities; ++i) {
      if (a && a->vertex == i) {
        printf("%.0f ", a->km);
        a = a->next;
      }
      else
        printf("0 ");
    }
    puts("");
  }
}

char *search(Graph *graph, int number) {
  size_t i;
  for (i = 0; i < graph->numberOfCities; ++i) {
    for (Node *walk = graph->adjacent[i]; walk; walk = walk->next) {
      if (walk->vertex == number) return walk->city;
    }
  }
  return "centro";
}

int menorRota = 1;
double distance[1000];
int prior[1000];
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

int sum = 0;
int ate(Graph *graph, int a) {
  for (int i = 0; i < graph->numberOfCities; ++i) {
    for (Node *walk = graph->adjacent[i]; walk; walk = walk->next) {
      printf("%s, %.0f Km a partir do centro\n", walk->city, distance[i]);
      if (walk->vertex == a)
        return 1;
    }
  }
  return 0;
}

int main(void) {
  /* ordem do mais perto (ordenar numeros) */
  Graph *graph = init(12);
  insert(graph, 0, 1, "Centro", "Saco dos Limoes", 5);
  insert(graph, 0, 2, "Centro", "Agronomico", 5);
  insert(graph, 1, 3, "Saco dos Limoes", "Trindade", 5);
  insert(graph, 1, 4, "Saco dos Limoes", "Costeira", 8);
  insert(graph, 2, 3, "Agronomico", "Trindade", 3);
  insert(graph, 2, 7, "Agronomico", "Cacupe", 8);
  insert(graph, 3, 1, "Trindade", "Saco dos Limoes", 4);
  insert(graph, 3, 2, "Trindade", "Agronomico", 3);
  insert(graph, 4, 5, "Costeira", "Aeroporto", 4);
  insert(graph, 4, 6, "Costeira", "Campeche", 5);
  insert(graph, 7, 2, "Cacupe", "Agronomico", 8);
  insert(graph, 7, 8, "Cacupe", "Sambaqui", 5);
  insert(graph, 7, 9, "Cacupe", "Jurere", 15);
  insert(graph, 7, 11, "Cacupe", "Canasvieiras", 17);
  insert(graph, 9, 11, "Jurere", "Canasvieiras", 4);
  insert(graph, 11, 10, "Canasvieiras", "Ingleses", 15);
  GRAPHshowAll(graph); puts("");

 /* prf professor eu nao vim do tecnico, comecei a programar ano passado com a Nara leve em consideracao */

  dijkstra(graph, 0, prior, distance);
  printf("01) Qual a distancia do centro ate cada um dos bairros?\n"); puts("");
  for (size_t v = 1; v < graph->numberOfCities; ++v)
    printf("de centro para %s %.2f km\n", search(graph, v), distance[v]);
  puts("");
  printf("02) Voce nao quer ser enganado pelo motorista; assim,\n"
         "quer determinar, a partir do Centro, seu trajeto.\n"
         "Programa isso.\n"); puts("");
  printf("Voce quer ir do Centro para que bairro? 10-Ingleses\n");
  puts("");
  printf("Sua corrida serah de %.2f km\n\n", distance[graph->numberOfCities - 2]);
  printf("Voce vai passar pelos seguintes bairros:\n\n");
  ate(graph, 10);
  system("pause");
  return 0;
}
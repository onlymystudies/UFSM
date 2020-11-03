/* Struct ponto
 * Armazena cordenadas x e y
 */
typedef struct ponto Ponto;

/* Funcao soma
 * Retorna a soma de dois pontos
 */
int soma(Ponto *p);

/* Funcao subtracao
 * Retorna a subtracao de dois pontos
 */
int subtracao(Ponto *p);

/* Funcao armazenar
 * permitam o armazenamento de pontos de uma trajetória de tamanho desconhecido
 */
Ponto *armazenar(float x, float y);

/* Funcao libera
 * libera a memória antes alocada para o vetor
 */
void libera(Ponto *vetor);

/* Funcao distancia
 * retorna a distancia entre dois pontos
 */
float distancia(Ponto *ponto1, Ponto *ponto2);


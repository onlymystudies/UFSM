typedef struct elemento {
    struct elemento *anterior;
    int valor;
    struct elemento *proximo;
}Lista;

typedef struct lista_circular {
    Lista *inicio;
    Lista *fim;
}Lista_c;

/* Fun��o Cria Lista
 * Aloca e retorna uma lista din�mica
 */
Lista *cria_lista(int valor);

/* Fun��o Cria Lista Circular
 * Aloca e retorna uma lista din�mica circular duplamente encadeada
 */
Lista_c *cria_lista_c();

/* Fun��o Destroior lista
 * Libera lista
 */
void libera_lista(Lista **list);

/* Fun��o Lista Vazia
 * Veficia se a lista esta vazia e retorna
 */
int lista_vazia(Lista_c *list_c);

/* Problema 4
 * Escreva as fun��es para inserir e retirar um elemento de uma lista circular duplamente encadeada.
 */
/* Fun��o Insere Lista Inicio
 * Insere elementos no inicio da lista
 */
void insere_lista_inicio(Lista_c *list_c, int valor);

/* Fun��o Insere Lista Fim
 * Insere elementos no fim da lista
 */
void insere_lista_fim(Lista_c *list_c, int valor);

/* Fun��o Imprimi Lista
 * Imprimi inteiramente a lista
 */
void imprime_lista(Lista_c *list_c);

/* Problema 4
 * Escreva as fun��es para inserir e retirar um elemento de uma lista circular duplamente encadeada.
 */
/* Fun��o Remove Lista
 * Remove elementos da lista
 */
void remove_lista(Lista_c *list_c, int valor);

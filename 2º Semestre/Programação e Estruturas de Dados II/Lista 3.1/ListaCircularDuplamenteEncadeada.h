typedef struct elemento {
    struct elemento *anterior;
    int valor;
    struct elemento *proximo;
}Lista;

typedef struct lista_circular {
    Lista *inicio;
    Lista *fim;
}Lista_c;

/* Função Cria Lista
 * Aloca e retorna uma lista dinâmica
 */
Lista *cria_lista(int valor);

/* Função Cria Lista Circular
 * Aloca e retorna uma lista dinâmica circular duplamente encadeada
 */
Lista_c *cria_lista_c();

/* Função Destroior lista
 * Libera lista
 */
void libera_lista(Lista **list);

/* Função Lista Vazia
 * Veficia se a lista esta vazia e retorna
 */
int lista_vazia(Lista_c *list_c);

/* Problema 4
 * Escreva as funções para inserir e retirar um elemento de uma lista circular duplamente encadeada.
 */
/* Função Insere Lista Inicio
 * Insere elementos no inicio da lista
 */
void insere_lista_inicio(Lista_c *list_c, int valor);

/* Função Insere Lista Fim
 * Insere elementos no fim da lista
 */
void insere_lista_fim(Lista_c *list_c, int valor);

/* Função Imprimi Lista
 * Imprimi inteiramente a lista
 */
void imprime_lista(Lista_c *list_c);

/* Problema 4
 * Escreva as funções para inserir e retirar um elemento de uma lista circular duplamente encadeada.
 */
/* Função Remove Lista
 * Remove elementos da lista
 */
void remove_lista(Lista_c *list_c, int valor);

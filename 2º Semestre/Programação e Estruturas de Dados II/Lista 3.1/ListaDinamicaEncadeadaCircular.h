struct valores {
    int numeros;
};
typedef struct elemento *Lista;

/* Funcao cria lista
 * Cria e retorna a lista
 */
Lista* cria_lista();

/* Funcao libera_lista
 * Esvazia a lista
 */
void libera_lista(Lista* l);

/* Funcao tamanho lista
 * Retorna o tamanho da lista
 */
int tamanho_lista(Lista *l);

/* Funcao lista vazia
 * retorna 1 quando a lista for valida e estiver vazia
 */
int lista_vazia(Lista *l);
// (listas dinamicas nunca estao cheias)

/* Problema 3
 * Escreva as fun��es para inserir e retirar um elemento de uma lista circular.
 */
int remove_lista(Lista *l, int val);

/* Problema 3
 * Escreva as fun��es para inserir e retirar um elemento de uma lista circular.
 */
int insere_lista_ordenada(Lista *l, struct valores val);

/* Funcao consulta lista
 * procura na lista conforme posicao
 */
int consulta_lista(Lista* l, int pos, struct valores *val);

/* Problema 1
 * Implemente uma fun��o que verifique se duas listas encadeadas s�o iguais.
 * Duas listas s�o consideradas iguais se t�m a mesma sequ�ncia de elementos.
 * O prot�tipo da fun��o deve ser dado por:
 */
int igual (Lista* l1, Lista* l2);

/* Problema 2
 * Exerc�cio: Implemente uma fun��o que crie uma c�pia de uma lista encadeada.
 * O prot�tipo da fun��o deve ser dado por:
 */
Lista* copia (Lista* l);
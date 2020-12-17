/* Problema 4
 * Modifique a função “Arv* insere (Arv* a, int v)” de “abp.c” para que instale os novos nodos
 * sempre deixando a sub-árvore da esquerda da raiz do mesmo tamanho da direita.
 */
#include <stdio.h>
#include <stdlib.h>

//O tipo da arvore binaria pode entao ser dado por:
struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
};
typedef struct arv Arv;

//A arvore e representada pelo ponteiro para o no raiz. A arvore vazia e inicializada
//atribuindo-se NULL a variavel que representa a arvore. Uma funcao simples de
//inicializacao e mostrada abaixo:
Arv* init (void)
{
    return NULL;
}

//Uma vez construida uma arvore de busca, podemos imprimir os valores da arvore em
//ordem crescente percorrendo os nos em ordem simetrica:
void imprime (Arv* a)
{
    if (a != NULL) {
        imprime(a->esq);
        printf("%d\n",a->info);
        imprime(a->dir);
    }
}

//Essas sao funcoes analogas as vistas para arvores binarias comuns, pois nao exploram a
//propriedade de ordenacao das arvores de busca. No entanto, as operacoes que nos
//interessa analisar em detalhes sao:
//a busca: funcao que busca um elemento na arvore;
//a insere: funcao que insere um novo elemento na arvore;
//a retira: funcao que retira um elemento da �rvore.

//Operacao de busca
//A operacao para buscar um elemento na arvore explora a propriedade de ordenacao da
//arvore, tendo um desempenho computacional proporcional a sua altura (O(log n) para o
//caso de arvore balanceada). Uma implementacao da funcao de busca e dada por:
Arv* busca (Arv* r, int v)
{
    if (r == NULL) return NULL;
    else if (r->info > v) return busca (r->esq, v);
    else if (r->info < v) return busca (r->dir, v);
    else return r;
}

//Operacao de insercao
//A operacao de insercao adiciona um elemento na arvore na posicao correta para que a
//propriedade fundamental seja mantida. Para inserir um valor v em uma arvore usamos
//sua estrutura recursiva, e a ordenacao especificada na propriedade fundamental. Se a
//(sub-) arvore e vazia, deve ser substituida por uma arvore cujo unico no (o no raiz)
//contem o valor v. Se a arvore nao e vazia, comparamos v com o valor na raiz da arvore,
//e inserimos v na sae ou na sad, conforme o resultado da comparacao. A funcao abaixo
//ilustra a implementacao dessa operaccao. A funcao tem como valor de retorno o eventual
//novo no raiz da (sub-) arvore.
//Arv* insere (Arv* a, int v)
//{
//    if (a==NULL) {
//        a = (Arv*)malloc(sizeof(Arv));
//        a->info = v;
//        a->esq = a->dir = NULL;
//    }
//    else if (v < a->info)
//        a->esq = insere(a->esq,v);
//    else /* v < a->info */
//        a->dir = insere(a->dir,v);
//    return a;
//}
int cont_dir (Arv *a)
{
    if (!a)
        return 0;
    else
        return 1 + cont_dir (a->dir);
}

int cont_esq (Arv *a)
{
    if (!a)
        return 0;
    else
        return 1 + cont_esq (a->esq);
}

Arv* insere (Arv* a, int v)
{
    if (!a) {
        a = (Arv *) malloc(sizeof(Arv));
        a->info = v;
        a->esq = a->dir = NULL;
    }
    else if (cont_dir (a) > cont_esq (a))
        a->esq = insere(a->esq,v);
    else
        a->dir = insere(a->dir,v);
    return a;
}


//O c�digo abaixo ilustra a implementa��o da fun��o para retirar um elemento da �rvore
//bin�ria de busca. A fun��o tem como valor de retorno a eventual nova raiz da (sub-)
//�rvore.
Arv* retira (Arv* r, int v)
{
    if (r == NULL)
        return NULL;
    else if (r->info > v)
        r->esq = retira(r->esq, v);
    else if (r->info < v)
        r->dir = retira(r->dir, v);
    else { /* achou o elemento */
        if (r->esq == NULL && r->dir == NULL) { /* elemento sem filhos */
            free (r);
            r = NULL;
        }
        else if (r->esq == NULL) { /* s� tem filho � direita */
            Arv* t = r;
            r = r->dir;
            free (t);
        }
        else if (r->dir == NULL) { /* s� tem filho � esquerda */
            Arv* t = r;
            r = r->esq;
            free (t);
        }
        else { /* tem os dois filhos */
            Arv* pai = r;
            Arv* f = r->esq;
            while (f->dir != NULL) {
                pai = f;
                f = f->dir;
            }
            r->info = f->info; /* troca as informa��es */
            f->info = v;
            r->esq = retira(r->esq,v);
        }
    }
    return r;
}

int vazia(Arv* a)
{
    return a==NULL;
}

void imprime_alt (Arv* a)
{
    if (!vazia(a)){
        if (a->info == 6)
            printf("<");
        printf("%d", a->info); /* mostra raiz */
        printf("<");
        imprime_alt(a->esq); /* mostra sae */
        printf(">");
        printf("<");
        imprime_alt(a->dir); /* mostra sad */
        printf(">");
        if (a->info == 6)
            printf(">");
    }
}

int main() {
    Arv *arv = init();
    arv = insere(arv, 6);
    arv = insere(arv, 8);
    arv = insere(arv, 2);
    arv = insere(arv, 1);
    arv = insere(arv, 4);
    arv = insere(arv, 3);
    imprime(arv);
    printf("nodos a esquerda %d\n", cont_esq (arv));
    printf("nodos a direita %d\n", cont_dir (arv));
/*	puts("");
	imprime_alt (arv);

	//void imprime (Arv* a)
	//Arv* busca (Arv* r, int v)

	arv = retira (arv, 6);
	imprime (arv);
	puts("");
	imprime_alt (arv);*/

    system("pause");
}
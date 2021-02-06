/* Nome: Leonardo Zamboni Nunes 202012828
 * Arquivo: ArvGen.C*/
#include <stdio.h>
#include <stdlib.h>

struct arvgen {
    char info;
    struct arvgen *prim;
    struct arvgen *prox;
};

typedef struct arvgen ArvGen;

//A estrutura arvgen, que representa o n� da �rvore, � definida conforme mostrado
//anteriormente. A fun��o para criar uma folha deve alocar o n� e inicializar seus campos,
//atribuindo NULL para os campos prim e prox, pois trata-se de um n� folha.
ArvGen* cria (char c)
{
  ArvGen *a =(ArvGen *) malloc(sizeof(ArvGen));
  a->info = c;
  a->prim = NULL;
  a->prox = NULL;
  return a;
}

//A fun��o que insere uma nova sub-�rvore como filha de um dado n� � muito simples.
//Como n�o vamos atribuir nenhum significado especial para a posi��o de um n� filho, a
//opera��o de inser��o pode inserir a sub-�rvore em qualquer posi��o. Neste caso, vamos
//optar por inserir sempre no in�cio da lista que, como j� vimos, � a maneira mais simples
//de inserir um novo elemento numa lista encadeada.
void insere (ArvGen* a, ArvGen* sa)
{
  sa->prox = a->prim;
  a->prim = sa;
}

void imprime (ArvGen* a)
{
  ArvGen* p;
  printf("%c\n",a->info);
  for (p=a->prim; p!=NULL; p=p->prox)
    imprime(p);
}

void imprime_alt (ArvGen* a)
{
  ArvGen* p;
  printf("<%c",a->info);
  for (p=a->prim; p!=NULL; p=p->prox)
    imprime_alt(p);
  printf(">");
}

//A opera��o para buscar a ocorr�ncia de uma dada informa��o na �rvore � exemplificada
//abaixo:
int busca (ArvGen* a, char c)
{
  ArvGen* p;
  if (a->info==c)
    return 1;
  else {
    for (p=a->prim; p!=NULL; p=p->prox) {
      if (busca(p,c))
        return 1;
    }
  }
  return 0;
}

// A ultima operacao apresentada e a que libera a memoria alocada pela arvore. O unico
//cuidado que precisamos tomar na programacao dessa funcao e a de liberar as subarvores
//antes de liberar o espaco associado a um no (isto e, usar pos-ordem).
void libera (ArvGen* a)
{
  ArvGen* p = a->prim;
  while (p!=NULL) {
    ArvGen* t = p->prox;
    libera(p);
    p = t;
  }
  free(a);
}


void imprime_por_nivel (ArvGen* a, int i)
{
  ArvGen* p;
  printf("%c, ",a->info);
  printf("nivel %d\n", i++);
  for (p=a->prim; p!=NULL; p=p->prox)
    imprime_por_nivel(p, i);
}

int main(void) {
  //Com essas duas fun��es, podemos construir a �rvore do exemplo da Figura 13.7 com o
  //seguinte fragmento de c�digo:
  /* cria n�s como folhas */
  ArvGen* a = cria('a');
  ArvGen* b = cria('b');
  ArvGen* c = cria('c');
  ArvGen* d = cria('d');
  ArvGen* e = cria('e');
  ArvGen* f = cria('f');
  ArvGen* g = cria('g');
  ArvGen* h = cria('h');
  ArvGen* i = cria('i');
  ArvGen* j = cria('j');
  /* monta a hierarquia */
  insere(a,f);
  insere(a,b);
  insere(a,g);
  insere(b,d);
  insere(b,c);
  insere(c,e);
  insere(g,h);
  insere(g,i);
  insere(i,j);
  imprime_por_nivel(a, 0); puts("");
  imprime(a);
  imprime_alt(a); puts("");
  system("pause");
  return 0;
}


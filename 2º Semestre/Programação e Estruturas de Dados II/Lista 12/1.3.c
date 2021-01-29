/* // Cria/instala um nodo em uma árvore binária
Arv* cria(char c, Arv* sae, Arv* sad){
}
// Cria/instala um nodo em uma árvore binária de pesquisa
Arv* cria_abp(char c){
}
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct arv {
    char info;
    struct arv* esq;
    struct arv* dir;
};

typedef struct arv Arv;

Arv* cria(char c, Arv* sae, Arv* sad){
  Arv *new = (Arv *) malloc(sizeof(Arv));
  new->info = c;
  new->esq = sae;
  new->dir = sad;
  return new;
}

Arv *cria_abp(Arv *a, char c) {
  if (!a) {
    a = (Arv *) malloc(sizeof(Arv));
    a->info = c;
    a->esq = a->dir = NULL;
    return a;
  }
  else if (a->info > c)
    a->esq = cria_abp(a->esq, c);
  else
    a->dir = cria_abp(a->dir, c);
  return a;
}

void abb_imprime(Arv *arvore) {
  if (arvore) {
    abb_imprime(arvore->esq);
    printf("%c ", arvore->info);
    abb_imprime(arvore->dir);
  }
}

int main(void) {
  Arv *v6 = cria('f', NULL, NULL);
  Arv *v5 = cria('e', v6, NULL);
  Arv *v4 = cria('d', NULL, v5);
  Arv *v3 = cria('c', NULL, NULL);
  Arv *v2 = cria('b', NULL, v3);
  Arv *v1 = cria('a', v2, v4);
  abb_imprime(v1); puts("");
  system("pause");
  return 0;
}
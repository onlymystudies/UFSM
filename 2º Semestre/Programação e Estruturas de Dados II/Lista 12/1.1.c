/* Semana 14 - Lista 14-1 de exercícios de Programação e Estruturas de Dados II */
#include <stdlib.h>

struct arvgen {
    char info;
    struct arvgen *prim;
    struct arvgen *prox;
};

typedef struct arvgen ArvGen;

ArvGen* cria(char c) {
    ArvGen *arv 	=	(ArvGen *) malloc(sizeof(ArvGen));
    arv->info		=	c;
    arv->prim 		=	arv->prox	=	NULL;
    return arv;
}

void insere(ArvGen* a, ArvGen* sa) {
    sa->prim	=	a->prox;
    a->prox		=	sa;
}

int busca(ArvGen *a, char c) {
    if (a->info == c)
        return 1;
    else
        for (ArvGen *walkTree = a->prox; walkTree; walkTree = walkTree->prox)
            if (busca(walkTree, c))
                return 1;
    return 0;
}

int main(void) {
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
    insere(c, d);
    insere(b, e);
    insere(b, c);
    insere(i, j);
    insere(g, i);
    insere(g, h);
    insere(a, g);
    insere(a, f);
    insere(a, b);
    return 0;
}

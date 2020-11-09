Lista2* insere_ordenado (Lista2* l, int v) {
    Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
    Lista2* p = l;

    while ((int) novo->prox < v) {
        p->ant = p;
        p = p->prox;
    }

    if (p->ant == NULL) {
        novo->prox = l;
    } else {
        novo->prox = p->ant->prox;
        p->ant->prox = novo;
    }

    return novo;
}
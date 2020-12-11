/* Problema 2
 * Implemente uma função que retorne a quantidade de folhas de uma árvore binária. Essa função deve obedecer
 * ao protótipo:
 * int folhas (Arv* a);
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    char info;
    struct arvore *esquerda;
    struct arvore *direita;
}Arvore;

Arvore *inicia(void) {
    return NULL;
}

Arvore *cria(char c, Arvore *esquerda, Arvore *direita) {
    Arvore *arvore = (Arvore *) malloc(sizeof(Arvore));
    arvore->info = c;
    arvore->esquerda = esquerda;
    arvore->direita = direita;
    return arvore;
}

int vazia(Arvore *arvore) {
    return arvore == NULL;
}

int folhas (Arvore *arvore) {
    if(!arvore)
        return 0;
    else
        return 1 + folhas(arvore->esquerda) + folhas(arvore->direita);
}

void imprimeOrdem(Arvore *arvore)
{
    if (!vazia(arvore)){
        imprimeOrdem(arvore->esquerda);
        printf("%c ", arvore->info);
        imprimeOrdem(arvore->direita);
    }
}

void imprimePosOrdem(Arvore *arvore)
{
    if (!vazia(arvore)){
        imprimePosOrdem(arvore->esquerda);
        imprimePosOrdem(arvore->direita);
        printf("%c ", arvore->info);
    }
}

void imprimePreOrdem(Arvore *arvore)
{
    if (!vazia(arvore)){
        printf("%c ", arvore->info);
        imprimePreOrdem(arvore->esquerda);
        imprimePreOrdem(arvore->direita);
    }
}

//void imprime_alt (Arvore *arvore)
//{
//    if (!vazia(arvore)){
//        if (arvore->info == 'a')
//            printf("<");
//        printf("%c", arvore->info);
//        printf("<");
//        imprime_alt(arvore->esquerda);
//        printf(">");
//        printf("<");
//        imprime_alt(arvore->direita);
//        printf(">");
//        if (arvore->info == 'a')
//            printf(">");
//    }
//}

Arvore* libera (Arvore *arvore){
    if (!vazia(arvore)){
        libera(arvore->esquerda);
        libera(arvore->direita);
        free(arvore);
    }
    return NULL;
}

int altura(Arvore *arvore) {
    if (arvore == NULL)
        return -1;
    else {
        int esquerda = altura (arvore->esquerda);
        int direita = altura (arvore->direita);
        if (esquerda < direita) return direita + 1;
        else return esquerda + 1;
    }
}

int busca (Arvore *arvore, char c){
    if (vazia(arvore))
        return 0;
    else
        return arvore->info==c || busca(arvore->esquerda,c) || busca(arvore->direita,c);
}

int main() {
    Arvore* a1= cria('d', inicia(), inicia());
    Arvore* a2= cria('b', inicia(), a1);
    Arvore* a3= cria('e', inicia(), inicia());
    Arvore* a4= cria('f', inicia(), inicia());
    Arvore* a5= cria('c', a3, a4);
    Arvore* a = cria('a', a2, a5 );
    printf("soma de folhas: %d", folhas(a) - 1);
//    puts("Ordem");
//    imprimeOrdem(a);
//    puts("\nPos");
//    imprimePosOrdem(a);
//    puts("\nPre");
//    imprimePreOrdem(a);
//    puts("");
//    imprime_alt(a);
//    printf("\nint altura(Arv* a) %d", altura(a));
//    printf("\nint busca (Arv* a, char c) %d", busca (a, 'a'));
//    printf("\nint busca (Arv* a, char c) %d", busca (a, 'x'));
//    libera(a);
    puts("");
    system("pause");
}
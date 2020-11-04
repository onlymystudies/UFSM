#include <stdio.h>
#include "ListaDinamicaEncadeadaCircular.c"

int main() {
    struct valores dados1, dados2;
    struct valores dados1_consult, dados2_consult;
    dados1.numeros = 1;
    dados2.numeros = 0;
    Lista *l1;
    l1 = cria_lista();
    insere_lista_ordenada(l1, dados1);
    insere_lista_ordenada(l1, dados2);

    consulta_lista(l1, 1, &dados1_consult);
    printf("valor :%d\n", dados1_consult.numeros);
    consulta_lista(l1, 2, &dados2_consult);
    printf("valor :%d\n", dados2_consult.numeros);
    printf("tamanho lista: %d\n", tamanho_lista(l1));

    struct valores dados1_2, dados2_2;
    struct valores dados1_consult_2, dados2_consult_2;
    dados1_2.numeros = 0;
    dados2_2.numeros = 1;
    Lista *l2;
    l2 = cria_lista();
    insere_lista_ordenada(l2, dados1_2);
    insere_lista_ordenada(l2, dados2_2);

    consulta_lista(l2, 1, &dados1_consult_2);
    printf("valor :%d\n", dados1_consult_2.numeros);
    consulta_lista(l2, 2, &dados2_consult_2);
    printf("valor :%d\n", dados2_consult_2.numeros);
    printf("tamanho lista: %d\n", tamanho_lista(l2));

    igual(l1, l2);

    Lista *lc;
    lc = copia(l1);
    struct valores dadoscopia;
    consulta_lista(lc, 1, &dadoscopia);
    printf("valor :%d\n", dadoscopia.numeros);
    consulta_lista(lc, 2, &dadoscopia);
    printf("valor :%d\n", dadoscopia.numeros);

    system("pause");
}
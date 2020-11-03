#include "L:\Usuarios\Github Storage\UFSM\2º Semestre\Programação e Estruturas de Dados II\Lista 2.1\matriz.h"

int main() {
    Matriz *mat = cria(5, 5);

    if (linhas(mat) == colunas(mat))
        printf("Matriz quadrada simetrica\n");\
    else
        printf("Matriz nao quadrada simetrica\n");

    system("pause");
}
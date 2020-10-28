/* Problema 1.1.4
 * Um comerciante deseja fazer o levantamento do lucro das mercadorias que ele comercializa. Para isto, mandou digitar numa linha para cada mercadoria com o nome, preço de compra e preço de venda das mesmas.
 * Fazer um algoritmo que:
 * determine e escreva quantas mercadorias proporcionam:
 * a) lucro menor que 10%
 * b) lucro entre 10% e 20%
 * c) lucro maior que 20%
 * determine e escreva o valor total de compra e de venda de todas as mercadorias, assim como o lucro total.
 * Obs.: o aluno deve adotar um flag.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int     valor_total_compra  =   0,
            valor_total_vendas  =   0,
            lucro_total         =   0,
            lucro_menor_10      =   0,
            lucro_entre_10e20   =   0,
            lucro_maior_20      =   0,
            nova_entrada        =   1,
            preco_compra,
            preco_venda;
    char    nome[64];

    do {
        printf("Nome do produto:\n");
        fgets(nome, 64, stdin);
        fflush(stdin);
        printf("Preco de compra:\n");
        scanf("%d", &preco_compra);
        printf("Preco de venda:\n");
        scanf("%d", &preco_venda);
        printf("1 - Nova entrada\n0 - Sair\n");
        scanf("%d", &nova_entrada);
        valor_total_compra += preco_compra;
        valor_total_vendas += preco_venda;
        lucro_total        += preco_venda - preco_compra;
        if ((preco_venda - preco_compra) * preco_compra < 10) lucro_menor_10++;
        if ((preco_venda - preco_compra) * preco_compra > 10 && (preco_venda - preco_compra) * preco_compra < 20) lucro_entre_10e20++;
        if ((preco_venda - preco_compra) * preco_compra > 20) lucro_maior_20++;
    } while (nova_entrada != 0);

    printf("a) lucro menor que 10%%: %d%%\n", lucro_menor_10);
    printf("b) lucro entre 10%% e 20%%: %d%%\n", lucro_entre_10e20);
    printf("c) lucro maior que 20%%: %d%%\n", lucro_maior_20);
    printf("Valor total de\nCompras: %d\nVendas: %d\nLucro: %d\n", valor_total_compra, valor_total_vendas, lucro_total);
    system("pause");
}
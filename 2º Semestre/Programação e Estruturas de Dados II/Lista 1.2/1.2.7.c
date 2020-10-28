/* Problema 1.2.7 (OBI2000)
 * Bits Trocados
 * As Ilhas Weblands formam um reino independente nos mares do Pacífico. Como é um reino recente, a sociedade é
 * muito influenciada pela informática. A moeda oficial é o Bit; existem notas de B$ 50,00, B$10,00, B$5,00 e B$1,00.
 * Você foi contratado(a) para ajudar na programação dos caixas automáticos de um grande banco das Ilhas Weblands.
 * 1. Tarefa) Os caixas eletrônicos das Ilhas Weblands operam com todos os tipos de notas disponíveis, mantendo um
 * estoque de cédulas para cada valor (B$ 50,00, B$10,00, B$5,00 e B$1,00). Os clientes do banco utilizam os caixas
 * eletrônicos para efetuar retiradas de um certo número inteiro de Bits. Sua tarefa é escrever um programa que, dado
 * o valor de Bits desejado pelo cliente, determine o número de cada uma das notas necessário para totalizar esse valor,
 * de modo a minimizar a quantidade de cédulas entregues. Por exemplo, se o cliente deseja retirar B$50,00, basta
 * entregar uma única nota de cinquenta Bits. Se o cliente deseja retirar B$72,00, é necessário entregar uma nota de
 * B$50,00, duas de B$10,00 e duas de B$1,00.
 * 2. Entrada) A entrada é composta de vários conjuntos de teste. Cada conjunto de teste é composto por uma única
 * linha, que contém um número inteiro positivo V, que indica o valor solicitado pelo cliente. O final da entrada é indicado
 * por V = 0.
 * Exemplo de Entrada
 * 1
 * 72
 * 0
 * 3. Saída) Para cada conjunto de teste da entrada seu programa deve produzir três linhas na saída. A primeira linha
 * deve conter um identificador do conjunto de teste, no formato ?Teste n?, onde n é numerado a partir de 1. Na segunda
 * linha devem aparecer quatro inteiros I, J, K e L que representam o resultado encontrado pelo seu programa: I indica o
 * número de cédulas de B$50,00, J indica o número de cédulas de B$10,00, K indica o número de cédulas de B$5,00 e L
 * indica o número de cédulas de B$1,00. A terceira linha deve ser deixada em branco. A grafia mostrada no Exemplo de
 * Saída, abaixo, deve ser seguida rigorosamente.
 * Exemplo de Saída
 * Teste 1
 * 0 0 0 1
 * Teste 2
 * 1 2 0 2
 * (esta saída corresponde ao exemplo de entrada acima)
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int valor_bits,
        cinquenta_bits = 0,
        dez_bits       = 0,
        cinco_bits     = 0,
        um_bit         = 0;

    printf("Valor de Bits desejado:\n");
    scanf("%d", &valor_bits);
    if (valor_bits > 50) do { valor_bits -= 50; cinquenta_bits++; } while (valor_bits >= 50);
    if (valor_bits > 10) do { valor_bits -= 10; dez_bits++      ; } while (valor_bits >= 10);
    if (valor_bits > 5 ) do { valor_bits -= 5 ; cinco_bits++    ; } while (valor_bits >= 5 );
    if (valor_bits > 1 ) do { valor_bits -= 1 ; um_bit++        ; } while (valor_bits >= 1 );

    printf("%d %d %d %d", cinquenta_bits, dez_bits, cinco_bits, um_bit);
    system("pause");
}
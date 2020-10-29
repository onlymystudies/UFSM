/* Problema 1.2.7 (OBI2000)
 * Bits Trocados
 * As Ilhas Weblands formam um reino independente nos mares do Pac�fico. Como � um reino recente, a sociedade �
 * muito influenciada pela inform�tica. A moeda oficial � o Bit; existem notas de B$ 50,00, B$10,00, B$5,00 e B$1,00.
 * Voc� foi contratado(a) para ajudar na programa��o dos caixas autom�ticos de um grande banco das Ilhas Weblands.
 * 1. Tarefa) Os caixas eletr�nicos das Ilhas Weblands operam com todos os tipos de notas dispon�veis, mantendo um
 * estoque de c�dulas para cada valor (B$ 50,00, B$10,00, B$5,00 e B$1,00). Os clientes do banco utilizam os caixas
 * eletr�nicos para efetuar retiradas de um certo n�mero inteiro de Bits. Sua tarefa � escrever um programa que, dado
 * o valor de Bits desejado pelo cliente, determine o n�mero de cada uma das notas necess�rio para totalizar esse valor,
 * de modo a minimizar a quantidade de c�dulas entregues. Por exemplo, se o cliente deseja retirar B$50,00, basta
 * entregar uma �nica nota de cinquenta Bits. Se o cliente deseja retirar B$72,00, � necess�rio entregar uma nota de
 * B$50,00, duas de B$10,00 e duas de B$1,00.
 * 2. Entrada) A entrada � composta de v�rios conjuntos de teste. Cada conjunto de teste � composto por uma �nica
 * linha, que cont�m um n�mero inteiro positivo V, que indica o valor solicitado pelo cliente. O final da entrada � indicado
 * por V = 0.
 * Exemplo de Entrada
 * 1
 * 72
 * 0
 * 3. Sa�da) Para cada conjunto de teste da entrada seu programa deve produzir tr�s linhas na sa�da. A primeira linha
 * deve conter um identificador do conjunto de teste, no formato ?Teste n?, onde n � numerado a partir de 1. Na segunda
 * linha devem aparecer quatro inteiros I, J, K e L que representam o resultado encontrado pelo seu programa: I indica o
 * n�mero de c�dulas de B$50,00, J indica o n�mero de c�dulas de B$10,00, K indica o n�mero de c�dulas de B$5,00 e L
 * indica o n�mero de c�dulas de B$1,00. A terceira linha deve ser deixada em branco. A grafia mostrada no Exemplo de
 * Sa�da, abaixo, deve ser seguida rigorosamente.
 * Exemplo de Sa�da
 * Teste 1
 * 0 0 0 1
 * Teste 2
 * 1 2 0 2
 * (esta sa�da corresponde ao exemplo de entrada acima)
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
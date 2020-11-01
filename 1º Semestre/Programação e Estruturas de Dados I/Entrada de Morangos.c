#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
/* Função para limpar o buffer do teclado */
void limpa_buffer()
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {} // getchar() retorna o caracter lido
    return; // EOF (end of file) retorna à função quando nao for possível ler nada
}
char nome[61]; // Variável global para armazenar o nome do produtor
/* Função de entrada para nome do produtor */
void digite_nome()
{
    system("cls");
    setlocale(LC_ALL, "Portuguese"); // Utilizando caracteres e acentuação da língua portuguesa biblioteca <locale.h>
    printf("=====================================================");
    printf("\n\t\tNome do produtor\n");
    printf("=====================================================");
    void lancamento(); // Declaração da função de lançamento
    printf("\nNome: \n");
    scanf("%s", &nome);
    limpa_buffer();

    lancamento();
}
float dia1, dia2, mes; // Variáveis para armazenar dias e mês
/* Função de entrada dias da semana para lançamento */
int dias_adjacente(int dia_adjacente)
{
    system("cls");
    setlocale(LC_ALL, "Portuguese");
    printf("=====================================================");
    printf("\n\t\tDias da semana\n");
    printf("=====================================================");
/* Mes de lançamento */
    printf("\nMês ");
    scanf("%f", &mes);
    limpa_buffer();
    if ((mes < 1) || (mes >= 13)) { // || = ou
        printf("\nMês inexistente");
        exit(0);
    }
/* Primeiro dia de lançamento */
    printf("do dia ");
    scanf("%f", &dia1);
    limpa_buffer();
    if ((dia1 < 1) || (dia1 > 31)) {
        printf("\nDia inexistente");
        exit(0);
    }
/* Segundo dia de lançamento */
    printf("até dia ");
    scanf("%f", &dia2);
    limpa_buffer();
    if ((dia2 < 1) || (dia2 > 31)) {
        printf("\nDia inexistente");
        exit(0);
    }
/* Dia incoerente */
    if (dia2 < dia1) {
        printf("Dia incoerente");
        exit(0);
    }
    dia_adjacente = dia2 - dia1;
    return dia_adjacente;
}
/* Função de Lançamento de produção */
void lancamento()
{
/* Retornar dia da função de entrada dias da semana para lançamento */
    int retorna = 0, dia;
    dia = dias_adjacente(retorna);
    system("cls");
    setlocale(LC_ALL, "Portuguese");
    printf("=====================================================");
    printf("\n\t\tLançamento\n");
    printf("=====================================================\n");
/* Variáveis auxiliares */
    typedef struct varint {
        int i;
        int y;
        int j;
        int x;
        int voltar;
        int diaprintf;
    } aux;
    aux varint;

/* Variáveis de soma */
    int Total_caixas_colhidas = 0;
    int valor_total_caixas = 0;
    int soma_indust_sujo = 0;
    int soma_indust_limpo = 0;
    int soma_filmes = 0;
    int soma_papelao = 0;
    int soma_bandeija = 0;
    int valor_pagar = 0;

/* Variáveis vetores */
    int caixas[dia];
    char condicao[dia];
    int valor[dia];
    float indust_limpo[dia];
    float indust_sujo[dia];
    int mult[dia];
    float filmes[dia];
    float papelao[dia];
    float bandeija[dia];

    varint.diaprintf = dia1;
/* Lançamento */
    for (varint.i = 1; varint.i <= dia; varint.i++)
    {
        /* Caixas */
        printf("Dia %d caixas:\n", varint.diaprintf);
        scanf("%d", &caixas[varint.i]);
        limpa_buffer();
        /* Codição do morango */
        printf("Condição dia %d (N - Novo / V - Velho):\n", varint.diaprintf);
        scanf("%c", &condicao[varint.i]);
        limpa_buffer();
        /* Valor pago por caixa */
        printf("Valor pago dia %d:\n", varint.diaprintf);
        scanf("%d", &valor[varint.i]);
        limpa_buffer();
        if (condicao[varint.i] == 'n') {
            valor[varint.i] = valor[varint.i] + 1;
        }

        /* Morango industrias limpo */
        printf("\nIndustria limpo dia %d:\n", varint.diaprintf);
        scanf("%f", &indust_limpo[varint.i]);
        limpa_buffer();
        /* Morango industrias Sujo */
        printf("Industria sujo dia %d:\n", varint.diaprintf);
        scanf("%f", &indust_sujo[varint.i]);
        limpa_buffer();
        /* Itens comprados para desconto */
        printf("Filmes dia %d:\n", varint.diaprintf);
        scanf("%f", &filmes[varint.i]);
        limpa_buffer();
        printf("Caixas de papelão dia %d:\n", varint.diaprintf);
        scanf("%f", &papelao[varint.i]);
        limpa_buffer();
        printf("Bandeija plástica dia %d:\n", varint.diaprintf);
        scanf("%f", &bandeija[varint.i]);
        limpa_buffer();

        varint.diaprintf++;
        system("cls");
    }
    for (varint.y = 1; varint.y <= dia; varint.y++)
    {
        mult[varint.y] = caixas[varint.y] * valor[varint.y];
        Total_caixas_colhidas = Total_caixas_colhidas + caixas[varint.y];
        valor_total_caixas = valor_total_caixas + mult[varint.y];
        soma_indust_sujo = soma_indust_sujo + indust_sujo[varint.y];
        soma_indust_limpo = soma_indust_limpo + indust_limpo[varint.y];
        soma_filmes = soma_filmes + filmes[varint.y];
        soma_papelao = soma_papelao + papelao[varint.y];
        soma_bandeija = soma_bandeija + bandeija[varint.y];
    }

/* Soma e subtração dos valores a serem pagos */
    valor_pagar = valor_pagar + soma_indust_sujo * 2 + soma_indust_limpo * 3 + valor_total_caixas;

/* Relatório final */
    printf("\nRelatório do mês %.0f do dia %.0f até dia %.0f de 2020\n", mes, dia1, dia2);
    printf("\nProdutor: %s\n", nome);
    printf("_____________________________________________________\n");
    printf("\nCaixas: %d\n", Total_caixas_colhidas);
    printf("Industria sujo: %d Kg\n", soma_indust_sujo);
    printf("Industria limpo: %d Kg\n", soma_indust_limpo);
    printf("Valor total: R$ %d\n", valor_total_caixas + soma_indust_sujo * 2 + soma_indust_limpo * 3);
    printf("\n\t\tDescontos\n");
    printf("_____________________________________________________\n");
    printf("\nFilmes: %d\n", soma_filmes);
    printf("Caixas de papelão: %d\n", soma_papelao);
    printf("Bandeijas: %d\n", soma_bandeija);
    printf("_____________________________________________________\n");
    printf("\nValor total a ser pago: R$ %d\n", valor_pagar - soma_filmes * 55 - soma_papelao * 1 - soma_bandeija * 32);
}
/* Menu */
int main()
{
    setlocale(LC_ALL, "Portuguese");
/* Variáveis */
    int menu, dia1, dia2;
    printf("=====================================================");
    printf("\n\tAutomatização entrada de morangos\n");
    printf("=====================================================");
    printf ("\n\t [1] Iniciar [2] Sair \n\n");
    scanf ("%d", & menu);
    limpa_buffer();
    while(menu != 2)
    {
        switch(menu)
        {
            case 1:
                digite_nome();
                break;
            case 2:
                exit(0);
            default:
                printf("Opção inexistente");
        }
        while(menu != 2);
    }
}

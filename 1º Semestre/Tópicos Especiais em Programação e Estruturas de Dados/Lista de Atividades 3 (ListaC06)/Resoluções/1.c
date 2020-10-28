#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

struct tempo {
    int tm_sec; // representa os segundos de 0 a 59
    int tm_min; // representa os minutos de 0 a 59
    int tm_hour; // representa as horas de 0 a 24
    int tm_mday; // dia do mês de 1 a 31
    int tm_mon; // representa os meses do ano de 0 a 11
    int tm_year; // representa o ano a partir de 1900
    int tm_wday; // dia da semana de 0 (domingo) até 6 (sábado)
    int tm_yday; // dia do ano de 1 a 365
    int tm_isdst; // indica horário de verão se for diferente de zero
};
struct tempo *t;

typedef struct Horario {
    int hora;
    int minutos;
    int segundos;
}hora;
hora h;

typedef struct Data {
    int dia;
    int mes;
    int ano;
}data;
data d;

typedef struct Compromisso {
    char descricao[280];
}comp;
comp c;

void tempo() {
    time_t segundos;
    time(&segundos);
    t = localtime(&segundos);
}

hora Horario() {
    char erro[] = "Horario";
    int deh;

    FILE *phrs = fopen("hora.txt", "a");
    if (phrs == NULL) {
        printf("Erro ao abrir o arquivo\nPor favor revise o código-fonte\n");
        printf("Erro: %s\n", erro);
        system("pause");
    }

    printf("[0] Usar horario de agora\n[1] Horario personalizada\n");
    scanf("%d", &deh);
    limpar_buffer();

    if (deh == 0) {
        h.hora = t->tm_hour;
        h.minutos = t->tm_min;
        h.segundos = t->tm_sec;
    } else {
        if (deh == 1) {
            printf("Hora:\n");
            scanf("%d", &h.hora);
            limpar_buffer();

            printf("Minutos:\n");
            scanf("%d", &h.minutos);
            limpar_buffer();

            printf("Segundos:\n");
            scanf("%d", &h.segundos);
            limpar_buffer();
        } else {
            printf("valor inexistente\n");
            system("pause");
        }
    }

    fprintf(phrs, "Hora: %d:%d:%d dia: %d/%d/%d | Horario agendado: %d:%d:%d\n", t->tm_hour, t->tm_min, t->tm_sec, t->tm_mday, t->tm_mon + 1, t->tm_year + 1900, h.hora, h.minutos, h.segundos);
    fclose(phrs);
}

data DiaMesAno() {
    char erro[] = "DiaMesAno";
    int dma;

    FILE *pdma = fopen("data.txt", "a");
    if (pdma == NULL) {
        printf("Erro ao abrir o arquivo\nPor favor revise o código-fonte\n");
        printf("Erro: %s\n", erro);
        system("pause");
    }

    printf("[0] Usar data de agora\n[1] Data personalizada\n");
    scanf("%d", &dma);
    limpar_buffer();

    if (dma == 0) {
        d.dia = t->tm_mday;
        d.mes = t->tm_mon;
        d.ano = t->tm_year;
    } else {
        if (dma == 1) {
            printf("Dia: \n");
            scanf("%d", &d.dia);
            limpar_buffer();

            printf("Mês: \n");
            scanf("%d", &d.mes);
            limpar_buffer();

            printf("Ano: \n");
            scanf("%d", &d.ano);
            limpar_buffer();
        } else {
            printf("valor inexistente\n");
            system("pause");
        }
    }

    fprintf(pdma, "Hora: %d:%d:%d dia: %d/%d/%d | Data agendada: %d/%d/%d\n", t->tm_hour, t->tm_min, t->tm_sec, t->tm_mday, t->tm_mon + 1, t->tm_year + 1900, d.dia, d.mes + 1, d.ano + 1900);
    fclose(pdma);
}

comp Descricao() {
    char erro[] = "Descricao";
    int descr = 0;
    char *st = malloc( 280 * sizeof(char));

    FILE *desc = fopen("descricao.txt", "a");
    if (desc == NULL) {
        printf("Erro ao abrir o arquivo\nPor favor revise o código-fonte\n");
        printf("Erro: %s\n", erro);
        system("pause");
    }

    printf("[0] Pular\n[1] Escrever descricao\n");
    scanf("%d", &descr);
    limpar_buffer();

    if (descr == 0) {
        fprintf(desc, "Hora: %d:%d:%d dia: %d/%d/%d | Descricao: Nenhuma legenda.\n", t->tm_hour, t->tm_min, t->tm_sec, t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);
    } else {
        if (descr == 1) {
            printf("Digite sua legenda (280 caracter):\n");
            scanf("%[^\n]s", &st);
            gets(c.descricao);
            fprintf(desc, "Hora: %d:%d:%d dia: %d/%d/%d | Descricao: ", t->tm_hour, t->tm_min, t->tm_sec, t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);
            fprintf(desc, "%s", &st);
            fprintf(desc, "\n");
        } else {
            printf("valor inexistente\n");
            system("pause");
        }
    }

    fclose(desc);
}
int main() {
    setlocale(LC_ALL, "ptb");
    tempo();

    Horario();
    FILE *phrs = fopen("hora.txt", "r");
    if (phrs == NULL) {
        printf("Erro ao abrir o arquivo\nPor favor revise o código-fonte\n");
        system("pause");
    }
    char hora[100];
    char *hrs;
    while (fgets(hora, 100, phrs) != NULL);
    hrs = strrchr(hora, '|');
    printf("%s\n", hrs+2);
    fclose(phrs);

    system("cls");

    DiaMesAno();
    FILE *pdma = fopen("data.txt", "r");
    if (pdma == NULL) {
        printf("Erro ao abrir o arquivo\nPor favor revise o código-fonte\n");
        system("pause");
    }
    char data[100];
    char *dat;
    while (fgets(data, 100, pdma) != NULL);
    dat = strrchr(data, '|');
    printf("%s\n", dat+2);
    fclose(pdma);

    system("cls");

    Descricao();
    FILE *desc = fopen("descricao.txt", "r");
    if (desc == NULL) {
        printf("Erro ao abrir o arquivo\nPor favor revise o código-fonte\n");
        system("pause");
    }
    char descri[280];
    char *dsc;
    while (fgets(descri,  280 , desc) != NULL);
    dsc = strrchr(descri, '|');
    printf("%s\n", dsc+2);
    fclose(desc);

    system("cls");

    printf("Agendado com sucesso!\n\n");
    printf("%s", hrs+2);
    printf("%s", dat+2);
    printf("%s", dsc+2);
    printf("%s", c.descricao);
    system("pause");
}

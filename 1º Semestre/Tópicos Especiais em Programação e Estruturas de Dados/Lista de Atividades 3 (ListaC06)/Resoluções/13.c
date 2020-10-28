#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define MAX 10

typedef struct dados_pessoais {
    char Nome[64];
    char Endereco[126];
    char data_nascimento[8];
    char Cidade[14];
    char CEP[10];
    char Email[64];
}dp;

typedef struct Pilha {
    dp Usuarios[MAX];
    int topo;
}Pilha;

struct auxiliar {
    char Nome[64];
    char Endereco[126];
    char data_nascimento[8];
    char Cidade[14];
    char CEP[10];
    char Email[64];
}aux;

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

void clear_buff() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void Pilha_inicia(Pilha *p) {
    p->topo = -1;
}

int Pilha_vazia(Pilha *p) {
    if (p->topo == -1)
        return 1;
    else
        return 0;
}

int Pilha_cheia(Pilha *p) {
    if (p->topo == MAX - 1)
        return 1;
    else
        return 0;
}

int menu(Pilha *p);

int Pilha_insere(Pilha *p, char Nome[64], char Endereco[126],
                 char data_nascimento[8], char Cidade[14],
                 char CEP[10], char Email[64]) {

    time_t segundos;
    time(&segundos);
    t = localtime(&segundos);

    FILE *hist = fopen("Historico.txt", "a");
    if (hist  == NULL) {
        puts("Erro ao abrir o arquivo\nPor favor revise o código-fonte\nint Pilha_insere\n");
        system("pause");
    }

    if (Pilha_cheia(p) == 1)
        printf("ERROR: stack overflow\n");
    else {
        p->topo++;

        strcpy(p->Usuarios[p->topo].Nome, Nome);
        strcpy(p->Usuarios[p->topo].Endereco, Endereco);
        strcpy(p->Usuarios[p->topo].data_nascimento, data_nascimento);
        strcpy(p->Usuarios[p->topo].Cidade, Cidade);
        strcpy(p->Usuarios[p->topo].CEP, CEP);
        strcpy(p->Usuarios[p->topo].Email, Email);

        fprintf(hist, "%d:%d:%d|%d/%d/%d| Dados inseridos\nNome: %sEndereco: %sData de nascimento: %sCidade: %sCEP: %sEmail: %s", t->tm_hour, t->tm_min, t->tm_sec, t->tm_mday, t->tm_mon + 1, t->tm_year + 1900, Nome, Endereco, data_nascimento, Cidade, CEP, Email);
        fclose(hist);
    }
}

void Pilha_zerar(Pilha *p) {
    if (Pilha_vazia(p) == 1) {
        printf("Pilha vazia\n");
        menu(p);
    }
    else {
        p->topo = -1;
        menu(p);
    }
}

dp Pilha_remove(Pilha *p) {

    FILE *hist = fopen("Historico.txt", "a");
    if (hist  == NULL) {
        puts("Erro ao abrir o arquivo\nPor favor revise o código-fonte\ndp Pilha_remove\n");
        system("pause");
    }

    if (Pilha_vazia(p) == 1) {
        puts("ERRO: Pilha Vazia\n");
        menu(p);
    }
    else {
        strcpy(aux.Nome, p->Usuarios[p->topo].Nome);
        strcpy(aux.Endereco, p->Usuarios[p->topo].Endereco);
        strcpy(aux.data_nascimento, p->Usuarios[p->topo].data_nascimento);
        strcpy(aux.Cidade, p->Usuarios[p->topo].Cidade);
        strcpy(aux.CEP, p->Usuarios[p->topo].CEP);
        strcpy(aux.Email, p->Usuarios[p->topo].Email);
        p->topo--;
    }

    printf("Removido com sucesso!\n");
    printf("Nome: %s", aux.Nome);
    printf("Endereco: %s", aux.Endereco);
    printf("Data de nascimento: %s", aux.data_nascimento);
    printf("Cidade: %s", aux.Cidade);
    printf("CEP: %s", aux.CEP);
    printf("Email: %s", aux.Email);

    fprintf(hist, "%d:%d:%d|%d/%d/%d| Dados removidos\nNome: %sEndereco: %sData de nascimento: %sCidade: %sCEP: %sEmail: %s",
            t->tm_hour, t->tm_min, t->tm_sec, t->tm_mday, t->tm_mon + 1, t->tm_year + 1900, aux.Nome, aux.Endereco, aux.data_nascimento,
            aux.Cidade, aux.CEP, aux.Email);
    fclose(hist);

    menu(p);
}

int entrada(Pilha *p) {
    Pilha_inicia(p);

    int quantidade;

    char Nome[64];
    char Endereco[126];
    char data_nascimento[8];
    char Cidade[14];
    char CEP[10];
    char Email[64];

    printf("Quantidade de entrada:\n");
    scanf("%d", &quantidade);
    clear_buff();

    system("cls");

    for (int i = 0; i < quantidade; ++i) {
        printf("Usuario %d\n", i + 1);

        printf("Nome:");
        fgets(Nome, 63, stdin);
        fflush(stdin);

        printf("Endereco:");
        fgets(Endereco, 125, stdin);
        fflush(stdin);

        printf("Data_Nascimento:");
        fgets(data_nascimento, 8, stdin);
        fflush(stdin);

        printf("Cidade:");
        fgets(Cidade, 14, stdin);
        fflush(stdin);

        printf("CEP:");
        fgets(CEP, 10, stdin);
        fflush(stdin);

        printf("Email:");
        fgets(Email, 64, stdin);
        fflush(stdin);

        Pilha_insere(p, Nome, Endereco, data_nascimento, Cidade, CEP, Email);
        system("cls");
    }

    menu(p);
}

int saida(Pilha *p) {
    if (Pilha_vazia(p) == 1) {
        printf("Pilha vazia\n");
        menu(p);
    } else {
        for (int i = p->topo; i > -1; --i) {
            printf("Aluno %d\n", i + 1);
            printf("Nome: %s", p->Usuarios[i].Nome);
            printf("Endereco: %s", p->Usuarios[i].Endereco);
            printf("Data de nascimento: %s", p->Usuarios[i].data_nascimento);
            printf("Cidade: %s", p->Usuarios[i].Cidade);
            printf("CEP: %s", p->Usuarios[i].CEP);
            printf("Email: %s", p->Usuarios[i].Email);
            puts(".....................................");
        }

        menu(p);
    }
}
int menu(Pilha *p) {
    int menu;

    puts("\tMENU\t\n");
    puts("[0] Sair");
    puts("[1] Entrada");
    puts("[2] Remover");
    puts("[3] Exibir");
    puts("[4] Zerar");
    scanf("%d", &menu);

    system("cls");

    while (menu != 5) {
        switch (menu) {
            case 0:
                exit(0);
            case 1:
                entrada(p);
                break;
            case 2:
                Pilha_remove(p);
                break;
            case 3:
                saida(p);
                break;
            case 4:
                Pilha_zerar(p);
                break;
            default:
                printf("Opcao invalida");
        }
        while (menu != 0);
    }
}

int main() {
    setlocale(LC_ALL, "ptb");
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    Pilha_inicia(p);
    menu(p);
    system("pause");
}

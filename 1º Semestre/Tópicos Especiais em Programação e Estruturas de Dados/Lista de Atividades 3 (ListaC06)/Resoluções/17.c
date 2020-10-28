#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define MAX 5

struct tempo {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
};
struct tempo *t;

typedef struct eletrodomesticos {
    char nome[15];
    float potencia;
    float tempo_ativo;
}eletros;

typedef struct Pilha {
    eletros eletrodomesticos[MAX];
    int topo;
}Pilha;

struct auxliar {
    char nome[15];
    float potencia;
    float tempo_ativo;
}aux;

int menu(Pilha *p);

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

int Pilha_insere(Pilha *p, char Nome[15], float potencia, float tempo_ativo) {

    time_t segundos;
    time(&segundos);
    t = localtime(&segundos);

    FILE *rela = fopen("relatorio.txt", "a");
    if (rela  == NULL) {
        puts("Erro ao abrir o arquivo\nPor favor revise o código-fonte\nint Pilha_insere\n");
        system("pause");
    }

    if (Pilha_cheia(p) == 1)
        printf("ERROR: stack overflow\n");
    else {
        p->topo++;

        strcpy(p->eletrodomesticos[p->topo].nome, Nome);
        p->eletrodomesticos[p->topo].potencia = potencia;
        p->eletrodomesticos[p->topo].tempo_ativo = tempo_ativo;

        fprintf(rela, "%d:%d:%d|%d/%d/%d| Relatorio\nEltrodomestico: %s\nPotencia: %f\nTempo ativo: %f\n", t->tm_hour, t->tm_min, t->tm_sec, t->tm_mday, t->tm_mon + 1, t->tm_year + 1900, Nome, potencia, tempo_ativo);
        fclose(rela);
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

eletros Pilha_remove(Pilha *p) {

    FILE *rela = fopen("relatorio.txt", "a");
    if (rela  == NULL) {
        puts("Erro ao abrir o arquivo\nPor favor revise o código-fonte\nint Pilha_remove\n");
        system("pause");
    }

    if (Pilha_vazia(p) == 1) {
        puts("ERRO: Pilha Vazia\n");
        menu(p);
    }
    else {
        strcpy(aux.nome, p->eletrodomesticos[p->topo].nome);
        aux.potencia = p->eletrodomesticos[p->topo].potencia;
        aux.tempo_ativo = p->eletrodomesticos[p->topo].tempo_ativo;
        p->topo--;
    }

    printf("Removido com sucesso!\n");
    printf("Eltrodomestico: %s\n", aux.nome);
    printf("Potencia: %.2f\n", aux.potencia);
    printf("Tempo ativo: %.2f\n", aux.tempo_ativo);

    fprintf(rela, "%d:%d:%d|%d/%d/%d| Removido:\nEltrodomestico: %s\nPotencia: %f\nTempo ativo: %f\n", t->tm_hour, t->tm_min, t->tm_sec, t->tm_mday, t->tm_mon + 1, t->tm_year + 1900, aux.nome, aux.potencia, aux.tempo_ativo);
    fclose(rela);

    menu(p);
}

int entrada(Pilha *p) {
    Pilha_inicia(p);

    int quantidade;

    char Nome[15];
    float potencia;
    float tempo_ativo;

    do {
    printf("Quantidade de entradas:\n");
    scanf("%d", &quantidade);
    clear_buff();
    if (quantidade > 5)
        puts("quantidade maior que 5\n");
    } while (quantidade > 5);

    system("cls");

    for (int i = 0; i < quantidade; ++i) {
        printf("Eletrodomestico %d\n", i + 1);

        printf("Nome do eletrodomestico:\n");
        fgets(Nome, 15, stdin);
        fflush(stdin);

        printf("Potencia (kW):");
        scanf("%f", &potencia);
        clear_buff();

        printf("Tempo Ativo por dia (horas):");
        scanf("%f", &tempo_ativo);
        clear_buff();

        Pilha_insere(p, Nome, potencia, tempo_ativo);
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
            printf("Eletrodomestico %d\n", i + 1);
            printf("Nome: %s", p->eletrodomesticos[i].nome);
            printf("potencia (kW): %.2f\n", p->eletrodomesticos[i].potencia);
            printf("Tempo ativo (horas): %2.f\n", p->eletrodomesticos[i].tempo_ativo);
            puts(".....................................\n");
        }

        menu(p);
    }
}

void consumo(Pilha *p) {
    float dia = 0;
    float mult = 0;
    float aux = 0;
    printf("Tempo (dias):\n");
    scanf("%f", &dia);

    for (int i = p->topo; i > -1; --i) {
        mult += dia * p->eletrodomesticos[i].potencia;
    }

    printf("Consumo total em %.0f dias: %.2f kW\n", dia, mult);
    printf("Consumo relativo em %.0f dias:\n", dia);
    for (int i = p->topo; i > -1; --i) {
        aux = p->eletrodomesticos[i].potencia / mult;
        printf("%sConsumo: %.2f porcento\n", p->eletrodomesticos[i].nome, aux * 100);
    }

    menu(p);
}

int menu(Pilha *p) {
    int menu;

    puts("\tMENU\t\n");
    puts("[0] Sair");
    puts("[1] Adicionar eletrodomestico");
    puts("[2] Remover eletrodomestico");
    puts("[3] Exibir eletrodomesticos");
    puts("[4] Relatorio de consumo");
    puts("[5] Zerar Pilha");
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
                consumo(p);
                break;
            case 5:
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

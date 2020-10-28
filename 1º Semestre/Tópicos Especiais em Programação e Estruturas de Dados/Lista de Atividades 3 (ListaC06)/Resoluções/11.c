#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

// CONTEM PILHA

void clear_buff() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

typedef struct {
    char nome[64];
    char matricula[10];
    int media_final;
}aluno;

typedef struct {
    aluno alunos[MAX];
    int topo;
}Pilha;

typedef struct {
    char nome[64];
    char matricula[10];
    int media_final;
}aux;
aux ax;

void menu(Pilha *p);


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

int Pilha_insere(Pilha *p, char nome[64], char matricula[10], int media_final) {
    if (Pilha_cheia(p) == 1)
        printf("ERROR: stack overflow\n");
    else {
        p->topo++;
        strcpy(p->alunos[p->topo].nome , nome);
        strcpy(p->alunos[p->topo].matricula, matricula);
        p->alunos[p->topo].media_final = media_final;
    }
    return 0;
}

aluno Pilha_remove(Pilha *p) {
    if (Pilha_vazia(p) == 1)
        printf("ERRO: Pilha Vazia\n");
    else {
        ax.media_final = p->alunos[p->topo].media_final;
        strcpy(ax.matricula, p->alunos[p->topo].matricula);
        strcpy(ax.nome, p->alunos[p->topo].nome);
        p->topo--;
    }

    printf("Removido\n");
    printf("Nome: %s", ax.nome);
    printf("Matricula: %s\n", ax.matricula);
    printf("Nota_final: %d", ax.media_final);
    menu(p);
}


int print(Pilha *p) {
    for (int i = p->topo; i > -1; i--) {
        printf("Aluno %d\n", i + 1);
        printf("Nome: %s", p->alunos[i].nome);
        printf("Matricula: %s\n", p->alunos[i].matricula);
        printf("Media_final: %d\n", p->alunos[i].media_final);
        puts("===================");
    }
    menu(p);
}

int adicionar(Pilha *p) {
    system("cls");

    Pilha_inicia(p);

    char nome[64];
    char matricula[10];
    int media;
    int quantidade;

    printf("Quantidade de entrada:\n");
    scanf("%d", &quantidade);
    clear_buff();

    system("cls");

    for (int i = 0; i < quantidade; i++) {
        printf("Aluno %d\n", i + 1);

        printf("Nome:\n");
        fgets(nome, 63, stdin);
        fflush(stdin);

        printf("Matricula:\n");
        fgets(matricula, 9, stdin);
        fflush(stdin);

        printf("Media final:\n");
        scanf("%d", &media);
        clear_buff();

        Pilha_insere(p, nome, matricula, media);
        system("cls");
    }

    menu(p);
}

void resultado(Pilha *p) {
    for (int i = p->topo; i > -1; --i) {
        if (p->alunos[i].media_final > 5) {
            printf("Aprovado\n");
            printf("Nome: %s", p->alunos[i].nome);
            printf("Matricula: %s\n", p->alunos[i].matricula);
            printf("Media_final: %d", p->alunos[i].media_final);
            puts("\n======================\n");
        } else {
            printf("Reprovado\n");
            printf("Nome: %s", p->alunos[i].nome);
            printf("Matricula: %s", p->alunos[i].matricula);
            printf("Media_final: %d", p->alunos[i].media_final);
            puts("\n======================\n");
        }
    }
    menu(p);
}

void zerarpilha(Pilha *p) {
    p->topo = -1;
    menu(p);
}

void menu(Pilha *p) {
    int menu;

    printf("Menu\n");
    printf("[0] Sair\n");
    printf("[1] Adicionar\n");
    printf("[2] Remover\n");
    printf("[3] Exibir\n");
    printf("[4] Resultado\n");
    printf("[5] Zerar Pilha\n");
    scanf("%d", &menu);

    system("cls");

    while (menu != 6) {
        switch (menu) {
            case 0:
                exit(0);
            case 1:
                adicionar(p);
                break;
            case 2:
                Pilha_remove(p);
                break;
            case 3:
                print(p);
                break;
            case 4:
                resultado(p);
                break;
            case 5:
                zerarpilha(p);
            default:
                printf("Opcao invalida\n");
        }
        while (menu != 0);
    }
}


int main() {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    menu(p);
    system("pause");
}


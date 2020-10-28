#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

struct aluno {
    char nome[5][64];
    int p1[5];
    int p2[5];
    int p3[5];
};
struct aluno al;

void a() {
    int aux = 0;
    for (int i = 0; i < 5; i++) {
        printf("Nome do aluno %d:\n", i + 1);
        scanf("%s", &al.nome[i]);
        limpar_buffer();
        do {
            printf("Prova 1:\n");
            scanf("%d", &aux);
            limpar_buffer();
            if (aux > 10) {
                printf("Nota maior que 10\n");
            } else {
                al.p1[i] = aux;
            }
        } while (aux > 10);

        do {
            printf("Prova 2:\n");
            scanf("%d", &aux);
            limpar_buffer();
            if (aux > 10) {
                printf("Nota maior que 10\n");
            } else {
                al.p2[i] = aux;
            }
        } while (aux > 10);

        do {
            printf("Prova 3:\n");
            scanf("%d", &aux);
            limpar_buffer();
            if (aux > 10) {
                printf("Nota maior que 10\n");
            } else {
                al.p3[i] = aux;
            }
        } while (aux > 10);

        system("cls");
    }
}

void b() {
    int maior = 0;
    int nome;

    for (int i = 0; i < 5; i++) {
        if (al.p1[i] > maior) {
            maior = al.p1[i];
            nome = i;
        }
    }

    printf("Aluno %s, maior nota prova 1: %d\n", al.nome[nome], maior);
}

void c() {
    int media1, media2, media3, media4, media5;
    media1 = al.p1[0] + al.p2[0] + al.p3[0];
    media2 = al.p1[1] + al.p2[1] + al.p3[1];
    media3 = al.p1[2] + al.p2[2] + al.p3[2];
    media4 = al.p1[3] + al.p2[3] + al.p3[3];
    media5 = al.p1[4] + al.p2[4] + al.p3[4];
    int maiormedia = 0;

    if (media1 > maiormedia) {
        maiormedia = media1;
    }
    if (media2 > maiormedia) {
        maiormedia = media2;
    }
    if (media3 > maiormedia) {
        maiormedia = media3;
    }
    if (media4 > maiormedia) {
        maiormedia = media4;
    }
    if (media5 > maiormedia) {
        maiormedia = media5;
    }

    int y = 0;
    if (maiormedia == media1) {
        if (y == 0) {
            printf("Aluno %s, maior media: %d\n", al.nome[0], media1/3);
        }
        y++;
    }
    if (maiormedia == media2) {
        if (y == 0) {
            printf("Aluno %s, maior media: %d\n", al.nome[1], media2 / 3);
        }
        y++;
    }
    if (maiormedia == media3) {
        if (y == 0) {
            printf("Aluno %s, maior media: %d\n", al.nome[2], media3/3);
        }
        y++;
    }
    if (maiormedia == media4) {
        if (y == 0) {
            printf("Aluno %s, maior media: %d\n", al.nome[3], media4/3);
        }
        y++;
    }
    if (maiormedia == media5) {
        if (y == 0) {
            printf("Aluno %s, maior media: %d\n", al.nome[4], media5/3);
        }
        y++;
    }
    if (y != 0) {
        printf("%d alunos com a mesma media\n", y);
    }
}

void d() {
    int media1, media2, media3, media4, media5;
    media1 = al.p1[0] + al.p2[0] + al.p3[0];
    media2 = al.p1[1] + al.p2[1] + al.p3[1];
    media3 = al.p1[2] + al.p2[2] + al.p3[2];
    media4 = al.p1[3] + al.p2[3] + al.p3[3];
    media5 = al.p1[4] + al.p2[4] + al.p3[4];
    int menormedia = 10;

    if (media1 < menormedia) {
        menormedia = media1;
    }
    if (media2 < menormedia) {
        menormedia = media2;
    }
    if (media3 < menormedia) {
        menormedia = media3;
    }
    if (media4 < menormedia) {
        menormedia = media4;
    }
    if (media5 < menormedia) {
        menormedia = media5;
    }

    int y = 0;
    if (menormedia == media1) {
        if (y == 0) {
            printf("Aluno %s, menor media: %d\n", al.nome[0], media1/3);
        }
        y++;
    }
    if (menormedia == media2) {
        if (y == 0) {
            printf("Aluno %s, menor media: %d\n", al.nome[1], media2 / 3);
        }
        y++;
    }
    if (menormedia == media3) {
        if (y == 0) {
            printf("Aluno %s, menor media: %d\n", al.nome[2], media3/3);
        }
        y++;
    }
    if (menormedia == media4) {
        if (y == 0) {
            printf("Aluno %s, menor media: %d\n", al.nome[3], media4/3);
        }
        y++;
    }
    if (menormedia == media5) {
        if (y == 0) {
            printf("Aluno %s, menor media: %d\n", al.nome[4], media5/3);
        }
        y++;
    }
    if (y != 0) {
        printf("%d alunos com a mesma media\n", y);
    }
}

void e() {
    int media[4], media1, media2, media3, media4, media5;
    int i = 0, y = 0;

    while (i < 4) {
        media[y] = al.p1[i] + al.p2[i] + al.p3[i];
        if (y == 0) {
            media1 = media[y];
            media1 / 3;
            if (media1 > 6) {
                printf("Aluno %s: aprovado\n", al.nome[i]);
            } else {
                printf("Aluno %s: reprovado\n", al.nome[i]);
            }
        }
        if (y == 1) {
            media2 = media[y];
            media2 / 3;
            if (media2 > 6) {
                printf("Aluno %s: aprovado\n", al.nome[i]);
            } else {
                printf("Aluno %s: reprovado\n", al.nome[i]);
            }
        }
        if (y == 2) {
            media3 = media[y];
            media3 / 3;
            if (media3 > 6) {
                printf("Aluno %s: aprovado\n", al.nome[i]);
            } else {
                printf("Aluno %s: reprovado\n", al.nome[i]);
            }
        }
        if (y == 3) {
            media4 = media[y];
            media4 / 3;
            if (media4 > 6) {
                printf("Aluno %s: aprovado\n", al.nome[i]);
            } else {
                printf("Aluno %s: reprovado\n", al.nome[i]);
            }
        }
        if (y == 4) {
            media5 = media[y];
            media5 / 3;
            if (media5 > 6) {
                printf("Aluno %s: aprovado\n", al.nome[i]);
            } else {
                printf("Aluno %s: reprovado\n", al.nome[i]);
            }
        }
        y++;
        i++;
    }
}

int main() {
    setlocale(LC_ALL, "ptb");
    system("cls");

    a();

    b();

    c();

    d();

    e();

    system("pause");
}

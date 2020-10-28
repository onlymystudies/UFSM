/*
1
*/

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

/*
2
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    struct estrutura {
        char nome[64];
        int idade;
        char endereco[126];
    };
    struct estrutura st;

    printf("Nome:\n");
    gets(st.nome); // or fgets(st.nome, 64, stdin); but this save enter zzzzzz

    printf("Idade:\n");
    scanf("%d", &st.idade);
    limpar_buffer();

    printf("Endereço:\n");
    gets(st.endereco);

    printf("Nome: %s\n", st.nome);
    printf("Idade: %d\n", st.idade);
    printf("Endereço: %s\n", st.endereco);

    system("pause");
}

/*
3
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

struct aluno {
    char nome[64];
    int numero;
    char curso[64];
};
struct aluno al;

int main() {
    setlocale(LC_ALL, "ptb");

    for (int i = 0; i < 5; i++) {
        printf("Nome do aluno %d:\n", i + 1);
        gets(al.nome);

        printf("Número de matrícula %d:\n", i + 1);
        scanf("%d", &al.numero);
        limpar_buffer();

        printf("curso %d:\n", i + 1);
        gets(al.curso);
    }
    int y = 0;
    while (y < 5) {
        printf("Aluno %d\n", y + 1);
        printf("Nome: %s\n", al.nome);
        printf("Numero de matrícula: %d\n", al.numero);
        printf("Curso: %s\n", al.curso);
        y++;
    }

    system("pause");
}

/*
4
*/

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

/*
5
*/

#include <stdio.h>
#include <stdlib.h>

void cb() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

struct Vector {
    float x;
    float y;
    float z;
};
struct Vector r;

float calc(float *v, float *v2, float *r3);
int main() {
    int i = 0;

    float *v = malloc(5 * sizeof(float));
    float *v2 = malloc(5 * sizeof(float));
    float *r3 = malloc(5 * sizeof(float));

    while (i < 5) {
        printf("vector 1, value %d:\n", i + 1);
        scanf("%f", &v[i]);
        cb();
        i++;
    }

    system("cls");

    i = 0;
    while (i < 5) {
        printf("vector 2, value %d:\n", i + 1);
        scanf("%f", &v2[i]);
        cb();
        i++;
    }

    system("cls");

    i = 0;
    while (i < 5) {
        printf("vector 3, value %d:\n", i + 1);
        scanf("%f", &r3[i]);
        cb();
        i++;
    }

    system("cls");

    calc(v, v2, r3);

    printf("\nVector 1:\n");
    i = 0;
    while (i < 5) {
        printf("%.2f\n", v[i]);
        i++;
    }
    printf("Total: %.2f\n", r.x);

    printf("\nVector 2:\n");
    i = 0;
    while (i < 5) {
        printf("%.2f\n", v2[i]);
        i++;
    }
    printf("Total: %.2f\n", r.y);

    printf("\nVector 3:\n");
    i = 0;
    while (i < 5) {
        printf("%.2f\n", r3[i]);
        i++;
    }
    printf("Total R(ao cubo): %.2f\n", r.z);

    system("pause");
}
float calc(float *v, float *v2, float *r3) {
    float total = 0, total2 = 0, total3 = 0;
    for (int i = 0; i < 4; i++) {
        total += v[i];
        total2 += v2[i];
        total3 += r3[i];
    }
    r.x = total;
    r.y = total2;
    r.z = total3 + total + total2;
}

/*
6
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

typedef struct {
    unsigned int cadaster;
    char name[64];
    int discipline_code;
    float note_1;
    float note_2;
}student;
student stu[10];

void cadaster() {
    float aux = 0;

    for (int i = 0; i < 10; i++) {
        printf("Student %d Cadaster:\n", i + 1);
        scanf("%d", &stu[i].cadaster);
        buffer();

        printf("Name of %d student:\n", i + 1);
        gets(stu[i].name);

        printf("Discipline code:\n");
        scanf("%d", &stu[i].discipline_code);
        buffer();

        do {
            printf("Note 1:\n");
            scanf("%f", &aux);
            buffer();
            if (aux < 1.1) {
                stu[i].note_1 = aux;
            } else {
                puts("Max note 1.0\n");
            }
        } while (aux > 1.1);

        aux = 0;

        do {
            printf("Note 2:\n");
            scanf("%f", &aux);
            buffer();
            if (aux < 2) {
                stu[i].note_2 = aux;
            } else {
                puts("Max note 2.0\n");
            }
        } while (aux > 2);

        system("cls");
    }
}

int main() {
    cadaster();

    int aux = 0;

    for (int i = 0; i < 10; i++) {
        puts("\tFINAL LISTING\t\n");
        printf("Student: %s\tCadaster: %d\n", stu[i].name, stu[i].cadaster);
        printf("Discipline code: %d\n", stu[i].discipline_code);
        puts("\tNOTES\t\n");
        printf("Note 1: %.2f\tNote 2: %.2f\n", stu[i].note_1, stu[i].note_2);
        printf("Average: %.2f\n", (stu[i].note_1 * 1.0 + stu[i].note_2 * 2.0)/3);
        puts("============================");
        do {
            printf("\nPage %d\n", i + 1);
            printf("Press '0' for the next page");
            scanf("%d", &aux);
        } while (aux > 0 || aux < 0);
        system("cls");
    }
}

/*
7
*/

#include <stdio.h>
#include <stdlib.h>

void clear_buff() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

struct {
    float ray;
    float argument;
}polar;

union { // union same thing as struct
    float x;
    float y;
}cartesian;

void conversion() {
    cartesian.x = polar.ray * polar.argument;
    cartesian.y = cartesian.x * polar.ray;
}

int main() {
    float aux;

    puts("polar coordinate ray (r):");
    scanf("%f", &polar.ray);
    clear_buff();

    do {
        puts("polar coordinate radians (a):");
        scanf("%f", &aux);
        clear_buff();
        if (aux == 0) {
            puts("Dont use ',' use '.'");
        } else {
            polar.argument = aux;
        }
    } while (aux == 0);

    conversion();

    system("cls");

    printf("Cartesian coordinate X: %f\n", cartesian.x);
    printf("Cartesian coordinate Y: %f\n", cartesian.y);

    system("pause");
}

/*
8
*/

#include <stdio.h>
#include <stdlib.h>

void clear_buff() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

struct data_registers{ // name of struct
    char name[64];
    unsigned int age;
    char gender;
    char cpf[11];
    char date_of_birth[8];
    unsigned int code;
    char profession[30];
    int salary;
}; // name here is for nickname of struct
struct data_registers *dr;
void print(int quant) {
    system("cls");

    int page = -1;

    for (int i = 0; i < quant; i++) {
        puts("\tREGISTERS\t");
        printf("Name: %s", dr[i].name);
        printf("Age: %d\n", dr[i].age);
        printf("Gender: %c\n", dr[i].gender);
        printf("CPF: %s", dr[i].cpf);
        printf("Date of birth: %s", dr[i].date_of_birth);
        printf("Sector code: %d\n", dr[i].code);
        printf("Profession: %s", dr[i].profession);
        printf("Salary: %d\n", dr[i].salary);
        puts("\n\n============================");
        printf("Page %d of %d", i + 1, quant);
        puts("[0] Next page [1] Exit");
        do {
            scanf("%d", &page);
            if (page == 1) {
                exit(0);
            }
        } while (page < 0);

        system("cls");
    }

}

int main() {
    int quant;

    puts("Quantity of employees:");
    scanf("%d", &quant);
    clear_buff();

    system("cls");

    dr = malloc(quant * sizeof(int));

    for (int i = 0; i < quant; i++) {
        printf("Name of employee %d:\n", i + 1);
        fgets(dr[i].name, 64, stdin); // gets not safe

        printf("Age of employee %d:\n", i + 1);
        scanf("%u", &dr[i].age); //u = Unsigned decimal integer
        clear_buff();

        printf("Gender of employee %d (M-F):\n", i + 1);
        scanf("%s", &dr[i].gender);
        clear_buff();

        printf("CPF of employee %d:\n", i + 1);
        fgets(dr[i].cpf, 11, stdin);

        printf("Date of birth of employee %d (MMDDYYYY):\n", i + 1);
        fgets(dr[i].date_of_birth, 8, stdin);

        printf("sector code of employee %d (0-99):\n", i + 1);
        scanf("%u", &dr[i].code);
        clear_buff();

        printf("Profession of employee %d:\n", i + 1);
        fgets(dr[i].profession, 30, stdin);

        printf("Salary of employee %d:\n", i + 1);
        scanf("%u", &dr[i].salary);
        clear_buff();

        system("cls");
    }

    print(quant);

    system("pause");
}

/*
9
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void clear_buff() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

struct {
    float z;
    float w;
}complex;

struct calculations{
    float sum;
    float subtraction;
    float product;
    float module;
};
struct calculations cl;

void calc() {
    cl.sum = complex.z + complex.w;

    cl.subtraction = complex.z - complex.w;

    cl.product = complex.z * complex.w;

    double aux;
    aux = pow(complex.z, 2) + pow(complex.w, 2);
    sqrt(aux);
    cl.module = aux;
}

int main() {
    printf("Real number: ");
    scanf("%f", &complex.z);
    clear_buff();

    printf("imaginary number: ");
    scanf("%f", &complex.w);

    calc();

    system("cls");
    printf("Sum: %.2f\n", cl.sum);
    printf("Subtraction: %.2f\n", cl.subtraction);
    printf("Product: %.2f\n", cl.product);
    printf("Module: %.2f\n", cl.module);

    system("pause");
}

/*
10
*/

#include <stdio.h>
#include <stdlib.h>

void clear_buff() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

typedef struct {
    char name[64];
    char address[64];
    long phone;
}regist3r;
regist3r *rg;

void print(int i) {
    printf("Name %d: %s", i + 1, rg[i].name);
    printf("Address %d: %s", i + 1, rg[i].address);
    printf("Fone %d: %s", i + 1, rg[i].address);
    puts("------------------------");
}

void alphabetic(regist3r *regs) {
    char alf[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','x','w','y','z'};
    char alfb[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','W','Y','Z'};


    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (regs[j].name[0] == alf[i] || regs[j].name[0] == alfb[i]) {
                print(j);
            }
        }
    }
}

int main() {
    rg = malloc(4 * sizeof(char));

    char ph[15];
    char *aux;

    for (int i = 0; i < 4; i++) {
        printf("Name %d:", i + 1);
        fgets(rg[i].name, 64, stdin);

        printf("Address %d:", i + 1);
        fgets(rg[i].address, 64, stdin);

        do {
            printf("Fone %d:", i + 1);
            fgets(ph, 15, stdin);
            rg[i].phone = strtol(ph, &aux, 15); // convert char in long
            if (rg[i].phone == 0) {
                printf("Invalid phone please put a valid phone\n");
            }
        } while (rg[i].phone == 0);

        system("cls");
    }

    alphabetic(rg);

    system("pause");
}

/*
11
*/

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

/*
12
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

typedef struct jogador1{
    char naipe[10];
    int valor;
}jogador1;
jogador1 jgd1[5];

typedef struct jogador2{
    char naipe[10];
    int valor;
}jogador2;
jogador2 jgd2[5];

char naipe1(int i) {
    int aux = rand() % 3;

    char naipe1[] = {"copas"};
    char naipe2[] = {"espadas"};
    char naipe3[] = {"paus"};
    char naipe4[] = {"ouro"};

    if (aux == 0) {
        strcpy(jgd1[i].naipe, naipe1);
    }
    if (aux == 1) {
        strcpy(jgd1[i].naipe, naipe2);
    }
    if (aux == 2) {
        strcpy(jgd1[i].naipe, naipe3);
    }
    if (aux == 3) {
        strcpy(jgd1[i].naipe, naipe4);
    }
}

char naipe2(int i) {
    int aux = rand() % 3;

    char naipe1[] = {"copas"};
    char naipe2[] = {"espadas"};
    char naipe3[] = {"paus"};
    char naipe4[] = {"ouro"};

    if (aux == 0) {
        strcpy(jgd2[i].naipe, naipe1);
    }
    if (aux == 1) {
        strcpy(jgd2[i].naipe, naipe2);
    }
    if (aux == 2) {
        strcpy(jgd2[i].naipe, naipe3);
    }
    if (aux == 3) {
        strcpy(jgd2[i].naipe, naipe4);
    }
}

void main() {
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            jgd1[i].valor = rand() % 13;
            naipe1(i);
        } else {
            jgd2[i].valor = rand() % 13;
            naipe2(i);
        }
    }

    puts("jogador 1:");
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            puts("------------");
            printf("Carta %d\n", i + 1);
            printf("Naipe %s\n", jgd1[i].naipe);
            printf("Valor %d\n", jgd1[i].valor);
        }
    }
    puts("============================");
    puts("jogador 2:");
    for (int y = 0; y < 10; ++y) {
        if (y % 2 != 0) {
            puts("------------");
            printf("Carta %d\n", y + 1);
            printf("Naipe %s\n", jgd2[y].naipe);
            printf("Valor %d\n", jgd2[y].valor);
        }
    }
    puts("============================");
    system("pause");
}

/*
13
*/

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

/*
14
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct carros {
    char marca[15];
    char ano;
    float preco;
}carros;

int main() {
    carros *car = malloc(5 * sizeof(carros));
    float valor;

    for (int i = 0; i < 5; ++i) {
        printf("Carro %d\n", i + 1);
        puts("Marca:");
        fgets(car[i].marca, 15, stdin);
        puts("Ano:");
        scanf("%s", &car[i].ano);
        puts("Preco:");
        scanf("%f", &car[i].preco);
        fflush(stdin);
        system("cls");
    }

    puts("Valor:");
    scanf("%f", &valor);
    system("cls");

    for (int i = 0; i < 5; ++i) {
        if (car[i].preco < valor) {
            printf("Carro %d\n", i + 1);
            printf("Marca: %s", car[i].marca);
            printf("Ano: %c\n", car[i].ano);
            printf("Preco: %.2f\n", car[i].preco);
            puts("================");
        }
    }

    system("pause");
}

/*
15
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livros {
    char titulo[30];
    char autor[15];
    char ano;
}livros;

int main() {
    livros *liv = malloc(5 * sizeof(livros));
    char titulo[30];

    for (int i = 0; i < 5; ++i) {
        printf("Livro %d\n", i + 1);
        puts("Titulo:");
        fgets(liv[i].titulo, 30, stdin);
        puts("Autor:");
        fgets(liv[i].autor, 15, stdin);
        puts("Preco:");
        scanf("%c", &liv[i].ano);
        fflush(stdin);
        system("cls");
    }

    puts("Titulo que deseja encontrar:");
    fgets(titulo, 30, stdin);
    system("cls");

    for (int i = 0; i < 5; ++i) {
        if (strcmp (liv[i].titulo, titulo) == 0) {
            printf("Livro %d\n", i + 1);
            printf("Titulo: %s", liv[i].titulo);
            printf("Autor: %s", liv[i].autor);
            printf("Ano: %c\n", liv[i].ano);
            puts("================");
        }
    }

    system("pause");
}

/*
16
*/

#include <stdio.h>
#include <stdlib.h>
#include "github.com/leozamboni/C/include/stbuffer.h"

struct datas {
    int dia,
            mes,
            ano;
}datas;

typedef struct agenda {
    char compromisso[60];
    struct datas data[5];
}agenda;

int main() {
    agenda *vetor = malloc(5 * sizeof(agenda));

    int M,
            A;

    for (int i = 0; i < 5; ++i) {
        printf("Compromisso %d", i + 1);
        fgets(vetor[i].compromisso, 60, stdin);
        fflush(stdin);

        puts("Dia, mes e ano:");
        scanf("%d %d %d", &vetor[i].data[i].dia, &vetor[i].data[i].mes, &vetor[i].data[i].ano);
        system("cls");
        clearbuffer();
    }

    puts("Mes:");
    scanf("%d", &M);
    puts("Ano:");
    scanf("%d", &A);

    for (int i = 0; i < M; ++i) {
        if (vetor[i].data[i].mes == M) {
            printf("Compromisso: %s", vetor[i].compromisso);
            printf("Dia: %d\nMes: %d\nAno: %d\n", vetor[i].data[i].dia, vetor[i].data[i].mes, vetor[i].data[i].ano);
        }
    }

    system("pause");
}

/*
17
*/

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

/*
18
*/

#include <stdio.h>
#include <stdlib.h>
#include "github.com/leozamboni/C/include/stbuffer.h"

struct produtos {
    int codigo,
            quantidade;
    float preco;
    char nome[15];
};
typedef struct produtos produto;

void ler_produtos(produto *v) {
    for (int i = 0; i < 5; ++i) {
        printf("Produto %d\n", i + 1);
        puts("Nome:");
        fgets(v[i].nome, 14, stdin);
        fflush(stdin);

        puts("Codigo:");
        scanf("%d", &v[i].codigo);
        clearbuffer();

        puts("Quantidade:");
        scanf("%d", &v[i].quantidade);
        clearbuffer();

        puts("Preco:");
        scanf("%f", &v[i].preco);
        clearbuffer();
        system("cls");
    }
}

int main() {
    produto *v = malloc(5 * sizeof(produto));
    int codigo, quantidade, aux = 0;

    ler_produtos(v);

    do {
        puts("Pedido:");
        puts("Codigo do produto:");
        scanf("%d", &codigo);
        puts("Quantidade:");
        scanf("%d", &quantidade);
        system("cls");
        for (int i = 0; i < 5; ++i) {
            if (codigo == v[i].codigo) {
                if (v[i].quantidade > quantidade) {
                    v[i].quantidade -= quantidade;
                    puts("Pedido Realizado com sucesso!");
                    printf("Baixa de %d no estoque de %s\nEstoque atual: %d\n", quantidade, v[i].nome, v[i].quantidade);
                    aux = 1;
                } else {
                    puts("Estoque insuficiente");
                }
            }
        }
    } while (aux < 0);

    system("pause");
}

/*
19
*/

#include <stdio.h>
#include <stdlib.h>
#include "github.com/leozamboni/C/include/stbuffer.h"

struct movimentacoes {
    char codigo[64],
            origem[64],
            destinho[64];
};
typedef struct movimentacoes voos;

struct locais {
    unsigned int codigo,
            quantidadeentra,
            quantidadesai;
};
typedef struct locais aeroportos;

int main() {
    voos *v = malloc(2 * sizeof(voos));
    aeroportos *v2 = malloc(5 * sizeof(aeroportos));

    for (int i = 0; i < 5; ++i) {
        printf("Voo %d\n", i + 1);
        puts("Codigo:");
        fgets(v[i].codigo, 63, stdin);
        fflush(stdin);

        puts("Origem");
        fgets(v[i].origem, 63, stdin);
        fflush(stdin);

        puts("Destino");
        fgets(v[i].destinho, 63, stdin);
        fflush(stdin);;
        system("cls");
    }

    int aux = 0;
    for (int i = 0; i < 2; ++i) {
        do {
            printf("Aeroportos %d\n", i + 1);
            puts("Codigo:");
            scanf("%d", &v2[i].codigo);
            clearbuffer();
            if (v2[i].codigo > 0) {
                aux++;
            } else {
                puts("Codigo invalido");
            }
        } while (aux > 0);

        puts("Voos que saem:");
        scanf("%d", &v2[i].quantidadesai);
        clearbuffer();

        puts("Voos que entra:");
        scanf("%d", &v2[i].quantidadeentra);
        clearbuffer();
        system("cls");
    }

    system("pause");
}

/*
20
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "github.com/leozamboni/C/include/stbuffer.h"

struct ingredientes {
    char nome[25];
    int quantidade;
};
typedef struct ingredientes ingre;

struct receitas {
    char nome[25];
    int quant_ingre;
};
typedef struct receitas receita;

int main() {
    char nome[64];
    int aux = 0;
    receita *v = malloc(5 * sizeof(receita));

    ingre **m = malloc(5 * sizeof(ingre *));
    for (int k = 0; k < 5; ++k) {
        m[k] = malloc(10 * sizeof(ingre));
    }

    for (int i = 0; i < 5; ++i) {
        printf("Receita %d\n", i + 1);
        puts("Nome:");
        fgets(v[i].nome, 24, stdin);
        fflush(stdin);
        do {
            puts("Quantidade de Ingredientes:");
            scanf("%d", &v[i].quant_ingre);
            clearbuffer();
            if (v[i].quant_ingre > 10) {
                puts("Numero de ingredientes nao suportado");
            } else {
                aux++;
            }
        } while (aux < 0);

        for (int j = 0; j < v[i].quant_ingre; ++j) {
            printf("Ingrediente %d\n", j + 1);
            puts("Nome:");
            fgets(m[i][j].nome, 24, stdin);
            fflush(stdin);

            puts("Quantidade:");
            scanf("%d", &m[i][j].quantidade);
            clearbuffer();
            system("cls");
        }
        system("cls");
    }

    puts("Nome:");
    fgets(nome, 63, stdin);
    for (int j = 0; j < 5; ++j)
        if (strcmp (nome, v[j].nome) == 0) {
            printf("Nome: %s", v[j].nome);
            if (v[j].quant_ingre != 0) {
                puts("Ingredientes:");
                for (int i = 0; i < v[j].quant_ingre; ++i) {
                    printf("Nome: %s", m[j][i].nome);
                    printf("Quantidade: %d\n", m[j][i].quantidade);
                    puts("==================");
                }
            }
        } else {
            puts("Receita não encontrada :(");
        }

    system("pause");
}

/*
21
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "github.com/leozamboni/C/include/stbuffer.h"

struct filmes {
    char
            nome[25],
            ano[4];
    float
            duracao;
};
typedef struct filmes film;

struct diretores {
    char nome[20];
    int quantfilmes;
};
typedef struct diretores dire;

int main() {
    char nome[64];
    int aux = 0;
    dire *v = malloc(5 * sizeof(dire));

    film **m = malloc(5 * sizeof(film *));
    for (int k = 0; k < 5; ++k) {
        m[k] = malloc(10 * sizeof(film));
    }

    for (int i = 0; i < 5; ++i) {
        printf("Diretor %d\n", i + 1);
        puts("Nome:");
        fgets(v[i].nome, 19, stdin);
        fflush(stdin);
        do {
            puts("Quantidade de filmes:");
            scanf("%d", &v[i].quantfilmes);
            clearbuffer();
            if (v[i].quantfilmes > 10) {
                puts("Numero de filmes nao suportado");
            } else {
                aux++;
            }
        } while (aux < 0);

        for (int j = 0; j < v[i].quantfilmes; ++j) {
            printf("Filme %d\n", j + 1);
            puts("Nome:");
            fgets(m[i][j].nome, 24, stdin);
            fflush(stdin);

            puts("Ano:");
            fgets(m[i][j].ano, 4, stdin);
            fflush(stdin);

            puts("Duracao:");
            scanf("%f", &m[i][j].duracao);
            fflush(stdin);
            system("cls");
        }
        system("cls");
    }

    puts("Nome:");
    fgets(nome, 63, stdin);
    for (int j = 0; j < 5; ++j)
        if (strcmp (nome, v[j].nome) == 0) {
            printf("Nome: %s", v[j].nome);
            if (v[j].quantfilmes != 0) {
                puts("Filmes:");
                for (int i = 0; i < v[j].quantfilmes; ++i) {
                    printf("Nome: %s", m[j][i].nome);
                    printf("Ano: %s\n", m[j][i].ano);
                    printf("Duracao: %.2f\n", m[j][i].duracao);
                    puts("==================");
                }
            }
        } else {
            puts("Filmes inexistentes");
        }

    system("pause");
}

/*
23
*/

#include <stdio.h>
#include <stdlib.h>
#include "github.com/leozamboni/stbuffer.h"

typedef struct data {
    int dia,
            mes,
            ano;
}dma;

int main() {
    dma *v = malloc(2 * sizeof(dma));

    for (int i = 0; i < 2; ++i) {
        do {
            puts("Dia:");
            scanf("%d", &v[i].dia);
            clearbuffer();
            if (v[i].dia > 31 || v[i].dia < 0)
                puts("Dia invalido");
        } while (v[i].dia > 31 || v[i].dia < 0);

        do {
            puts("Mes:");
            scanf("%d", &v[i].mes);
            clearbuffer();
            if (v[i].mes > 12 || v[i].mes < 0) {
                puts("Mes invalido");
            }
        } while (v[i].mes > 12 || v[i].mes < 0);

        puts("Ano:");
        scanf("%d", &v[i].ano);
        clearbuffer();

        system("cls");
    }

    int dia, mes, ano;
    dia = v[0].dia - v[1].dia;
    mes = v[0].mes - v[1].mes;
    ano = v[0].ano - v[1].ano;
    if (dia < 0) {
        dia *= -1;
    }
    if (mes < 0) {
        mes *= -1;
    }
    if (ano < 0) {
        ano *= -1;
    }
    printf("%d dia(s), %d mes(es) e %d ano(s) decorrerem entre as duas datas\n", dia, mes, ano);

    system("pause");
}
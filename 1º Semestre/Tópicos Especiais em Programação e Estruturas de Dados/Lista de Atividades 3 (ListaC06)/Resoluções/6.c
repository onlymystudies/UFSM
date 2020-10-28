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

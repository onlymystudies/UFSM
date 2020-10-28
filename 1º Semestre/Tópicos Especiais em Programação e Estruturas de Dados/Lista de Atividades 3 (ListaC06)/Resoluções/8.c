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

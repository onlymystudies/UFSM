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

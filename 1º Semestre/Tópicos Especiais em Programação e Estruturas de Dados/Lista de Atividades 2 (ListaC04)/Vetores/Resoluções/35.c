#include <stdio.h>
#include <stdlib.h>

union numbers {
    unsigned int a;
    unsigned int b;
}nmbr;

void clear_buff() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int input() {
    do {
        puts("First Number:");
        scanf("%d", &nmbr.a);
        clear_buff();
        if (nmbr.a > 10000)
            puts("number over 10000");
    } while (nmbr.a > 10000);

    do {
        puts("Second Number:");
        scanf("%d", &nmbr.b);
        clear_buff();
        if (nmbr.b > 10000)
            puts("number over 10000");
    } while (nmbr.b > 10000);
}

unsigned int count(unsigned int i) {
    unsigned int ret=1;
    while (i/=10) ret++;
    return ret;
}

int main() {
    input();

    unsigned int auxa = count(nmbr.a);
    char *v = malloc(auxa * sizeof(char));

    unsigned int sum = auxa;

    printf("First vector it has %d positions\n", auxa);

    while (auxa--) {
        v[auxa]=nmbr.a%10;
        nmbr.a/=10;
    }

    unsigned int auxb = count(nmbr.b);
    char vectorb[auxa];

    printf("Second vector it has %d positions\n", auxb);

    sum += auxb;

    while (auxb--) {
        vectorb[auxb]=nmbr.b%10;
        nmbr.b/=10;
    }

    v =  realloc(v, (sum * sizeof(char)));

    printf("New vector it has %d positions\n", sum);

    system("pause");
}

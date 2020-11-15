#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct infos {
    int* numero;
}Info;

typedef struct fila {
    int inicio;
    int final;
    Info valores[MAX];
}Fila;

void imprime(Fila* fila) {
    for (int i = 0; i < fila->final; ++i) {
        for (int j = 0; ; ++j) {
            if (fila->valores[fila->final].numero[j] == 0)
                break;
            printf("fila %d valor %d\n", i, fila->valores[fila->final].numero[j]);
        }
    }
}

void insere(Fila* fila) {
    fila->final++;
    fila->valores[fila->final].numero = (int *) malloc(sizeof(int));
    printf("Fila %d\n", fila->final);
    printf("0 - para sair\n");
    for (size_t i = 0; ; i++) {
        printf("Valor %d\n", i);
        scanf("%d", &fila->valores[fila->final].numero[i]);
        if (fila->valores[fila->final].numero[i] == 0)
            return;
    }
}

Fila* cria() {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->inicio = fila->final = 0;
    return fila;
}

int main(void) {
    Fila *acabate = cria();
    insere(acabate);
    insere(acabate);
    imprime(acabate);
    system("pause");
}
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
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

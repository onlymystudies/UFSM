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

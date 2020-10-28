#include <stdio.h>
#include <stdlib.h>

void limpa_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

typedef struct st
{
    int *small_big; // Poderia também ser um vetor sem tamanho v[] (Clion nao permite)
}st;
st vector;
st data(int value, int *v);
int main()
{
    system("cls");
    int value = 0;
    int *v = (int*) malloc(64 * sizeof(int)); // cast (int*) considera malloc como inteiro
    vector.small_big = (int*) malloc(2 * sizeof(int));

    printf("Numero de valores que voce deseja inserir\n");
    scanf("%d", &value);
    limpa_buffer();

    printf("%d valores de entrada\n", value);
    for (int i = 1; i <= value; i++)
    {
        printf("%d:", i);
        scanf("%d", &v[i]);
        limpa_buffer();
    }
    v = (int*) realloc(v, (value + 1) * sizeof(int));

    data(value, v);

    printf("Numero de valores que voce deseja inseri: %d\n", value);
    printf("O valor minimo: %d\n", vector.small_big[1]);
    printf("O valor maximo: %d\n", vector.small_big[0]);
    free(v);
    free(vector.small_big);
    getchar(); // NUNCA MAIS USAR GETCHAR PARA PAUSAR (ele usa sujeira do buffer)
}
st data(int value, int *v)
{
    int small, big;

    for (int y = 1; y <= value; y++)
    {
        if (y == 1)
        {
            vector.small_big[1] = v[y];
            vector.small_big[0] = v[y];
        }
        if (v[y] > vector.small_big[0])
        {
            vector.small_big[0] = v[y];
        }
        if (v[y] < vector.small_big[1])
        {
            vector.small_big[1] = v[y];
        }
    }
    return vector;
}

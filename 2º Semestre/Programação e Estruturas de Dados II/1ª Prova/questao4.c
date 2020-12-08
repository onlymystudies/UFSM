/* Nome: Leonardo Zamboni Nunes 202012828
 * Codigo referencia: lista 4.1
 *
 * (2,0 Pontos) O código abaixo permite dividir uma frase em palavras e as palavras em letras.
 * Implemente o código em C que, usando a estrutura de dados adequada, inverte as letras de cada
 * palavra de um determinado texto, preservando a ordem das palavras. Por exemplo, dado o texto:
 * “ESTE EXERCICIO EH MUITO CHATO”, a saída deve ser: “ETSE OICICREXE HE OTIUM LICAF”.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char letra;
    struct no *proximo;
}No;

typedef struct pilha{
    struct no *topo;
}Pilha;

Pilha *cria(void) {
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void insere(Pilha *pilha, char letra) {
    No *novo = (No *) malloc(sizeof(No));
    novo->letra = letra;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

void pilhaLibera(Pilha *pilha) {
    pilha->topo = NULL;
}

void imprime(Pilha *pilha) {
    No *percorre = pilha->topo;
    while (percorre) {
        printf("%c",  percorre->letra);
        percorre =  percorre->proximo;
    }
}

int main()
{
    Pilha *pilha = cria();
    char str[] = "ESTE EXERCICIO EH MUITO FACIL"; //chato
    int init_size = strlen(str);
    char delim[] = " ";
    char *ptr = strtok(str, delim);
    while (ptr != NULL)
    {
        //printf("'%s'\n", ptr); // aqui sai uma palavra

        while (*ptr != '\0') {
            // imprime caracteres, não strings, portanto
            // com base em sua necessidade, você pode armazenar isso em outro array!
            //printf ("%c ", *ptr );
            insere(pilha, *ptr);
            ptr++ ;

        }
        imprime(pilha);
        pilhaLibera(pilha);
        puts("");
        ptr = strtok(NULL, delim);
    }
    system("pause");
}
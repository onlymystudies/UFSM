#include <stdio.h>
#include<stdlib.h>

typedef struct
{
    char nome[20];
    int codigo, tipo;
    float area, condominio;
}tipo_shopping;
tipo_shopping shopping;

FILE *p_shopping;

void abre_arquivo(void)
{
    p_shopping = fopen("shooping_center.bin", "a+b");
}

float condominio2(int t_tipo, float t_area)
{
    switch(t_tipo)
    {
        case 1:
            return t_area * 50;
            break;
        case 2:
            return t_area * 65;
            break;
        case 3:
            return t_area * 80;
            break;
        case 4:
            return t_area * 95;
            break;
    }
}

void mostrar(void)
{
    printf("\n%6d %-13s %4.2f %4d %10.2f", shopping.codigo, shopping.nome,
           shopping.area, shopping.tipo, shopping.condominio);
}

void procurar(int cod)
{
    rewind(p_shopping);
    do
    {
        fread(&shopping, sizeof(tipo_shopping), 1, p_shopping);
        if (cod == shopping.codigo) mostrar();
    }while(feof(p_shopping) == 0 && cod != shopping.codigo);
    if (cod != shopping.codigo)
        printf("\n\nLoja nao cadastrada");
}

void cadastrar(void)
{
    int continuar;
    do
    {
        system("cls");
        printf("\t\tCadastro");
        printf("\n\nShopping Center");
        printf("\n\nCadastro de Loja");
        printf("\n\nCodigo: ");
        scanf("%d", &shopping.codigo);
        printf("\nNome: ");
        fflush(stdin);
        scanf("%s", &shopping.nome);
        printf("\nArea: ");
        scanf("%f", &shopping.area);
        printf("Tipo (1-confeccoes, 2-alimentacao, 3-livros, 4-servicoes): ");
        shopping.condominio = condominio2(shopping.tipo, shopping.area);
        fseek(p_shopping, 0, SEEK_END);
        fwrite(&shopping, sizeof(tipo_shopping), 1, p_shopping);
        printf("\nCadastrado com sucesso");
        printf("\n\nCadastrar outraa (1-Sim / 0-Nao)");
        scanf("%d", &continuar);

    }while(continuar == 1);
}

void consultar(void)
{
    int t_codigo, continuar;
    do
    {
        system("cls");
        printf("\t\tConsultyar");
        printf("\n\nShopping Center");
        printf("\n\nConsultar loja");
        printf("\n\nCondigo da loja que deseja consultar: ");
        scanf("%d", &t_codigo);
        printf("______________________________________________________________");
        printf("\nCodigo Nome Area Tipo Condominio");
        printf("______________________________________________________________");
        procurar(t_codigo);
        printf("______________________________________________________________");
        printf("\n\nConsultar outra loja (1-Sim / 0-Nao): ");
        scanf("%d", &continuar);
    }while(continuar == 1);
}

void listar(void)
{
    system("cls");
    printf("\t\tRelatorio Geral");
    printf("Shopping Center");
    printf("Listagem Geral");
    printf("______________________________________________________________");
    printf("\nCodigo Nome Area Tipo Condominio");
    printf("______________________________________________________________");
    rewind(p_shopping);
    do
    {
        fread(&shopping, sizeof(tipo_shopping), 1, p_shopping);
        if (feof(p_shopping) == 0) mostrar();
    }while(feof(p_shopping) == 0);
    printf("______________________________________________________________");
    printf("\nTecle enter para voltar ao menu...");
    system("pause");
}

int main()
{
    int opcao;
    abre_arquivo();
    do
    {
        system("cls");
        printf("\t\tTela de Menu");
        printf("\n\nShopping Center");
        printf("\n\nOpcoes");
        printf("\n[1] Cadastrar Loja");
        printf("\n[2] Consultar Loja");
        printf("\n[3] listagem de todas as Loja");
        printf("\n[0] Sair");
        scanf("%d", &opcao);
        if (opcao != 0)
        {
            switch(opcao)
            {
                case 1:
                    cadastrar();
                    break;
                case 2:
                    consultar();
                    break;
                case 3:
                    listar();
                    break;
                default:
                    printf("\nOpcao invalida");
                    break;
            }
        }
    }while(opcao != 0);
}

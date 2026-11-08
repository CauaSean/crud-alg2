#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char CPF[15], Tipo, Nome[50], Email[50], Tel[15];
}Pessoa;

typedef struct{
    char TipoC, NomeV[50];
    int IDVela;
    float Preco;
}Velas;

typedef struct{
    int IDVenda, QntdVendida;
    float ValorT;
    char CPFC[15], Data[9];
}Vendas;

void menuPessoa();
void menuVelas();
void menuVendas();
void listarPessoas(Pessoa *p, int qntd);
void listarVelas(Velas *p, int qntd);
void menuConsultaVendas();
void menuRelatorios();


int main(){
    Pessoa *pessoas = NULL;  
    Velas *velas = NULL;
    int qntdPessoas = 0, qntdVelas = 0;
    int opcao;
    do{
        printf("========================================\n");
        printf("      SISTEMA DE VENDAS DE VELAS\n");
        printf("========================================\n");
        printf("1 - Gerenciar Pessoas\n");
        printf("2 - Gerenciar Velas\n");
        printf("3 - Gerenciar Vendas\n");
        printf("4 - Listar Pessoas\n");
        printf("5 - Listar Velas\n");
        printf("6 - Consultar Vendas\n");
        printf("7 - Relatorios\n");
        printf("8 - Sair\n");
        printf("Escolha uma opcao: \n");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            menuPessoa();
            break;
        case 2:
            menuVelas();
            break;
        case 3:
            menuVendas();
            break;
        case 4:
            listarPessoas(pessoas, qntdPessoas);
            break;

        case 5:
            listarVelas(velas, qntdVelas);
            break;
        case 6:
            menuConsultaVendas();
            break;
        case 7:
            menuRelatorios();
            break;
        case 8:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }while(opcao != 8);

    return 0;
}

void menuPessoa()
{
    int opcao;

    do
    {
        printf("\n========================================\n");
        printf("          GERENCIAR PESSOAS\n");
        printf("========================================\n");
        printf("1 - Cadastrar pessoa\n");
        printf("2 - Alterar pessoa\n");
        printf("3 - Consultar pessoa\n");
        printf("4 - Remover pessoa\n");
        printf("5 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                // funcao para cadastrar pessoa
                break;

            case 2:
                // funcao para alterar pessoa
                break;

            case 3:
                // funcao para consultar pessoa
                break;

            case 4:
                // funcao para remover pessoa
                break;

            case 5:
                printf("\nVoltando...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }

    } while(opcao != 5);
}

void menuVelas()
{
    int opcao;

    do
    {
        printf("\n========================================\n");
        printf("          GERENCIAR VELAS\n");
        printf("========================================\n");
        printf("1 - Cadastrar vela\n");
        printf("2 - Alterar vela\n");
        printf("3 - Consultar vela\n");
        printf("4 - Remover vela\n");
        printf("5 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                // funcao para cadastrar vela
                break;

            case 2:
                // funcao para alterar vela
                break;

            case 3:
                // funcao para consultar vela
                break;

            case 4:
                // funcao para remover vela
                break;

            case 5:
                printf("\nVoltando...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }

    } while(opcao != 5);
}
void menuVendas()
{
    int opcao;

    do
    {
        printf("\n========================================\n");
        printf("          GERENCIAR VENDAS\n");
        printf("========================================\n");
        printf("1 - Cadastrar venda\n");
        printf("2 - Alterar venda\n");
        printf("3 - Consultar venda\n");
        printf("4 - Remover venda\n");
        printf("5 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                // funcao para cadastrar venda
                break;

            case 2:
                // funcao para alterar venda
                break;

            case 3:
                // funcao para consultar venda
                break;

            case 4:
                // funcao para remover venda
                break;

            case 5:
                printf("\nVoltando...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }

    } while(opcao != 5);
}
void listarPessoas(Pessoa *p, int qntd)
{
    for(int i = 0; i < qntd; i++)
    {
        printf("\nPessoa %d\n", i + 1); 
        printf("CPF: %s\n", p->CPF);
        printf("Tipo: %c\n", p->Tipo);
        printf("Nome: %s\n", p->Nome);
        printf("Email: %s\n", p->Email);
        printf("Telefone: %s\n", p->Tel);

        p++;
    }
}
void listarVelas(Velas *p, int qntd)
{
    for(int i = 0; i < qntd; i++)
    {
        printf("\nVela %d\n", i + 1);
        printf("Tipo de Cera: %c\n", p->TipoC);
        printf("Nome: %s\n", p->NomeV);
        printf("ID da Vela: %d\n", p->IDVela);
        printf("Preco: %.2f\n", p->Preco);

        p++;
    }
}
void menuConsultaVendas()
{
    int opcao;

    do
    {
        printf("\n========================================\n");
        printf("          CONSULTA DE VENDAS\n");
        printf("========================================\n");
        printf("1 - Consultar por Data da Compra\n");
        printf("2 - Consultar por CPF do Cliente\n");
        printf("3 - Consultar por ID da Vela\n");
        printf("4 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                // funcao de consulta por data
                break;

            case 2:
                // funcao de consulta por CPF
                break;

            case 3:
                // funcao de consulta por ID da vela
                break;

            case 4:
                printf("\nVoltando...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }

    } while(opcao != 4);
}
void menuRelatorios()
{
    int opcao;

    do
    {
        printf("\n========================================\n");
        printf("              RELATORIOS\n");
        printf("========================================\n");
        printf("1 - Vendas a partir de uma data\n");
        printf("2 - Compras por cliente\n");
        printf("3 - Vendas por tipo de cera\n");
        printf("4 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                // funcao de relatorio por data
                break;

            case 2:
                // funcao de relatorio por cliente
                break;

            case 3:
                // funcao de relatorio por tipo de cera
                break;

            case 4:
                printf("\nVoltando...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }

    } while(opcao != 4);
}

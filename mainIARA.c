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
    int IDVenda, IDVela, QntdVendida;
    float ValorT;
    char CPFC[15], Data[11];
}Vendas;

void menuPessoa(Pessoa *pessoas, int *qntdPessoas, Vendas *vendas, int qntdVendas);
void menuVelas(Velas *velas, int *qntdVelas, Vendas *vendas, int qntdVendas);
void menuVendas(Vendas *vendas, int *qntdVendas, Pessoa *pessoas, int qntdPessoas, Velas *velas, int qntdVelas);
void listarPessoas(Pessoa p[], int qntd);
void listarVelas(Velas p[], int qntd);
void menuConsultaVendas(Vendas *vendas, int qntdVendas);
void menuRelatorios(Vendas *vendas, int qntdVendas, Pessoa *pessoas, int qntdPessoas, Velas *velas, int qntdVelas);


void cadastrarPessoa(Pessoa *pessoas, int *qntdPessoas);
void alterarPessoa(Pessoa *pessoas, int qntdPessoas);
void consultarPessoa(Pessoa *pessoas, int qntdPessoas);
void removerPessoa(Pessoa *pessoas, int *qntdPessoas, Vendas *vendas, int qntdVendas);

void cadastrarVela(Velas *velas, int *qntdVelas);
void alterarVela(Velas *velas, int qntdVelas);
void consultarVela(Velas *velas, int qntdVelas);
void removerVela(Velas *velas, int *qntdVelas, Vendas *vendas, int qntdVendas);

int main(){
    Pessoa pessoas[5];
    Velas velas[5];
    Vendas vendas[5];

    int qntdPessoas = 0, qntdVelas = 0, qntdVendas = 0;
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
            menuPessoa(pessoas, &qntdPessoas, vendas, qntdVendas);
            break;
        case 2:
            menuVelas(velas, &qntdVelas, vendas, qntdVendas);
            break;
        case 3:
            menuVendas(vendas, &qntdVendas, pessoas, qntdPessoas, velas, qntdVelas);
            break;
        case 4:
            listarPessoas(pessoas, qntdPessoas);
            break;
        case 5:
            listarVelas(velas, qntdVelas);
            break;
        case 6:
            menuConsultaVendas(vendas, qntdVendas);
            break;
        case 7:
            menuRelatorios(vendas, qntdVendas, pessoas, qntdPessoas, velas, qntdVelas);
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

void menuPessoa(Pessoa *pessoas, int *qntdPessoas, Vendas *vendas, int qntdVendas)
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
                cadastrarPessoa(pessoas, qntdPessoas);
                break;
            case 2:
                alterarPessoa(pessoas, *qntdPessoas);
                break;
            case 3:
                consultarPessoa(pessoas, *qntdPessoas);
                break;
            case 4:
                removerPessoa(pessoas, qntdPessoas, vendas, qntdVendas);
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

void menuVelas(Velas *velas, int *qntdVelas, Vendas *vendas, int qntdVendas)
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
                cadastrarVela(velas, qntdVelas);
                break;
            case 2:
                alterarVela(velas, *qntdVelas);
                break;
            case 3:
                consultarVela(velas, *qntdVelas);
                break;
            case 4:
                removerVela(velas, qntdVelas, vendas, qntdVendas);
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
void menuVendas(Vendas *vendas, int *qntdVendas, Pessoa *pessoas, int qntdPessoas, Velas *velas, int qntdVelas)
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
void listarPessoas(Pessoa p[], int qntd)
{
    if(qntd == 0){
        printf("Nenhuma pessoa cadastrada\n");
    }
    else{
        for(int i = 0; i < qntd; i++)
        {
            printf("\nPessoa %d\n", i + 1); 
            printf("CPF: %s\n", p[i].CPF);
            printf("Tipo: %c\n", p[i].Tipo);
            printf("Nome: %s\n", p[i].Nome);
            printf("Email: %s\n", p[i].Email);
            printf("Telefone: %s\n", p[i].Tel);
        }
    }
}
void listarVelas(Velas p[], int qntd)
{
    if(qntd == 0){
        printf("Nenhuma vela cadastrada\n");
    }
    else{
        for(int i = 0; i < qntd; i++)
        {
            printf("\nVela %d\n", i + 1);
            printf("Tipo de Cera: %c\n", p[i].TipoC);
            printf("Nome: %s\n", p[i].NomeV);
            printf("ID da Vela: %d\n", p[i].IDVela);
            printf("Preco: %.2f\n", p[i].Preco);
        }
    }
}
void menuConsultaVendas(Vendas *vendas, int qntdVendas)
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

void menuRelatorios(Vendas *vendas, int qntdVendas, Pessoa *pessoas, int qntdPessoas, Velas *velas, int qntdVelas)
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

void cadastrarPessoa(Pessoa *pessoas, int *qntdPessoas)
{
    if(*qntdPessoas >= 5){
        printf("Limite de pessoas atingido!\n");
        return;
    }
    int pos = *qntdPessoas;
    char cpf[15];

    printf("Digite o CPF: ");
    scanf(" %14s", cpf);

    for(int i = 0; i < *qntdPessoas; i++){
        if(strcmp(pessoas[i].CPF, cpf) == 0){
            printf("CPF ja cadastrado!\n");
            return;
        }
    }

    strcpy(pessoas[pos].CPF, cpf);

    printf("Digite o tipo da pessoa (Cliente ou Vendedor):");
    scanf(" %c", &pessoas[pos].Tipo);

    printf("Digite o nome: ");
    scanf(" %49[^\n]", pessoas[pos].Nome);

    printf("Digite o email: ");
    scanf(" %49s", pessoas[pos].Email);

    printf("Digite o telefone: ");
    scanf(" %14s", pessoas[pos].Tel);

    (*qntdPessoas)++;
    printf("Pessoa cadastrada com sucesso!\n");
}

void alterarPessoa(Pessoa *pessoas, int qntdPessoas)
{
    char cpf[15];

    if(qntdPessoas == 0){
        printf("Nenhuma pessoa cadastrada!\n");
        return;
    }

    printf("Digite o CPF da pessoa: ");
    scanf(" %14s", cpf);

    for(int i = 0; i < qntdPessoas; i++){
        if(strcmp(pessoas[i].CPF, cpf) == 0){

            printf("Digite o novo tipo: ");
            scanf(" %c", &pessoas[i].Tipo);

            printf("Digite o novo nome: ");
            scanf(" %49[^\n]", pessoas[i].Nome);

            printf("Digite o novo email: ");
            scanf(" %49s", pessoas[i].Email);

            printf("Digite o novo telefone: ");
            scanf(" %14s", pessoas[i].Tel);

            printf("Pessoa alterada com sucesso!\n");
            return;
        }
    }
    printf("Pessoa nao encontrada!\n");
}

void consultarPessoa(Pessoa *pessoas, int qntdPessoas)
{
    char cpf[15];

    if(qntdPessoas == 0){
        printf("Nenhuma pessoa cadastrada!\n");
        return;
    }
    printf("Digite o CPF da pessoa: ");
    scanf(" %14s", cpf);
    for(int i = 0; i < qntdPessoas; i++){
        if(strcmp(pessoas[i].CPF, cpf) == 0){

            printf("\nCPF: %s\n", pessoas[i].CPF);
            printf("Tipo: %c\n", pessoas[i].Tipo);
            printf("Nome: %s\n", pessoas[i].Nome);
            printf("Email: %s\n", pessoas[i].Email);
            printf("Telefone: %s\n", pessoas[i].Tel);

            return;
        }
    }
    printf("Pessoa nao encontrada!\n");
}

void removerPessoa(Pessoa *pessoas, int *qntdPessoas, Vendas *vendas, int qntdVendas)
{
    char cpf[15], pos = -1; //indica que ainda não encontramos a pessoa.

    if(*qntdPessoas == 0){
        printf("Nenhuma pessoa cadastrada!\n");
        return;
    }
    printf("Digite o CPF da pessoa a remover: ");
    scanf(" %14s", cpf);

    for(int i = 0; i < *qntdPessoas; i++){
        if(strcmp(pessoas[i].CPF, cpf) == 0){
            pos = i;
            break;
        }
    }
    if(pos == -1){
        printf("Pessoa nao encontrada!\n");
        return;
    }
    for(int i = 0; i < qntdVendas; i++){
        if(strcmp(vendas[i].CPFC, cpf) == 0){
            printf("Nao e possivel remover: pessoa possui vendas!\n");
            return;
        }
    }
    for(int i = pos; i < *qntdPessoas - 1; i++){
        pessoas[i] = pessoas[i + 1];
    }

    (*qntdPessoas)--;
    printf("Pessoa removida com sucesso!\n");
}

void cadastrarVela(Velas *velas, int *qntdVelas)
{
    if(*qntdVelas >= 5){
        printf("Limite de velas atingido!\n");
        return;
    }
    int pos = *qntdVelas, id;

    printf("Digite o ID da vela: ");
    scanf("%d", &id);

    for(int i = 0; i < *qntdVelas; i++){
        if(velas[i].IDVela == id){
            printf("ID ja cadastrado!\n");
            return;
        }
    }
    velas[pos].IDVela = id;

    printf("Digite o tipo de cera: ");
    scanf(" %c", &velas[pos].TipoC);

    printf("Digite o nome da vela: ");
    scanf(" %49[^\n]", velas[pos].NomeV);

    printf("Digite o preco: ");
    scanf("%f", &velas[pos].Preco);
    if(velas[pos].Preco <= 0){
        printf("Preco invalido!\n");
        return;
    }
    (*qntdVelas)++;
    printf("Vela cadastrada com sucesso!\n");
}

void alterarVela(Velas *velas, int qntdVelas)
{
    int id;
    float novoPreco;

    if(qntdVelas == 0){
        printf("Nenhuma vela cadastrada!\n");
        return;
    }
    printf("Digite o ID da vela: ");
    scanf("%d", &id);
    for(int i = 0; i < qntdVelas; i++){
        if(velas[i].IDVela == id){

            printf("Digite o novo preco: ");
            scanf("%f", &novoPreco);

            if(novoPreco <= 0){
                printf("Preco invalido!\n");
                return;
            }
            printf("Digite o novo tipo de cera: ");
            scanf(" %c", &velas[i].TipoC);

            printf("Digite o novo nome: ");
            scanf(" %49[^\n]", velas[i].NomeV);

            velas[i].Preco = novoPreco;

            printf("Vela alterada com sucesso!\n");
            return;
        }
    }
    printf("Vela nao encontrada!\n");
}

void consultarVela(Velas *velas, int qntdVelas)
{
    int id;
    if(qntdVelas == 0){
        printf("Nenhuma vela cadastrada!\n");
        return;
    }
    printf("Digite o ID da vela: ");
    scanf("%d", &id);
    for(int i = 0; i < qntdVelas; i++){
        if(velas[i].IDVela == id){

            printf("\nID: %d\n", velas[i].IDVela);
            printf("Tipo de cera: %c\n", velas[i].TipoC);
            printf("Nome: %s\n", velas[i].NomeV);
            printf("Preco: %.2f\n", velas[i].Preco);
            return;
        }
    }
    printf("Vela nao encontrada!\n");
}

void removerVela(Velas *velas, int *qntdVelas, Vendas *vendas, int qntdVendas)
{
    int id, pos = -1;

    if(*qntdVelas == 0){
        printf("Nenhuma vela cadastrada!\n");
        return;
    }
    printf("Digite o ID da vela a remover: ");
    scanf("%d", &id);

    for(int i = 0; i < *qntdVelas; i++){
        if(velas[i].IDVela == id){
            pos = i;
            break;
        }
    }
    if(pos == -1){
        printf("Vela nao encontrada!\n");
        return;
    }
    for(int i = 0; i < qntdVendas; i++){
        if(vendas[i].IDVela == id){
            printf("Nao e possivel remover: vela possui vendas!\n");
            return;
        }
    }
    for(int i = pos; i < *qntdVelas - 1; i++){
        velas[i] = velas[i + 1];
    }
    (*qntdVelas)--;
    printf("Vela removida com sucesso!\n");
}
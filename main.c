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
    int IDVenda, QntdVendida, ValorT;
    char CPFC[15], Data[9];
}Vendas;

int main(){
    
    return 0;
}

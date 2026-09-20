#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


////                    seção produtos                           ////
typedef struct
{
    char nome[MAX];
    char codigo[MAX];
    char categoria[MAX];
    int qtd_estoque;
    float preco;
    char tamanho[MAX];
} Produto;

void alloca_produtos(){

//allocamos a variavel produtos zerada e crescemos conforme cadastramos
Produto *produtos = NULL;
//esta variavel se refere a quantidade de produtos no vetor de produtos
int quantidade = 0;
}

void menu_produtos(){
int escolha = 0;
    printf("=====MENU PRODUTOS=====\n ");
        printf("1 - Cadastrar Produto\n ");
        printf("2 - Buscar Produtos\n ");
        printf("3 - Exibir Estoque\n ");
        printf("4 - Editar Produtos\n");
        printf("5 - Alterar Estoque\n");
        printf("0 - Sair\n ");
        scanf("%i", &escolha);
}
////                    seção produtos                           ////



int main(){
int escolha = 0;
    do{
        menu_produtos();
    } while (escolha > 0);

    return 0;
}

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

//allocamos a variavel produtos zerada e crescemos conforme cadastramos
Produto *produtos = NULL;
//esta variavel se refere a quantidade de produtos no vetor de produtos
int quantidade = 0;

void exibirInfoProduto(Produto produtos[], int i){
    printf("PRODUTO %i",i+1 );
    printf("%s",produtos[i].nome);
    printf("Codigo: %s",produtos[i].codigo);
    printf("Categoria: %s",produtos[i].categoria);
    printf("Tamanho: %s",produtos[i].tamanho);
    printf("Quantidade em estoque: %d unidades", produtos[i].qtd_estoque);
    printf("Preco: %.2f\n", produtos[i].preco);
} // funcao que sera usada para exibir as informacoes dos produtos tanto na funcao exibir_estoque quanto na buscar_produto


void buscar_codigo(Produto produtos[],int quantidade){ //função buscar codigo| procura produtos e quantidade na struct Produto
    char codigo_busca[MAX]; //variavel que guarda o codigo que o usuario quer buscar
    printf("Digite o codigo do produto do produto que deseja buscar: ");
    scanf("%s",codigo_busca);
    int encontrado = 0; // variavel que verifica se o produto foi

    for(int i =0;i<quantidade;i++){// for para procurar na var quantidade
        if (strcmp(produtos[i].codigo,codigo_busca)==0){ //função da biblioteca string para comparar strings| compara produtos e codigo_busca
            printf("\n--- Produto encontrado ---\n"); // print para mostras as informações da busca
            printf("Nome: %s",produtos[i].nome); // print para mostras as informações da busca
            printf("Codigo:  %s",produtos[i].codigo); // print para mostras as informações da busca 
            printf("Categoria %s",produtos[i].categoria); // print para mostras as informações da busca 
            printf("Quantidade em estoque %d",produtos[i].qtd_estoque); // print para mostras as informações da busca
            printf("Preco: %.2f",produtos[i].preco); // print para mostras as informações da busca

            encontrado=1; // se encontrado for 1, para o laço
            break;

        }
        
    }
    if(encontrado==0){//se for rodar e não achar nada, mostrar no print que não achou nenhum produto
            printf("Produto não encontrado.");
        }
}

void exibir_estoque(Produto produtos[],int quantidade){
    if(quantidade==0){
        printf("Nenhum produto cadastrado");
        return;
    } // se não houver nenhum produto cadastrado ele printa a mensagem e retorna

    printf("=====EXIBIR ESTOQUE=====\n");

    int choice; // o usuario escolhe se quer exibir o estoque total ou por categoria
    printf("1 - Exibir estoque total\n "); // menu de escolha
    printf("2 - Exibir por categoria\n ");
    printf("Digite uma opcao: ");
    scanf("%i",&choice);

    if(choice==1){
        printf("=====PRODUTOS CADASTRADOS=====\n");
    
        for(int i = 0; i<quantidade; i++){
            exibirInfoProduto(produtos, i); // chamada da funcao que exibe as informacoes do produto
        }
    }else if(choice==2){
        //Kauê vai implementar por categoria
    }else{
        printf("Opcao invalida");
    }
}

int menu_produtos(){
    int escolha;
    printf("\n=====MENU PRODUTOS=====\n ");
        printf("1 - Cadastrar Produto\n ");
        printf("2 - Buscar Produtos\n ");
        printf("3 - Exibir Estoque\n ");
        printf("4 - Editar Produtos\n ");
        printf("5 - Alterar Estoque\n ");
        printf("0 - Sair\n ");
        printf("Digite uma opcao: ");
        scanf("%i", &escolha);
    return escolha;
} // funcao que exibe o menu do sistema de estoque e retorna o inteiro digitado (escolha) pelo usuario

////                    seção produtos                           ////



int main(){
int opcao;
    do{
        opcao = menu_produtos();
        switch (opcao){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (opcao!=0);
    
    return 0;
}

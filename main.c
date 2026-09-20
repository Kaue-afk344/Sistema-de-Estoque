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

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void reallocar_produtos(){ //função para realocar produtos
    quantidade++;
    produtos = realloc(produtos, quantidade * sizeof(Produto)); //realocando produtos com a função realloc
}

int verificar_codigo(char codigo_digitado[], Produto produtos[], int quantidade) {
    for (int i = 0; i < quantidade-1; i++) {
        if (strcmp(produtos[i].codigo, codigo_digitado) == 0) {
            return 1;
        }
    }
    return 0;
}
void cadastro_codigo(){
    do{
        char codigo_digitado[MAX];
        scanf(" %99[^\n]",codigo_digitado);
        if((verificar_codigo(codigo_digitado, produtos, quantidade))==0){
            strcpy(produtos[quantidade - 1].codigo, codigo_digitado);
            break;
        }else{
            printf("Codigo ja registrado, tente outro!\n"); 
        }
    }while(1);
}



int verificar_nome(char nome_digitado[], Produto produtos[], int quantidade) {
    for (int i = 0; i < quantidade-1; i++) {
        if (strcmp(produtos[i].nome, nome_digitado) == 0) {
            return 1;
        }
    }
    return 0;
}

void cadastro_nome(){
    do{
        char nome_digitado[MAX];
        scanf(" %99[^\n]",nome_digitado);
        if((verificar_nome(nome_digitado, produtos, quantidade))==0){
            strcpy(produtos[quantidade - 1].nome, nome_digitado);
            break;
        }else{
            printf("Nome ja registrado, tente outro!\n"); 
        }
    }while(1);
}


void cadastrar_produto(){ //função cadastrar produto| procura produtos e quantidade na struct Produto
    reallocar_produtos();
    int i = quantidade - 1;
    
    printf("Digite o nome do produto: ");
    cadastro_nome();
    printf("Digite o codigo do produto: ");
    cadastro_codigo();
    printf("Digite a categoria do produto: ");
    scanf(" %99[^\n]",produtos[i].categoria);
    printf("Digite a quantidade em estoque do produto: ");
    scanf("%d",&produtos[i].qtd_estoque);
    printf("Digite o preco do produto: ");
    scanf("%f",&produtos[i].preco);
    limpar_buffer();
    printf("Digite o tamanho do produto: ");
    scanf("%s",produtos[i].tamanho);

}

void exibirInfoProduto(Produto produtos[], int i){
    printf("PRODUTO %i",i+1 );
    printf("%s",produtos[i].nome);
    printf("Codigo: %s",produtos[i].codigo);
    printf("Categoria: %s",produtos[i].categoria);
    printf("Tamanho: %s",produtos[i].tamanho);
    printf("Quantidade em estoque: %d unidades", produtos[i].qtd_estoque);
    printf("Preco: %.2f\n", produtos[i].preco);
} // funcao que sera usada para exibir as informacoes dos produtos tanto na funcao exibir_estoque quanto na buscar_produto

//pedro
void buscar_codigo(Produto produtos[],int quantidade){ //função buscar codigo| procura produtos e quantidade na struct Produto
    if(quantidade==0){
        printf("Nenhum produto cadastrado.");
        return;
    }
    char codigo_busca[MAX]; //variavel que guarda o codigo que o usuario quer buscar
    printf("Digite o codigo do produto do produto que deseja buscar: ");
    scanf("%s",codigo_busca); //guarda o input do usuario na var codigo_busca
    int encontrado = 0;// variavel que verifica se o produto foi encontrado
    for(int i =0;i<quantidade;i++){// for para procurar na var quantidade
        if (strcmp(produtos[i].codigo,codigo_busca)==0){ //função da biblioteca string para comparar strings| compara produtos e codigo_busca
            exibirInfoProduto(produtos, i);// chama a função exibir info produto
            encontrado=1; // se encontrado for 1, faz o laço parar
            break;
        }
    }
    if(encontrado==0){//se for rodar e não achar nada, mostrar no print que não achou nenhum produto
            printf("Produto não encontrado.");
        }
    }//pedro|procurar codigo

    //pedro|buscar por nome
    void buscar_nome(Produto produtos[],int quantidade){
        if(quantidade==0){
            printf("Nenhum produto cadastrado.");
            return;
        }
        char nome_busca[MAX]; // variavel que guarda o nome que o usuario quer buscar
        printf("Digite o nome do produto que deseja buscar.");
        scanf(" %[^\n]",nome_busca); //guarda o input do usuario na var nome_busca
        int encontrado =0; // variavel que verifica se o produto foi encontrado
        for(int i=0;i<quantidade;i++){
            if(strcmp(produtos[i].nome,nome_busca)==0){
                 exibirInfoProduto(produtos, i);// chama a função exibir info produto
                 encontrado=1;// se encontrado for 1, faz o laço para
                 }
            }
            if(encontrado==0){
                printf("Produto nao encontrado.");
            }
        }//pedro buscar por nome

//pedro

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
        limpar_buffer();
    return escolha;
} // funcao que exibe o menu do sistema de estoque e retorna o inteiro digitado (escolha) pelo usuario

////                    seção produtos                           ////



int main(){
int opcao;
    do{
        opcao = menu_produtos();
        switch (opcao){
            case 1:
                cadastrar_produto();
                break;
            case 2:
            //pedro|case
            int opc_busca;//var para guardar a opcao que o usuario digitou
            printf("=====Buscar produtos=====");
            printf("1 - Buscar por codigo.");
            printf("2 - Buscar por nome.");
            print("Digite uma opcao: ");
            scanf("d",&opc_busca);

            if(opc_busca ==1){ //se o usuario escolher 1, chama a função buscar por codigo
                busca_codigo(produtos,quantidade);
            }else if(opc_busca ==2){ // se o usuario escolher 2, chama a funcao buscar por nome
                busca_nome(produtos,quantidade);
            }else{// se ele nao digitar nada, diz que nenhuma opcao foi encontrada
                printf("Opcao nao encontrada.");
            }
            break;//pedro|case2
               
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

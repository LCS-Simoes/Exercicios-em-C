#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Estoques
{
    int quantidade;
    float precoUnitario;
    char nomeProduto[20];
    int codigo;

} Estoques;

int i;
int total = 0;
int produtosCadastrados = 0;
Estoques *estoques = NULL;

void gerarCodigo()
{
    estoques = (Estoques*) malloc(10 * sizeof(Estoques));
    for(i = 0; i < 10 ; i++)
    {
        estoques[i].codigo = i;
    }
}

void cadastrarProduto()
{
    int produtosCadastrar;
    printf("Digite quantos produtos voce deseja cadastrar: ");
    scanf("%d",&produtosCadastrar);
    getchar();
    estoques = (Estoques*) realloc(estoques, (produtosCadastrados + produtosCadastrar) * sizeof(Estoques));
    for(i = produtosCadastrados; i < produtosCadastrados + produtosCadastrar; i++)
    {
        printf("\nDigite o nome do produto: ");
        fgets(estoques[i].nomeProduto,20, stdin);
        printf("Digite a quantidade do produto: ");
        scanf("%d",&estoques[i].quantidade);
        printf("\nDigite o preco unitario do produto: ");
        scanf("%f",&estoques[i].precoUnitario);
        getchar();
        estoques[i].codigo = i;
    }
    produtosCadastrados += produtosCadastrar;
}

void buscarProduto()
{
    char buscarProd[20];
    printf("Digite o nome do produto que deseja buscar: ");
    fgets(buscarProd,20,stdin);
    int encontrado = 0;
    for(i = 0; i < produtosCadastrados; i++)
    {
        if(strcmp(buscarProd, estoques[i].nomeProduto) == 0)
        {
            printf("Codigo: %d, Nome: %s, Quantidade: %d, Preco Unitario: %.2f\n", estoques[i].codigo, estoques[i].nomeProduto, estoques[i].quantidade, estoques[i].precoUnitario);
        }
        else
        {
            printf("Produto nao encontrado ou nome incorreto");
        }
    }

}

void atualizarProduto()
{
    char atualizar[20];
    printf("Digite o nome do produto que deseja buscar para atualizar: ");
    fgets(atualizar,20,stdin);
    int encontrado = 0;
    for(i = 0; i < produtosCadastrados; i++)
    {
        if(strcmp(atualizar, estoques[i].nomeProduto) == 0)
        {
            printf("Digite a quantidade do produto: ");
            scanf("%d",&estoques[i].quantidade);
            printf("\nDigite o preco unitario do produto: ");
            scanf("%f",&estoques[i].precoUnitario);
        }
        else
        {
            printf("Produto nao encontrado ou nome incorreto");
        }
    }
}

void listarProdutos()
{
    if(produtosCadastrados == 0)
    {
        printf("Nenhum produto cadastrado");
    }
    else
    {
        for(i = 0; i < produtosCadastrados; i++)
        {
            printf("Codigo: %d, Nome: %s, Quantidade: %d, Preco Unitario: %.2f\n", estoques[i].codigo, estoques[i].nomeProduto, estoques[i].quantidade, estoques[i].precoUnitario);
        }
    }
}

void vender()
{
    int venda;
    float totalVenda;
    int quantidadeVenda;

    char buscarProd[20];
    printf("Digite o nome do produto que deseja buscar para vender: ");
    fgets(buscarProd,20,stdin);
    int encontrado = 0;
    for(i = 0; i < produtosCadastrados; i++)
    {
        if(strcmp(buscarProd, estoques[i].nomeProduto) == 0)
        {
            printf("Produto encntrado\n");
            printf("Digite a quantidade que voce deseja vender \n");
            scanf("%d",&quantidadeVenda);
            if(estoques[i].quantidade > quantidadeVenda)
            {
                estoques[i].quantidade - quantidadeVenda;
                totalVenda += estoques[i].precoUnitario * quantidadeVenda;
            }else {
                printf("Quantidade desejada e maior que a do estoque");
            }
        }
        else
        {
            printf("Produto nao encontrado\n");
        }


    }
    printf("\nTotal dessa venda foi de %.2f", totalVenda);



}
int main()
{
    int op;

    do
    {
        printf("\n---------- Controle de Estoque ----------");
        printf("\n1 - Gerar Codigo");
        printf("\n2 - Cadastrar produto / quantidade e Preco");
        printf("\n3 - Pesquisa de produto por Descricao");
        printf("\n4 - Atualizar produtos");
        printf("\n5 - Produtos cadastrados");
        printf("\n6 - Venda e baixa o produto");
        printf("\n7 - Historico de venda");
        printf("\n0 - Sair");
        printf("\nDigite a opcao: ");
        scanf("%d",&op);
        getchar();
        switch(op)
        {
        case 1:
            gerarCodigo();
            break;
        case 2:
            cadastrarProduto();
            break;
        case 3:
            buscarProduto();
            break;
        case 4:
            atualizarProduto();
            break;
        case 5:
            listarProdutos();
            break;
        case 6:
            vender();
            break;
        case 7:
            break;
        case 0:
            printf("Saindo\n");
            free(estoques);
            break;
        default:
            printf("Opcao invalida\n");
        }
    }
    while(op != 0);

    return 0;
}

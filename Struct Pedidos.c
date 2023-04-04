#include <stdlib.h>
#include <stdio.h>

typedef struct Endereco
{
    char logradouro[30];
    int numero;
    char bairro[20];
    char complemento[30];
} Endereco;
typedef struct Itens
{
    char sabor[10];
    float tamanho;
    int quantidade;
}Itens;
typedef struct Pagamento
{
    char pagamento[20];
    float valorpedido;
}Pagamento;

typedef struct Pedido
{
    int numeropedido;
    char nomecliente[20];
    char telefone[20];
    Endereco informacoes;
    Itens item[10];
    Pagamento Pagamento;
} Pedido;

int main(void)
{
    struct Pedido pedido;
    printf("Digite o codigo do pedido: \n");
    scanf("%d",&pedido.numeropedido);
    printf("Digite o nome do cliente: \n");
    scanf("%s",&pedido.nomecliente);
    printf("Digite o numero do telefone: \n");
    scanf("%s",&pedido.telefone);
    printf("Digite o Logradouro do cliente: \n");
    scanf("%s",&pedido.informacoes.logradouro);
    printf("Digite o numero da casa ou apartamento do cliente: \n");
    scanf("%d",&pedido.informacoes.numero);
    printf("Digite o Bairro do Cliente: \n");
    scanf("%s",&pedido.informacoes.bairro);
    printf("Digite o Complemento do cliente: \n");
    scanf("%s",&pedido.informacoes.complemento);
    printf("Digite o sabor: \n");
    scanf("%s",&pedido.item[0].sabor);
    printf("Digite a quantidade: \n");
    scanf("%d",&pedido.item[0].quantidade);
    printf("Digite o tamanho: \n");
    scanf("%f",&pedido.item[0].tamanho);
    printf("Qual sera a forma de pagamento?: \n");
    scanf("%s",&pedido.Pagamento.pagamento);
    printf("Digite o valor do pagamento:  \n");
    scanf("%f",&pedido.Pagamento.valorpedido);
    printf("---------------------- DADOS DO PEDIDO ----------------------\n");
    printf("Codigo do produto: %d \n",pedido.numeropedido);
    printf("Nome: %s, Telefone: %s    \n",pedido.nomecliente,pedido.telefone);
    printf("Logradouro: %s, Numero Casa ou Apartamento: %d, Bairro: %s, Complemento: %s \n",pedido.informacoes.logradouro,pedido.informacoes.numero,pedido.informacoes.bairro,pedido.informacoes.complemento);
    printf("Sabor: %s, Tamanho: %.2f, Quantidade: %d \n",pedido.item[0].sabor,pedido.item[0].tamanho,pedido.item[0].quantidade);
    printf("Pagamento em:%s, Valor: %.2f",pedido.Pagamento.pagamento,pedido.Pagamento.valorpedido);


}


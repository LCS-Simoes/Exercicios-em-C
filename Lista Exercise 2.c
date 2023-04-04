#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct number
{
    int numeros;
};
typedef struct no
{
    struct number numero;
    struct no *proximo;
} No;

void exibir(No *no)
{
    printf("\n\n Numeros cadastrados \n");
    while (no != NULL)
    {
        printf("Numero: %d\n", no->numero.numeros);
        no = no->proximo;
    }
    printf("\n\n");
}
void inserir(No **novo)
{
    No* atual = *novo;
    if (*novo == NULL)
    {
        *novo = malloc(sizeof(No));
        atual = *novo;
    }
    else
    {
        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = malloc(sizeof(No));
        atual = atual->proximo;
    }
    printf("Digite um numero: ");
    scanf("%d", &atual->numero.numeros);
    atual->proximo = NULL;
}
void buscar(No *novo)
{
    int buscar;
    printf("Digite o numero que deseja buscar: ");
    scanf("%d", &buscar);
    No *atual = novo;
    while (atual != NULL)
    {
        if (atual->numero.numeros == buscar)
        {
            printf("Numero cadastrado encontrado: %d\n", atual->numero.numeros);
            return;
        }
        atual = atual->proximo;
    }
    printf("Contato nao encontrado.\n");
}
void remover(No **novo)
{
    int buscar;
    printf("Digite o numero que deseja remover: ");
    scanf("%d", &buscar);
    No *anterior = NULL;
    No *atual = *novo;
    while (atual != NULL)
    {
        if(atual->numero.numeros == buscar)
        {
            if (anterior == NULL)
            {
                *novo = atual->proximo;
            }
            else
            {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            printf("Contato removido com sucesso.\n");
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Contato nao encontrado.\n");
}



int main()
{
    int li_opcao;
    No *novo = NULL;
    do
    {
        printf("EXIBIR[1],BUSCAR[2],INSERIR[3],REMOVER[4]\n");
        printf("Digite a opcao que deseja:");
        scanf("%d", &li_opcao);
        switch(li_opcao)
        {
        case 1:
            exibir(novo);
            break;
        case 2:
            buscar(novo);
            break;
        case 3:
            inserir(&novo);
            break;
        case 4:
            remover(&novo);
            break;
        default:
            printf("Numero digitado e incoretto");
        }

    }
    while(li_opcao != 5);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aplicativos
{
    char nome_app[80];
    char empresa[80];
    int data_empresa;
};

typedef struct no
{
    struct aplicativos aplicativo;
    struct no *proximo;

} No;

void cadastrar(No **novo)
{
    No *atual = *novo;
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
    printf("Nome aplicativo: ");
    fgets(atual->aplicativo.nome_app, 80, stdin);
    atual->aplicativo.nome_app[strcspn(atual->aplicativo.nome_app, "\n")] = '\0'; // remover o caractere \n da string
    printf("\nAno de criacao: ");
    scanf("%d", &atual->aplicativo.data_empresa);
    getchar();
    fflush(stdin);
    printf("Empresa: ");
    fgets(atual->aplicativo.empresa, 80, stdin);
    atual->aplicativo.empresa[strcspn(atual->aplicativo.empresa, "\n")] = '\0'; // remover o caractere \n da string
    atual->proximo = NULL;
}

void exibir(No *no)
{
    if (no == NULL)
    {
        printf("Lista vazia.\n\n");
    }
    else
    {
        printf("\n\n Cadastros: \n");
        while (no != NULL)
        {
            printf("Nome: %s, Data: %d, Empresa: %s\n", no->aplicativo.nome_app, no->aplicativo.data_empresa, no->aplicativo.empresa);
            no = no->proximo;
        }
        printf("\n\n");
    }
}

int buscar(No **novo)
{
    if (*novo == NULL)
    {
        printf("Lista vazia.\n");
        return -1;
    }
    char nome[80];
    printf("Digite o nome a buscar: ");
    fgets(nome, 80, stdin);
    nome[strcspn(nome, "\n")] = '\0'; // remover o caractere \n da string
    fflush(stdin);
    No *anterior = NULL;
    No *atual = *novo;
    while (atual != NULL && strcmp(atual->aplicativo.nome_app, nome) != 0)
    {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual != NULL)
    {
        if (anterior != NULL)
        {
            anterior->proximo = atual->proximo;
            atual->proximo = *novo;
            *novo = atual;
        }
        printf("Nome: %s, Data de desenvolvimento: %d, Empresa: %s\n", atual->aplicativo.nome_app, atual->aplicativo.data_empresa, atual->aplicativo.empresa);
        return 1;
    }
    else
    {
        printf("Aplicativo nao encontrado.\n");
        return 0;
    }
}

int main()
{
    int li_opcao;
    No *novo = NULL;
    do
    {
        printf("CADASTRAR[1], BUSCAR[2], EXIBIR[3]\n");
        printf("Digite o que deseja: ");
        scanf("%d",&li_opcao);
        getchar();
        switch(li_opcao)
        {
        case 1:
            cadastrar(&novo);
            break;
        case 2:
            buscar(&novo);
            break;
        case 3:
            exibir(novo);
            break;
        default:
            printf("Numero digitado e incorreto");
        }
    }while(li_opcao != 4);
}

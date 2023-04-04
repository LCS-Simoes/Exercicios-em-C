#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contatos
{
    char nome[80];
    int telefone;
    char email[80];
};
typedef struct no
{
    struct contatos contato;
    struct no *proximo;
} No;

void exibir(No *no)
{
    printf("\n\n Cadastros: ");
    while (no != NULL)
    {
        printf("Nome: %s, Telefone: %d, Email: %s\n", no->contato.nome, no->contato.telefone, no->contato.email);
        no = no->proximo;
    }
    printf("\n\n");
}

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
    printf("Nome: ");
    fgets(atual->contato.nome, 80, stdin);
    printf("\nTelefone: ");
    scanf("%d", &atual->contato.telefone);
    getchar();
    fflush(stdin);
    printf("\nEmail: ");
    fgets(atual->contato.email, 80, stdin);
    atual->proximo = NULL;
}
void buscar(No *novo)
{
    char nome[80];
    printf("Digite o nome da pessoa que deseja buscar: ");
    fgets(nome, 80, stdin);
    No *atual = novo;
    while (atual != NULL)
    {
        if (strcmp(atual->contato.nome, nome) == 0)
        {
            printf("Nome: %s, Telefone: %d, Email: %s\n", atual->contato.nome, atual->contato.telefone, atual->contato.email);
            return;
        }
        atual = atual->proximo;
    }
    printf("Contato nao encontrado.\n");
}
void remover_contato(No **novo)
{
    char nome[80];
    printf("Digite o nome da pessoa que deseja remover: ");
    fgets(nome, 80, stdin);
    No *anterior = NULL;
    No *atual = *novo;
    while (atual != NULL)
    {
        if (strcmp(atual->contato.nome, nome) == 0)
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
void ultimo_contato(No *novo)
{
    No *atual = novo;
    while (atual != NULL)
    {
        if (atual->proximo == NULL)
    {
        printf("Nome: %s, Telefone: %d, Email: %s\n", atual->contato.nome, atual->contato.telefone, atual->contato.email);
            return;
        }
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
        printf("CADASTRADOS[1]\nCADASTRAR[2]\nPESQUISAR[3]\nREMOVER[4]\n");
        printf("Digite a opcao que deseja: ");
        scanf("%d", &li_opcao);
        getchar();
        switch (li_opcao)
        {
        case 1:
            exibir(novo);
            break;
        case 2:
            cadastrar(&novo);
            break;
        case 3:
            buscar(novo);
            break;
        case 4:
            remover_contato(&novo);
            system("pause");
            break;
        case 5:
            ultimo_contato(novo);
            break;
        default:
            printf("Numero digitado e incorreto");
        }

    }
    while (li_opcao != 6);

    return 0;
}

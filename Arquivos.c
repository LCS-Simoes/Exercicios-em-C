#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente
{
    int codigo;
    char nome[20];
    int idade;
    int cpf;
    char endereco[30];
    int telefone;
};

void incluir()
{
    char numstr[15];
    char resp;
    FILE *fptr;

    fptr = fopen("cadastro", "ab");

    if (fptr == NULL)
    {
        printf("\n Problema com Abertura do Arquivo");
        system("pause");
    }
    else
    {
        struct cliente fatec;
        do
        {
            system("cls");
            printf("\n *******************************");
            printf("\n ****** CADASTRO DE CLIENTE  ***");
            printf("\n *******************************");

            printf("\n Informe o Codigo do Cliente: ");
            scanf("%d", &fatec.codigo);
            fflush(stdin);

            printf("\n Informe o Nome do Cliente: ");
            gets(fatec.nome);
            fflush(stdin);

            printf("\n Informe a Idade do Cliente: ");
            scanf("%d", &fatec.idade);
            fflush(stdin);

            printf("\n Informe o Endere�o do Cliente: ");
            gets(fatec.endereco);
            fflush(stdin);

            printf("\n Informe o Telefone do Cliente: ");
            gets(numstr);
            fatec.telefone = atoi(numstr);

            printf("\n Informe o CPF do Cliente: ");
            gets(numstr);
            fatec.cpf = atoi(numstr);
            fflush(stdin);

            fwrite(&fatec, sizeof(fatec), 1, fptr);

            printf("\n Deseja continuar o Cadastro [S]im ou [N]ao: ");
            scanf(" %c", &resp);
            resp = toupper(resp);
            fflush(stdin);

        }
        while (resp != 'N');
        fclose(fptr);
    }
}


void relatorio()
{
    FILE *fptr;
    struct cliente fatec;
    fptr = fopen("cadastro", "rb");

    if(fptr == NULL)
    {
        printf("\n Arquivo nao existe");
        system("pause");
    }
    else
    {
        printf("******** CLIENTES CADASTRADOS ********\n");
        printf(" %-10s %-20s %-5s %-12s %-30s\n", "Codigo", "Nome", "Idade", "CPF", "Endereco");
        while(fread(&fatec, sizeof(fatec), 1, fptr))
        {
            printf(" %-10d %-20s %-5d %-12d %-30s\n", fatec.codigo, fatec.nome,
                   fatec.idade, fatec.cpf, fatec.endereco);
        }
    }
    fclose(fptr);
}

void consultar()
{
    FILE *fptr;
    struct cliente fatec;

    fptr = fopen("cadastro", "rb");

    if(fptr == NULL)
    {
        printf("Aquivo nao existe");
        system("pause");
    }
    else
    {
        char nome_consulta[20];
        printf("Digite o nome que deseja ser consultado: ");
        fgets(nome_consulta, 20, stdin);
        nome_consulta[strcspn(nome_consulta, "\n")] = '\0'; //sem isso nao acha
        int encontrado = 0;

        while(fread(&fatec, sizeof(fatec),1,fptr))
        {
            if(strcmp(fatec.nome, nome_consulta) == 0)
            {
                encontrado = 1;
                printf("******** INFORMACOES DO CLIENTE ********");
                printf(" %-10s %-20s %-5s %-12s %-30s\n", "Codigo", "Nome", "Idade", "CPF", "Endereco");
                printf(" %-10d %-20s %-5d %-12d %-30s\n", fatec.codigo, fatec.nome,
                       fatec.idade, fatec.cpf, fatec.endereco);
                break;
            }
        }
        if(!encontrado)
        {
            printf("\n Cliente nao encontrado\n");
        }

        fclose(fptr);
        system("pause");
    }
}

void alterar()
{
    FILE *fptr;
    struct cliente fatec;

    fptr = fopen("cadastro", "rb+");

    if(fptr == NULL)
    {
        printf("Aquivo nao existe");
        system("pause");
    }
    else
    {
        char nome_consulta[20];
        char numstr[15];
        printf("Digite o nome que deseja ser consultado: ");
        fgets(nome_consulta, 20, stdin);
        nome_consulta[strcspn(nome_consulta, "\n")] = '\0';
        int encontrado = 0;
        while(fread(&fatec, sizeof(fatec),1,fptr))
        {
            if(strcmp(fatec.nome, nome_consulta) == 0)
            {
                encontrado = 1;
                printf("\n Diga o Nome do Cliente que deseja mudar: ");
                gets(fatec.nome);
                fflush(stdin);

                printf("\n Diga  a Idade do Cliente que deseja mudar: ");
                scanf("%d", &fatec.idade);
                fflush(stdin);

                printf("\n Diga  o Endereco do Cliente que deseja mudar: ");
                gets(fatec.endereco);
                fflush(stdin);

                printf("\n Diga  o Telefone do Cliente que deseja mudar: ");
                gets(numstr);
                fatec.telefone = atoi(numstr);

                printf("\n Diga  o CPF do Cliente que deseja mudar: ");
                gets(numstr);
                fatec.cpf = atoi(numstr);
                fflush(stdin);
                fseek(fptr, -sizeof(fatec), SEEK_CUR);
                fwrite(&fatec, sizeof(fatec), 1, fptr);
                break;
            }
        }
        if(!encontrado)
        {
            printf("Cliente nao encontrado");
        }
        fclose(fptr);
        system("pause");
    }
}

void remover()
{
    FILE *fptr, *temp;
    struct cliente fatec;
    char nome_consulta[20];
    int encontrado = 0;

    fptr = fopen("cadastro", "rb");
    temp = fopen("temp", "wb");

    if (fptr == NULL || temp == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    printf("Digite o nome do cliente que deseja remover: ");
    fgets(nome_consulta, 20, stdin);
    nome_consulta[strcspn(nome_consulta, "\n")] = '\0';

    while (fread(&fatec, sizeof(fatec), 1, fptr))
    {
        if (strcmp(fatec.nome, nome_consulta) == 0)
        {
            encontrado = 1;
            printf("Cliente removido com sucesso\n");
        }
        else
        {
            fwrite(&fatec, sizeof(fatec), 1, temp);
        }
    }

    fclose(fptr);
    fclose(temp);
    remove("cadastro");
    rename("temp", "cadastro");

    if (!encontrado)
    {
        printf("Cliente nao encontrado\n");
    }
}

int main()
{
    int op;
    do
    {
        system("cls");
        printf("\n *********** CADASTRO DE CLIENTE ***************");
        printf("\n ***********************************************");
        printf("\n           [1] - Inclusao de Registros          ");
        printf("\n           [2] - Relatorio                      ");
        printf("\n           [3] - Consulta                       ");
        printf("\n           [4] - Alteracao                      ");
        printf("\n           [5] - Remocao                        ");
        printf("\n           [6] - Sair                           ");
        printf("\n ***********************************************");
        printf("\n ********* Escolha a opcao desejada ************");
        printf("\n");
        scanf("%d", &op);
        fflush(stdin);

        switch (op)
        {
        case 1:
            incluir();
            break;
        case 2:
            relatorio();
            system("pause");
            break;
        case 3:
            consultar();
            break;
        case 4:
            alterar();
            break;
        case 5:
            remover();
            break;
        default:
            printf("\n Opcao Invalida .. tente novamente");
            system("pause");
        }
    }
    while (op != 6);

    return 0;
}

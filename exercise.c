#include <stdio.h>

// Variáveis globais
int vetor[100];  
int tamanho = 0;

// Funções
void definirTamanho() {
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    if (tamanho > 100 || tamanho <= 0) {
        printf("Tamanho de vetor inválido\n");
        tamanho = 0;
    }
}

void definirValores() {
    if(tamanho == 0){
        printf("Tamanho de valor invalido para se calcular");
        return;
    }
    printf("Digite o valores\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("\nDigite o valor da posicao %d: ", i);
        scanf("%d",&vetor[i]);
    }
}

void calcularVetor() {
    int soma = 0;
    for (int i = 0; i < tamanho; i++)
    {
        soma += vetor[i];

    }
    float media = (float)soma / tamanho;
    printf("A média dos valores no vetor é: %.2f\n", media);
    
}

int main() {
    int li_opcao;
    do{
    printf("----------- Media vetores -----------\n");
    printf("1 - Tamanho do vetor\n");
    printf("2 - Valores\n");
    printf("3 - Calcular média\n");
    printf("Digite qual opção voce deseja: ");
    scanf("%d", &li_opcao);
    fflush(stdin);

    switch (li_opcao) {
        case 1:
            definirTamanho();
            break;
        case 2:
            definirValores();
            break;
        case 3:
            calcularVetor();
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    }while (li_opcao != 0);

    return 0;
}

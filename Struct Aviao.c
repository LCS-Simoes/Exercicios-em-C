#include <stdlib.h>
#include <stdio.h>

struct Aviao
{
    char modelo[20];
    char fabricante[20];
    int passageiros;
    float altura;
    float comprimento;
    float velocidade;
    char motor[20];
};

int main(void)
{
    struct Aviao aviao;
    printf("Bem vindo ao cadastro de AVIOES\n");
    printf("Digite o modelo do aviao: ");
    scanf("%s",&aviao.modelo);
    printf("\n");
    printf("Digite o nome do Fabricante: ");
    scanf("%s",&aviao.fabricante);
    printf("\n");
    printf("Digite a quantidade de pasageiros: ");
    scanf("%d",&aviao.passageiros);
    printf("\n");
    printf("Digite a altura da aeronave considerada em metros: ");
    scanf("%f",&aviao.altura);
    printf("\n");
    printf("Digite o comprimento da aeronave considerada em metros: ");
    scanf("%f",&aviao.comprimento);
    printf("\n");
    printf("Digite o motor utilizado no aviao: ");
    scanf("%s",&aviao.motor);
    printf("\n");
    printf("Digite a velocidade maxima do aviao: ");
    scanf("%f",&aviao.velocidade);
    printf("\n");
    printf("--------------------------- DADOS CADASTRADOS ---------------------------\n");
    printf("Fabricante: %s  Comprimento: %s \n",aviao.fabricante,aviao.modelo);
    printf("Altura:%.2f Comprimento:%.2f\n",aviao.altura,aviao.comprimento);
    printf("Motor: %s Velocidade maxima em milhas: %.2f\n",aviao.motor,aviao.velocidade);
    printf("Limite de passageiros: %d",aviao.passageiros);
}


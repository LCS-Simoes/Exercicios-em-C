#include <stdio.h>

float precoUnitario;
float precoComunitario;
float imposto;
char refrigeracao;
char categoria;

int main(){
    printf("Digite o preco do seu produto: ");
    scanf("%f", &precoUnitario);
    if(precoUnitario <= 20){
        printf("Digite a categoria desse produto: ");
        scanf("%s", &categoria);
        if(categoria == 'A' || categoria == 'a'){
            precoComunitario = precoUnitario + 5;
        }else if(categoria == 'L' || categoria == 'l'){
            precoComunitario = precoUnitario + 10;
        }else if(categoria == 'V' || categoria == 'v'){
            precoComunitario = precoUnitario + 15;
        }else{
            printf("Opcao de categoria invalida");
            categoria = "";
        }
    }
    if(precoUnitario > 20 && precoUnitario <= 50){
        printf("Digite se seu produto e refrigerado ou nao: ");
        scanf("%s",&refrigeracao);
        if(refrigeracao == 'S' || refrigeracao == 's'){
            precoComunitario = precoUnitario + 21;
        }else if(refrigeracao == 'N' || refrigeracao == 'n'){
            precoComunitario = precoUnitario + 0;
        }else {
            printf("Opcao de refrieracao digitada incorretamente");
            refrigeracao = "";
        }
    }
    if(precoUnitario > 50){
        refrigeracao = 'S';
        printf("Digite a categoria desse produto: ");
        scanf("%s", &categoria);
        if(categoria == 'A' || categoria == 'a'){
            precoComunitario = precoUnitario + 6;
        }else if(categoria == 'L' || categoria == 'l'){
            precoComunitario = precoUnitario + 2;
        }else if(categoria == 'V' || categoria == 'v'){
            precoComunitario = precoUnitario + 4;
        }else{
            printf("Opcao de categoria invalida");
            categoria = "";
        }
    }
    printf("Produto com preco: %.2f \n De categoria: %c \n Refrigerado: %c\n", precoComunitario, categoria, refrigeracao);
    printf("Calculando imposto....\n");
    if(categoria == 'A' || categoria == 'a'){
        if(refrigeracao == 'S' || refrigeracao == 's'){
            imposto  = precoComunitario + (precoComunitario * 0.02);
        }
    }else{
        imposto =  precoComunitario + (precoComunitario * 0.04);
    }
    printf("Com impostto aplicado o produto passou a ser: %.2f", imposto);
}
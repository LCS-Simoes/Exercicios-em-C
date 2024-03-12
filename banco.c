#include <stdio.h>
#include <stdlib.h> 


//variaveis
int numConta;
double saldo;

//functions
void depositar(){
    double valor;
    printf("Digite o valor que deseja depositar\n");
    scanf("%lf", &valor);
    if(saldo < 0 ){
        printf("Impossivel depositar, sua conta esta negativada");
    }else{
        saldo += valor;
    }
}

void sacar(){
    double valor;
    printf("Digite o valor que deseja sacar: ");
    scanf("%lf",&valor);
    if(valor > saldo){
        printf("\nValor digitado e superior ao valor de saldo");
    }else{
        saldo -= valor;
        printf("\nFoi descontado do seu saldo: %lf", valor);
    }
}

void exibirSaldo(){
    printf("Seu saldo e de %lf \n", saldo);
}

int main(){
    int li_opcao;

    printf("----- BANCO NOT LIFE -----\n");
    
    do{
        printf("1 - Depositar\n");
        printf("2 - Saca\n");
        printf("3 - Exibir saldo\n");
        printf("Digite a opcao que deseja: ");
        scanf("%d",&li_opcao);
        switch (li_opcao)
        {
        case 1:
            depositar();
            break;
        case 2:
            sacar();
            break;
        case 3:
            exibirSaldo();
            break;
                
        default:
            break;
        }


    }while(li_opcao != 0);

    return 0;
}
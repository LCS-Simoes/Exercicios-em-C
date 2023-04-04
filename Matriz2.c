#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i,j,coluna_maior, linha_maior,linha_menor,coluna_menor,maior,menor;
    int matriz[4][4];
    srand(time(NULL));
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            matriz[i][j] = rand() %100;
        }
    }
    maior = matriz[0][0];
    menor = matriz[0][0];
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(matriz[i][j] > maior)
            {
                maior = matriz[i][j];
                linha_maior = i;
                coluna_maior = j;
            }
            if(matriz[i][j] < menor)
            {
                menor=matriz[i][j];
                linha_menor = i;
                coluna_menor = j;
            }
        }
    }
    printf("Matriz:\n");
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("Maior valor: %d,  na linha %d e coluna %d\n", maior, linha_maior, coluna_maior);
    printf("Menor valor: %d,  na linha %d e coluna %d\n", menor, linha_menor, coluna_menor);
}


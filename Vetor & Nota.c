#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i,j,maiornota,menornota, notamaior,notamenor;
    int matriz[5][3];
    srand(time(NULL));
    for(i=0; i<5; i++)
    {
        for(j=0; j<3; j++)
        {
            matriz[i][j] = rand() %11;
        }
    }
    printf("Pontuacao:\n");
    for (i = 0; i <5; i++)
    {
        printf("Atleta %d: ", i+1);
        for (j = 0; j <3; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    for (j = 0; j <3; j++) {
        maiornota = -1;
        for (i = 0; i < 5; i++) {
            if (matriz[i][j] > maiornota) {
                maiornota = matriz[i][j];
                notamaior = i;
            }
        }
        printf("Maior nota no aparelho %d: Atleta %d\n", j+1, notamaior+1);
    }
    for (i = 0; i < 5; i++) {
        menornota = 11;
        notamenor = 0;
        for (j = 0; j < 3; j++) {
            if (matriz[i][j] < menornota) {
                menornota = matriz[i][j];
                 notamenor = j;
        }
    }
    printf("Menor nota do Atleta %d: Aparelho %d\n", i+1, notamenor+1);
}



}

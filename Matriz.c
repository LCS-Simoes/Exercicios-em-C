#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, k, existe, tam;
    int vetorA[20], vetorB[20], interseccao[20];

    k = 0;
    srand(time(NULL));
    printf("Vetor A\n");
    for (i = 0; i < 20; i++)
    {
        vetorA[i] = rand() % 100;
        printf("%d ", vetorA[i]);
    }
    printf("\nVetor B\n");
    for (j = 0; j < 20; j++)
    {
        vetorB[j] = rand() % 100;
        printf("%d ", vetorB[j]);
    }

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            if (vetorA[i] == vetorB[j])
            {
                interseccao[k] = vetorA[i];
                existe = 1;
                k++;
            }
        }
        existe = 0;
    }

    tam = k;
    for (i = 0; i < tam; i++)
    {
        for (j = i + 1; j < tam; )
        {
            if (interseccao[j] == interseccao[i])
            {
                for (k = j; k < tam; k++)
                {
                    interseccao[k] = interseccao[k + 1];
                }
                tam--;
            }
            else
            {
                j++;
            }
        }
    }

    printf("\nIntersecao entre o vetor A e B:\n");
    for (i = 0; i < tam; i++)
    {
        printf("%d\n ", interseccao[i]);
    }
    printf("\n");
}

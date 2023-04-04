#include <stdio.h>
#include <stdlib.h>


void intercalacao(int vetorA[], int vetorB[], int vetorC[], int tamanho);
void bubble_sort(int vetor[], int tamanho);

int main(void)
{

    int i,j,k;
    int vetorA[5], vetorB[5], vetorC[10];
    srand(time(NULL));
    printf("Vetor A\n");
    for (i=0; i<5; i++)
    {
        vetorA[i] = rand() % 100;
        printf("%d ", vetorA[i]);
    }

    printf("\n\nVetor B:\n");
    for(j=0; j<5; j++)
    {
        vetorB[j] = rand() %100;
        printf("%d ", vetorB[j]);
    }

    bubble_sort(vetorA, 5);
    bubble_sort(vetorB, 5);
    intercalacao(vetorA, vetorB, vetorC, 5);
    printf("\n\nVetor C em ordem crescente \n");
    for (k = 0; k < 10; k++)
    {
        printf("%d ", vetorC[k]);
    }
    printf("\n");

    return 0;
}

void intercalacao(int vetorA[], int vetorB[], int vetorC[], int tamanho)
{
    int i = 0, j = 0, k = 0;

    while (i < tamanho && j < tamanho)
    {
        if (vetorA[i] < vetorB[j])
        {
            vetorC[k] = vetorA[i];
            i++;
        }
        else
        {
            vetorC[k] = vetorB[j];
            j++;
        }
        k++;
    }

    while (i < tamanho)
    {
        vetorC[k] = vetorA[i];
        i++;
        k++;
    }

    while (j < tamanho)
    {
        vetorC[k] = vetorB[j];
        j++;
        k++;
    }
}

void bubble_sort(int vetor[], int tamanho)
{
    int i, j, aux;

    for(i=0; i<tamanho-1; i++)
    {
        for(j=0; j<tamanho-1-i; j++)
        {
            if(vetor[j] > vetor[j+1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

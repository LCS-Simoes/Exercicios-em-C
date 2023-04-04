#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int vetor[10];
    int vetorpar[10], vetorimpar[10];
    int i, j=0, k=0;

    for(i=0 ; i < 10 ; i++){
        printf("Digite um numero:\n");
        scanf("%d", &vetor[i]);
    }

    for(i=0; i<10 ; i++){
        if(vetor[i] % 2 == 0) {
            vetorpar[j] = vetor[i];
            j++;
        } else {
            vetorimpar[k] = vetor[i];
            k++;
        }
    }

    printf("\nSao Impares\n");
    for(i=0; i<j; i++){
        printf("%d ", vetorpar[i]);
    }

    printf("\Sao Impares\n");
    for(i=0; i<k; i++){
        printf("%d ", vetorimpar[i]);
    }
}

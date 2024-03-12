#include <stdio.h>

#define N 5

int main() {
    int vetor1[N], vetor2[N], vetorResultado[N];
    int i;

    // Preenchendo os vetores
    printf("Digite %d numeros para o primeiro vetor:\n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &vetor1[i]);
    }

    printf("Digite %d numeros para o segundo vetor:\n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &vetor2[i]);
    }

    // Realizando a soma dos vetores
    for (i = 0; i < N; i++) {
        vetorResultado[i] = vetor1[i] + vetor2[i];
    }

    // Exibindo 
    printf("A soma dos elementos dos dois vetores e: \n");
    for (i = 0; i < N; i++) {
        printf("%d ", vetorResultado[i]);
    }
    printf("\n");

    return 0;
}

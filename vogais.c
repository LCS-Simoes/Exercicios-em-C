#include <stdio.h>
#include <stdlib.h>

char Vogais[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

int main(){
    char frases[50];
    printf("Digite uma frase: ");
    fgets(frases,sizeof(frases),stdin);

    int contador = 0;

    for (int i = 0; i < frases[i] != '\0'; i++)
    {
        for (int j = 0; j < sizeof(Vogais)/sizeof(Vogais[0]); j++)
        {
            if(frases[i] == Vogais[j]){
                contador++;
                break;
            }
        }
        
    }
    printf("Número de vogais na entrada: %d\n", contador);
    return 0;
}
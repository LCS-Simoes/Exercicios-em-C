#include <stdio.h>

int vetorIdade[8];
int vetorCodigo[8];
int vetorDisciplina[5];
int matriz[8][5];
int contadorAlunos;
int i,j;

int main ()
{
    contadorAlunos = 0;
    for(i=0; i<8; i++)
    {
        printf("Digite a idade do  aluno %d:", i+1);
        scanf("%d",&vetorIdade[i]);
        vetorCodigo[i] = i + 1;
    }

    for(j=0; j<5; j++)
    {
        printf("Digite o codigo da  disciplina %d:", j+1);
        scanf("%d",&vetorDisciplina[j]);
    }
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("Digite quantas provas o aluno %d participou na disciplina %d: ", i + 1, vetorDisciplina[j]);
            scanf("%d",&matriz[i][j]);
        }
    }

    for (i = 0; i < 8; i++)
    {
        if (vetorIdade[i] >= 18 && vetorIdade[i] <= 25)
        {
            int MaisDeDuasProvas = 0;
            for (j = 0; j < 5; j++)
            {
                if (matriz[i][j] > 2)
                {
                    MaisDeDuasProvas++;
                }
            }
            if (MaisDeDuasProvas > 1)
            {
                contadorAlunos++;
            }
        }
    }
    printf("Numero de alunos com idade entre 18 e 25 que participaram de mais de 2 provas em mais de uma disciplina: %d\n", contadorAlunos);

    int pesquisarCodigo;
    int infeliz = 0;
    printf("\nDigite o codigo do aluno: ");
    scanf("%d", &pesquisarCodigo);
    for(i = 0; i < 8; i++) {
        if(pesquisarCodigo == vetorCodigo[i]) {
            infeliz = 1;
            for(j = 0; j < 5; j++) {
                int pesquisarDisciplina;
                printf("Digite o codigo da materia: ");
                scanf("%d", &pesquisarDisciplina);

                if(pesquisarDisciplina == vetorDisciplina[j]) {
                    int quantidade = matriz[i][j];
                    printf("O aluno %d participou de %d provas na disciplina %d\n", pesquisarCodigo, quantidade, pesquisarDisciplina);
                }
            }
        }
    }

    if(!infeliz) {
        printf("Codigo do aluno invalido\n");
    }

    for (i = 0; i < 8; i++) {
        int fezMenosDeTresProvasEmTodas = 1;
        for (j = 0; j < 5; j++) {
            if (matriz[i][j] >= 3) {
                fezMenosDeTresProvasEmTodas = 0;
            }
        }
        if (fezMenosDeTresProvasEmTodas) {
            printf("O aluno %d fez menos de 3 provas em todas as disciplinas\n", vetorCodigo[i]);
        }
    }



    return 0;
}

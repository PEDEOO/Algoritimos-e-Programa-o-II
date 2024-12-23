// Aluno : Pedro da Silva Silveira; Prontuario: PE3030547
// Aluno : Eduardo de Oliveira Viana; Prontuario: PE3029387

#include <stdio.h>

void ler_n(float a[50], float b[50])
{
    int i, j;

    printf("----Notas Primeiro Bimestre---\n");
    for(i=0; i<50; i++)
    {
        printf("Aluno[%d]: ", i+1);
        scanf("%f", &a[i]);
    }
    printf("----Notas Segundo Bimestre----\n");
    for(j=0; j<50; j++)
    {
        printf("Aluno[%d]: ", j+1);
        scanf("%f", &b[j]);
    }
}

void media(float a[50],float b[50],float c[50])
{
    int i,j,k;

    for(i=0; i<50; i++)
    {
        c[i]=a[i];
    }
    for(j=0; i<50; j++)
    {
        c[i]=b[j];
    }

    printf("----Media dos alunos----\n");
    for(k=0; k<50; k++)
    {
        c[k]=(c[k] + c[k] )/ 2;
        printf("Aluno[%d]: %.2f\n", k+1, c[k]);
    }
}

void media_t(float c[50])
{
    float m;

    m = c[50] / 50;

    printf("\n");
    printf("A media da turma foi de: %.2f\n", m);
}

void aprovados(float c[50])
{
    int i;

    printf("\n----Alunos Reprovados----\n");
    for(i=0; i<50; i++)
    {
        if(c[i] >= 6)
        {
            printf("Aluno[%d]: Aprovado\n", i+1);
        }
        else
        {
            printf("Aluno[%d]: Reprovado\n", i+1);
        }
    }
}


void main()
{
    float a[50], b[50], c[50];

    ler_n(a, b);
    media(a,b,c);
    media_t(c);
    aprovados(c);
}

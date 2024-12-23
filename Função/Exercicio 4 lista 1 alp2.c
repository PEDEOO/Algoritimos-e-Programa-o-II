// Aluno : Pedro da Silva Silveira; Prontuario: PE3030547
// Aluno : Eduardo de Oliveira Viana; Prontuario: PE3029387

#include <stdio.h>

#define TF 100

void ler_pessoas(int *n, char genero[], float altura[])
{
    printf("Quantidade de pessoas (maximo de 100): ");
    scanf("%d", n);
    if (*n > TF)
    {
        *n = TF;
    }
    for (int i = 0; i < *n; i++)
    {
        printf("\nDigite seu genero (M/m = masculino, F/f = feminino): ");
        scanf(" %c", &genero[i]);
        printf("Digite sua altura: ");
        scanf("%f", &altura[i]);
    }
}

void menor_altura(int n, float altura[])
{
    float menor = altura[0];
    for (int i = 1; i < n; i++)
    {
        if (altura[i] < menor)
        {
            menor = altura[i];
        }
    }
    printf("A menor altura e: %.2f\n", menor);
}

void maior_altura(int n, float altura[])
{
    float maior = altura[0];
    for (int i = 1; i < n; i++)
    {
        if (altura[i] > maior)
        {
            maior = altura[i];
        }
    }
    printf("A maior altura e: %.2f\n", maior);
}

void media_altura_fem(int n, float altura[], char genero[])
{
    float somadasmulheres = 0;
    int contmulheres = 0;
    for (int i = 0; i < n; i++)
    {
        if (genero[i] == 'F' || genero[i] == 'f')
        {
            somadasmulheres += altura[i];
            contmulheres++;
        }
    }
    if (contmulheres > 0)
    {
        float mediadasfem = somadasmulheres / contmulheres;
        printf("A media de altura das mulheres e: %.2f\n", mediadasfem);
    }
    else
    {
        printf("Nao ha mulheres na amostra.\n");
    }
}

void media_geral(int n, float altura[])
{
    float somageral = 0;
    for (int i = 0; i < n; i++)
    {
        somageral += altura[i];
    }
    float mediageral = somageral / n;
    printf("A media geral de altura e: %.2f\n", mediageral);
}

void percentual_homens(int n, char genero[])
{
    int conthomens = 0;
    for (int i = 0; i < n; i++)
    {
        if (genero[i] == 'M' || genero[i] == 'm')
        {
            conthomens++;
        }
    }
    float percentual = (float)conthomens / n * 100;
    printf("O percentual de homens e: %.2f%%\n", percentual);
}

void  main()
{
    int n;
    char genero[TF];
    float altura[TF];

    ler_pessoas(&n, genero, altura);
    menor_altura(n, altura);
    maior_altura(n, altura);
    media_altura_fem(n, altura, genero);
    media_geral(n, altura);
    percentual_homens(n, genero);


}

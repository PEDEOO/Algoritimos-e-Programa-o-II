// Aluno: Pedro da Silva Silveira; Prontuario: PE3030547
// Aluno: João Otto Nagay Portaluppi ; Prontuario: PE3029891

#include <stdio.h>

void l_matriz(int n[10][10])
{
    int i, j;

    for(i = 0; i<10; i++)
    {
        printf("-----LINHA[%d]-----\n", i);
        for(j = 0; j<10; j++)
        {
            printf("[%d]: ", j);
            scanf("%d", &n[i][j]);
        }
    }
}

void soma_L(int n[10][10])
{
    int i, j;
    int somaL;
    printf("-----Soma das Linhas-----\n");
    for(i=0; i<10; i++)
    {
        somaL=0;

        for(j=0; j<10; j++)
        {
            somaL += n[i][j];
        }
        printf("Linha[%d]: %d\n", i, somaL);
    }
}

void soma_C(int n[10][10])
{
    int i, j;
    int somaC = 0;

     printf("-----Soma das Colunas-----\n");
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
        somaC += n[i][j];
        }

     printf("Coluna[%d]: %d\n", i, somaC);
    }

}

void apresent_LS(int n[10][10])
{
    int i, j;
    int soma;
    int LS = 0, MS = 0;

    for(i = 0; i<10; i++)
    {
        soma = 0;
        for(j=0; j<10; j++)
        {
            soma += n[i][j];

            if(i == 0 || soma > MS)
            {
            MS = soma;
            LS = i;
            }
        }
    }

    printf("A linha com a maior soma é a: %d\n", LS);
}

void apresent_LME(int n[10][10])
{
    int i, j;
    int m = n[0][0];
    int LM = 0;

    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            if(n[i][j] > m)
            {
                m = n[i][j];
                LM = i;
            }
        }
    }

    printf("Esta é a linha do maior elemento: %d\n", LM);
}

void apresent_CME(int n[10][10])
{
    int i, j;
    int CM = 0;
    int m = n[0][0];

    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            if(n[i][j] > m)
            {
                m = n[i][j];
                CM = j;
            }
        }
    }
    printf("Esta é a coluna do maior elemento: %d\n", CM);
}

void pos_ME(int n[10][10])
{
    int i, j;
    int ML = 0, MC = 0;
    int m = n[0][0];

    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            if(n[i][j] < m)
            {
                m = n[i][j];
                ML = i;
                MC = j;
            }
        }
    }
    printf("Esta é a posicao do menor elemento: Linha: %d, Coluna: %d\n", ML, MC);
}

void main()
{
    int n[10][10];

    l_matriz(n);
    soma_L(n);
    soma_C(n);
    apresent_LS(n);
    apresent_LME(n);
    apresent_CME(n);
    pos_ME(n);

}


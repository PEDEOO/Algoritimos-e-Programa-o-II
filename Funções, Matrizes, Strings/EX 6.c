#include <stdio.h>
#include <stdlib.h>

// Aluno: Pedro da Silva Silveira; Prontuario: PE3030547
// Aluno: João Otto Nagay Portaluppi ; Prontuario: PE3029891

void zerar_matriz(int matriz[10][10])
{
    int i, j;
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            matriz[i][j] = 0;
        }
    }
}
void inserir_matriz(int matriz[10][10])
{
    int i;
    for(i=0; i<20; i++)
    {
        int linha = rand() % 10;
        int coluna = rand() % 10;
        matriz[linha][coluna] = 2 + rand() % 20;

    }
}
void exibirMatriz(int matriz[10][10])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            printf("| %d | ", matriz[i][j]);
        printf("\n");
    }
}


void atirarJeM(int matriz[10][10], int *pontosUsuario, int *pontosRobo)
{

    int linha, coluna;
    for (int i = 0; i < 5; i++)
    {
        printf("Escolha a linha e coluna para atirar (0-9) : ");
        scanf("%d %d", &linha, &coluna);
        if(matriz[linha][coluna] == 0)
        {
            printf("Voce errou!\n");
        }
        else
        {
            printf("\nVoce acertou! Acaba de ganhar %d pontos\n", matriz[linha][coluna]);
            *pontosUsuario += matriz[linha][coluna];
              matriz[linha][coluna] = 0;

        }

        linha = rand() % 10;
        coluna = rand() % 10;

        printf("O computador escolheu a posicao: (%d, %d)\n", linha, coluna);
        if (matriz[linha][coluna] == 0)
        {
            printf("Ele errou\n");
        }
        else {
            printf("\nEle acertou! %d pontos para ele\n", matriz[linha][coluna]);
            *pontosRobo += matriz[linha][coluna];
            matriz[linha][coluna] = 0;

        }

    }

}

void contarPontos(int matriz[10][10], int pontosRobo, int pontosUsuario)
{
    if(pontosRobo > pontosUsuario)
    {
        printf("O computador foi o vencedor: %d a %d\n", pontosRobo, pontosUsuario);


    }
    else
    {
        printf("Voce foi o vencedor: %d a %d pontos\n", pontosUsuario, pontosRobo);

    }



}

int main()
{
    srand(time(NULL));
    char teste;
    int matriz[10][10];
    int i, posLin, posCol;
    int pontosUsuario = 0, pontosRobo = 0;


    zerar_matriz(matriz);
    inserir_matriz(matriz);
    exibirMatriz(matriz);
    atirarJeM(matriz, &pontosUsuario, &pontosRobo);
    contarPontos(matriz, pontosRobo, pontosUsuario);

    return 0;
}



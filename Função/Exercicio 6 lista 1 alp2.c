// Aluno : Pedro da Silva Silveira; Prontuario: PE3030547
// Aluno : Eduardo de Oliveira Viana; Prontuario: PE3029387

#include <stdio.h>
#define MAX_ALUNOS 50

void main()
{
    executar_programa();
}

void adicionar_prontuario(int prontuarios[], int TL)
{
    for(int i = 0; i < TL; i++)
    {
        int pront = -1;
        printf("\nDigite o valor do prontuario do %dº aluno: ", i + 1);
        while(pront <= 0)
        {
            scanf("%d", &pront);
        }
        prontuarios[i] = pront;
    }
}

void procurar_prontuario(int prontuarios[], int tam, int pront)
{
    int encontrado = -1;
    for(int i = 0; i < tam; i++)
    {
        if(prontuarios[i] == pront)
        {
            encontrado = i;
            break;
        }
    }
    if(encontrado != -1)
    {
        printf("O prontuario %d foi encontrado na lista na posicao: %d\n", pront, encontrado);
    }
    else
    {
        printf("Prontuario nao encontrado\n");
    }
}

void primeirasPosProntuario(int prontuarios[], int tam, int x)
{
    if (x <= tam)
    {
        for(int i = 0; i < x; i++)
        {
            printf("\nProntuario beneficiado %d: %d", i + 1, prontuarios[i]);
        }
    }
    else
    {
        printf("\nO numero excede o limite");
    }
}

void mostrarArray(int arr[], int t)
{
    for(int i = 0; i < t; i++)
    {
        printf("\n%dº prontuario: %d", i, arr[i]);
    }
}

void executar_programa()
{
    int tl = 0;
    while(tl > 50 || tl < 1)
    {
        printf("Digite a quantidade total de prontuarios: ");
        scanf("%d", &tl);
    }

    int prontuarios[tl];
    adicionar_prontuario(prontuarios, tl);

    int prontuario;
    printf("Digite o prontuario que voce deseja procurar: ");
    scanf("%d", &prontuario);
    procurar_prontuario(prontuarios, tl, prontuario);

    int beneficiados;
    printf("\nDigite o numero de beneficiados: ");
    scanf("%d", &beneficiados);
    primeirasPosProntuario(prontuarios, tl, beneficiados);

    printf("\n");
    mostrarArray(prontuarios, tl);
}

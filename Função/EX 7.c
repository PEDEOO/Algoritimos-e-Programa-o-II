// Aluno : Pedro da Silva Silveira; Prontuario: PE3030547
// Aluno : Eduardo de Oliveira Viana; Prontuario: PE3029387

#include <stdio.h>

int menu(int op)
{
    printf("-----Menu de Interacoes-----\n");
    printf("1. Ler dois vetores inteiros a e b, com 5 elementos.\n");
    printf("2. Colocar os elementos dos dois vetores a e b, em um terceiro vetor c com tamanho de 10 elementos.\n");
    printf("3. Imprimir qual dos dois (a e b) tem a maior soma de elementos.\n");
    printf("4. Multiplicar os elementos do vetor c \n");
    printf("5. Trocar os elementos entre os vetores a e b.\n");
    printf("6. Apresentar os elementos dos vetores a e b.\n");
    printf("0. Para encerrar o programa\n");
    printf("Insira a opcao..:");
    scanf("%d", &op);

    return op;

}
void ler_v(int a[5], int b[5])
{

    int i, j;

    printf("Vetor A\n");
    for(i = 0 ; i<5; i++)
    {
        printf("[%d]: ", i+1);
        scanf("%d", &a[i]);
    }

    printf("\nVetor B\n");
    for(j = 0; j<5; j++)
    {
        printf("[%d]: ", j+1);
        scanf("%d", &b[j]);

    }
}

void unico_v(int a[5], int b[5],int c[10])
{
    int k, i, j;
    for(i=0; i<5; i++)
    {
        c[i]=a[i];
    }

    for(k=0; k<5; k++, i++)
    {
        c[i]= b[k];
    }

    printf("\n-----Juncao dos vetores-----\n");
    for(j=0; j<5+5; j++)
    {
        printf("[%d]: %d\n", j+1,c[j]);
    }
}

void somar_vetores(int a[5],int b[5])
{
    int i,j;
    int soma1 = 0, soma2 = 0;

    for(i=0; i<5; i++)
    {
        soma1+= a[i];
    }

    for(j=0; j<5; j++)
    {
        soma2+= b[j];
    }

    if(soma1 > soma2)
    {
        printf("\nO Vetor A e o maior\n");
    }
    else if(soma2 > soma1)
    {
        printf("\nO Vetor B e o maior\n");
    }

}

multiplicar(int c[10], int num)
{
    int i, j, mult;

    for(i=0; i<10; i++)
    {
        c[i] = c[i] * num;
    }

    printf("-----Vetor Multiplicado-----\n");
    for(j=0; j<10; j++)
    {
        printf("[%d]: %d\n", j+1, c[j]);
    }

}

void troc_elem(int a[5], int b[5])
{
    int i, j;

    for(i=0; i<5; i++)
    {
        j = a[i];
        a[i] = b[i];
        b[i] = j;
    }

}

void apresent(int a[5], int b[5])
{
    int i, j;

    printf("\n-----Elementos do Vetor A-----\n");
    for(i=0; i<5; i++)
    {
        printf("[%d]: %d\n", i+1, a[i]);
    }

    printf("\n-----Elementos do Vetor B-----\n");
    for(j=0; j<5; j++)
    {
        printf("[%d]: %d\n", j+1, b[j]);
    }
}

void main()
{

    int a[5], b[5], c[10], i, num, op;


    do
    {

        op = menu(op);
        switch(op)
        {
        case 1:
            ler_v(a,b);
            break;

        case 2:
            unico_v(a,b,c);
            break;

        case 3:
            somar_vetores(a,b);
            break;

        case 4:
            printf("Insira o valor a ser multiplicado..:");
            scanf("%d", &num);
            multiplicar(c, num);
            break;

        case 5:
            troc_elem(a,b);
            break;

        case 6:
            apresent(a,b);
            break;

        default:
            break;
        }
    }
    while(op!=0);
}

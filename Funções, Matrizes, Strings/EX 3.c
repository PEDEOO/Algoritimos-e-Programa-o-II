// Aluno: Pedro da Silva Silveira; Prontuario: PE3030547
// Aluno: João Otto Nagay Portaluppi ; Prontuario: PE3029891

#include <stdio.h>
#include <string.h>

void ler_nome(char nome[3][50])
{
    int i;

    for(i=0; i<3; i++)
    {
        printf("Insira o nome do aluno[%d]..:", i+1);
        gets(nome[i]);
    }
}

void imprimir(char nome[3][50])
{
    char temp[50];

    for (int i = 0; i < 2; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {

            if (strcmp(nome[i], nome[j]) > 0)
            {
                strcpy(temp, nome[i]);
                strcpy(nome[i], nome[j]);
                strcpy(nome[j], temp);
            }
        }
    }

    printf("\nNomes em ordem alfabetica:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", nome[i]);
    }
}

void main()
{
    char nome[3][50];

    ler_nome(nome);
    imprimir(nome);

}

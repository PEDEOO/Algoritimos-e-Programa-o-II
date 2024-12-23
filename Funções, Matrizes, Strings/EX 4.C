#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Aluno: Pedro da Silva Silveira; Prontuario: PE3030547
// Aluno: João Otto Nagay Portaluppi ; Prontuario: PE3029891

void ler_informacoes(char sobrenome[], char nome[], char titulo[], char editora[], char cidade[], char anos[])
{
    printf("Digite o nome:  ");
    gets(nome);
    nome[0] = toupper(nome[0]);

    printf("Digite o sobrenome:  ");
    gets(sobrenome);
    for (int i = 0; i < strlen(sobrenome); i++)
    {
        sobrenome[i] = toupper(sobrenome[i]);
    }

    printf("Digite o titulo:  ");
    gets(titulo);
    titulo[0] = toupper(titulo[0]);

    printf("Digite o editora:  ");
    gets(editora);
    editora[0] = toupper(editora[0]);

    printf("Digite o cidade:  ");
    gets(cidade);
    cidade[0] = toupper(cidade[0]);
    printf("Digite o ano:  ");
    gets(anos);




}

void printar(char abnt[],char nome[],char sobrenome[],char titulo[],char editora[],char cidade[],char anos[])
{

    strcpy(abnt, sobrenome);
    strcat(abnt, ", ");
    strcat(abnt, nome);
    strcat(abnt, ". ");
    strcat(abnt, titulo);
    strcat(abnt, ". ");
    strcat(abnt, editora);
    strcat(abnt, ": ");
    strcat(abnt, cidade);
    strcat(abnt, ", ");
    strcat(abnt, anos);
    strcat(abnt, ".");




}



int main()
{
    char sobrenome[100];
    char nome[80];
    char titulo[90];
    char editora[90];
    char cidade[100];
    char abnt[150];
    char anos[10];

    ler_informacoes(sobrenome, nome, titulo, editora, cidade, anos);

    printar(abnt, nome, sobrenome, titulo, editora, cidade, anos);

    printf("%s\n", abnt);


    return 0;
}



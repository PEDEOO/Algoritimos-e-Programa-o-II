#include <stdio.h>

// Aluno: Pedro da Silva Silveira; Prontuario: PE3030547
// Aluno: João Otto Nagay Portaluppi ; Prontuario: PE3029891
void trocarC(char str[], char antigo, char novo)
{

    int i;
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == antigo)
        {
            str[i] = novo;
        }

    }
}

void trocarS(char str1[], char str2[])
{
    int i;
    char aux;
    for (i = 0; str1[i] != '\0' || str2[i] != '\0'; i++)
    {

        if(str1[i] != '\0' && str2[i] != '\0')
        {
            aux = str1[i];
            str1[i] = str2[i];
            str2[i] = aux;
        }
        else if(str1[i] != '\0')
        {

             str2[i] = str1[i];
            str1[i] = '\0';
        }
        else if(str2[i] != '\0')
        {
            str1[i] = str2[i];
            str2[i] = '\0';

        }

    }

}

void converterMaiuscula(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - ('a' - 'A');
        }
    }


}
void converterMinuscula(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] - ('A' - 'a');
        }
    }
}


void retirarNumeros(char str[])
{
    int i, j;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')
        {
            for (j = i; str[j] != '\0'; j++)
            {
                str[j] = str[j + 1];
            }
            i--;
        }
    }



}

void separar_letras(char str[], char maiusculas[], char minusculas[])
{
    int i, j = 0, k = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            maiusculas[j] = str[i];
            j++;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            minusculas[k] = str[i];
            k++;
        }
    }
    maiusculas[j] = '\0';
    minusculas[k] = '\0';




}


int main()
{

    int opcao;
    char str1[100];
    char str[100];
    char str2[100];
    char antigo, novo;
    char maiusculas[100], minusculas[100];

    do
    {
        printf("\ --------------------- \n");
        printf("1. Trocar caractere por outro \n");
        printf("2. Trocar conteudo das strings \n");
        printf("3. Converter string para maiusculo\n");
        printf("4. Converter string para minusculo\n");
        printf("5. Retirar numeros da string\n");
        printf("6. Separar maiusculas e minusculas\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();



        switch (opcao) {
        case 1:
        {
             printf("Digite uma string: ");
                fgets(str, sizeof(str), stdin);
                printf("Digite o caractere a ser trocado: ");
                scanf(" %c", &antigo);
                printf("Digite o novo caractere: ");
                scanf(" %c", &novo);
                trocarC(str, antigo, novo);
                printf("String apos troca: %s", str);
                break;

        }
        case 2:
        {
            printf("\n-------------------------\n");

            printf("Digite a primeira string: ");
            getchar();
            fgets(str1, sizeof(str1), stdin);

            printf("Digite a segunda string: ");
            getchar();
            fgets(str2, sizeof(str2), stdin);

            trocarS(str1, str2);

            printf("Apos a troca: \n");
            printf("String 1: %s", str1);
            printf("String 2: %s", str2);
            break;
        }
        case 3:
        {
            printf("Digite a string a ser convertida em maiuscula: ");
            fgets(str, sizeof(str), stdin);

            converterMaiuscula(str);

            printf("String em maiusculas: %s", str);
            break;
        }
        case 4:
        {
            printf("Digite a string a ser convertida em minuscula: ");
            fgets(str, sizeof(str), stdin);

            converterMinuscula(str);

            printf("String em minuscula: %s", str);
            break;
        }

        case 5:
        {

            printf("Digite a string a se retirar os numeros: ");
            fgets(str, sizeof(str), stdin);

            retirarNumeros(str);
            printf("String sem numeros: %s", str);
            break;
        }
        case 6:
        {

            printf("Digite a string a ser separada em maiusculas e minusculas: ");
            fgets(str, sizeof(str), stdin);

            separar_letras(str, maiusculas, minusculas);
            printf("Maiusculas: %s\n", maiusculas);
            printf("Minusculas: %s\n", minusculas);
            break;

        }
        case 7: {
            printf("Saindo...\n");
            break;
        }
        default:
        printf("Opcao invalida! Tente novamente.\n");

    }
        } while(opcao!=7);




        return 0;

}

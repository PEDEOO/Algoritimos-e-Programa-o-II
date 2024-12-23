// Aluno: Pedro da Silva Silveira; Prontuario: PE3030547
// Aluno: João Otto Nagay Portaluppi ; Prontuario: PE3029891

#include <stdio.h>
#include <string.h>

int ler_nome(char n[50][50], int tl)
{
    int i, j;

    printf("Insira a quantidade de alunos..: ");
    scanf("%d", &tl);
    fflush(stdin);

    for(i=0; i<tl; i++)
    {
        printf("Aluno[%d]: ", i+1);
        gets(n[i]);
    }

    return tl;
}

int menu(char op)
{
    do{
    printf("\n----Menu----\n");
    printf("A. Determinar a quantidade de pessoas que os nomes iniciam com uma determinada letra.\n");
    printf("B. Determinar a posição na lista de um determinado nome.\n");
    printf("C. Localizar a quantidade de ocorrência de uma determinada letra.\n");
    printf("D. Apresentar todos os nomes iniciados com uma determinada string.\n");
    printf("E. A posição da pessoa que possui o maior nome.\n");
    printf("F. Apresentar apenas os primeiros nomes das pessoas da lista.\n");
    printf("G. Apresentar apenas o sobrenome das pessoas da lista.\n");
    printf("H. Apresentar a pessoa que possui mais palavras em seu nome.\n");
    printf("I. Encerrar programa.\n");
    scanf(" %c", &op);
    fflush(stdin);
    return op;
    }while(op != 'A','B','C','D','E','F','G','H','I' );


}

void determinar_pessoas_que_comecam_com_mesma_letra(char n[50][50], int tl)
{
    int i, cont = 0;
    char letra;

    printf("Insira a letra que deseja achar..:");
    scanf("%c", &letra);

    for(i=0; i<tl; i++)
    {
        if(n[i][0]== letra)
        {
            cont++;
        }
    }

    printf("Existem um total de %d pessoas que iniciam com a letra %c.\n", cont, letra);
}

void determinar_posicao_pessoa(char n[50][50], int tl)
{
    int i;
    char N[50];

    printf("Qual nome gostaria de procurar: ");
    fgets(N, 50, stdin);
    N[strcspn(N, "\n")] = '\0';  // Remove a nova linha capturada

    for(i = 0; i < tl; i++)
    {
        if(strcmp(n[i], N) == 0)
        {
            printf("Posição[%d]: %s\n", i+1, n[i]);
            return;
        }
    }
}

void ocorrencia_de_uma_letra(char n[50][50], int tl)
{
    int cont = 0, i, j;
    char letra;

    printf("Insira a letra que desja verificar a ocorrencia..: ");
    scanf(" %c", &letra);

    for(i=0; i<tl; i++)
    {
        for(j=0; j<50; j++)
        {
            if(n[i][j] == letra)
            {
                cont++;
            }
        }

    }

    printf("O numero de ocorrencia da letra '%c' e de %d vezes.\n", letra, cont);
}

void pessoas_cmesmo_nome(char n[50][50], int tl)
{
    int i, j, tam;
    char nome[50];

    printf("Insira o nome que quer procurar..: ");
    scanf("%s", nome);

    tam = strlen(nome);

    for(i=0; i<tl; i++)
    {
        if(strncmp(n[i], nome, tam)== 0)
        {
            printf("Aluno[%d]: %s\n",i+1, n[i]);
        }
    }

}

void posicao_maior_nome(char n[50][50], int tl)
{
    int i, j;
    int m = 0, pos = 0;

    for(i=0; i<tl; i++)
    {
        if(strlen(n[i]) > m)
        {
            m = strlen(n[i]);
            pos = i;
        }
    }
    printf("O maior nome esta na posicao %d.\n", pos+1);
}

void primeiro_nome(char n[50][50], int tl, char nome[50])
{
    int i, j;

    printf("\n----Nomes----\n");
    for(i = 0; i < tl; i++)
    {
        nome[50];
        j = 0;


        while(n[i][j] != ' ' && n[i][j] != '\0')
        {
            nome[j] = n[i][j];
            j++;
        }
        nome[j] = '\0';

        printf("Primeiro nome do aluno[%d]: %s\n", i+1, nome);
    }
}

void apresentar_sobrenome(char n[50][50], int tl, char nome[50])
{
    int i, j, tam;

    printf("\n----Sobrenomes----\n");
    for (i = 0; i < tl; i++)
    {
        tam = strlen(n[i]);
        j = tam - 1;

        while (j >= 0 && n[i][j] != ' ')
        {
            j--;
        }
        if (j >= 0)
        {
            printf("Sobrenome do aluno[%d]: %s\n", i+1, &n[i][j+1]);
        }
        else
        {
            printf("Aluno[%d] nao possui sobrenome: %s\n", i+1, n[i]);
        }
    }
}

void pessoa_com_mais_palavras(char n[50][50], int tl)
{
    int i, j;
    int max_palavras = 0;
    int pessoa_max = 0;
    int tam, palavras;


    for (i = 0; i < tl; i++)
    {
        palavras = 0;
        tam = strlen(n[i]);

        if (n[i][0] != ' ')
        {
            palavras = 1;
        }

        for (j = 0; j < tam; j++)
        {
            if (n[i][j] == ' ' && n[i][j+1] != ' ' && n[i][j+1] != '\0')
            {
                palavras++;
            }
        }
        if (palavras > max_palavras)
        {
            max_palavras = palavras;
            pessoa_max = i;
        }
    }
    printf("Pessoa com mais palavras no nome: %s\n", n[pessoa_max]);
    printf("Numero de palavras: %d\n", max_palavras);
}

void main()
{
    char n[50][50], nome[50], op;
    int tl = 0;

    tl = ler_nome(n, tl);

    do
    {
        op = menu(op);

        switch(op)
        {
        case 'A':
            determinar_pessoas_que_comecam_com_mesma_letra(n, tl);
            break;

        case 'B':
            determinar_posicao_pessoa(n, tl);
            break;

        case 'C':
            ocorrencia_de_uma_letra(n, tl);
            break;

        case 'D':
            pessoas_cmesmo_nome(n, tl);
            break;

        case  'E':
            posicao_maior_nome(n, tl);
            break;

        case 'F':
            primeiro_nome(n,tl, nome);
            break;

        case 'G':
            apresentar_sobrenome(n, tl, nome);
            break;

        case 'H':
            pessoa_com_mais_palavras(n, tl);
            break;

        case 'I':
            break;
        }
    }while(op != 'I');
}

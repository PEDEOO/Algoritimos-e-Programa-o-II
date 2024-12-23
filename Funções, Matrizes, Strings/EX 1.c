// Aluno: Pedro da Silva Silveira; Prontuario: PE3030547
// Aluno: João Otto Nagay Portaluppi ; Prontuario: PE3029891

#include <stdio.h>
#define TF 1000

int opcao(int op)
{
    do{
    printf("A. Excluir um caracter de uma determinada posição de uma string.\n");
    printf("B. Incluir um caracter em uma determinada posição de uma string.\n");
    printf("C. Copiar uma parte de uma string para dentro de outra.\n");
    printf("D. Copiar a última palavra de uma string para outra string.\n");
    printf("E. Copiar a primeira palavra de uma string para outra.\n");
    printf("F. Retirar os espaços em branco repetidos de uma string.\n");
    printf("G. Retirar os espaços em branco do final de uma string.\n");
    printf("H. Retirar os espaços em branco do início de uma string.\n");
    printf("I. Copiar o conteúdo de uma string para outra.\n");
    printf("J. Apagar o conteúdo de uma string.\n");
    printf("K. Mostrar a string.\n");
    printf("L. Encerrar programa.\n");
    scanf(" %c", &op);
    return op;
    }while(op != 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L');
}

int ler_string(char string[], int tl)
{
    int i=0;

    printf("Insira a string..: ");
    scanf("%c", &string[i]);
    while(string[i] != 10)
    {
        i++;
        scanf("%c", &string[i]);
    }
    tl = i;
    string[i]='\0';
    return tl;
}

void ex_c(char string[], int pos)
{

    int i;

    for(i=pos; i<TF; i++)
    {
        string[i] = string[i+1];
    }
}

void incluir_carac(char string[], int *tl, int pos, char el)
{
    int i;

    for(i = tl - 1; i > pos; i--)
    {
        string[i] = string[i - 1];
    }
    string[pos] = el;
    (*tl)++;
    string[*tl] = '\n';
}

void copiar_p(char string[], int pi, int pf, char sp[])
{
    int i, j;


    for(i= pi - 1; i< pf; i++)
    {
        sp[i] = string[i];
    }

    for(j=0; j<i; j++)
    {
        printf("%c", sp[i]);
    }

}

void copiar_up(char string[], char cup[], int tl)
{
    int i=tl;
    int j=0;

    while(string[i] != ' ')
    {
        i--;
    }

    for(i; i<tl; i++)
    {
        cup[j] = string[i+1];
        j++;
    }
}

void copiar_pp(char string[],char cpp[])
{
    int i=0;
    int j=0;

    while(string[i] != ' ')
    {
        cpp[j] = string[i];
        j++;
        i++;
    }
}

void r_espacos(char string[], int *tl)
{
    int i, j;

    for(i = 0; i<tl; i++)
    {
        if(string[i] == ' ' && string[i-1] == ' ')
        {
            for(j=i; j<tl; j++)
            {
                string[j]= string[j+1];
            }
            i--;
            (*tl)--;
        }
    }
}

void r_espacosF(char string[], int *tl)
{
    int i = *tl - 1;

    while( i >= 0 &&string[i] == ' ')
    {
        i--;
    }

    string[i+1] = '\0';
    *tl = i + 1;
}

void r_espacosI(char string[], int *tl)
{
    int i=0;
    int j=0;

    while(string[i] == ' ')
    {
        i++;
    }
    while(string[i] != '\0')
    {
        string[j++] = string[i++];
    }
    string[j]= '\0';
    *tl = j;
}

void cop(char string[], char copia[])
{
    int i = 0;

    while(string[i] != '\0')
    {
        copia[i]=string[i];
        i++;
    }
    copia[i] = '\0';
}

void apag(char string[])
{
    string[0] = '\0';
}

void main()
{
    char op,string[TF], sp[TF], cup[TF], cpp[TF], copia[TF], el;
    int pos, pi = 0, pf = 0, tl = 0;


    tl = ler_string(string, tl);


    do
    {
        op = opcao(op);
        switch(op)
        {
        case 'A':
            printf("Insira a posicao a ser excluida..: ");
            scanf("%d", &pos);
            ex_c(string, pos);
            break;
        case 'B':
            printf("Insira o caracter a ser inserido..: ");
            scanf(" %c", &el);
            printf("Insira a posicao a ser incluida..: ");
            scanf("%d", &pos);
            incluir_carac(string, &tl, pos, el);
            break;

        case 'C':
            printf("Insira a primeira parte a ser copiada..: ");
            scanf("%d", &pi);
            printf("Insira a ultima parte a ser copiada..:");
            scanf("%d", &pf);
            copiar_p(string, pi, pf, sp);
            printf("String copiada: ");
            puts(sp);
            break;

        case 'D':
            copiar_up(string, cup, tl);
            printf("Ultima palavra copiasa: ");
            puts(cup);
            break;

        case 'E':
            copiar_pp(string, cpp);
            printf("Primeira palavra copiada: ");
            puts(cpp);
            break;

        case 'F':
            r_espacos(string, &tl);
            break;

        case 'G':
            r_espacosF(string, &tl);
            break;

        case 'H':
            r_espacosI(string, &tl);
            break;

        case 'I':
            cop(string, copia);
            printf("String copiada: ");
            puts(copia);
            break;

        case 'J':
            apag(string);
            break;

        case 'K':
            printf("\n");
            printf("String..: ");
            puts(string);
            break;
        }

    }
    while(op != 'L');
}

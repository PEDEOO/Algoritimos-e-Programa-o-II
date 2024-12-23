// Aluno : Pedro da Silva Silveira; Prontuario: PE3030547
// Aluno : Eduardo de Oliveira Viana; Prontuario: PE3029387

#include <stdio.h>
#define TF 50

int menu(int op)
{
    printf("----Menu----\n");
    printf("1. Excluir determinado caracter do vetor em determinada posicao.\n");
    printf("2. Incluir um caracter em determinada posicao.\n");
    printf("3. Copiar uma parte para um vetor.\n");
    printf("4. Copiar a primeira palavra para outro vetor.\n");
    printf("5. Copiar a ultima palavra para outro vetor.\n");
    printf("6. Retirar os espacos em brancos repetidos.\n");
    printf("7. Contar a quantidade de palavras.\n");
    printf("8. Contar a quantidade de vogais.\n");
    printf("9. Mostrar o vetor.\n");
    printf("0. Encerrar o programa.\n");
    printf("Insira a sua opcao..: ");
    scanf("%d", &op);

    return op;
}

int escrever_c(char V[])
{
    char carac = '-';
    int tl = 0;

    printf("Insira os caracteres..: ");
    do
    {
        scanf("%c", &carac);
        if (carac != 10)
        {
            V[tl] = carac;
            tl++;
        }
    }
    while (carac != 10);

    return tl;
}

void excluir_c(char V[], int *tl)
{
    int i, pos;
    (*tl)--;

    printf("Insira a posição que ira ser excluida..: ");
    scanf("%d", &pos);
    for(i = pos - 1; i < *tl; i++)
    {
        V[i] = V[i+1];
    }
}

void incluir(char V[], int *tl)
{
    int pos, i;
    char el;
    (*tl)++;

    printf("Insira o elemento a ser inserido..: ");
    scanf(" %c", &el);

    printf("Insira a posicao que sera inserido..: ");
    scanf("%d", &pos);
    for(i = *tl-1; i > pos; i--)
    {
        V[i] = V[i-1];
    }
    V[pos] = el;
}

void copiar_v(char vp[], char V[], int *tlp)
{
    int i, pi, pf;

    printf("Insira o posicao inicial..: ");
    scanf("%d", &pi);

    printf("Insira a posicao final..: ");
    scanf("%d", &pf);

    for(i = pi - 1; i <= pf - 1; i++)
    {
        vp[*tlp] = V[i];
        (*tlp)++;
    }
}

void copiar_up(char V[], int tl, char up[], int *tlpu)
{
    int i;
    int pos = tl;

    while(pos > 0 && V[pos-1] != ' ')
        pos--;

    for(i = pos; i < tl; i++)
    {
        up[*tlpu] = V[i];
        (*tlpu)++;
    }
}

void copiar_pp(char V[], char pp[], int *tlpp, int vsize)
{
    int i = 0;

    while (V[i] != ' ' && i < vsize)
    {
        pp[*tlpp] = V[i];
        (*tlpp)++;
        i++;
    }
}

void r_espacos(char V[], int *tl)
{
    int i, j;

    for(i = 0; i < *tl; i++)
    {
        if(V[i] == ' ' && V[i-1] == ' ')
        {
            (*tl)--;
            for(j = i; j < *tl; j++)
            {
                V[j] = V[j+1];
            }
            i--;
        }
    }
}

void cont_p(char V[], int tl, int palavra)
{
    int i;

    if(V[0] != ' ')
    {
        palavra++;
    }

    for(i = 0; i < tl; i++)
    {
        if(V[i] == ' ' && V[i+1] != ' ')
        {
            palavra++;
        }
    }

    printf("O numero de palavras dentro do vetor é de: %d\n", palavra);
}

void cont_vogal(char V[], int tl, int vogal)
{
    int i;

    for(i = 0; i < tl; i++)
    {
        if(V[i] == 'a' || V[i] == 'A' ||
                V[i] == 'e' || V[i] == 'E' ||
                V[i] == 'i' || V[i] == 'I' ||
                V[i] == 'o' || V[i] == 'O' ||
                V[i] == 'u' || V[i] == 'U')
        {
            vogal++;
        }
    }

    printf("O numero de vogais dentro do vetor é de: %d\n", vogal);
}

void mostrar_v(char V[], int tl)
{
    int i;
    for(i = 0; i < tl; i++)
    {
        printf("%c", V[i]);
    }
    printf("\n");
}

void main()
{

    char V[TF], pp[TF], up[TF],vp[TF];
    int tl = 0, pos, tlp = 0, tlpp = 0, tlpu = 0, palavra = 0, vogal = 0, op;

    tl = escrever_c(V);


    do
    {

        op = menu(op);

        switch(op)
        {

        case 1:
            excluir_c(V,&tl);
            break;

        case 2:
            incluir(V, &tl);
            break;

        case 3:
            copiar_v(vp, V, &tlp);
            printf("\nA parte copiada do vetor..: ");
            mostrar_v(vp, tlp);
            printf("\n");
            break;

        case 4:
            copiar_pp(V, pp, &tlpp, tl);
            printf("\nA primeira palavra copiada..: ");
            mostrar_v(pp, tlpp);
            printf("\n");
            break;

        case 5:
            copiar_up(V, tl, up, &tlpu);
            printf("\nA ultima palavra copiada..: ");
            mostrar_v(up, tlpu);
            printf("\n");
            break;

        case 6:
            r_espacos( V, &tl);
            break;

        case 7:
            cont_p(V, tl, palavra);
            break;

        case 8:
            cont_vogal(V, tl, vogal);
            break;

        case 9:
            printf("\n");
            mostrar_v(V, tl);
            printf("\n");
            break;
        }
    }
    while(op != '0');
}

// Aluno : Pedro da Silva Silveira; Prontuario: PE3030547
// Aluno : Eduardo de Oliveira Viana; Prontuario: PE3029387

#include <stdio.h>
#define TF 50

void realizar_eleicao(char op[], int *tl)
{
    int i;

    printf("-----Menu da Eleicao-----\n");
    printf("M. Para votar em Marcos como presidente.\n");
    printf("A. Para votar em Ana como presidente.\n");
    printf("B. Para votar branco.\n");
    printf("N. Para votar nulo.\n");
    printf("X. Para encerrar a votacao.\n");
    printf("-----------------------\n");

    do
    {
        printf("Informe seu voto: ");
        scanf(" %c", &op[*tl]);
        if(op[*tl] != 'X')
        {
            (*tl)++;
        }
    }
    while(op[*tl] != 'X');
}

void votacao(int *m, int *a, int *b, int *n, char op[], int tl)
{
    int i;

    for(i=0 ; i < tl; i++)
    {
        switch(op[i])
        {
        case 'M':
            (*m)++;
            break;

        case 'A':
            (*a)++;
            break;

        case 'B':
            (*b)++;
            break;

        default:
            (*n)++;
            break;
        }
    }
}

void total_v(int *m, int *a, int *b, int *n, int tl)
{
    printf("O total de pessoas que votaram foi de: %d\n", tl);
    printf("Total de votos para Marcos: %d\n", *m);
    printf("Total de votos para Ana: %d\n", *a);
    printf("Total de votos Brancos: %d\n", *b);
    printf("Total de votos Nulos: %d\n", *n);
}

void percent_validos(int *m, int *a, int tl, float *p_m, float *p_a)
{
    float tv;
    tv = *m + *a;
    float p_t;

    *p_m = (*m / tv)* 100.0;
    *p_a = (*a  / tv)* 100.0;
    p_t = (tv/tl)* 100.0;

    printf("O percentual de votos validos: %.2f\n", p_t);
    printf("O percentual de votos para Marcos foi de: %.2f\n", *p_m);
    printf("O percentual de votos para Ana foi de: %.2f\n", *p_a);


}

void vencedor(float p_m, float p_a)
{
    if(p_m > 50 || p_a > 50)
    {
        if (p_m > p_a)
        {
            printf("O ganhador da eleicao foi Marcos\n");
        }
        else
        {
            printf("O ganhador da eleicao foi Ana\n");
        }
    }
    else
    {
        printf("Essa eleicao foi considerada invalida\n");
    }

}

void main()
{
    int a=0, b=0, m=0, n=0, tl=0;
    char op[TF];
    float p_m, p_a;

    realizar_eleicao( op,&tl);
    votacao(&m, &a, &b, &n, op, tl);

    printf("\n-----Quantidade de votos-----\n");
    total_v(&m, &a, &b, &n, tl);

    printf("\n-----Percentual de votos-----\n");
    percent_validos(&m, &a, tl, &p_m, &p_a);

    printf("\n-----Vencedor da eleicao-----\n");
    vencedor(p_m, p_a);

}

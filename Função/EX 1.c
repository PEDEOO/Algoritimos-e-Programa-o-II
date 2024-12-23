// Aluno : Pedro da Silva Silveira; Prontuario: PE3030547
// Aluno : Eduardo de Oliveira Viana; Prontuario: PE3029387

#include <stdio.h>

int menu(int op)
{
    printf("-----Menu-----\n");
    printf("1. Insira para Fazer calculo de Celsius para Fahrenheit \n");
    printf("2. Insira para Fazer calculo de Fahrenheit para Celsius \n");
    scanf("%d", &op);

    return op;
}

void calc_f(float c)
{
    float F;

    F =  (9 * c + 160) / 5;

    printf("O valor em Fahrenheit sera: %.2f\n", F);
}

void calc_c(float f)
{
    float C;

    C = (f - 32.0) * (5.0/9.0);

    printf("O valor em Celsius sera: %.2f\n", C);
}

void main()
{

    int op;
    float c, f;

    op = menu(op);
    switch(op)
    {
    case 1:
        printf("Insira o valor da temperatura em Celsius..: ");
        scanf("%f", &c);
        calc_f(c);
        printf("\n");
        break;

    case 2:
        printf("Insira o valor da temperatura em Fahrenheit..: ");
        scanf("%f", &f);
        calc_c(f);
        printf("\n");
        break;

    default:
        printf("Opcao invalida\n");
        break;

    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int tombo, ano, qtd, disponivel;
    char nome[100],autores[100];
    char sit;

} biblioteca;

biblioteca ler_biblioteca()
{
    biblioteca a;

    fflush(stdin);
    printf("Tombo...: ");
    scanf("%d", &a.tombo);
    fflush(stdin);

    printf("Titulo..:");
    gets(a.nome);
    fflush(stdin);

    printf("Autores.: ");
    gets(a.autores);
    fflush(stdin);

    printf("Ano Publicado.: ");
    scanf("%d", &a.ano);
    a.sit = 'D';
    a.qtd = 0;
    return a;
}

biblioteca pegar_livro(int pos)
{
    FILE *arq;
    biblioteca a;

    arq = fopen("Biblioteca.dat", "rb");
    if(arq == NULL)
    {
        printf("Não foi possivel");
    }
    else
    {
        fseek(arq, pos*sizeof(biblioteca), SEEK_SET);
        fread(&a, sizeof(biblioteca),1,arq);
        fclose(arq);
    }
    return a;
}

void apresentar(biblioteca a)
{
    printf("%-5d %-30s %-30s %-10d %-10d %-5c\n",
           a.tombo, a.nome, a.autores, a.ano, a.qtd, a.sit);
}

void infos_livros()
{
    printf("%-5s %-30s %-30s %-10s %-10s %-5s\n",
           "Tombo", "Titulo", "Autores", "Ano", "Emprestimo", "Situacao");
    printf("-------------------------------------------------------------------------------------------------------------------||\n");
}

void apresentar_livro(biblioteca a)
{
    printf("Tombo...: %d\n", a.tombo);
    printf("Nome....: %s\n", a.nome);
    printf("Autores.: %s\n", a.autores);
    printf("Ano.....: %d\n", a.ano);
    printf("Situacao: %c\n", a.sit);
    printf("Quantidade emprestada.: %d\n", a.qtd);
}

void incluir(biblioteca a)
{
    FILE *arq;

    arq = fopen("Biblioteca.dat", "ab");
    if(arq == NULL)
    {
        arq = fopen("Biblioteca.dat", "wb");
    }
    if(arq == NULL )
    {
        printf("nao foi possivel");
    }

    else
    {
        a.disponivel = 1;
        fwrite(&a, sizeof(biblioteca), 1, arq);
        fclose(arq);
    }
}

void excluir_fisicamente()
{
    FILE *arq, *excluir;

    biblioteca a;

    arq = fopen("Biblioteca.dat", "rb");

    if (arq == NULL)
    {
        printf("Não foi possível abrir o arquivo Biblioteca.dat\n");
    }

    else
    {
        excluir = fopen("Excluir.dat", "wb");

        if (excluir == NULL)
        {
            printf("Não foi possível criar o arquivo temporário.\n");
        }

        else
        {
            fread(&a, sizeof(biblioteca), 1, arq);

            while (!feof(arq))
            {
                if (a.sit != 'I')
                {
                    fwrite(&a, sizeof(biblioteca), 1, excluir);
                }

                fread(&a, sizeof(biblioteca), 1, arq);
            }

            fclose(arq);
            fclose(excluir);
            remove("Biblioteca.dat");
            rename("Excluir.dat", "Biblioteca.dat");
        }
    }
}

void sobreescrever_livro(biblioteca a, int pos)
{
    FILE *arq;

    arq = fopen("Biblioteca.dat", "rb+");

    if(arq == NULL)
    {
        printf("Nao foi possivel abrir");
    }
    else
    {
        fseek(arq, pos * sizeof(biblioteca), SEEK_SET);
        fwrite(&a, sizeof(biblioteca), 1, arq);
        fclose(arq);

    }
}

int localizar_livro_nome(char name[])
{
    FILE *arq;

    biblioteca a;
    int i = 0, pos = -1;

    arq = fopen("Biblioteca.dat", "rb");

    if(arq == NULL)
    {
        printf("Nao foi possivel abrir o arquivo\n");
    }
    else
    {
        fread(&a, sizeof(biblioteca), 1, arq);
        while(!feof(arq))
        {
            if(strcmp(a.nome, name)==0)
            {
                pos = i;
            }
            i++;
            fread(&a, sizeof(biblioteca), 1, arq);
        }
        fclose(arq);
    }
    return pos;
}

void excluir_livro()
{
    char name[100], excluir;
    int pos;
    biblioteca a;

    fflush(stdin);
    printf("Insira o nome do livro: ");
    gets(name);

    pos = localizar_livro_nome(name);
    if(pos == -1)
    {
        printf("Livro nao localizado");
    }
    else
    {
        a = pegar_livro(pos);
        apresentar_livro(a);

        if(a.disponivel == 1)
        {
            printf("Deseja excluir este livro <S/N>");
            scanf(" %c", &excluir);
            if(excluir == 'S' || excluir == 's')
            {
                a.disponivel = 0;
                a.sit= 'I';
                sobreescrever_livro(a, pos);
                printf("Livro exlcuido com sucesso.\n");
            }
        }
        else
        {
            printf("Livro ja foi excluido\n.");
        }
    }
}

void excluir_livro_fisicamente()
{
    char exclu;

    biblioteca a;

    printf("Deseja excluir os livros fisicamente <S/N>");
    scanf(" %c", &exclu);
    if(exclu == 'S' || exclu == 's')
    {
        excluir_fisicamente();
        printf("Livros excluidos fisicamente com sucesso.\n");
    }

    else
    {
        printf("Operacao cancelada.\n");
    }
}

void cadastrar_livro()
{
    biblioteca livro;
    char opcao;

    printf("Inclusao de livro\n");
    do
    {
        livro = ler_biblioteca();
        incluir(livro);
        printf("Incluir mais algum livro na biblioteca? ");
        scanf(" %c", &opcao);
    }
    while(opcao == 's' || opcao == 'S');
}

void apresentar_todos()
{
    FILE *arq;

    biblioteca a;

    arq = fopen("Biblioteca.dat", "rb");

    if(arq == NULL)
    {
        printf("Nao foi possivel abrir o arquivo\n");
    }
    else
    {

        infos_livros();
        fread(&a, sizeof(biblioteca), 1, arq);
        while(!feof(arq))
        {
            if(a.disponivel == 1)
            {
                apresentar(a);
            }
            fread(&a, sizeof(biblioteca), 1, arq);
        }
        fclose(arq);
    }

}

void pesquisar_livro()
{

    char name[100], excluir;
    biblioteca a;
    int pos;

    fflush(stdin);
    printf("Insira o nome do livro: ");
    gets(name);

    pos = localizar_livro_nome(name);
    if(pos == -1)
    {
        printf("Livro nao localizado\n");
    }
    else
    {
        a = pegar_livro(pos);
        apresentar_livro(a);
    }
}

void recuperar_livro()
{
    char name[100], excluir;
    biblioteca a;
    int pos;

    fflush(stdin);
    printf("Insira o nome do livro: ");
    gets(name);

    pos = localizar_livro_nome(name);
    if(pos == -1)
    {
        printf("Livro nao localizado\n");
    }
    else
    {
        a = pegar_livro(pos);
        apresentar_livro(a);

        if(a.sit == 'I')
        {
            printf("Deseja recuperar este livro <S/N>");
            scanf(" %c", &excluir);
            if(excluir == 'S' || excluir == 's')
            {
                a.sit = 'D';
                a.disponivel = 1;
                sobreescrever_livro(a, pos);
                printf("Livro recuperado com sucesso\n");

            }
        }
        else
        {
            printf("Este livro nao foi excluido.\n");
        }
    }
}

void livros_ED()
{
    FILE *arq;
    biblioteca a;
    int quant = 0;

    arq = fopen("Biblioteca.dat", "rb");
    if(arq == NULL)
    {
        printf("Nao foi possivel abri-lo\n");
    }
    else

        infos_livros();
    fread(&a, sizeof(biblioteca), 1, arq);
    while(!feof(arq))
    {
        if(a.sit == 'D'|| a.sit == 'E')
        {
            quant += a.qtd;
            apresentar(a);
        }
        fread(&a, sizeof(biblioteca), 1, arq);
    }
    printf("\nO total de livros emprestados é de %d\n", quant);
    fclose(arq);
}

void emprestar_livro_novo()
{
    int pos;
    char op, name[100];

    biblioteca a;

    fflush(stdin);
    printf("Insira o titulo do livro: ");
    gets(name);

    pos = localizar_livro_nome(name);
    if (pos != -1)
    {
        a = pegar_livro(pos);
        if(a.sit!= 'I' && a.sit != 'E' )
        {
            apresentar_livro(a);
            printf("Este livro sera emprestado? ");
            scanf(" %c", &op);
            if(op == 'S' || op == 's')
            {
                a.sit = 'E';
                a.qtd++;
                sobreescrever_livro(a, pos);
                printf("Livro emprestado com sucesso.\n");
            }
            else
            {
                printf("Operacao candelada.\n");
            }
        }
        else
        {
            printf("Nao foi possivel pois o livro esta indisponivel ou emprestado.\n");
        }
    }
    else
    {
        printf("Nao existe livro com esse tombo.\n");

    }
}

void alterar_livro()
{

    biblioteca a;
    int pos;
    char name[100];

    fflush(stdin);
    printf("Insira o titulo do livro: ");
    gets(name);

    pos = localizar_livro_nome(name);
    if (pos != -1)
    {
        a = pegar_livro(pos);

        printf("Livro encontrado.\n");
        apresentar_livro(a);

        fflush(stdin);
        printf("Insira o novo titulo: ");
        gets(a.nome);
        fflush(stdin);
        printf("Insira os novos autores: ");
        gets(a.autores);
        fflush(stdin);
        printf("Insira o novo ano: ");
        scanf("%d", &a.ano);

        sobreescrever_livro(a, pos);

        printf("Livro alterado\n.");
    }
    else
    {
        printf("Nao foi possivel achar o livro.\n");
    }
}

void realizar_devolucao()
{
    int pos;
    char op, name[100];

    biblioteca a;

    fflush(stdin);
    printf("Insira o titulo do livro: ");
    gets(name);

    pos = localizar_livro_nome(name);
    if (pos != -1)
    {
        a = pegar_livro(pos);
        if(a.sit!= 'I' || a.sit != 'D')
        {
            apresentar_livro(a);
            printf("Este livro sera devolvido? ");
            scanf(" %c", &op);
            if(op == 'S' || op == 's')
            {
                a.sit = 'D';
                sobreescrever_livro(a, pos);
                printf("Livro devolvido com sucesso.\n");
            }
            else
            {
                printf("Operacao candelada.\n");
            }
        }
        else
        {
            printf("Nao foi possivel pois o livro esta indisponivel ou emprestado.\n");
        }
    }
    else
    {
        printf("Nao existe livro com esse titulo.\n");

    }
}


void livros_emprestados()
{
    FILE *arq;
    biblioteca a;
    int quant = 0;

    arq = fopen("Biblioteca.dat", "rb");
    if(arq == NULL)
    {
        printf("Nao foi possivel abri-lo\n");
    }
    else

        infos_livros();
    fread(&a, sizeof(biblioteca), 1, arq);
    while(!feof(arq))
    {
        if(a.sit == 'E')
        {
            quant++;
            apresentar(a);
        }
        fread(&a, sizeof(biblioteca), 1, arq);
    }
    printf("\nO total de livros emprestados é de %d\n", quant);
    fclose(arq);
}

int apresentar_menu()
{
    int op;

    do
    {
        printf("\n1 - Incluir livro.\n");
        printf("2 - Recuperar livro.\n");
        printf("3 - Excluir livro logicamente.\n");
        printf("4 - Pesquisar livro.\n");
        printf("5 - Alterar livro.\n");
        printf("6 - Livros emprestados ou disponiveis.\n");
        printf("7 - Emprestar livro.\n");
        printf("8 - Realizar devolucao.\n");
        printf("9 - Apresentar livros emprestados.\n");
        printf("10 - Excluir livro fisicamente.\n");
        printf("11 - Apresentar todos\n");
        printf("0 - Encerrar o programa.\n");

        printf("Digite a opcao desejada: ");
        scanf("%d", &op);
    }
    while(op > 12 || op < 0);

    return op;
}

void main()
{
    int op;

    do
    {
        op = apresentar_menu();
        switch(op)
        {
        case 1:
            cadastrar_livro();
            break;

        case 2:
            recuperar_livro();
            break;

        case 3:
            excluir_livro();
            break;

        case 4:
            pesquisar_livro();
            break;

        case 5:
            alterar_livro();
            break;

        case 6:
            livros_ED();
            break;

        case 7:
            emprestar_livro_novo();
            break;

        case 8:
            realizar_devolucao();
            break;

        case 9:
            livros_emprestados();
            break;

        case 10:
            excluir_livro_fisicamente();
            break;

        case 11:
            apresentar_todos();
            break;
        }
    }
    while(op != 0);
}

/*Faça um programa em C que receba o nome de
alunos em uma estrutura fila e as notas de cada
aluno em uma estrutura pilha;
 Todas as operações devem seguir as restrições de
cada estrutura.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

typedef struct aluno
{
    int n; // n é a quantidade de elementos!
    int inicio;
    char vet[N][20];

} alunos;

alunos *criar_fila()
{

    alunos *f = (alunos *)malloc(sizeof(alunos));
    f->n = 0;
    f->inicio = 0;

    return f;
}

void inserir_aluno(alunos *f, char *novoNome)
{

    int fim; // fim é o índice do último elemento da minha fila

    if (f->n == N)
    {
        printf("a fila nao tem espaco disponivel");

        return NULL;
    }

    else
    {

        fim = (f->inicio + f->n) % N; // calculando o índice do ultimo elemento do vetor da minha fila

        strcpy(f->vet[fim], novoNome);

        f->n++;
    }
}

alunos *removerAluno(alunos *f)
{

    //char v[20];

    if (f->n == 0)
    {
        printf("pilha vazia");
        return f;
    }

    else
    {

        printf("removido %s\n", f->vet[f->inicio]);
        f->inicio = (f->inicio + 1) % N;

        f->n--;

        system("pause");
        return f;
    }
}

void listarAlunos(alunos *f)
{

    int fim;
    fim = (f->inicio + f->n) % N;

    for (int i = f->inicio; i < fim; i++)
    {

        printf("%s\n", f->vet[i]);
    }
    system("pause");
}

int main()
{
    int opcao;

    alunos *listaAlunos = (alunos *)malloc(sizeof(alunos));

    listaAlunos = criar_fila();

    char nome[20];

    do
    {
        system("cls");
        printf("digite sua opcao\n");
        printf("///////////////////\n");
        printf("*******************\n");
        printf("1-inserir aluno\n");
        printf("2- remover aluno\n");
        printf("3- visualizar lista\n");
        printf("4- sair\n");
        printf("*******************\n");
        printf("///////////////////\n");

        scanf("%d", &opcao);
        system("cls");
        if (opcao == 1)
        {
            printf("digite o nome do aluno, por favor\n");
            scanf("%s", nome);
            inserir_aluno(listaAlunos, nome);
            system("cls");
        }
        else if (opcao == 2)
        {
            listaAlunos = removerAluno(listaAlunos);
        }

        else if (opcao == 3)
        {
            listarAlunos(listaAlunos);
        }

    } while (opcao != 4);

    return 0;
}

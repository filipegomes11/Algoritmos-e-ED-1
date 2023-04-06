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
    float vet[N];

} alunos;

alunos *criar_fila()
{

    alunos *f = (alunos *)malloc(sizeof(alunos));
    f->n = 0;
    f->inicio = 0;

    return f;
}

void inserir_aluno(alunos *f ,float v)
{

    int fim; // fim é o índice do último elemento da minha fila

    if (f->n == N)
    {
        printf("a fila nao tem espaco disponivel");
        exit(1);
    }

    fim = (f->inicio + f->n) % N; // calculando o índice do ultimo elemento do vetor da minha fila

    f->vet[fim] = v;

    printf("%.2f", f->vet[fim]);

    f->n++;
}

/*char removerAluno(alunos *f)
{

    char v[20];

    if (f->n == 0 && f->inicio == 0)
    {

        printf("pilha vazia");
    }

    *v = f->vet[f->inicio];

    f->inicio = (f->inicio + 1) % N;

    f->n--;

    return v;
}
*/

/*alunos* listarAlunos(alunos* f){
    printf("%s", f->vet[0]);

    return f;
}
*/

int main()
{

    alunos *listaAlunos = (alunos *)malloc(sizeof(alunos));

    listaAlunos = criar_fila();

    inserir_aluno(listaAlunos, 10);
    // listarAlunos(listaAlunos);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

float *novaMatrizA(int linhas, int colunas)
{
    float *mat;
    int tamanho = linhas * colunas;
    mat = (float *)malloc(tamanho * sizeof(float));

    return mat; // mat neste caso é um vetor que vai representar toda a matriz, ou seja, linhasxcolunas = tamanho do array.
}

float **novaMatrizB(int linhas, int colunas)
{
    float **mat; // essa lista está armazenando endereços de outras listas
    mat = (float **)malloc(linhas * sizeof(float *));
    for (int i = 0; i < linhas; i++)
    {
        mat[i] = (float *)malloc(colunas * sizeof(float));
    }
    return mat;
}

void preencherMatrizA(float *matrizA, int linhas, int colunas)
{

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("Escreva o valor do elemento da linha %d e da coluna %d\n", i + 1, j + 1);
            scanf("%f", &matrizA[(i * colunas) + j]);
        }
    }
}

void preencherMatrizB(float **matrizB, int linhas, int colunas)
{

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("Escreva o valor do elemento da linha %d e da coluna %d\n", i + 1, j + 1);
            scanf("%f", &matrizB[i][j]);
        }
    }
}

void somaMatrizes(float *matrizA, float **matrizB, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            float soma = matrizB[i][j] + matrizA[(i * colunas) + j];
            printf("%.2f ", soma);
        }

        if (linhas % (i + 1) == 0)
            printf("\n");
    }
}

int main()
{

    int linhas;
    int colunas;

    printf("Digite quantas linhas vc quer:\n");
    scanf("%d", &linhas);
    printf("Digite quantas colunas vc quer:\n");
    scanf("%d", &colunas);

    float *matrizA = novaMatrizA(linhas, colunas);
    float **matrizB = novaMatrizB(linhas, colunas);

    preencherMatrizA(matrizA, linhas, colunas);
    printf("matriz A preenchida\n");
    preencherMatrizB(matrizB, linhas, colunas);
    printf("matriz B preenchida\n");
    somaMatrizes(matrizA, matrizB, linhas, colunas);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

void swap(int *vet)
{
    int i, maior, menor, aux, j;
    for (j = 0; j < TAMANHO / 2; j++)
    { // menor = tamanho - j - 1 e j é o maior
        maior = j;

        for (i = j + 1; i < TAMANHO - j; i++)
        {
            if (vet[i] > vet[maior])
            {
                maior = i;
            }
        }
        aux = vet[j];
        vet[j] = vet[maior];
        vet[maior] = aux;
        menor = j;
        for (i = j + 1; i < TAMANHO - j; i++)
        {

            if (vet[i] < vet[menor])
            {
                menor = i;
            }
        }
        aux = vet[TAMANHO - j - 1];
        vet[TAMANHO - j - 1] = vet[menor];
        vet[menor] = aux;
    }
}

void imprimirOrdenado(int *vet)
{
    int i;
    printf("\n vetor ordenado:\n");
    for (i = 0; i < TAMANHO; i++)
    {
        printf("%d", vet[i]);
    }
    printf("\n");
}

void deletarNumero(int *vet, int posicao)
{
    int i, aux;

    vet[posicao] = 0;
    for (i = posicao; i < 10 - 1; i++)
    {
        aux = vet[i];
        vet[i] = vet[i + 1];
        vet[i + 1] = aux;
    }
}

int main()
{

    int vet[] = {7, 5, 9, 4, 6, 3, 2, 7, 8, 2};
    int opcao, posicao;

    swap(vet);

    do
    {
        printf("Selecione uma opcao. \n 1 - imprimir o vetor ordenado; \n 2- excluir um numero do vetor \n 3 -sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            imprimirOrdenado(vet);
            break;
        case 2:
            printf("informe a posicao\n");
            scanf("%d", &posicao);
            deletarNumero(vet, posicao);
            break;
        case 3:
            break;

        default:
            printf("opcao invalida!");
            break;
        }

    } while (opcao != 3);

    return 0;
}

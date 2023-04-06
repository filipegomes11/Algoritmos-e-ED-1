#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{

    int info;
    struct lista *proximo;

} listas;

listas *inicializa(void)
{

    return NULL;
}

listas *lst_insere(listas *l, int i)
{
    listas *novo = (listas *)malloc(sizeof(listas));
    novo->info = i;
    
    if(l==NULL || i < l->info){
        novo->proximo = l;
        return novo;
    }
listas *p;

    for (p = l; p != NULL; p = p->proximo)
    {
        if(i >= p->info){
            if(p->proximo == NULL){
                novo->proximo = NULL;
                p->proximo = novo;
                break;
            } else if (p->proximo->info >= i) {
                novo->proximo  = p->proximo;
                p->proximo = novo;
                break;
            } else {
                continue;
            }
        } else {
            novo->proximo = p;
            return novo;
        }

    }


    return l;
}

void imprime(listas *l)
{

    listas *p;

    for (p = l; p != NULL; p = p->proximo)
    {
        printf("info = %d\n", p->info);
    }
}


int main()
{

    listas *a = inicializa();
    int quantidade, i;

    printf("quantos numeros vc quer colocar na lista? ");
    scanf("%d", &quantidade);

    for (int l = 0; l < quantidade; l++)
    {
        printf("Digite um numero");
        scanf("%d", &i);
        a = lst_insere(a, i);
    }

    
    imprime(a);

    return 0;
}
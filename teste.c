#include <stdio.h>

void printAll(int *v, int s) {
    for(int i=0; i<s; i++){
        printf("%d, ", v[i]);
    }
    printf("\n");
}

void swap(int ori, int des, int *v){
    int aux;
    aux = v[des];
    v[des] = v[ori];
    v[ori] = aux;
}

void ord(int *v, int s){
    int min,max, aux;
    for(int j=s-1; j>=s/2; j-=1){
        for (int i=s-j-1; i<=j; i++) {
            if(i==s-j-1){
                min = s-j-1;
                max = s-j-1;
                continue;
            }
            if(v[i] < v[min]){
                min = i;
            }
            if(v[i]>v[max]){
                max = i;
            }
            
        }
        swap(s-j-1, max, v);
        if(j != max){
            swap(j, min, v);
        }
    }
}

void rem(int *v, int s, int pe){
    v[pe] = 0;
    for(int i=pe; i<s-1; i++){
        swap(i, i+1, v);
    }
}



int main()
{
    int v[] = {5,4,78,65,3,24,67,2,98,-7}, op=0;
    int e;
    ord(v,10);
    
    do {
        printf("-------Opcoes-------\n");
        printf("1 - Exibir vetor\n");
        printf("2 - Remover elemento\n");
        printf("3 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        printf("--------------------\n");
        switch(op) {
            case 1:
                printAll(v, 10);
                break;
            case 2:
                printf("Posicao do elemento: ");
                scanf("%d", &e);
                rem(v, 10, e);
                break;
            case 3:
                break;
            default:
                printf("Opcao invalida");
        }
        printf("--------------------\n");
    }while(op!=3);
    return 0;
}
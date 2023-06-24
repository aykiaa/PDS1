#include <stdio.h>
#include <stdlib.h>

int* uniao(int *v1, int n1, int *v2, int n2, int *qtd)
{
    int* v3 = malloc((n1+n2)*sizeof(int)); //Contagem dos nunmeros 
    for(int i=0; i < n1+n2;i++) v3[i]=0;
    for (int i = 0; i < n1; i++)
    {
        v3[v1[i]]++;
    }
    
    for (int i = 0; i < n2; i++)
    {
        v3[v2[i]]++;
    }
    for (int i = 0; i < n1+n2; i++) //Imprimir vetor de contagem
    {
        printf("%d ", v3[i]);
    }
    printf("\n");

    int* v4 = malloc((n1+n2)*sizeof(int)); //Vetor da uniao
    int j=0;
    for (int i = 0; i < n1+n2; i++)
    {
        if (v3[i] > 0)
        {
            v4[j] = i;
            j++;
        }
        
    }
    free(v3);
    *qtd = j;  
    return v4;
}

int main(){
    int n1,n2;
    scanf("%d %d", &n1, &n2);
    int* x1=malloc(n1*sizeof(int));
    int* x2=malloc(n2*sizeof(int));
    
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &x1[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &x2[i]);
    }
    int qtd;
    int* x3 = uniao(x1, n1, x2, n2, &qtd);
    for (int i = 0; i < n1; i++) printf("%d ", x1[i]);
    printf("\n");
    for (int i = 0; i < n2; i++) printf("%d ", x2[i]);
    printf("\n");
    for (int i = 0; i < qtd; i++)
    {
        printf("%d ", x3[i]);
    }
    printf("\n");
    free(x1);
    free(x2);
    free(x3);

    return 0;




}
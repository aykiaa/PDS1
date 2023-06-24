#include <stdio.h>
#include <stdlib.h>

int* uniao(int *v1, int n1, int *v2, int n2, int *qtd)
{
    int* v3 = malloc((n1+n2)*sizeof(int)); //Contagem dos nunmeros 
    for(int i=0; i < n1+n2; i++) v3[i]=0;
    
    
    for (int i = 0; i < n1; i++)
    {
        v3[v1[i]]++;
    }
    
    for (int i = 0; i < n2; i++)
    {
        v3[v2[i]]++;
    }
    printf("Vetor Contagem\n");
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
int* interseccao(int *x1, int *x2, int n1, int n2, int *qtd)
{
    int* x3 = malloc((n1+n2)*sizeof(int));
    int j = 0;
    for (int i = 0; i < n1+n2; i++) x3[i] = 0; //tirar lixo

    for (int i = 0; i < n1+n2; i++)
    {
        for (int k = 0; k < n2; k++)
        {
            if (x1[i] == x2[k])
            {
                if (x1[i] == x3[k]) break; // para nao colocar valor repetido na interseccao
                x3[j] = x1[i];
                j++;
            } 
        }
        
    }
    

    *qtd = j;
    return x3;

}   

int* preencher (int* x1, int n)
{
    printf("Digite os %d elementos do vetor N\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x1[i]); 
    }

    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", x1[i]); 
    }
}




int main(){
    int n1,n2;
    printf("Digite o numeros de elementos de cada vetor\n");
    printf("Vetor 1: \n"); scanf("%d", &n1);
    printf("Vetor 2: \n"); scanf("%d", &n2);
    int* x1=malloc(n1*sizeof(int));
    int* x2=malloc(n2*sizeof(int));
    
    printf("Digite os %d elementos do vetor 1: \n", n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &x1[i]);
    }

    printf("Digite os %d elementos do vetor 2: \n", n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &x2[i]);
    }
    int qtd;
    int* x3 = uniao(x1, n1, x2, n2, &qtd);
    printf("Vetor 1\n");
    for (int i = 0; i < n1; i++) printf("%d ", x1[i]);
    printf("\n");
    
    printf("Vetor 2\n");
    for (int i = 0; i < n2; i++) printf("%d ", x2[i]);
    printf("\n");

    printf("Vetor Uniao\n");
    for (int i = 0; i < qtd; i++) //vetor uniao
    {
        printf("%d ", x3[i]);
    }
    printf("\n");


    printf("Vetor interseccao\n");
    int qtd2;
    int* vetor_interseccao = interseccao(x1, x2, n1, n2, &qtd2);
    for (int i = 0; i < qtd2; i++)
    {
        printf("%d ", vetor_interseccao[i]);
    }
    printf("\n");
    printf("\n");
    //questao 3

    int n;
    printf("Questao 3\n");
    printf("Digite o numero de elementos do vetor N: \n");
    scanf("%d", &n);
    int* vetor_n = malloc(n*sizeof(int));
    preencher(vetor_n, n);
    
    
    
    free(x1);
    free(x2);
    free(x3);
    free(vetor_interseccao);
    free(vetor_n);
    return 0;
}
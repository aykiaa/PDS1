#include <stdio.h>
#include <stdbool.h>

// questoes 1,2,3,4,5 feitas

void transposta(int n, float A[][100], float T[][100]){
    for(int i=0; i<n; i++)
    {
        for (int j=0; j < n; j++)
        {
            T[j][i] = A[i][j];
        }
        
    }
}

bool simetrica(int n, float A[][100]){
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(A[i][j] != A[j][i]) return(false);
        }
    }
    return true;
}

float medi_matriz(int n, float mat[][100]){
    float soma = 0;

    for(int i = 0; i<n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            soma += mat[i][j];
        }
    }
    return soma / (n*n);
}



void identidade(int n, float A[][100]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                A[i][j] = 1.0;
            }
            else A[i][j] = 0.0;
        }
    }
}

void soma_matriz(int n, float A[][100], float B[][100], float S[][100]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            S[i][j] = A[i][j] + B[i][j];
        }
    }
}


void mult_matriz(int n, float A[][100], float B[][100], float P[][100]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            P[i][j] = 0;
            for (int a = 0; a < n; a++)
            {
                P[i][j] += A[i][a] * B[a][j];
            }
        }
    }
}







int main(){
    FILE* f_matriz = fopen("matriz.txt", "r+t");
    if (f_matriz == NULL){
        printf("Erro ao ler o arquivo\n");
        return 1;
    }

    FILE* f_matrizB = fopen("matrizb.txt", "r+t");
    if (f_matrizB == NULL)
    {
        printf("Erro ao ler o arquivo\n");
        return 1;
    }

       

    float mat[100][100];
    float matB[100][100];
    float T[100][100];
    float mat_soma[100][100];
    float mat_mult[100][100];
    int linhas,colunas; 
    int linhas_b, colunas_b;
    

    fscanf(f_matrizB, "%d %d", &linhas_b, &colunas_b); // scan matriz B
    
    for (int i = 0; i < linhas_b; i++)
    {
        for (int j = 0; j < colunas_b; j++)
        {
            fscanf(f_matrizB, "%f", &matB[i][j]);
        }
    }
    
    
    fscanf(f_matriz, "%d %d", &linhas,&colunas); //scannear os valores da matriz A original
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            fscanf(f_matriz, "%f", &mat[i][j]);
        }
    }

    
    printf("Matriz original / A\n");
    
    for(int i=0; i< linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
                printf("%.1f ", mat[i][j]);
        }
        printf("\n");
    } 
    
    printf("\n \n");

    printf("Matriz B\n");
    for (int i = 0; i < linhas_b; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%.1f ", matB[i][j]);
        }
        printf("\n");
    }


    printf("\n \n");
    
    transposta(linhas,mat,T); //pegou os valores e colocou dentro da Transposta
    printf("Matriz transposta\n");
    for(int i=0; i<linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
                printf("%.1f ", T[i][j]);
        }
        printf("\n");
    } 
    
    // print da simetrica
    printf("\n");
    if(simetrica(linhas, mat) == true)
    {
        printf("A matriz eh simetrica\n");
    }
    else printf("A matriz nao eh simetrica\n");
   
    printf("A media da matriz eh %.3f\n", medi_matriz(linhas, mat));
    printf("\n");

    soma_matriz(linhas,mat,matB,mat_soma);
    printf("Soma das matrizes A + B\n");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)   
        {
            printf("%.2f ", mat_soma[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    printf("A x B\n");
    // multiplicacao das matrizes A e B
    
    mult_matriz(linhas,mat, matB, mat_mult);
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < linhas; j++)
        {
            printf("%.1f ", mat_mult[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    identidade(linhas, mat);
    printf("Matriz identidade\n");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < linhas; j++)
        {
            printf("%.1f ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    
    fclose(f_matriz);
    fclose(f_matrizB);
    return 0;
}
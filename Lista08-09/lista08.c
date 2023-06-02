#include <stdio.h>
#include <stdbool.h>



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







int main(){
    FILE* f_matriz = fopen("matriz.txt", "r+t");
    if (f_matriz == NULL){
        printf("Erro ao ler o arquivo\n");
        return 1;
    }

    float mat[100][100];
    int linhas,colunas;

    fscanf(f_matriz, "%d %d", &linhas,&colunas);
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            fscanf(f_matriz, "%f", &mat[i][j]);
        }
    }

    fclose(f_matriz);
    
    float T[100][100]; 
    
    for(int i=0; i<linhas; i++) //for para matriz sem valor
    {
        for (int j = 0; j < colunas; j++)
        {
                printf("%.2f ", T[i][j]);
        }
        printf("\n");
    }
    printf("\n \n");
    
    
    
    transposta(linhas,mat,T); //pegou os valores e colocou dentro na Transposta
    
    for(int i=0; i<linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
                printf("%.2f ", T[i][j]);
        }
        printf("\n");
    } 
    
    return 0;
}
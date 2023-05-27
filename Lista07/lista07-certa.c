#include <stdio.h>
#include <math.h>


float maior(float v[1000], int n){
    float r = v[0];
    int i = 0;
    while (i<n){
        if (v[i]>r) r = v[i];
        i++;
    }
    return r;
}

float menor(float v[1000], int n){
    float r = v[0];
    int i = 0;
    while (i < n){
        if (v[i] < r) r = v[i];
        i++; 
    }
    return r;
}


float media(float v[1000], int n){
    float s = 0;
    int i = 0;
    while (i < n){
        s = s + v[i];
        i++;
    }
    return(s/n);
}

float variancia(float v[1000], int n){
    int i = 0;
    float variancia_total = 0;
    float media_va = media(v,n);
    while(i < n){
        variancia_total += pow(v[i] - media_va,2);
        i++;
    }
    return (variancia_total/(n-1));
}


float produto_escalar(float u[1000], float v[1000], int n, int x){
    int i = 0;
    int k = 0;
    float pe = 0;
    while (i < n && k < x){
        float a1 = v[i]; 
        float a2 = u[k];
        pe += a1*a2;
        i++;
        k++;
    }
    return pe;
}


int main(){
    FILE* f=fopen("naturais.txt", "r+t");
    FILE* f_numbers=fopen("numbers.txt", "r+t");
    if (f==NULL){
        printf("Erro ao abrir arquivo\n");
        return 1;
    }
    if (f_numbers==NULL){
        printf("Erro ao abrir arquivo\n");
        return 1;
    }
    
    
    float arr2[1000];
    float arr[1000];
    int i = 0;
    int k = 0;
    
    fscanf(f,"%f", &arr[i]);
    while(!feof(f)){
        i++;
        fscanf(f, "%f", &arr[i]);
    }
    
    fscanf(f_numbers,"%f", &arr2[k]);
    while(!feof(f_numbers)) {
        k++;
        fscanf(f_numbers, "%f", &arr2[k]);
    }


    fclose(f);
    fclose(f_numbers);
    printf("2) A media eh %.3f\n",media(arr,i));
    printf("3) A variancia eh %.3f\n", variancia(arr,i));
    printf("4) O maior eh %.3f\n",maior(arr,i));
    printf("5) O menor eh %.3f\n", menor(arr,i));
    printf("6) O produto escalar eh %.3f\n", produto_escalar(arr2,arr,i,k));
    return 0;



}
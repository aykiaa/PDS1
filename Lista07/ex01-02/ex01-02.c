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



float media(float v[1000], int n){
    float s = 0;
    int i = 0;
    while (i < n){
        s = s + v[i];
        i++;
    }
    return(s/n);
}


int main(){
    FILE* f=fopen("naturais.txt", "r+t");
    if (f==NULL){
        printf("Erro ao abrir arquivo\n");
        return 1;
    }
    float arr[1000];
    int i = 0;
    fscanf(f,"%f", &arr[i]);
    while(!feof(f)){
        i++;
        fscanf(f, "%f", &arr[i]);
    }
    fclose(f);
    printf("A media eh %.3f\n",media(arr,i));
    printf("O maior eh %.3f\n",maior(arr,i));
    
    return 0;



}
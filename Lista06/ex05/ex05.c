/*5. Escreva um programa em C++ que lê um arquivo com números reais (um número por linha) e
grava outro arquivo onde cada linha mostra o valor do respectivo número aplicado a função
f(x)= ax3 + bx2 + cx + d, onde a, b, c e d são lidos do teclado.*/


#include <stdio.h>
#include <math.h>

float funcao(float x, float a, float b, float c, float d)
{
    float result = a*(pow(x,3)) + b*(pow(x,2)) + c*x + d;
    return result;
}


int main(){
    FILE* f_numbers = fopen("numbers.txt", "r+t");
    FILE* f_results = fopen("results.txt", "w+t");
    if (f_numbers == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    if (f_results == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    float x, a,b,c,d;
    scanf("%f %f %f %f",&a,&b,&c,&d);
    fscanf(f_numbers, "%f", &x);
    while(!feof(f_numbers)){
        fprintf(f_results, "%f\n", funcao(x,a,b,c,d));
        fscanf(f_numbers,"%f",&x);
    }
    fclose(f_numbers);
    fclose(f_results);
    return 0;
}

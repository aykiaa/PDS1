/*4. Escreva um programa em C++ que lê um arquivo com números reais (um número por linha) e
grava outro arquivo onde cada linha mostra o valor do respectivo número aplicado a função
f(x)= x^2 - 5x + 1.*/


#include <stdio.h>
#include <math.h>


float funcao(float x)
{
    float result = x*x - (5*x) + 1;
    return result;
}


int main()
{
    FILE* f_number = fopen("numbers.txt", "r+t");
    FILE* f_results = fopen("results.txt", "w+t");
    if (f_number == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
     if (f_results == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    float x;
    fscanf(f_number, "%f", &x);
    while (!feof(f_number)){
        fprintf(f_results, "%.3f\n", funcao(x));
        fscanf(f_number, "%f", &x);
    }
    fclose(f_number);
    fclose(f_results);
    return 0;
}

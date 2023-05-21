//1. Escreva um programa em C++ que lê um número n do teclado e gera um arquivo com os n primeiros números primos.
/* 2. Escreva um programa em C++ que lê um arquivo com números naturais (um número por
linha) e grava outro arquivo onde cada linha indica se o respectivo número é primo ou não. */

#include <stdio.h>

int primo (int x){
  int i = x-1;
  while (i>1){
    if (x%i==0) return 0;
    i--;
  }
  return 1;
}


int main()
{
  FILE* f=fopen("primos-gerados.txt","w+t");
  FILE* f_naturais = fopen("naturais.txt", "r+t");
  FILE* f_primos = fopen("primos.txt", "w+t");
  if(f==NULL){
    printf("Erro ao tentar abrir o arquivo\n");
    return(1); 
  }
  if (f_naturais == NULL){
    printf("Erro ao abrir o arquivo\n");
    return 1;
  }
  if (f_primos == NULL){
    printf("Erro ao tentar abrir o arquivo\n");
    return 1;   
  }
  int z;
  int n;
  scanf("%d", &n);
  int count = 0;
  int x = 2;
  while ( count < n ){
    if (primo(x)){
      fprintf(f, "%d ",x);
      count++;
    } 
    x++;
  }
  fscanf(f_naturais, "%d", &z);
  while (!feof(f_naturais))
  {
    if (primo(z)) fprintf(f_primos, "Eh primo\n");
    else fprintf(f_primos, "Nao eh primo\n");
    fscanf(f_naturais, "%d", &z);
 }
  fclose(f_naturais);
  fclose(f_primos);
  fclose(f);
  return(0);
}
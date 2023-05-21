//1. Escreva um programa em C++ que lê um número n do teclado e gera um arquivo com os n primeiros números primos.
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
  FILE* f=fopen("primos.txt","w+t");
  if(f==NULL){
    printf("Erro ao tentar abrir o arquivo\n");
    return(1); 
  }
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
  fclose(f);
  return(0);
}
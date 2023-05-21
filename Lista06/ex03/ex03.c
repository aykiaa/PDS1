/*3. Escreva um programa em C++ que lê um arquivo com números naturais e gera dois arquivos:
“primos.txt” com aqueles números que são primos e “outros.txt” com aqueles números que não
são primos.*/

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
    FILE* f_naturais = fopen("naturais.txt", "r+t");
    FILE* f_primos = fopen("primos.txt", "w+t");
    FILE* f_outros = fopen("outros.txt", "w+t");

    if (f_naturais == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    if (f_primos == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    if (f_outros == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    int x;
    fscanf(f_naturais, "%d", &x);
    while (!feof(f_naturais))
    {
        if (primo(x)) fprintf(f_primos, "%d\n", x);
        else fprintf(f_outros, "%d\n", x);
        fscanf(f_naturais,"%d",&x);
    }
    fclose(f_naturais);
    fclose(f_primos);
    fclose(f_outros);
    return 0;
}
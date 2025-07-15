
#include<stdio.h>
#include<stdlib.h>

struct Cadastro {
  char nome[100];
  int idade;
  char endereco[250];
};

int main(){
  int N = 0;
  printf("Digite um numero inteiro positivo: ");
  scanf("%d",&N);

  if(N < 0){
    printf("Digite um numero válido");
  }

return 0;
}
#include<stdio.h>
#include<stdlib.h>

int main(){
  int N;
  int *V;
  int i;

  do{
    printf("Digite um valor inteiro N (positivo): ");
    scanf("%d", &N);
    if(N <= 0){
      printf("Valor invalido. Tente novamente.\n");
    }
  } while(N <= 0);

  V = (int*) malloc(N * sizeof(int));
  if(V == NULL){
    printf("Erro de alocacao de memoria.\n");
    return 1;
  }

  printf("Digite os %d elementos do vetor (cada valor deve ser >= 2):\n", N);
  for(i = 0; i < N; i++){
    do{
      printf("Elemento %d: ", i);
      scanf("%d", V + i);
      if(*(V + i) < 2){
        printf("Valor invalido. Digite um numero maior ou igual a 2.\n");
      }
    } while(*(V + i) < 2);
  }

  printf("\nVetor lido com sucesso.\n");
  
  free(V);

  return 0;
}
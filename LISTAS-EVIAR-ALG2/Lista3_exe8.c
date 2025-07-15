#include<stdio.h>
#include<stdlib.h>

int* alocaVetor(int N){
  if(N <= 0){
    return NULL;
  }
  int *vetor = (int*) malloc(N * sizeof(int));
  return vetor;
}

int main(){
  int tamanho = 5;
  int *vetor;

  vetor = alocaVetor(tamanho);

  if(vetor == NULL){
    printf("Nao foi possivel alocar o vetor (tamanho invalido ou memoria insuficiente).\n");
  } else {
    printf("Vetor de tamanho %d alocado com sucesso no endereco: %p\n", tamanho, (void*)vetor);
    free(vetor);
  }

  return 0;
}
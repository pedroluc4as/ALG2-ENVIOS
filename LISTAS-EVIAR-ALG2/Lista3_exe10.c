#include<stdio.h>
#include<stdlib.h>

int* criaVetorPreenchido(int N, int valor){
  int i;
  
  if(N <= 0){
    return NULL;
  }
  
  int *vetor = (int*) malloc(N * sizeof(int));
  if(vetor == NULL){
    return NULL;
  }

  for(i = 0; i < N; i++){
    *(vetor + i) = valor;
  }

  return vetor;
}

int main(){
  int tamanho = 8;
  int valor = 99;
  int *vetor;
  int i;
  
  vetor = criaVetorPreenchido(tamanho, valor);
  if(vetor != NULL){
    printf("Vetor preenchido com o valor %d:\n", valor);
    for(i = 0; i < tamanho; i++){
      printf("%d ", *(vetor + i));
    }
    printf("\n");
    free(vetor);
  }
  return 0;
}
#include<stdio.h>
#include<stdlib.h>

int* criaVetorSequencial(int N){
  int *vetor;
  int i;
  
  vetor = (int*) malloc(N * sizeof(int));
  if(vetor == NULL){
    return NULL;
  }

  for(i = 0; i < N; i++){
    *(vetor + i) = i;
  }
  
  return vetor;
}

int main(){
  int N = 10;
  int *meuVetor;
  int i;

  meuVetor = criaVetorSequencial(N);
  
  if(meuVetor != NULL){
    printf("Vetor criado com sucesso:\n");
    for(i = 0; i < N; i++){
      printf("%d ", *(meuVetor + i));
    }
    printf("\n");
    free(meuVetor);
  }
  
  return 0;
}
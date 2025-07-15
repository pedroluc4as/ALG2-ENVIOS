#include<stdio.h>
#include<stdlib.h>

int** criaMatrizIdentidade(int N){
  int i, j;
  int **matriz = (int**) malloc(N * sizeof(int*));
  if(matriz == NULL) return NULL;

  for(i = 0; i < N; i++){
    matriz[i] = (int*) malloc(N * sizeof(int));
    if(matriz[i] == NULL) return NULL;
    for(j = 0; j < N; j++){
      if(i == j){
        matriz[i][j] = 1;
      } else {
        matriz[i][j] = 0;
      }
    }
  }
  return matriz;
}

int main(){
  int N = 4;
  int **matrizId;
  int i, j;

  matrizId = criaMatrizIdentidade(N);
  if(matrizId != NULL){
    printf("Matriz Identidade %dx%d:\n", N, N);
    for(i = 0; i < N; i++){
      for(j = 0; j < N; j++){
        printf("%d ", matrizId[i][j]);
      }
      printf("\n");
    }
    for(i = 0; i < N; i++){
      free(matrizId[i]);
    }
    free(matrizId);
  }
  return 0;
}
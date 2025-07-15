#include<stdio.h>
#include<stdlib.h>

int** criaMatrizDiagSecundaria(int N){
  int i, j;
  int **matriz = (int**) malloc(N * sizeof(int*));
  if(matriz == NULL) return NULL;

  for(i = 0; i < N; i++){
    matriz[i] = (int*) malloc(N * sizeof(int));
    if(matriz[i] == NULL) return NULL;
    for(j = 0; j < N; j++){
      if(i + j == N - 1){
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
  int **matrizSec;
  int i, j;

  matrizSec = criaMatrizDiagSecundaria(N);
  if(matrizSec != NULL){
    printf("Matriz com Diagonal Secundaria %dx%d:\n", N, N);
    for(i = 0; i < N; i++){
      for(j = 0; j < N; j++){
        printf("%d ", matrizSec[i][j]);
      }
      printf("\n");
    }
    for(i = 0; i < N; i++){
      free(matrizSec[i]);
    }
    free(matrizSec);
  }
  return 0;
}
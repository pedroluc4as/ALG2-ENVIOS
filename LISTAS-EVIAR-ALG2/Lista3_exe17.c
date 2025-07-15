#include<stdio.h>
#include<stdlib.h>

int* somaColunas(int **A, int N){
  int i, j;
  int *B = (int*) calloc(N, sizeof(int));
  if(B == NULL) return NULL;

  for(j = 0; j < N; j++){
    for(i = 0; i < N; i++){
      B[j] += A[i][j];
    }
  }
  return B;
}

int main(){
  int N = 3;
  int **A, *B;
  int i, j, cont = 1;
  
  A = (int**) malloc(N * sizeof(int*));
  for(i = 0; i < N; i++){
    A[i] = (int*) malloc(N * sizeof(int));
    for(j = 0; j < N; j++){
      A[i][j] = cont++;
    }
  }

  B = somaColunas(A, N);
  if(B != NULL){
    printf("Vetor B (soma das colunas de A):\n");
    for(i = 0; i < N; i++){
      printf("Soma coluna %d: %d\n", i, B[i]);
    }
    free(B);
  }

  for(i = 0; i < N; i++){
    free(A[i]);
  }
  free(A);
  
  return 0;
}
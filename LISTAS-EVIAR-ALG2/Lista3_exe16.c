#include<stdio.h>
#include<stdlib.h>

int* produtoMatrizVetor(int **A, int *B, int N){
  int i, j;
  int *C = (int*) calloc(N, sizeof(int));
  if(C == NULL) return NULL;

  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      C[i] += A[i][j] * B[j];
    }
  }
  return C;
}

int main(){
  int N = 2;
  int **A, *B, *C;
  int i;
  
  A = (int**) malloc(N * sizeof(int*));
  A[0] = (int*) malloc(N * sizeof(int));
  A[1] = (int*) malloc(N * sizeof(int));
  A[0][0]=1; A[0][1]=2;
  A[1][0]=3; A[1][1]=4;

  B = (int*) malloc(N * sizeof(int));
  B[0]=5; B[1]=6;

  C = produtoMatrizVetor(A, B, N);
  if(C != NULL){
    printf("Vetor C (produto da Matriz A pelo Vetor B):\n");
    for(i = 0; i < N; i++){
      printf("%d\n", C[i]);
    }
    free(C);
  }
  
  free(A[0]); free(A[1]); free(A);
  free(B);
  
  return 0;
}
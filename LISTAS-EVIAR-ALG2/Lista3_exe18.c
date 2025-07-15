#include<stdio.h>
#include<stdlib.h>

int** produtoMatrizes(int **A, int L1, int C1, int **B, int L2, int C2){
  if(C1 != L2){
    return NULL;
  }
  int i, j, k;
  int **C = (int**) calloc(L1, sizeof(int*));
  if(C == NULL) return NULL;
  for(i = 0; i < L1; i++){
    C[i] = (int*) calloc(C2, sizeof(int));
    if(C[i] == NULL) return NULL;
  }

  for(i = 0; i < L1; i++){
    for(j = 0; j < C2; j++){
      for(k = 0; k < C1; k++){
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return C;
}

int main(){
  int L1=2, C1=3, L2=3, C2=2;
  int **A, **B, **C;
  int i, j;
  
  A = (int**) malloc(L1*sizeof(int*));
  for(i=0;i<L1;i++) A[i]=(int*)malloc(C1*sizeof(int));
  A[0][0]=1;A[0][1]=2;A[0][2]=3;
  A[1][0]=4;A[1][1]=5;A[1][2]=6;

  B = (int**) malloc(L2*sizeof(int*));
  for(i=0;i<L2;i++) B[i]=(int*)malloc(C2*sizeof(int));
  B[0][0]=7;B[0][1]=8;
  B[1][0]=9;B[1][1]=10;
  B[2][0]=11;B[2][1]=12;

  C = produtoMatrizes(A, L1, C1, B, L2, C2);
  if(C != NULL){
    printf("Matriz C (produto de A por B):\n");
    for(i = 0; i < L1; i++){
      for(j = 0; j < C2; j++){
        printf("%d ", C[i][j]);
      }
      printf("\n");
    }
    for(i=0;i<L1;i++) free(C[i]);
    free(C);
  }
  
  for(i=0;i<L1;i++) free(A[i]);
  free(A);
  for(i=0;i<L2;i++) free(B[i]);
  free(B);
  
  return 0;
}
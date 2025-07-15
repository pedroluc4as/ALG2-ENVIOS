#include<stdio.h>
#include<stdlib.h>

int main(){
  int N;
  int **matriz;
  int i, j;

  printf("Digite a dimensao N da matriz: ");
  scanf("%d", &N);
  
  matriz = (int**) malloc(N * sizeof(int*));
  if(matriz == NULL){ return 1; }
  for(i = 0; i < N; i++){
    matriz[i] = (int*) malloc(N * sizeof(int));
    if(matriz[i] == NULL){ return 1; }
  }

  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      if(i < j){
        matriz[i][j] = 1;
      } else if(i > j){
        matriz[i][j] = -1;
      } else {
        matriz[i][j] = 0;
      }
    }
  }

  printf("Matriz gerada:\n");
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      printf("%2d ", matriz[i][j]);
    }
    printf("\n");
  }

  for(i = 0; i < N; i++){
    free(matriz[i]);
  }
  free(matriz);
  return 0;
}
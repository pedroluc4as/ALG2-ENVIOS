#include<stdio.h>
#include<stdlib.h>

int buscaNaMatriz(int **matriz, int linhas, int colunas, int valor){
  int i, j;
  for(i = 0; i < linhas; i++){
    for(j = 0; j < colunas; j++){
      if(matriz[i][j] == valor){
        return 1;
      }
    }
  }
  return 0;
}

int main(){
  int **matriz;
  int linhas, colunas, valorBusca;
  int i, j;

  printf("Digite o numero de linhas da matriz: ");
  scanf("%d", &linhas);
  printf("Digite o numero de colunas da matriz: ");
  scanf("%d", &colunas);
  
  matriz = (int**) malloc(linhas * sizeof(int*));
  if(matriz == NULL){
    printf("Erro de alocacao.\n"); return 1;
  }
  for(i = 0; i < linhas; i++){
    matriz[i] = (int*) malloc(colunas * sizeof(int));
    if(matriz[i] == NULL){
      printf("Erro de alocacao.\n"); return 1;
    }
  }

  printf("Digite os elementos da matriz:\n");
  for(i = 0; i < linhas; i++){
    for(j = 0; j < colunas; j++){
      printf("Elemento [%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }
  
  printf("Digite o valor a ser buscado na matriz: ");
  scanf("%d", &valorBusca);

  if(buscaNaMatriz(matriz, linhas, colunas, valorBusca)){
    printf("O valor %d ESTA na matriz.\n", valorBusca);
  } else {
    printf("O valor %d NAO ESTA na matriz.\n", valorBusca);
  }
  
  for(i = 0; i < linhas; i++){
    free(matriz[i]);
  }
  free(matriz);

  return 0;
}
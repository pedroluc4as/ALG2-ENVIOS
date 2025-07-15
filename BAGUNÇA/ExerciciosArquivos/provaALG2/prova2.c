#include<stdio.h>
#include<stdlib.h>

#define LINHAS 10
#define COLUNAS 10 

int calcularMedia (int mediaMatriz[LINHAS][COLUNAS]){
  int soma = 0, mediaResultado = 0;
  for(int i = 0; i < LINHAS; i++){
    for(int j = 0; j < COLUNAS; j++){
      soma += mediaMatriz[i][j];
    }
  }
  mediaResultado = soma / (LINHAS*COLUNAS);
  return(mediaResultado);
}

int main(){
  int matriz[LINHAS][COLUNAS] = {
      {1, 1, 1},
      {1, 1, 1}
  };

  int media = calcularMedia(matriz);
  printf("a media é:%d\n", media);
  return 0;
}
#include<stdio.h>
#include<stdlib.h>

int main(){
  float matriz[3][3];
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      printf("Endereço da %d° linha e da %d° coluna posição do array de float: %p\n", i, j, (void*)&matriz[i][j]);
    }
    printf("\n");
  }
return 0;
}
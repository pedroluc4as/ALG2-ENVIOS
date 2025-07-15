#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *vet, int tamanho){
  for(int i = 0; i < tamanho; i++){
    printf("O valor na posicao %d e: %d\n", i, *(vet + i));
  }
  printf("\n");
}
 
int main(){
  int vet[5] = {100, 250, 31, 48, 55};
  int tamanho = 5;

  imprimeVetor(vet, tamanho);

  return 0;
}
#include<stdio.h>
#include<stdlib.h>

int main(){
  int tamanho;
  int *vetor;
  int i;

  printf("Digite o tamanho do vetor: ");
  scanf("%d", &tamanho);

  vetor = (int*) malloc(tamanho * sizeof(int));

  if(vetor == NULL){
    printf("Erro de alocacao de memoria.\n");
    return 1;
  }

  printf("Digite os %d elementos do vetor:\n", tamanho);
  for(i = 0; i < tamanho; i++){
    printf("Elemento %d: ", i);
    scanf("%d", vetor + i);
  }

  printf("\nVetor lido:\n");
  for(i = 0; i < tamanho; i++){
    printf("%d ", *(vetor + i));
  }
  printf("\n");

  free(vetor);

  return 0;
}
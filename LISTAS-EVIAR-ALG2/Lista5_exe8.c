/*8) Crie uma função que receba dois parâmetros: um vetor e um valor do mesmo tipo do
vetor. A função deverá preencher os elementos de vetor com esse valor. Não utilize
índices para percorrer o vetor, apenas aritmética de ponteiros.*/
#include <stdio.h>
#include <stdlib.h>

void preencheVet(int *vet, int tamanho, int vlr){
  for(int i = 0; i < tamanho; i++){
    *(vet + i) = vlr; //mesma coisa que eu fazer vet[i] = vlr;
  }
}

int main(){
  int vetor[5];
  int tamanhoDoVetor = 5;
  int valor = 10;

  printf("Chamando a funcao para preencher o vetor com o valor %d...\n\n", valor);
  preencheVet(vetor, tamanhoDoVetor, valor);
  
  printf("Resultado:\n");
  for(int i = 0; i < tamanhoDoVetor; i++){
    printf("O valor na posicao %d e: %d\n", i, *(vetor + i));
  }

  return 0;
}
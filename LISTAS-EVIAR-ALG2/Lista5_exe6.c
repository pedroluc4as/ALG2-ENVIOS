#include<stdio.h>
#include<stdlib.h>

int main(){
  int array[5];
  int *p = array;
  for(int i = 0; i < 5; i++){
    printf("Digite o valor da %d° posição:\n",i);
    scanf("%d",&array[i]);
    if(array[i] % 2 == 0){
      printf("Endereco da posicao do valor par do indice %d do array: %p\n", i, (void*)&array[i]);
    }
  }
return 0;
}
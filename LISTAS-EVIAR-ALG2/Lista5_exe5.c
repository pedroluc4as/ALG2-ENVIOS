#include<stdio.h>
#include<stdlib.h>

int main(){
  int array[5];
  int *p = array;
  for(int i = 0; i < 5; i++){
    printf("Digite o valor da %d° posição:\n",i);
    scanf("%d",p+i);
    printf("Doboro do valor da %d° posição do array: %d\n", i, *(p+i)*2);
  }
return 0;
}
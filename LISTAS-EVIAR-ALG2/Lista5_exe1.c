#include<stdio.h>
#include<stdlib.h>

int main(){
  int v1;
  int v2;

  int *ptr1, *ptr2;

  ptr1 = &v1;
  ptr2 = &v2;

  if(ptr1 > ptr2){
    printf("Variavel v1 = %d tem o maior endereço %p\n",v1, ptr1);
  }
  else{
    printf("Variavel v2 = %d tem o maior endereço %p\n",v2, ptr2);
  }
return 0;
}
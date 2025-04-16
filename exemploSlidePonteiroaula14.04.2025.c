#include<stdio.h>

int main()
{
  int a = 5;
  int *pa;
  pa = &a;

  printf("\n O endereco do ponteiro %p", &pa);
  printf("\n O endereco da variavel que foi atribuida ao ponteiro %p", pa);
  printf("\n O valor da variavel sendo impressa pelo ponteiro %d", *pa);

  printf("\n O endereco da varivavel a %p\n", &a);


  return 0;
}
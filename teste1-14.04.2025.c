#include<stdio.h>

int main()
{
  int a = 5;
  int *pa;
  int *p;
  pa = &a;
  
  p = pa;

  *pa = 10;
  printf("\n O valor da variavel a %d", a);


  printf("\n O endereco do ponteiro pa %p", &pa);
  printf("\n O endereco da variavel que foi atribuida ao ponteiro %p", pa);
  printf("\n O valor da variavel sendo impressa pelo ponteiro %d", *pa);

  printf("\n O endereco da varivavel a %p\n", &a);

  printf("\n O endereco da variavel que foi atribuida ao ponteiro p %p", p);
  printf("\n O valor da variavel sendo impressa pelo ponteiro p %d\n", *p);

  return 0;
}
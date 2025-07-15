#include <stdio.h>
#include <stdlib.h>

int main(){
  int a, *b, **c, ***d;

  printf("Digite um valor inteiro:\n");
  scanf("%d",&a);

  b = &a;
  c = &b;
  d = &c;

  printf("O valor original (via *b) e: %d\n", *b);
  printf("O dobro e: %d\n", (*b) * 2);

  printf("O valor original (via **c) e: %d\n", **c);
  printf("O triplo e: %d\n", (**c) * 3);

  printf("O valor original (via ***d) e: %d\n", ***d);
  printf("O quadruplo e: %d\n", (***d) * 4);

  return 0;
}

#include<stdio.h>
#include<stdlib.h>

int main (){
  char a;
  int b;
  float c;
  double d;
  printf("char --> %lu", sizeof(a));
  printf("\nint --> %lu", sizeof(b));
  printf("\nfloat --> %lu", sizeof(c));
  printf("\ndouble --> %lu", sizeof(d));
  return 0;
}
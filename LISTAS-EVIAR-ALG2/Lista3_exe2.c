
#include<stdio.h>
#include<stdlib.h>

struct aluno{
  int matricula;
  char nome[100];
  int p1;
  int p2;
  int p3;
};

int main(){
  printf("Tamanho em bytes da Struct Aluno --> %lu",sizeof(struct aluno));
  return 0;
}
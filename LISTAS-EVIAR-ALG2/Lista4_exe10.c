/*Usando a estrutura “atleta” do exercício anterior, escreva um programa que leia os
dados de cinco atletas e os exiba por ordem de idade, do mais velho para o mais novo.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Atleta
{
  char nome[100];
  char esporte[100];
  int idade;
  float altura;
};

int main()
{
  struct Atleta a[5];
  for (int i = 0; i < 5; i++)
  {
    printf("Digite nome, esporte, idade e altura do atleta %d:\n", i + 1);
    scanf("%s %s %d %f", a[i].nome, a[i].esporte, &a[i].idade, &a[i].altura);
  }

  // Ordenação por idade (do mais velho para o mais novo)
  for (int i = 0; i < 4; i++)
  {
    for (int j = i + 1; j < 5; j++)
    {
      if (a[j].idade > a[i].idade)
      {
        struct Atleta temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }

  printf("\nAtletas em ordem do mais velho para o mais novo:\n");
  for (int i = 0; i < 5; i++)
  {
    printf("%s %s %d %.2f\n", a[i].nome, a[i].esporte, a[i].idade, a[i].altura);
  }
  return 0;
}
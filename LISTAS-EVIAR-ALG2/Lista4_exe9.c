/*Crie uma estrutura representando um atleta. Essa estrutura deve conter o nome do
atleta, seu esporte, idade e altura. Agora, escreva um programa que leia os dados de cinco
atletas. Calcule e exiba os nomes do atleta mais alto e do mais velho.*/
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
 
int main(){
  struct Atleta a[5];
  for(int i = 0; i < 5; i++){
    printf("Digite nome, esporte, idade e altura do atleta %d:\n", i+1);
    scanf("%s %s %d %f", a[i].nome, a[i].esporte, &a[i].idade, &a[i].altura);
  }
  int maisAlto = 0;
  int maisVelho = 0;
  for(int i = 1; i < 5; i++){
    if(a[i].altura > a[maisAlto].altura){
      maisAlto = i;
    }
    if(a[i].idade > a[maisVelho].idade){
      maisVelho = i;
    }
  }
  printf("Atleta mais alto: %s\n", a[maisAlto].nome);
  printf("Atleta mais velho: %s\n", a[maisVelho].nome);
  return 0;
}
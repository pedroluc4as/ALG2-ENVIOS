/*Crie uma estrutura capaz de armazenar o nome e a data de nascimento de uma pessoa.
Agora, escreva um programa que leia os dados de seis pessoas. Calcule e exiba os nomes
da pessoa mais nova e da mais velha.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Data
{
  int dia, mes, ano;
};

struct Pessoa
{
  char nome[100];
  struct Data dtNasc;
};

int main()
{
  struct Pessoa p[6];
  for (int i = 0; i < 6; i++)
  {
    printf("Digite os dados da %d° pessoa (Nome, Data de Nascimento):\n", i + 1);
    scanf("%s %d %d %d", p[i].nome, &p[i].dtNasc.dia, &p[i].dtNasc.mes, &p[i].dtNasc.ano);
  }
  int pVelha = 0;
  int pNova = 0;
  for (int i = 1; i < 6; i++)
  {
    if(p[i].dtNasc.ano < p[pVelha].dtNasc.ano || (p[i].dtNasc.ano == p[pVelha].dtNasc.ano && p[i].dtNasc.mes < p[pVelha].dtNasc.mes) || (p[i].dtNasc.ano == p[pVelha].dtNasc.ano && p[i].dtNasc.mes == p[pVelha].dtNasc.mes && p[i].dtNasc.dia < p[pVelha].dtNasc.dia)){
      pVelha = i;
    }
    if(p[i].dtNasc.ano > p[pNova].dtNasc.ano || (p[i].dtNasc.ano == p[pNova].dtNasc.ano && p[i].dtNasc.mes > p[pNova].dtNasc.mes) || (p[i].dtNasc.ano == p[pNova].dtNasc.ano && p[i].dtNasc.mes == p[pNova].dtNasc.mes && p[i].dtNasc.dia > p[pNova].dtNasc.dia)){
      pNova = i;
    }
  }
  printf("Pessoa mais velha: %s\n", p[pVelha].nome);
  printf("Pessoa mais nova: %s\n", p[pNova].nome);
  return 0;
}
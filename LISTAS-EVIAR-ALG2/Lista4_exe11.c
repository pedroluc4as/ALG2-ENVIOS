/*Escreva um programa que contenha uma estrutura representando uma data válida.
Essa estrutura deve conter os campos dia, mês e ano. Em seguida, leia duas datas e
armazene nessa estrutura. Calcule e exiba o número de dias que decorreram entre as duas
datas.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Data {
  int dia;
  int mes;
  int ano;
};

int bissexto(int ano){
  if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
    return 1;
  }
  return 0;
}

long int dataParaDias(struct Data dt){
  long int totalDias = 0;
  int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  for(int i = 1; i < dt.ano; i++){
    totalDias += 365 + bissexto(i);
  }

  for(int i = 0; i < dt.mes - 1; i++){
    totalDias += diasNoMes[i];
  }

  if(dt.mes > 2 && bissexto(dt.ano)){
    totalDias++;
  }

  totalDias += dt.dia;

  return totalDias;
}

int main(){
  struct Data data1, data2;

  printf("Digite a primeira data (DD MM AAAA):\n");
  scanf("%d %d %d", &data1.dia, &data1.mes, &data1.ano);

  printf("Digite a segunda data (DD MM AAAA):\n");
  scanf("%d %d %d", &data2.dia, &data2.mes, &data2.ano);

  long int diasData1 = dataParaDias(data1);
  long int diasData2 = dataParaDias(data2);

  long int diferenca = abs(diasData2 - diasData1);

  printf("\nO numero de dias que decorreram entre as duas datas e: %ld\n", diferenca);

  return 0;
}
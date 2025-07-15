/*Crie uma estrutura representando uma hora. Essa estrutura deve conter os campos hora,
minuto e segundo. Agora, escreva um programa que leia um vetor de cinco posições dessa
estrutura e imprima a maior hora.*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Horas {
  int hora, minuto, segundo;
};

int main(){
  struct Horas h[5];
  
  for(int i = 0; i < 5; i++){
    printf("Digite a %d° hora HH/MM/SS:\n", i+1);
    scanf("%d %d %d",&h[i].hora, &h[i].minuto, &h[i].segundo);
  }
  int maiorHora = 0;
  for(int i = 1; i < 5; i++){
    if(h[i].hora > h[maiorHora].hora || (h[i].hora == h[maiorHora].hora && h[i].minuto > h[maiorHora].minuto) || (h[i].hora == h[maiorHora].hora && h[i].minuto == h[maiorHora].minuto && h[i].segundo > h[maiorHora].segundo)){
      maiorHora = i;
    }
  }
  printf("Maior hora: \n%dh:%dm:%ds\n",h[maiorHora].hora, h[maiorHora].minuto, h[maiorHora].segundo);
return 0;
}
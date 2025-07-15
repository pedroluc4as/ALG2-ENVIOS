/*2) Crie uma estrutura para representar as coordenadas de um ponto no plano 
(posições X e Y). 
Em seguida, declare e leia do teclado um ponto e exiba a distância dele até 
a origem das coordenadas, isto é, a posição (0,0).*/
#include<stdio.h>
#include<stdio.h>
#include<math.h>

struct posicao
{
  int y;
  int x;
};

int main(){
  struct posicao distancia;
  printf("Digite o ponto x: ");
  scanf("%d", &distancia.x);

  printf("Digite o ponto y: ");
  scanf("%d", &distancia.y);

  float calculoDistancia;

  calculoDistancia = sqrt(distancia.x * distancia.x + distancia.y * distancia.y);

  printf("A distância até a origem é: %.2f\n", calculoDistancia);
return 0;
}
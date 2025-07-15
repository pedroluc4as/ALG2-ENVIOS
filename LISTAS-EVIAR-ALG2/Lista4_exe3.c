/*Crie uma estrutura para representar as coordenadas de um ponto no plano 
(posições X e Y). 
Em seguida, declare e leia do teclado dois pontos e exiba a distância entre eles.*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct pontoPlano
{
  double posX;
  double posY;
};

int main() {

struct pontoPlano p1, p2;
printf("digite o valor de x e y do primeiro ponto, um valor apos o outro utilizando a tecla enter:\n");
scanf("%lf \n %lf",&p1.posX, &p1.posY);

printf("digite o valor de x e y do segundo ponto, um valor apos o outro utilizando a tecla enter:\n");
scanf("%lf \n %lf",&p2.posX, &p2.posY);

double distancia = sqrt(pow(p2.posX - p1.posX, 2)) + (pow(p2.posY - p1.posY, 2));
distancia = sqrt(distancia);

printf("%.2lf\n",distancia);
return 0;
}
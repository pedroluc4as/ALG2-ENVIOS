/*Usando a estrutura Retângulo do exercício anterior, faça um programa que declare e
leia uma estrutura Retângulo e um Ponto, e informe se esse ponto está ou não dentro do
retângulo.*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Ponto {
  double posX;
  double posY;
};

struct Retangulo {
  struct Ponto supEsq;
  struct Ponto infDir;
};

int main() {
    struct Retangulo ret;
    struct Ponto p;

    printf("digite as coordenadas do ponto superior esquerdo do retangulo (x y): \n");
    scanf("%lf %lf", &ret.supEsq.posX, &ret.supEsq.posY);

    printf("digite as coordenadas do ponto inferior direito do retangulo (x y): \n");
    scanf("%lf %lf", &ret.infDir.posX, &ret.infDir.posY);

    printf("digite as coordenadas do ponto a ser testado (x y): \n");
    scanf("%lf %lf", &p.posX, &p.posY);

  
    if(p.posX >= ret.supEsq.posX && p.posX <= ret.infDir.posX && p.posY >= ret.infDir.posY && p.posY <= ret.supEsq.posY) {
        printf("o ponto esta dentro do retangulo.\n");
    } 
    else {
        printf("o ponto NAO está dentro do retangulo.\n");
    }

    return 0;
}
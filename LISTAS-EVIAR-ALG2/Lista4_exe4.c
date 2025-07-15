/*4) Crie uma estrutura chamada Retângulo. Essa estrutura deverá conter o ponto superior
esquerdo e o ponto inferior direito do retângulo. Cada ponto é definido por uma estrutura
Ponto, a qual contém as posições X e Y. Faça um programa que declare e leia uma
estrutura Retângulo e exiba a área e o comprimento da diagonal e o perímetro desse
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
  printf("Digite as coordenadas do ponto superior esquerdo (x y): \n");
  scanf("%lf %lf",&ret.supEsq.posX, &ret.supEsq.posY);

  printf("Digite as coordenadas do ponto inferior direito (x y): \n");
  scanf("%lf %lf",&ret.infDir.posX, &ret.infDir.posY);

  double base, altura, area, compDiagonal, perimetro;

  base = (ret.infDir.posX -  ret.supEsq.posX);
  altura = (ret.supEsq.posY - ret.infDir.posY);
  area = base * altura;
  perimetro = 2 * (base + altura);
  compDiagonal = sqrt(base * base + altura * altura);

  printf("AREA: %.2lf\n COMPRIMENTO DIAGONAL:%.2lf\n PERIMETRO:%.2lf\n", area, compDiagonal, perimetro);

return 0;
}
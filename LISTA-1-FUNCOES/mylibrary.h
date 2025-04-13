#include <stdio.h>
#include <math.h>
//printf OI
void oi()
{
  printf("OI\n");
}

//printf
void printmsg(char msg[50])
{
  printf("%s", msg);
}

char* printarRetornarOk (char texto[50])
{
  printf("%s", texto);

  return "ok";
}

void calcularBaskara (float a, float b, float c)
{
  float delta = 0;
  float x1 = 0;
  float x2 = 0;
  
  delta = (b*b) - (4 * a * c);
  if(delta <0)
  {
    printf("impossivel calcular, pois o valor de delta e negativo = (%f).\n",delta);
  }
  else
  {
    x1 = (-b + sqrt(delta)) / (2*a);
    x2 = (-b - sqrt(delta)) / (2*a);

    printf("delta existe! = (%3.f)\n",delta);
    printf("x1 = %.2f\n", x1);
    printf("x2 = %.2f\n", x2);
  }
  }

  void conversaoTempo (int tempoemSegundos)
  {
    int segundos = 0;
    int segundosResto = 0;
    int minutos = 0;
    int minutosResto = 0;
    int horas = 0;
    int horasResto = 0;
    
    minutos = tempoemSegundos / 60;
    minutosResto = minutos % 60;
    horas = minutos / 60;
    horasResto = minutos % 60;
    segundosResto = tempoemSegundos % 60;
    
  printf("eis o valor em HH:MM:SS:\n %dh:%dm:%ds",horas, minutosResto, segundosResto);
  }

  


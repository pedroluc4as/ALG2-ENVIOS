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

  int calculoDiasdeVida (int anos, int meses, int dias)
  {
    int diasVida = 0;

    if(anos > 100 || anos < 1 || meses > 12 || meses < 1 || dias > 31 || dias < 1)  
    {
      printf("insira uma data valida!");
    }
    else
    {
      diasVida = 0;
      diasVida = anos * 365;
      diasVida+= meses * 31;
      diasVida+= dias;
    
      printf("voce tem aproximadamente %d dias de idade!\n",diasVida);
    }
  
  return diasVida;
  }

  int valorPerfeito (int valor)
  {
    int verdadeiroFalso = 0;
  
  return verdadeiroFalso;
  }

  int idadeCategoriaNadador (int idade)
  {
    printf("Insira a idade do nadador para visualizar sua categoria!\n");
    scanf("%d",&idade);
    if(idade <= 0)
    {
      printf("insira uma idade valida!\n");
    }
    else if(idade >= 5 && idade <= 7)
    {
      printf("nadador na categoria Infantil A");
    }
    else if(idade >= 8 && idade <= 10)
    {
      printf("nadador na categoria Infantil B");
    }
    else if(idade >= 11 && idade <= 13)
    {
      printf("nadador na categoria Juvenil A");
    }
    else if(idade >= 14 && idade <= 17)
    {
      printf("nadador na categoria Juvenil B");
    }
    else if(idade >= 18)
    {
      printf("nadador na categoria Adulto");
    }
    else
    {
      printf("a idade do nadador nao se encaixa em nenhuma das categorias!\n");
    }
  }

  int verificarValorPositivoNegativo (int valor)
  {
    if(valor > 0)
    {
      return valor;
    }
    else
    {
      return valor;
    }
  }

    int verificarValorParImpar (int valor)
  {
    int numero = 0;
    if (numero % 2 == 0)
    {
      return valor;
    }
    else
    {
      return valor;
    }
  }

  char mediaConceitoAluno (int media)
  {
  if(media < 0)
    {
      printf("insira uma media valida!\n");
    }
    else if(media >= 0.0 && media <= 4.9)
    {
      return 'D';
    }
    else if(media >= 5.0 && media <= 6.9)
    {
      return 'C';
    }
    else if(media >= 7.0 && media <= 8.9)
    {
      return 'B';
    }
    else if(media >= 9.0 && media <= 10.0)
    {
      return 'A';
    }
    else
    {
      printf("a media do estudante nao se encaixa em nenhum conceito!\n");
    }
  }

  int ordemCrescente (int vet[3])
  {
    int ordem = 0;
    int temp = 0;

    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        if(vet[i] > vet[j])
        {
          temp = vet[j];
          vet[j] = vet[i];
          vet[i] = temp;
        }
      }
    }
    for(int i = 2; i >= 0; i--)
    {
      printf("%d ",vet[i]);
    } 
  return ordem;
  }

  int verificarExistenciaTriangulo (int lado_a, int lado_b, int lado_c)
  {
    if(((((lado_a + lado_b) > lado_c) && (abs (lado_a - lado_b) < lado_c) && ((lado_a + lado_c) > lado_b) && (abs (lado_a - lado_c) < lado_b) && ((lado_b + lado_c) > lado_a) && (abs (lado_b - lado_c) < lado_a))))
    {
      printf("E UM TRIANGULO, DO TIPO ");

      if((lado_a == lado_b ) && (lado_a == lado_c))
      {
        printf("EQUILATERO, TODOS LADOS SAO IGUAIS!");
      }
      if(((((lado_a == lado_b) && (lado_a != lado_c)) || ( (lado_a == lado_c) && (lado_a != lado_b))) || ((lado_b == lado_c) && (lado_b != lado_a))))
      {
        printf("ISOSCELES, DOIS LADOS SAO IGUAIS!");
      }
      if((((lado_a != lado_b) && (lado_a != lado_c)) && (lado_b != lado_c)))
      {
        printf("ESCALENO, TODOS LADOS SAO DIFERENTES!");
      }
    }
    else
    {
      printf("TRIANGULO INEXISTENTE!");
    }
    
}

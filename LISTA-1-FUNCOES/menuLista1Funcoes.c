#include <stdio.h>
#include <stdlib.h>
#include "mylibrary.h"

int main()
{
  int menu;
  int sair = 1;

  while(sair == 1)
  {
    printf("Escolha uma opcao com o teclado numerico para o programa ser executado: \n");
    printf("1 - Funcao imprimir OI\n");
    printf("2 - Funcao imprimir texto\n");
    printf("3 - Funcao imprimir texto\n");
    printf("4 - Calculo formula de Baskara\n");
    printf("5 - Conversao de segundos para o padrao (HH:MM:SS)\n");
    printf("6 - \n");
    printf("7 - \n");
    printf("8 - \n");
    printf("9 - \n");
    printf("10 - \n");
    printf("11 - \n");
    printf("12 - \n");
    printf("13 - \n");
    printf("14 - \n");
    printf("15 - \n");
    
    scanf("%d",&menu);
    switch (menu)
    {
      case 1:
        oi();
      break;
      
      case 2:
        char msg[50];
        printf("digite um texto: \n");
        scanf("%s", &msg);
        printmsg(msg);
      break;

      case 3:
        char texto[100];
        printf("digite um texto: \n");
        scanf("%s", texto);
        char* ok = printarRetornarOk(texto);
        printf("\n%s",ok);
      break;
      case 4:
        float a, b, c;
        printf("insira o valor de a: \n");
        scanf("%f", &a);
        printf("insira o valor de b: \n");
        scanf("%f", &b);
        printf("insira o valor de c: \n");
        scanf("%f", &c);
        calcularBaskara(a, b, c);
      break;
      case 5:
        int tempo = 0;
        printf("digite o valor do tempo em segundos: \n");
        scanf("%d",&tempo);
        conversaoTempo(tempo);
      break;
      default:
      break;
    }

    printf("\nSe deseja continuar no programa digite 1");
    printf("\nSe deseja sair do programa digite 0:\n");
    scanf("%d", &sair);
  }

  return 0;
}
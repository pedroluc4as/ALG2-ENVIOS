#include <stdio.h>
#include <stdlib.h>
#include "mylibrary.h"

int main()
{
  int menu;
  int sair = 1;

  while(sair == 1)
  {
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
        cinco
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
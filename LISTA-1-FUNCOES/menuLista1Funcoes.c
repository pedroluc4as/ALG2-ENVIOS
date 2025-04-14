#include <stdio.h>
#include <stdlib.h>
#include "mylibrary.h"
#include <stdbool.h>

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
    printf("6 - Conversao anos de vida para dias de vida\n");
    printf("7 - Verificar se um valor e perfeito\n");
    printf("8 - Identificar a categoria do nadador por meio de sua idade\n");
    printf("9 - Verificar se um valor inteiro e positivo ou negativo\n");
    printf("10 - Verificar se um valor inteiro e par ou impar\n");
    printf("11 - Verificar a qual conceito o aluno se encaixa atraves da media de suas notas\n");
    printf("12 - Imprimir tres valores inteiros em ordem crescente\n");
    printf("13 - Identificar o tipo do triangulo\n");
    printf("14 - Media de valores positivos\n");
    printf("15 - Transformar X e Z em potencia e calcular\n");
    
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
      case 6:
        int diasVida = 0;
        int anos = 0;
        int meses = 0;
        int dias = 0;

        printf("digite sua idade:\n");
        printf("Anos:\n");
        scanf("%d",&anos);
        printf("Meses:\n");
        scanf("%d",&meses);
        printf("Dias:\n");
        scanf("%d",&dias);
        calculoDiasdeVida(anos, meses, dias);
      break;

      case 7:
      int numero;
      printf("Digite um valor:\n");
      scanf("%d", &numero);
      bool verdadeiro_falso = numeroPerfeito(numero);
      printf("\n %d \n", verdadeiro_falso);
      break;

      case 8:
      int idade;
      idadeCategoriaNadador(idade);
      break;

      case 9:
      int valor;
      printf("insira um valor inteiro:\n");
      scanf("%d", &valor);
      valor = verificarValorPositivoNegativo(valor);
      printf("%d",valor);
      break;

      case 10:
      int numero1 = 0;
      printf("insira um valor inteiro:\n");
      scanf("%d", &numero1);
      numero1 = verificarValorParImpar(numero1);
      printf("%d",numero1);
      break;

      case 11:
      float media;
      printf("insira a media final do aluno:\n");
      scanf("%f", &media);
      char conceito = mediaConceitoAluno(media);
      printf("estudante conceito %c",conceito);
      break;

      case 12:
      int valor1[3];
      printf("insira tres valores:\n");
      for(int i = 0; i < 3; i++)
      {
        scanf("%d", &valor1[i]);
      }
      ordemCrescente(valor1);
      break;

      case 13:
      int lado_a, lado_b, lado_c;
      printf("DIGITE UM VALOR a: \n");
      scanf("%d",&lado_a);
      printf("DIGITE UM VALOR b: \n");
      scanf("%d",&lado_b);
      printf("DIGITE UM VALOR c: \n");
      scanf("%d",&lado_c);
      verificarExistenciaTriangulo(lado_a, lado_b, lado_c);
      break;

      case 14:  
      int n;
      printf("insira um valor para n:\n");
      scanf("%d", &n);
      int mediaN = mediaNnumeros(n);
      printf("Media = %d\n", mediaN);
      break;

      case 15:
      int base, expoente;
      printf("\nDigite um valor para x: ");
      scanf("%d", &base);
      printf("\nDigite um valor para y: ");
      scanf("%d", &expoente);
      int potencia =  calcular_potencia(base, expoente);
      printf("\nBase %d elevado a %d = %d \n", base, expoente, potencia);
      break;

      default:
      printf("Por obsequio digite uma opcao valida!\n");
      break;
    }

    printf("\nSe deseja continuar no programa digite 1");
    printf("\nSe deseja sair do programa digite 0:\n");
    scanf("%d", &sair);
  }

  return 0;
    
}
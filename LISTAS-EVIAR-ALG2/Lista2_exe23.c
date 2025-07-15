#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
  FILE *produtos;
  char *url_produtos = "PRODUTOS.txt";
  int Codigo, encontrado = 0;
  char Descricao[100];
  float Preco, precoMin, precoMax;
  char letra;

  printf("Digite a letra inicial para a busca: ");
  scanf(" %c", &letra);
  printf("Digite o preco minimo: ");
  scanf("%f", &precoMin);
  printf("Digite o preco maximo: ");
  scanf("%f", &precoMax);

  letra = toupper(letra);

  produtos = fopen(url_produtos, "r");
  if(produtos == NULL){
    printf("Erro: Arquivo PRODUTOS.txt nao encontrado.\n");
    return 1;
  }
  
  printf("\n--- Resultado da Busca ---\n");
  fscanf(produtos, "%*[^\n]\n");
  while(fscanf(produtos, " %d,%[^,],%f", &Codigo, Descricao, &Preco) != EOF){
    if(toupper(Descricao[0]) == letra && Preco >= precoMin && Preco <= precoMax){
      printf("Cod: %d, Descricao: %s, Preco: %.2f\n", Codigo, Descricao, Preco);
      encontrado = 1;
    }
  }

  if(encontrado == 0){
    printf("Nenhum produto encontrado com os criterios especificados.\n");
  }

  fclose(produtos);
  return 0;
}
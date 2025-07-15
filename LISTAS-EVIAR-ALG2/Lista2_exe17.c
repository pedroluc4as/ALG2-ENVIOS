#include<stdio.h>
#include<stdlib.h>
 
int main(){
  FILE *produtos;
  char *url_produtos = "PRODUTOS.txt";
  int Codigo, encontrado = 0;
  char Descricao[100];
  float Preco;

  produtos = fopen(url_produtos, "r");
  if(produtos == NULL){
    printf("Erro: Arquivo PRODUTOS.txt nao encontrado.\n");
    return 1;
  }

  printf("--- Produtos com preco superior a R$ 500.00 ---\n");
  fscanf(produtos, "%*[^\n]\n");
  while(fscanf(produtos, " %d,%[^,],%f", &Codigo, Descricao, &Preco) != EOF){
    if(Preco > 500.00){
      printf("Descricao: %s\n", Descricao);
      encontrado = 1;
    }
  }

  if(encontrado == 0){
    printf("Nenhum produto encontrado com preco superior a R$ 500.00\n");
  }

  fclose(produtos);
  return 0;
}
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

  printf("--- Produtos cujo nome comeca com a letra 'M' ---\n");
  fscanf(produtos, "%*[^\n]\n");
  while(fscanf(produtos, " %d,%[^,],%f", &Codigo, Descricao, &Preco) != EOF){
    if(Descricao[0] == 'M' || Descricao[0] == 'm'){
      printf("Cod: %d, Descricao: %s, Preco: %.2f\n", Codigo, Descricao, Preco);
      encontrado = 1;
    }
  }

  if(encontrado == 0){
    printf("Nenhum produto encontrado com a letra 'M'.\n");
  }

  fclose(produtos);
  return 0;
}
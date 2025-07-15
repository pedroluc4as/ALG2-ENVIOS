#include<stdio.h>
#include<stdlib.h>
 
int main(){
  FILE *produtos;
  char *url_produtos = "PRODUTOS.txt";

  produtos = fopen(url_produtos, "w");
  if(produtos == NULL){
    printf("Erro ao criar o arquivo PRODUTOS.txt\n");
    return 1;
  }

  fprintf(produtos, "Codigo,Descricao,Preco\n");
  fclose(produtos);

  printf("Arquivo PRODUTOS.txt criado com sucesso.\n");

  return 0;
}
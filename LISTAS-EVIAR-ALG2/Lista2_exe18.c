#include<stdio.h>
#include<stdlib.h>
 
int main(){
  FILE *produtos, *temp;
  char *url_produtos = "PRODUTOS.txt", *url_temp = "temp_prod.txt";
  int Codigo;
  char Descricao[100];
  float Preco, novoPreco;

  produtos = fopen(url_produtos, "r");
  temp = fopen(url_temp, "w");
  if(produtos == NULL || temp == NULL){
    printf("Erro ao abrir os arquivos.\n");
    return 1;
  }
  
  fprintf(temp, "Codigo,Descricao,Preco\n");
  fscanf(produtos, "%*[^\n]\n");
  while(fscanf(produtos, " %d,%[^,],%f", &Codigo, Descricao, &Preco) != EOF){
    novoPreco = Preco * 1.15;
    fprintf(temp, "%d,%s,%.2f\n", Codigo, Descricao, novoPreco);
  }

  fclose(produtos);
  fclose(temp);
  remove(url_produtos);
  rename(url_temp, url_produtos);

  printf("Precos de todos os produtos alterados em 15%% com sucesso.\n");
  return 0;
}
#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE *produtos, *temp;
  char *url_produtos = "PRODUTOS.txt", *url_temp = "temp_prod.txt";
  int Codigo;
  char Descricao[100];
  float Preco, precoMin, precoMax, percentual, novoPreco;
  float multiplicador;

  printf("Conceder desconto para produtos com preco entre (minimo maximo): ");
  scanf("%f %f", &precoMin, &precoMax);
  printf("Digite o percentual de desconto (ex: 10 para 10%%): ");
  scanf("%f", &percentual);

  multiplicador = 1.0 - (percentual / 100.0);

  produtos = fopen(url_produtos, "r");
  temp = fopen(url_temp, "w");
  if(produtos == NULL || temp == NULL){
    printf("Erro ao abrir os arquivos.\n");
    return 1;
  }
  
  fprintf(temp, "Codigo,Descricao,Preco\n");
  fscanf(produtos, "%*[^\n]\n");
  while(fscanf(produtos, " %d,%[^,],%f", &Codigo, Descricao, &Preco) != EOF){
    if(Preco >= precoMin && Preco <= precoMax){
      novoPreco = Preco * multiplicador;
      fprintf(temp, "%d,%s,%.2f\n", Codigo, Descricao, novoPreco);
    } else {
      fprintf(temp, "%d,%s,%.2f\n", Codigo, Descricao, Preco);
    }
  }

  fclose(produtos);
  fclose(temp);
  remove(url_produtos);
  rename(url_temp, url_produtos);

  printf("Desconto de %.2f%% aplicado com sucesso.\n", percentual);
  return 0;
}
#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE *produtos, *temp;
  char *url_produtos = "PRODUTOS.txt", *url_temp = "temp_prod.txt";
  int Codigo, Codigo_Excluir, encontrado = 0;
  char Descricao[100];
  float Preco;

  printf("Digite o codigo do produto a ser excluido: ");
  scanf("%d", &Codigo_Excluir);

  produtos = fopen(url_produtos, "r");
  temp = fopen(url_temp, "w");
  if(produtos == NULL || temp == NULL){
    printf("Erro ao abrir os arquivos.\n");
    return 1;
  }
  
  fprintf(temp, "Codigo,Descricao,Preco\n");
  fscanf(produtos, "%*[^\n]\n");
  while(fscanf(produtos, " %d,%[^,],%f", &Codigo, Descricao, &Preco) != EOF){
    if(Codigo == Codigo_Excluir){
      encontrado = 1;
    } else {
      fprintf(temp, "%d,%s,%.2f\n", Codigo, Descricao, Preco);
    }
  }
  
  fclose(produtos);
  fclose(temp);

  if(encontrado){
    remove(url_produtos);
    rename(url_temp, url_produtos);
    printf("Produto com codigo %d excluido com sucesso.\n", Codigo_Excluir);
  } else {
    remove(url_temp);
    printf("Produto com codigo %d NAO foi encontrado.\n", Codigo_Excluir);
  }
  return 0;
}
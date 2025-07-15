#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE *produtos, *temp;
  char *url_produtos = "PRODUTOS.txt", *url_temp = "temp_prod.txt";
  int Codigo;
  char Descricao[100];
  float Preco;
  int excluidos = 0;

  produtos = fopen(url_produtos, "r");
  temp = fopen(url_temp, "w");
  if(produtos == NULL || temp == NULL){
    printf("Erro ao abrir os arquivos.\n");
    return 1;
  }

  fprintf(temp, "Codigo,Descricao,Preco\n");
  fscanf(produtos, "%*[^\n]\n");
  while(fscanf(produtos, " %d,%[^,],%f", &Codigo, Descricao, &Preco) != EOF){
    if(Preco <= 200.00){
      fprintf(temp, "%d,%s,%.2f\n", Codigo, Descricao, Preco);
    } else {
      excluidos++;
    }
  }

  fclose(produtos);
  fclose(temp);
  remove(url_produtos);
  rename(url_temp, url_produtos);
  
  if(excluidos > 0){
    printf("%d produto(s) com preco superior a R$ 200.00 foram excluidos.\n", excluidos);
  } else {
    printf("Nenhum produto com preco superior a R$ 200.00 foi encontrado para excluir.\n");
  }
  
  return 0;
}
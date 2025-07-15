#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE *produtos;
  char *url_produtos = "PRODUTOS.txt";
  int Codigo, tempCod;
  char Descricao[100], tempDesc[100];
  float Preco, tempPreco;
  int codigoExiste = 0;

  printf("--- Incluir Novo Produto ---\n");
  printf("Digite o codigo do novo produto: ");
  scanf("%d", &Codigo);

  produtos = fopen(url_produtos, "r");
  if(produtos != NULL){
    fscanf(produtos, "%*[^\n]\n");
    while(fscanf(produtos, " %d,%[^,],%f", &tempCod, tempDesc, &tempPreco) != EOF){
      if(tempCod == Codigo){
        codigoExiste = 1;
        break;
      }
    }
    fclose(produtos);
  }

  if(codigoExiste){
    printf("\nErro: Ja existe um produto com o codigo %d.\n", Codigo);
  } else {
    printf("Digite a descricao do produto: ");
    scanf("%s", Descricao);
    printf("Digite o preco do produto: ");
    scanf("%f", &Preco);

    produtos = fopen(url_produtos, "a");
    if(produtos == NULL){
      printf("Erro ao abrir o arquivo para escrita.\n");
      return 1;
    }
    fprintf(produtos, "%d,%s,%.2f\n", Codigo, Descricao, Preco);
    fclose(produtos);
    printf("\nProduto cadastrado com sucesso!\n");
  }

  return 0;
}
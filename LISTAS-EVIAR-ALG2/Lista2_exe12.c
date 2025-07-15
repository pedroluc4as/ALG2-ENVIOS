#include<stdio.h>
#include<stdlib.h>
 
int main(){
  FILE *estilistas, *roupas, *estacoes;
  char *url_estilistas = "estilistas.txt";
  char *url_roupas = "roupas.txt";
  char *url_estacoes = "estacoes.txt";

  estilistas = fopen(url_estilistas, "w");
  if(estilistas == NULL){
    printf("Erro ao criar o arquivo estilistas.txt\n");
    return 1;
  }
  fprintf(estilistas, "Cod_Estilista,Nome,Salario\n");
  fclose(estilistas);

  roupas = fopen(url_roupas, "w");
  if(roupas == NULL){
    printf("Erro ao criar o arquivo roupas.txt\n");
    return 1;
  }
  fprintf(roupas, "Cod_Roupa,Descricao,Cod_Estilista,Cod_Estacao,Ano\n");
  fclose(roupas);
  
  estacoes = fopen(url_estacoes, "w");
  if(estacoes == NULL){
    printf("Erro ao criar o arquivo estacoes.txt\n");
    return 1;
  }
  fprintf(estacoes, "Cod_Estacao,Nome_Estacao\n");
  fclose(estacoes);

  printf("Arquivos estilistas.txt, roupas.txt e estacoes.txt criados com sucesso.\n");

  return 0;
}
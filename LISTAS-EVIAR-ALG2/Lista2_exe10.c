#include<stdio.h>
#include<stdlib.h>
 
int main(){
  FILE *recebimentos;
  char *url_recebimentos = "recebimentos.txt";

  int Valor_Limite;
  int encontrado = 0;

  int Num_doc, Valor_doc, Cod_Cli_Rec;
  char Data_Emissao[11], Data_Vencimento[11];

  printf("Mostrar recebimentos com valor ABAIXO de: ");
  scanf("%d", &Valor_Limite);

  recebimentos = fopen(url_recebimentos, "r");
  if(recebimentos == NULL){
    printf("Erro ao abrir arquivo de recebimentos.\n");
    return 1;
  }

  printf("\n--- Recebimentos com valor abaixo de %d ---\n", Valor_Limite);
  fscanf(recebimentos, "%*[^\n]\n");

  while(fscanf(recebimentos, "%d, %d, %[^,], %[^,], %d", &Num_doc, &Valor_doc, Data_Emissao, Data_Vencimento, &Cod_Cli_Rec) != EOF){
    if(Valor_doc < Valor_Limite){
      printf("Num Doc: %d, Valor: %d, Vencimento: %s, Cod Cli: %d\n", Num_doc, Valor_doc, Data_Vencimento, Cod_Cli_Rec);
      encontrado = 1;
    }
  }

  if(encontrado == 0){
    printf("Nenhum recebimento encontrado abaixo do valor especificado.\n");
  }

  fclose(recebimentos);
  return 0;
}
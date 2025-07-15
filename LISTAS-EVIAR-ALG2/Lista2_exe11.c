#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE *recebimentos;
  char *url_recebimentos = "recebimentos.txt";

  int Valor_Min, Valor_Max;
  int encontrado = 0;

  int Num_doc, Valor_doc, Cod_Cli_Rec;
  char Data_Emissao[11], Data_Vencimento[11];

  printf("Mostrar recebimentos com valor ENTRE (minimo maximo): ");
  scanf("%d %d", &Valor_Min, &Valor_Max);

  recebimentos = fopen(url_recebimentos, "r");
  if(recebimentos == NULL){
    printf("Erro ao abrir arquivo de recebimentos.\n");
    return 1;
  }

  printf("\n--- Recebimentos com valor entre %d e %d ---\n", Valor_Min, Valor_Max);
  fscanf(recebimentos, "%*[^\n]\n");

  while(fscanf(recebimentos, " %d, %d, %[^,], %[^,], %d", &Num_doc, &Valor_doc, Data_Emissao, Data_Vencimento, &Cod_Cli_Rec) != EOF){
    if(Valor_doc >= Valor_Min && Valor_doc <= Valor_Max){
      printf("Num Doc: %d, Valor: %d, Vencimento: %s, Cod Cli: %d\n", Num_doc, Valor_doc, Data_Vencimento, Cod_Cli_Rec);
      encontrado = 1;
    }
  }

  if(encontrado == 0){
    printf("Nenhum recebimento encontrado na faixa de valor especificada.\n");
  }

  fclose(recebimentos);
  return 0;
}
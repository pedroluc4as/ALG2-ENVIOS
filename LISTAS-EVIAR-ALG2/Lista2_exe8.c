#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE *recebimentos;
  char *url_recebimentos = "recebimentos.txt";

  int Cod_Cli_Alvo;
  int encontrado = 0;

  int Num_doc, Valor_doc, Cod_Cli_Rec;
  char Data_Emissao[11], Data_Vencimento[11];

  printf("Digite o codigo do cliente para listar os recebimentos: ");
  scanf("%d", &Cod_Cli_Alvo);

  recebimentos = fopen(url_recebimentos, "r");
  if(recebimentos == NULL){
    printf("Erro ao abrir arquivo de recebimentos.\n");
    return 1;
  }
  
  printf("\n--- Recebimentos do Cliente %d ---\n", Cod_Cli_Alvo);
  fscanf(recebimentos, "%*[^\n]\n");

  while(fscanf(recebimentos, "%d, %d, %[^,], %[^,], %d", &Num_doc, &Valor_doc, Data_Emissao, Data_Vencimento, &Cod_Cli_Rec) != EOF){
    if(Cod_Cli_Rec == Cod_Cli_Alvo){
      printf("Num Doc: %d, Valor: %d, Emissao: %s, Vencimento: %s\n", Num_doc, Valor_doc, Data_Emissao, Data_Vencimento);
      encontrado = 1;
    }
  }
  
  if(encontrado == 0){
    printf("Nenhum recebimento encontrado para este cliente.\n");
  }

  fclose(recebimentos);
  return 0;
}
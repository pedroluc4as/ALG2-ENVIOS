#include<stdio.h>
#include<stdlib.h>

int main(){

  FILE *recebimentos;
  FILE *temp;

  char *url_recebimentos = "recebimentos.txt";
  char *url_temp = "temp.txt";

  int Num_doc_Alvo;
  int Cod_Cli_Alvo;
  //novas
  int Novo_Valor_doc;
  char Nova_Data_Emissao[11];
  char Nova_Data_Vencimento[11];
  int Num_doc;
  int Valor_doc;
  char Data_Emissao[11];
  char Data_Vencimento[11];
  int Cod_Cli;

  int encontrado = 0; 

  printf("--- Alteracao de Recebimento ---\n");
  printf("Digite o numero do documento a ser alterado: ");
  scanf("%d", &Num_doc_Alvo);
  printf("Digite o codigo do cliente deste documento: ");
  scanf("%d", &Cod_Cli_Alvo);

  printf("\n--- Digite os novos dados ---\n");
  printf("Digite o novo valor do documento: ");
  scanf("%d", &Novo_Valor_doc);
  printf("Digite a nova data de emissao (DD/MM/AAAA): ");
  scanf("%s", Nova_Data_Emissao);
  printf("Digite a nova data de vencimento (DD/MM/AAAA): ");
  scanf("%s", Nova_Data_Vencimento);


  recebimentos = fopen(url_recebimentos, "r");
  temp = fopen(url_temp, "w");

  if(recebimentos == NULL || temp == NULL){
    printf("Erro ao abrir os arquivos de recebimentos.");
    return 1;
  }
  
  fprintf(temp, "Num_doc,  Valor_doc,  Data_Emissao,  Data_Vencimento, Cod_Cli");
  fscanf(recebimentos, "%*[^\n]\n");

  while(fscanf(recebimentos, "%d, %d, %[^,], %[^,], %d", &Num_doc, &Valor_doc, Data_Emissao, Data_Vencimento, &Cod_Cli) != EOF){
    if(Num_doc == Num_doc_Alvo && Cod_Cli == Cod_Cli_Alvo){
      fprintf(temp, "\n%d, %d, %s, %s, %d", Num_doc, Novo_Valor_doc, Nova_Data_Emissao, Nova_Data_Vencimento, Cod_Cli);
      encontrado = 1;
    } 
    else{
      fprintf(temp, "\n%d, %d, %s, %s, %d", Num_doc, Valor_doc, Data_Emissao, Data_Vencimento, Cod_Cli);
    }
  }
  
  fclose(recebimentos);
  fclose(temp);
  
  if(encontrado){
    remove(url_recebimentos);
    rename(url_temp, url_recebimentos);
    printf("\nRecebimento alterado com sucesso!\n");
  } 
  else{
    remove(url_temp);
    printf("\nRecebimento com o numero de documento e codigo de cliente informados NAO foi encontrado.\n");
  }

  return 0;
}
#include<stdio.h>

int main(){

  FILE *clientes;
  FILE *recebimentos;

  char *url = "clientes.txt";
  char *url1 = "recebimentos.txt";
  int Num_doc = 0;
  int Valor_doc = 0;
  char Data_Emissao[10];
  char Data_Vencimento[10];
  int Cod_Cli = 0;

  char Nome[100];
  char Endereco[100];
  int Fone;
  
  printf("Digite os dados do recebimento abaixo\n");
  printf("Digite o numero do documento do cliente: ");
  scanf("%d", &Num_doc);
  printf("\nDigite o valor do documento: ");
  scanf("%d", &Valor_doc);
  printf("\nDigite a data de emissao DD/MM/AAAA: ");
  scanf("%s", Data_Emissao);
  printf("\nDigite a data de vencimento DD/MM/AAAA: ");
  scanf("%s", Data_Vencimento);
  printf("\nDigite o codigo do cliente: ");
  scanf("%d", &Cod_Cli);

  recebimentos = fopen(url1, "a");
    if(recebimentos == NULL){
      printf("Erro ao abrir o arquivo");
    return 0;
    }
  fprintf(recebimentos, "\n%d, %d, %s, %s, %d", Num_doc, Valor_doc, Data_Emissao, Data_Vencimento, Cod_Cli);
  fscanf((recebimentos, "\n%d, %d, %s, %s, %d", Num_doc, Valor_doc, Data_Emissao, Data_Vencimento, Cod_Cli);

  fclose(recebimentos);
  
  clientes = fopen(url, "r");
    if(clientes == NULL){
      printf("Erro ao abrir o arquivo");
    return 0;
    }
  //fprintf(clientes, "\n%d, %s, %s, %d", Cod_Cli, Nome, Endereco, Fone);
  fclose(clientes);

return 0;
}
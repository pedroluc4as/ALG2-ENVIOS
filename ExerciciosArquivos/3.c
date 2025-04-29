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

  printf("Digite o codigo do cliente: ");
  scanf("%d", &Cod_Cli);
  printf("\nDigite o nome do cliente: ");
  scanf("%s", Nome);
  printf("\nDigite o endereco do cliente: ");
  scanf("%s", Endereco);
  printf("\nDigite o telefone do cliente: ");
  scanf("%d", &Fone);

  recebimentos = fopen(url, "a");
    if(recebimentos == NULL){
      printf("Erro ao abrir o arquivo");
    return 0;
    }
  fprintf(recebimentos, "\n%d, %d, %s, %s, %d", Num_doc, Valor_doc, Data_Emissao, Data_Vencimento, Cod_Cli);
  fclose(recebimentos);
  
  clientes = fopen(url, "r");
    if(clientes == NULL){
      printf("Erro ao abrir o arquivo");
    return 0;
    }
  fprintf(clientes, "\n%d, %s, %s, %d", Cod_Cli, Nome, Endereco, Fone);
  fclose(clientes);

return 0;
}
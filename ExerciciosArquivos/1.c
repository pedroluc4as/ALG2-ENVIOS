#include<stdio.h>

int main(){

  FILE *clientes;
  FILE *recebimentos;

  char *url = "clientes.txt";

  char *url1 = "recebimentos.txt";

  clientes = fopen(url, "w");
  fprintf(clientes, "Cod_Cli, Nome, Endereco, Fone");
  fclose(clientes);

  recebimentos = fopen(url1, "w");
  fprintf(recebimentos, "Num_doc,  Valor_doc,  Data_Emissao,  Data_Vencimento, Cod_Cli");
  fclose(recebimentos);

return 0;
}
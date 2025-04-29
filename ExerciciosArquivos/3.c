#include<stdio.h>

int main(){

  FILE *recebimentos;

  char *url = "recebimentos.txt";
  int Num_doc = 0;
  int Valor_doc = 0;
  char Data_Emissao[10];
  char Data_Vencimento[10];
  int Cod_Cli = 0;

  while()


  recebimentos = fopen(url, "a");
  fprintf(recebimentos, "\n%d, %d, %s, %s, %d", Num_doc, Valor_doc, Data_Emissao, Data_Vencimento, Cod_Cli);
  fclose(recebimentos);

return 0;
}
#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE *clientes, *recebimentos, *temp;
  char *url_clientes = "clientes.txt", *url_recebimentos = "recebimentos.txt", *url_temp = "temp.txt";
  int Cod_Cli_Excluir = 0;
  int Cod_Cli, Fone, Num_doc, Valor_doc, Cod_Cli_Rec;
  char Nome[100], Endereco[100], Data_Emissao[11], Data_Vencimento[11];

  printf("Digite o codigo do cliente a ser excluido: ");
  scanf("%d", &Cod_Cli_Excluir);

  clientes = fopen(url_clientes, "r");
  temp = fopen(url_temp, "w");
  if(clientes == NULL || temp == NULL){
    printf("Erro ao abrir arquivos de clientes."); return 1;
  }
  
  fprintf(temp, "Cod_Cli, Nome, Endereco, Fone"); 
  fscanf(clientes, "%*[^\n]\n");
  while(fscanf(clientes, " %d, %[^,], %[^,], %d", &Cod_Cli, Nome, Endereco, &Fone) != EOF){
    if(Cod_Cli != Cod_Cli_Excluir){
      fprintf(temp, "\n%d, %s, %s, %d", Cod_Cli, Nome, Endereco, Fone);
    }
  }
  fclose(clientes);
  fclose(temp);
  remove(url_clientes);
  rename(url_temp, url_clientes);

  recebimentos = fopen(url_recebimentos, "r");
  temp = fopen(url_temp, "w");
  if(recebimentos == NULL || temp == NULL){
    printf("Erro ao abrir arquivos de recebimentos."); return 1;
  }

  fprintf(temp, "Num_doc,  Valor_doc,  Data_Emissao,  Data_Vencimento, Cod_Cli");
  fscanf(recebimentos, "%*[^\n]\n");
  while(fscanf(recebimentos, " %d, %d, %[^,], %[^,], %d", &Num_doc, &Valor_doc, Data_Emissao, Data_Vencimento, &Cod_Cli_Rec) != EOF){
    if(Cod_Cli_Rec != Cod_Cli_Excluir){
      fprintf(temp, "\n%d, %d, %s, %s, %d", Num_doc, Valor_doc, Data_Emissao, Data_Vencimento, Cod_Cli_Rec);
    }
  }
  fclose(recebimentos);
  fclose(temp);
  remove(url_recebimentos);
  rename(url_temp, url_recebimentos);

  printf("\nCliente %d e todos os seus recebimentos foram excluidos com sucesso.\n", Cod_Cli_Excluir);
  return 0;
}
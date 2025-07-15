#include<stdio.h>
#include<stdlib.h>
 
int main(){
  FILE *clientes, *temp;
  char *url_clientes = "clientes.txt", *url_temp = "temp.txt";
  int Cod_Cli_Alvo, Cod_Cli, Fone;
  char Nome[100], Endereco[100];
  char Novo_Nome[100], Novo_Endereco[100];
  int Novo_Fone, encontrado = 0;

  printf("Digite o codigo do cliente a ser alterado: ");
  scanf("%d", &Cod_Cli_Alvo);

  printf("\n--- Digite os NOVOS dados para o cliente %d ---\n", Cod_Cli_Alvo);
  printf("Digite o novo nome: ");
  scanf("%s", Novo_Nome);
  printf("Digite o novo endereco: ");
  scanf("%s", Novo_Endereco);
  printf("Digite o novo telefone: ");
  scanf("%d", &Novo_Fone);

  clientes = fopen(url_clientes, "r");
  temp = fopen(url_temp, "w");
  if(clientes == NULL || temp == NULL){
    printf("Erro ao abrir arquivos."); return 1;
  }
  
  fprintf(temp, "Cod_Cli, Nome, Endereco, Fone");
  fscanf(clientes, "%*[^\n]\n");

  while(fscanf(clientes, " %d, %[^,], %[^,], %d", &Cod_Cli, Nome, Endereco, &Fone) != EOF){
    if(Cod_Cli == Cod_Cli_Alvo){
      fprintf(temp, "\n%d, %s, %s, %d", Cod_Cli_Alvo, Novo_Nome, Novo_Endereco, Novo_Fone);
      encontrado = 1;
    } else {
      fprintf(temp, "\n%d, %s, %s, %d", Cod_Cli, Nome, Endereco, Fone);
    }
  }
  fclose(clientes);
  fclose(temp);

  if(encontrado){
    remove(url_clientes);
    rename(url_temp, url_clientes);
    printf("\nCliente %d alterado com sucesso!\n", Cod_Cli_Alvo);
  } else {
    remove(url_temp);
    printf("\nCliente com codigo %d NAO foi encontrado.\n", Cod_Cli_Alvo);
  }
  return 0;
}
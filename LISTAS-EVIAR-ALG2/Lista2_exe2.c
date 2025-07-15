#include<stdio.h>

int main(){
 
  FILE *clientes;

  char *url = "clientes.txt";
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


  clientes = fopen(url, "a");
    if(clientes == NULL){
      printf("Erro ao abrir o arquivo");
    return 0;
    }
  fprintf(clientes, "\n%d, %s, %s, %d", Cod_Cli, Nome, Endereco, Fone);
  fclose(clientes);

return 0;
}
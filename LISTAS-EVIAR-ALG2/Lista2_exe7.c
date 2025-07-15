#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int bissexto(int ano){
  if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
    return 1;
  }
  return 0;
}

long int dataParaDias(int dia, int mes, int ano){
  long int totalDias = 0;
  int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int i;

  for(i = 1; i < ano; i++){
    totalDias += 365 + bissexto(i);
  }
  for(i = 0; i < mes - 1; i++){
    totalDias += diasNoMes[i];
  }
  if(mes > 2 && bissexto(ano)){
    totalDias++;
  }
  totalDias += dia;
  return totalDias;
}

int main(){
  FILE *recebimentos;
  FILE *clientes;
  char *url_recebimentos = "recebimentos.txt";
  char *url_clientes = "clientes.txt";

  char dataInicioStr[11], dataFimStr[11];
  int diaInicio, mesInicio, anoInicio;
  int diaFim, mesFim, anoFim;
  long int diasInicio, diasFim, diasVenc, diasHoje;
  int encontrado = 0;

  int Num_doc, Valor_doc, Cod_Cli_Rec;
  char Data_Emissao[11], Data_Vencimento[11];
  int diaVenc, mesVenc, anoVenc;

  int Cod_Cli;
  char Nome[100], Endereco[100], Fone[100];

  printf("Digite a data de inicio do periodo (DD/MM/AAAA): ");
  scanf("%s", dataInicioStr);
  printf("Digite a data de fim do periodo (DD/MM/AAAA): ");
  scanf("%s", dataFimStr);

  sscanf(dataInicioStr, "%d/%d/%d", &diaInicio, &mesInicio, &anoInicio);
  sscanf(dataFimStr, "%d/%d/%d", &diaFim, &mesFim, &anoFim);

  diasInicio = dataParaDias(diaInicio, mesInicio, anoInicio);
  diasFim = dataParaDias(diaFim, mesFim, anoFim);
  diasHoje = dataParaDias(14, 7, 2025);

  recebimentos = fopen(url_recebimentos, "r");
  if(recebimentos == NULL){
    printf("Erro ao abrir arquivo de recebimentos.\n");
    return 1;
  }

  printf("\n--- Recebimentos no Periodo de %s a %s ---\n", dataInicioStr, dataFimStr);
  fscanf(recebimentos, "%*[^\n]\n");

  while(fscanf(recebimentos, "%d, %d, %[^,], %[^,], %d", &Num_doc, &Valor_doc, Data_Emissao, Data_Vencimento, &Cod_Cli_Rec) != EOF){
    sscanf(Data_Vencimento, "%d/%d/%d", &diaVenc, &mesVenc, &anoVenc);
    diasVenc = dataParaDias(diaVenc, mesVenc, anoVenc);

    if(diasVenc >= diasInicio && diasVenc <= diasFim){
      encontrado = 1;
      clientes = fopen(url_clientes, "r");
      if(clientes != NULL){
        fscanf(clientes, "%*[^\n]\n");
        while(fscanf(clientes, "%d, %[^,], %[^,], %s", &Cod_Cli, Nome, Endereco, Fone) != EOF){
          if(Cod_Cli == Cod_Cli_Rec){
            long int diasAtraso = diasHoje - diasVenc;
            if(diasAtraso < 0){
              diasAtraso = 0;
            }
            printf("----------------------------------------\n");
            printf("Num Doc: %d | Valor: %d | Vencimento: %s\n", Num_doc, Valor_doc, Data_Vencimento);
            printf("Cod Cli: %d | Nome: %s | Dias em Atraso: %ld\n", Cod_Cli_Rec, Nome, diasAtraso);
            break;
          }
        }
        fclose(clientes);
      }
    }
  }

  if(encontrado == 0){
    printf("Nenhum recebimento encontrado no periodo especificado.\n");
  }

  fclose(recebimentos);
  return 0;
}
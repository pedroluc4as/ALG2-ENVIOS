#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int main(){
  int opcao;
  FILE *arquivo;

  do{
    printf("\n--- MENU ---\n");
    printf("1 - Cadastrar Estacao\n");
    printf("2 - Cadastrar Estilista\n");
    printf("3 - Cadastrar Roupa\n");
    printf("4 - Relatorio de Roupas por Estacao\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    switch(opcao){
      case 1:{
        int Cod_Estacao;
        char Nome_Estacao[100];
        printf("Digite o codigo da estacao: ");
        scanf("%d", &Cod_Estacao);
        printf("Digite o nome da estacao (ex: Primavera-Verao): ");
        scanf("%s", Nome_Estacao);
        arquivo = fopen("estacoes.txt", "a");
        if(arquivo != NULL){
          fprintf(arquivo, "%d,%s\n", Cod_Estacao, Nome_Estacao);
          fclose(arquivo);
          printf("Estacao cadastrada com sucesso!\n");
        }
        break;
      }
      case 2:{
        int Cod_Estilista;
        char Nome[100];
        float Salario;
        printf("Digite o codigo do estilista: ");
        scanf("%d", &Cod_Estilista);
        printf("Digite o nome do estilista: ");
        scanf("%s", Nome);
        printf("Digite o salario do estilista: ");
        scanf("%f", &Salario);
        arquivo = fopen("estilistas.txt", "a");
        if(arquivo != NULL){
          fprintf(arquivo, "%d,%s,%.2f\n", Cod_Estilista, Nome, Salario);
          fclose(arquivo);
          printf("Estilista cadastrado com sucesso!\n");
        }
        break;
      }
      case 3:{
        int Cod_Roupa, Cod_Estilista, Cod_Estacao, Ano;
        char Descricao[100];
        int estilistaExiste = 0, estacaoExiste = 0;
        int tempCod;
        char tempStr[100];
        float tempFloat;

        printf("Digite o codigo do estilista para a roupa: ");
        scanf("%d", &Cod_Estilista);
        printf("Digite o codigo da estacao para a roupa: ");
        scanf("%d", &Cod_Estacao);
        
        FILE *valida_estilista = fopen("estilistas.txt", "r");
        if(valida_estilista != NULL){
          fscanf(valida_estilista, "%*[^\n]\n");
          while(fscanf(valida_estilista, " %d,%[^,],%f", &tempCod, tempStr, &tempFloat) != EOF){
            if(tempCod == Cod_Estilista){
              estilistaExiste = 1;
              break;
            }
          }
          fclose(valida_estilista);
        }

        FILE *valida_estacao = fopen("estacoes.txt", "r");
        if(valida_estacao != NULL){
          fscanf(valida_estacao, "%*[^\n]\n");
          while(fscanf(valida_estacao, " %d,%s", &tempCod, tempStr) != EOF){
            if(tempCod == Cod_Estacao){
              estacaoExiste = 1;
              break;
            }
          }
          fclose(valida_estacao);
        }
        
        if(estilistaExiste && estacaoExiste){
          printf("Digite o codigo da roupa: ");
          scanf("%d", &Cod_Roupa);
          printf("Digite a descricao da roupa: ");
          scanf("%s", Descricao);
          printf("Digite o ano da colecao: ");
          scanf("%d", &Ano);
          arquivo = fopen("roupas.txt", "a");
          if(arquivo != NULL){
            fprintf(arquivo, "%d,%s,%d,%d,%d\n", Cod_Roupa, Descricao, Cod_Estilista, Cod_Estacao, Ano);
            fclose(arquivo);
            printf("Roupa cadastrada com sucesso!\n");
          }
        } else {
          if(!estilistaExiste) printf("Erro: Codigo do estilista nao encontrado.\n");
          if(!estacaoExiste) printf("Erro: Codigo da estacao nao encontrado.\n");
        }
        break;
      }
      case 4:{
        int Cod_Estacao_Busca, encontrado = 0;
        printf("Digite o codigo da estacao para o relatorio: ");
        scanf("%d", &Cod_Estacao_Busca);
        
        printf("\n--- Relatorio de Roupas da Estacao %d ---\n", Cod_Estacao_Busca);
        
        FILE *roupas = fopen("roupas.txt", "r");
        if(roupas == NULL){
          printf("Arquivo de roupas nao encontrado.\n");
          break;
        }
        fscanf(roupas, "%*[^\n]\n");
        int r_Cod_Roupa, r_Cod_Estilista, r_Cod_Estacao, r_Ano;
        char r_Descricao[100];

        while(fscanf(roupas, " %d,%[^,],%d,%d,%d", &r_Cod_Roupa, r_Descricao, &r_Cod_Estilista, &r_Cod_Estacao, &r_Ano) != EOF){
          if(r_Cod_Estacao == Cod_Estacao_Busca){
            encontrado = 1;
            char e_Nome[100];
            float e_Salario;
            int e_Cod;
            FILE *estilistas = fopen("estilistas.txt", "r");
            if(estilistas != NULL){
              fscanf(estilistas, "%*[^\n]\n");
              while(fscanf(estilistas, " %d,%[^,],%f", &e_Cod, e_Nome, &e_Salario) != EOF){
                if(e_Cod == r_Cod_Estilista){
                  printf("Roupa: %s (Cod: %d) | Estilista: %s\n", r_Descricao, r_Cod_Roupa, e_Nome);
                  break;
                }
              }
              fclose(estilistas);
            }
          }
        }
        if(encontrado == 0){
          printf("Nenhuma roupa encontrada para esta estacao.\n");
        }
        fclose(roupas);
        break;
      }
    }
  } while(opcao != 0);

  return 0;
}
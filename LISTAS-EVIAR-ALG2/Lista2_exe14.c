#include<stdio.h>
#include<stdlib.h>

int main(){
  int opcao;
  FILE *arquivo;
  char *url_alunos = "alunos_notas.txt";

  do{
    printf("\n--- MENU ---\n");
    printf("1. Criar\n");
    printf("2. Incluir\n");
    printf("3. Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    switch(opcao){
      case 1:{
        arquivo = fopen(url_alunos, "w");
        if(arquivo == NULL){
          printf("Erro ao criar o arquivo.\n");
          break;
        }
        fprintf(arquivo, "Numero,Nome,Nota1,Nota2\n");
        fclose(arquivo);
        printf("Arquivo 'alunos_notas.txt' criado com sucesso.\n");
        break;
      }
      case 2:{
        int numero;
        char nome[100];
        float nota1, nota2;

        arquivo = fopen(url_alunos, "a");
        if(arquivo == NULL){
          printf("Erro: arquivo nao existe. Crie o arquivo primeiro (Opcao 1).\n");
          break;
        }
        printf("Digite o numero do aluno: ");
        scanf("%d", &numero);
        printf("Digite o nome do aluno: ");
        scanf("%s", nome);
        printf("Digite a primeira nota: ");
        scanf("%f", &nota1);
        printf("Digite a segunda nota: ");
        scanf("%f", &nota2);
        fprintf(arquivo, "%d,%s,%.2f,%.2f\n", numero, nome, nota1, nota2);
        fclose(arquivo);

        printf("\n--- REGISTROS CADASTRADOS E MEDIAS ---\n");
        arquivo = fopen(url_alunos, "r");
        if(arquivo == NULL){
          printf("Erro ao ler o arquivo.\n");
          break;
        }
        fscanf(arquivo, "%*[^\n]\n");
        while(fscanf(arquivo, " %d,%[^,],%f,%f", &numero, nome, &nota1, &nota2) != EOF){
          float media = (nota1 + nota2) / 2.0;
          printf("Aluno: %s (Num: %d) | Notas: %.2f, %.2f | Media: %.2f\n", nome, numero, nota1, nota2, media);
        }
        fclose(arquivo);
        break;
      }
      case 3:{
        printf("Saindo...\n");
        break;
      }
      default:{
        printf("Opcao invalida.\n");
        break;
      }
    }
  } while(opcao != 3);

  return 0;
}
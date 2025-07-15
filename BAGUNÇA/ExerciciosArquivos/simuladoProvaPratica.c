#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 10
#define COLUNAS 10
// GERAR MATRIZ COM VALORES ALEATORIOS
void gerarMatriz(int matriz[LINHAS][COLUNAS])
{
  srand(time(NULL));
  printf("MATRIZ DE ENTRADA ALEATORIA:\n");
  for (int i = 0; i < LINHAS; i++)
  {
    for (int j = 0; j < COLUNAS; j++)
    {
      matriz[i][j] = rand() % 256;
      printf("[%3d]", matriz[i][j]);
    }
    printf("\n");
  }
  printf("VEJA A MATRIZ MEDIA NO ARQUIVO CSV\n");
}
// ZERA A MATRIZ INTEIRA E DEPOIS PREENCHE SOMENTE O TAMANHO DA MATRIZ DEIXANDO OS EXTREMOS (BORDAS) COM ZERO
void aplicarFiltro(int entrada[LINHAS][COLUNAS], int saida[LINHAS][COLUNAS])
{
  int matriz[LINHAS][COLUNAS];

  for (int i = 0; i < LINHAS; i++)
  {
    for (int j = 0; j < COLUNAS; j++)
    {
      saida[i][j] = 0;
    }
  }
  for (int i = 2; i < LINHAS - 2; i++)
  {
    for (int j = 2; j < COLUNAS - 2; j++)
    {
      int soma = 0;

      for (int x = -2; x <= 2; x++)
      {
        for (int y = -2; y <= 2; y++)
        {
          soma = soma + entrada[i + x][j + y];
        }
      }
        saida[i][j] = soma / 25.0;
    }
  }
}

void salvarCSV(int matriz[LINHAS][COLUNAS], char *nome_arquivo)
{
  FILE *arquivo;
  arquivo = fopen(nome_arquivo,"w");

  if(arquivo == NULL)
  {
    printf("Erro ao abrir arquivo!\n");
    return;
  }
  for (int i = 0; i < LINHAS; i++)
  {
    for (int j = 0; j < COLUNAS; j++)
    {
      fprintf(arquivo,"[%3d]", matriz[i][j]);
    }
    fprintf(arquivo, "\n");
  }
  fclose(arquivo);
}
int main()
{
  int entrada[LINHAS][COLUNAS];
  int saida[LINHAS][COLUNAS];

  gerarMatriz(entrada);
  aplicarFiltro(entrada, saida);
  salvarCSV(saida, "nome_arquivo.csv");

  return 0;
}
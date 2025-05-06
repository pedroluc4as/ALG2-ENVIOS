#include<stdio.h>
#include<stdlib.h>
#include<time.h>  

#define LINHAS 5
#define COLUNAS 5

int main(){

  FILE *csv;
  char *url = "csv.csv";

  int entrada [LINHAS][COLUNAS];
  int janela [LINHAS][COLUNAS];
  float saidaMedia [LINHAS] [COLUNAS];  

  srand(time(NULL));

  for(int i = 0; i < LINHAS; i++){
    for(int j = 0; j < COLUNAS; j++){
    entrada[i][j] = rand() % 256;
    janela[i][j] = rand() % 256;
    }
  }

  for(int i = 0; i < LINHAS; i++){
    for(int j = 0; j < COLUNAS; j++){
      saidaMedia[i][j] = entrada[i][j] + janela[i][j] / 2.0;
    }
  }

  for(int i = 0; i < LINHAS; i++){
    for(int j = 0; j < COLUNAS; j++){
      printf(" [%3d] ",entrada[i][j]);
    }
    printf("\n");
  }

  for(int i =0; LINHAS < 5; i++)
  {
    for(int j = 0; COLUNAS < 5; j++)
    {
      if(((i - 2 >= 0 && i + 2 <= 4) && (j - 2 >= 0 j + 2 <= 4)) && ((i - 2 >=0  && j - 2 >= 0) && (i + 2 <= 4 && j + 2 <= 4)))
      {
          
      }
    }
  }

  for(int i = 0; i < LINHAS; i++){
    for(int j = 0; j < COLUNAS; j++){
      //printf("%d",janela[i][j]);
    }
    printf("\n");
  }

  for(int i = 0; i < LINHAS; i++){
    for(int j = 0; j < COLUNAS; j++){
      //printf("%d",saidaMedia[i][j]);
    }
    printf("\n");
  }

for(int i = 0; i < LINHAS; i++){
    for(int j = 0; j < COLUNAS; j++){
      //printf(" %d ",saidaMedia[i][j]);
    }
    printf("\n");
  }

return 0;
}

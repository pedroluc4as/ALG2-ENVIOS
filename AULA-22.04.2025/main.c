#include<stdio.h>

int main()
{
  FILE *arquivo;

  char *url ="teste.txt";

  arquivo = fopen(url, "w");

  fprintf(arquivo, "*\n");
  fprintf(arquivo, "**\n");
  fprintf(arquivo, "***\n");
  fprintf(arquivo, "****\n");
  fprintf(arquivo, "*****\n");
  fprintf(arquivo, "******\n");
  fprintf(arquivo, "*******\n");
  fprintf(arquivo, "********\n");
  fprintf(arquivo, "*********\n");
  fprintf(arquivo, "**********");
  
  fclose(arquivo);

return 0;
}

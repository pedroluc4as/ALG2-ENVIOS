#include<stdio.h>

int main()
{
  FILE *arquivo;

  char *url ="teste.txt";

  arquivo = fopen(url, "w");

  if(arquivo == NULL)
  {
    printf("ERROR, VERIFY PERMISSIONS AND STORAGE AFTER TRY AGAIN");
  }
  if(arquivo != NULL)
  {
    fprintf(arquivo, "*\n");
    fprintf(arquivo, "**\n");
    fprintf(arquivo, "***\n");
    fprintf(arquivo, "****\n");
    fprintf(arquivo, "*****\n");
    fprintf(arquivo, "******");

  fclose(arquivo);

  }
  return 0;
}
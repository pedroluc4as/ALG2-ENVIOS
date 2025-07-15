#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* inverteString(const char *str){
  int i, j;
  int len = strlen(str);
  char *invertida = (char*) malloc((len + 1) * sizeof(char));
  
  if(invertida == NULL){
    return NULL;
  }

  for(i = len - 1, j = 0; i >= 0; i--, j++){
    *(invertida + j) = *(str + i);
  }
  *(invertida + len) = '\0';

  return invertida;
}

int main(){
  char original[] = "programacao";
  char *stringInvertida;

  stringInvertida = inverteString(original);

  if(stringInvertida != NULL){
    printf("Original: %s\n", original);
    printf("Invertida: %s\n", stringInvertida);
    free(stringInvertida);
  }
  
  return 0;
}
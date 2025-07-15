#include <stdio.h>
#include <stdlib.h>
int Ocorre(const char *str1, const char *str2){
  const char *p1, *p2;

  if(*str2 == '\0'){
    return 1;
  }
  while(*str1 != '\0'){
    if(*str1 == *str2){
      p1 = str1;
      p2 = str2;

      while(*p1 != '\0' && *p2 != '\0' && *p1 == *p2){
        p1++;
        p2++;
      }
      if(*p2 == '\0'){
        return 1;
      }
    }
    str1++;
  }
  return 0;
}

int main(){
  const char *texto = "engenharia de computacao";
  const char *palavra = "computacao";

  if(Ocorre(texto, palavra)){
    printf("A string \"%s\" ocorre dentro de \"%s\"\n", palavra, texto);
  } 
  else{
    printf("A string \"%s\" nao ocorre dentro de \"%s\"\n", palavra, texto);
  }
  return 0;
}
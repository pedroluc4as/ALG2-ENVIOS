#include<stdio.h>
#include<stdlib.h>

int* multiplicaVetores(int *A, int *B, int N){
  int i;
  int *C = (int*) malloc(N * sizeof(int));
  if(C == NULL) return NULL;
  
  for(i = 0; i < N; i++){
    *(C + i) = *(A + i) * *(B + i);
  }
  return C;
}

int main(){
  int N = 5;
  int vetA[] = {1, 2, 3, 4, 5};
  int vetB[] = {10, 2, 3, 1, 5};
  int *vetC;
  int i;
  
  vetC = multiplicaVetores(vetA, vetB, N);
  if(vetC != NULL){
    printf("Vetor C (produto de A e B):\n");
    for(i = 0; i < N; i++){
      printf("%d ", *(vetC + i));
    }
    printf("\n");
    free(vetC);
  }
  return 0;
}
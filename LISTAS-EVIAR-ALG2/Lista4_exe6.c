/*Crie uma estrutura representando um aluno de uma disciplina. Essa estrutura deve
conter o número de matrícula do aluno, seu nome e as notas de três provas. Agora, escreva
um programa que leia os dados de cinco alunos e os armazene nessa estrutura. Em
seguida, exiba o nome e as notas do aluno que possui a maior média geral dentre os cinco.*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Aluno {
  int nMatricula;
  char nome[100];
  double p1, p2, p3;
};

int main(){
  struct Aluno media[5];

  printf("Digite os dados do aluno!\n");

  for(int i = 0; i < 5; i++){
    printf("Digite matricula, nome e as 3 notas do aluno %d:\n", i+1);
    scanf("%d %s %lf %lf %lf", &media[i].nMatricula, media[i].nome, &media[i].p1, &media[i].p2, &media[i].p3);
  }
  double mediaF[5];
  for(int i = 0; i < 5; i++){
    mediaF[i] = (media[i].p1 + media[i].p2 + media[i].p3) / 3;
  }
  int maiorMedia = 0;
  for(int i = 1; i < 5; i++){
    if(mediaF[i] > mediaF[maiorMedia]){
      maiorMedia = i;
    }
  }
  printf("Aluno com maior media:\n%d %s %.2lf\n",media[maiorMedia].nMatricula, media[maiorMedia].nome, mediaF[maiorMedia]);

return 0;
}

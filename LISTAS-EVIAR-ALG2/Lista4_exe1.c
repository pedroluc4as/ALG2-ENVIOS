/*1) Implemente um programa que leia o nome, a idade e o endereço de uma pessoa e
armazene esses dados em uma estrutura. Em seguida, imprima na tela os dados da
estrutura lida.*/
#include<stdio.h>
#include<stdio.h>

struct dados {
  char nome[100];
  int idade;
  char endereco[250];
};
int main(){
  struct dados pessoa;
  printf("Digite o nome: ");
  fgets(pessoa.nome, sizeof(pessoa.nome),stdin);

  printf("Digite a idade: ");
  scanf("%d",&pessoa.idade);

  getchar();

  printf("Digite o endereço: ");
  fgets(pessoa.endereco, sizeof(pessoa.endereco),stdin);

  printf("\nNome: %sIdade: %d\nEndereco: %s",pessoa.nome, pessoa.idade, pessoa.endereco);

return 0;
}

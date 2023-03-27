#include <stdio.h>



typedef struct date {
int dia;
int mes;
int ano;
} date;

struct date data;

typedef struct aluno{
  int matricula;
  char cpf[15];
  char nome[50];
  char sexo;
  int data;
}aluno;

struct aluno Aluno;

int main(){
  printf("\n Cadastro de Aluno \n");
  printf("\n informe o numero de matricula \n");
  scanf("%d", &Aluno.matricula);
  
  printf("%d", Aluno.matricula);

  
  

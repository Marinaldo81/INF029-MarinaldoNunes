#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#define tam 2;

  /*Criando struct de aluno */
  struct Cad_aluno
  {
   int matricula;
   char nome[50];
   int sexo; /* 1: Masculino e 2: Feminino*/
   int cpf; 
    };
 

  struct Cad_aluno Aluno ;

  /*Criação de Data de nascimento */
  struct Data_Nascimento
{
  int dia;
  int mes;
  int ano;
};

  struct Data_Nascimento dt;
  

int main() {

  setlocale(LC_ALL, "Portugese");
  aluno1 Aluno[tam]; /* vatiavel  ficha aluno*/
  
  int i = 0; /* quantidade de alunos cadastrados*/ 
  
  int op;
  int exit =0;
  
   while (!exit) {
  printf("\n-----------PROGRAMA ESCOLA---------\n ");
  printf("\n     1 - CADASTRO DE ALUNO\n");
  printf("\n     2 - CADASTRO DE PROFESSORES\n");
  printf("\n     3 - CADASTRO DE DISCIPLINAS \n");
  printf("\n     4  -  SAIR  \n");

  
  printf("\n informe a opcao desejada \n");
  scanf("%d", &op);
  
    switch(op){
     
     case 1:
 
  printf("\n cadastro de aluno\n");
  printf("\n informe o numero de matricula\n ");
  scanf("%d", &aluno[i].matriculas);  
  printf("\n informe o nome do aluno");
  fflush(stdin);
  fgets(aluno[i].nome, 50, stdin);
  printf("\n Informe CPF do aluno\n");
  scanf("%d", &aluno[i].cpf);
     
  printf("\n Informe o Sexo do aluno\n");
  scanf("%d", &aluno[i].sexo);
  printf("\n informe o dia de nascimento do aluno\n ");
  scanf("%d", &dt.dia);  
  printf("\n informe o mês de nascimento do aluno\n");
  scanf("%d", &dt.mes);
  printf("\n informe o ano de nascimento do aluno\n");
  scanf("%d", &dt.ano);  
  
  printf ("\n matricula %d ", aluno.matricula);
  printf ("\n matricula %c ", aluno.nome);
  printf ("\n matricula %d ", aluno.cpf);
  printf ("\n matricula %d ", aluno.sexo);
  printf ("\n matricula %d ", dt.dia);
  printf ("\n matricula %d ", dt.mes);
  printf ("\n matricula %d ", dt.ano);  
    
  } 

        
    
	 
     
  }
  
}
	

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 5
#include "CadastroAluno.h"


typedef struct dados_professor
{
  int matricula;
  char nome[50];
  char sexo; //M - Masculino, F - Feminino
  Data date;
  char cpf[15];
    
} profes;

typedef struct dados_disciplina
{
  int codigo;
  char nome[50];
  int  matricula_prof; 
  char semestre;
  int matriculaProfessor;
  profes  matri;
 
    
} disciplina;



int MP();
int inserirAluno(Alunos Aluno[], int quant);
int inserirProfessor(profes Professor[], int quant);
int inserirDisciplina(disciplina Disciplina[], int quant);
void listarAlunos(Alunos Aluno[], int quant);
void listarProfessor(profes Professor[], int quant);
int alterarAlunos(Alunos Aluno[], int quant);
int alterarProfessor(profes Professor[], int quant);
int excluirAlunos(Alunos Aluno[], int quant);
int excluirProfessor(profes Professor[], int quant);

void listarAlunosSexo(Alunos Aluno[], int quant);
void ltAlunosNome(Alunos Aluno[], int quant);
void ltAlunodt(Alunos Aluno[], int quant);

int main(){    
 
  Alunos alu; /*Criando a variável aluno que será do tipo struct Ficha_Aluno */
  Alunos Aluno[TAM]; // vetor para armazenar a lista de alunos
  int quant = 0; // variável para controlar a quantidade de alunos cadastrados
  profes prof;
  profes Professor[TAM];
  disciplina disc;
  disciplina Disciplina[TAM];
  
  
  int op, opAL, retorno;
  int  exit = 0;
    
  while (!exit){
    op = MP();
      
    switch(op){
  	  case 0:{
        printf("Finalizando Escola\n");
        exit = 1;
        break;
      }
      case 1:{
        CADALUNO();
        while (!exit){  
          switch(opAL){
            
            case 1:{
              retorno = inserirAluno(Aluno, quant);
              if (retorno == CADASTRO_REALIZADO){
              printf("Cadastro realizado com sucesso\n");
              quant++;  
              }else{
                switch(retorno) {
                  case ERRO_CADASTRO_MATRICULA:{
                  printf("Matrícula Inválida");
                  break;
                  }
                  case ERRO_CADASTRO_SEXO:{
                  printf("Sexo Inválido");
                  break;
                  }
                }
              }
              
              default:
                           
            }
            case 2: {
              listarAlunos(Aluno, quant);
          	         
              break;
            }
            case 3: {
              alterarAlunos(Aluno, quant);
            	break;
        	  }
        	  case 4: {
              excluirAlunos(Aluno, quant);
              quant--;
          	  break;
        	  }
            case 5: {
              void listaAlunosSexo(Aluno, quant);
          	  break;
        	  }
            case 6: {
              ltAlunosNome(Aluno, quant);
          	  break;
        	  }  
            case 7: {
              ltAlunodt(Aluno, quant);
          	  break;
        	  }  
              printf("Não foi possível fazer o cadastro\n");          
          }    
       
          break;
        }      
      }
      
      case 2: {
        listarAlunos(Aluno, quant);
    	      	        
        break;
      }
      case 3: {
        alterarAlunos(Aluno, quant);
      	break;
  	  }
  	  case 4: {
        excluirAlunos(Aluno, quant);
        quant--;
    	  break;
  	  }

      /* 	  case 5: {
        retorno = inserirProfessor(Professor, quant);
        	if (retorno == CADASTRO_REALIZADO){
          printf("Cadastro realizado com sucesso\n");
          quant++;
        	}
          else{
          	switch(retorno) {
              case ERRO_CADASTRO_MATRICULA:{
              printf("Matrícula Inválida");
              break;
              }
              case ERRO_CADASTRO_SEXO:{
              printf("Sexo Inválido");
              break;
              }
              default:{
              printf("Erro desconhecido!");
              }
                               
            }
            printf("Não foi possível fazer o cadastro\n"); 
                      
          }    
        break;
      }
      case 6: {
        listarProfessor(Professor, quant);
  	      	        
        break;
      }
      case 7: {
        alterarProfessor(Professor, quant);
  	    break;
  	  }
  	  case 8: {
        excluirProfessor(Professor, quant);
        quant--;
    	  break;
  	  }
  	  case 9: {
        inserirDisciplina(Disciplina, quant);
        quant++;
    	  break;
  	  }*/
      default:{
      printf("Opção Inválida\n");
      }
    }
  }  

return 0;
}

int MP(){
  int op;
  printf("-----PROGRAMA ESCOLA -----\n");
  printf("1 -  CADASTRO ALUNO \n");
  printf("2 -  CADASTRO PROFESSOR \n");
  printf("3 -  CADASTRO DISCIPLINA \n");
  scanf("%d",&op);
  return op;
}

int CADALUNO(){
  int opAl;
  printf("----- PAINEL ALUNO -----\n");
  printf("0 - Retornar \n");
  printf("1 -  INSERIR ALUNO \n");
  printf("2 -  ATUALIZAR ALUNO \n");
  printf("3 -  EXCLUIR ALUNO \n");
  printf("4 -  LISTAR ALUNO \n");
  printf("5 -  LISTAR ALUNO POR SEXO \n");
  printf("6 -  LISTAR ALUNO ORDENADO POR NOME \n");
  printf("7 -  LISTAR ALUNO POR DATA DE NASCIMENTO \n");
  printf("\n INFORME UMA OPCAO ? ");
  scanf("%d",&opAl);
  return opAl;
}

int CADPROFESSOR(){
  int opPr;
  printf("----- PAINEL PROFESSOR -----\n");
  printf("1 -  INSERIR PROFESSOR \n");
  printf("2 -  ATUALIZAR PROFESSOR \n");
  printf("3 -  EXCLUIR PROFESSOR \n");
  printf("4 -  LISTAR PROFESSOR \n");
  printf("5 -  LISTAR ALUNO POR SEXO \n");
  printf("6 -  LISTAR ALUNO ORDENADO POR NOME \n");
  printf("7 -  LISTAR ALUNO POR DATA DE NASCIMENTO \n");
  printf("\n INFORME UMA OPCAO ? ");
  scanf("%d",&opPr);
  return opPr;
}

int RELATORIOS(){
  int opPr;
  printf("----- PAINEL RELATORIOS -----\n");
  printf("1 -  ANIVERSARIANTES DO MES\n");
  printf("2 -  LISTA DE PESSOAS (PROFESSORR / ALUNO) \n");
  printf("3 -  LISTAR DE DISCIPLINAS \n");
  printf("4 -  LISTA DE ALUNOS MATRICULADOS EM MENOS DE 3 DISCIPLINAS  \n");
  printf("\n INFORME UMA OPCAO ? ");
  scanf("%d",&opPr);
  return opPr;
}


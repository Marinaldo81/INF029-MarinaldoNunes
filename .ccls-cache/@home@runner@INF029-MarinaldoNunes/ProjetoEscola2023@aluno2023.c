#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 5
#define SUCESSO_CADASTRO 1
#define ERRO_CADASTRO_MATRICULA 2
#define ERRO_CADASTRO_SEXO 3
#define ERRO_matricula 4
#define cadastro_realizado -1

typedef struct dma {
  int dia;
  int mes;
  int ano; 
} Data; 

/*Criando a struct aluno */
typedef struct dados_aluno
{
  int matricula;
  char nome[50];
  char sexo; //M - Masculino, F - Feminino
  Data date;
  char cpf[15];
    
} Alunos;

int MP();
int inserirAluno(Alunos Aluno[], int quant);
void listarAlunos(Alunos Aluno[], int quant);

int main(void)
{    
 
  Alunos alu; /*Criando a variável aluno que será do tipo struct Ficha_Aluno */
  Alunos Aluno[TAM]; // vetor para armazenar a lista de alunos
  int quant = 0; // variável para controlar a quantidade de alunos cadastrados

  int op, retorno;
  int sair = 0;
  
  while (!sair){
    
    op = MP();
    
    switch(op){
      case 0:{
        printf("Finalizando Escola\n");
        sair = 1;
        break;
      }
      case 1: {
        retorno = inserirAluno(Aluno, quant);
        if (retorno == cadastro_realizado){
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
                default:{
                    printf("Erro desconhecido!");
                }
               
            }
           printf("Não foi possível fazer o cadastro\n"); 
            
        }    
        break;
      }
      case 2: {
        listarAlunos(Aluno, quant);
        break;
      }
      default:{
        printf("Opção Inválida\n");
      }
    }
  }


  return 1;

}

int MP(){
    int op;
    printf("Digite a opção:\n");
    printf("0 - Sair\n");
    printf("1 - Inserir Aluno\n");
    printf("2 - Listar Alunos\n");
    scanf("%d",&op);
    return op;
}

int inserirAluno(Alunos Aluno[], int quant){
    printf("\n informe o numero de matricula \n");
    scanf("%d", &Aluno[quant].matricula);
    
     printf("\n      Cadastro de Aluno  \n");
    if (Aluno[quant].matricula <= 0 ){
    //return erro_matricula;
    }else {
    if (Aluno[quant].matricula == TAM){
    printf("\n Cadastro Cheio");}    
    }

    return cadastro_realizado;
  }


void listarAlunos (Alunos Aluno[], int quant){
   printf("\n     LISTA DE ALUNOS   \n");
    int i;
	for (i=0; i<quant; i++){
    if(Aluno[quant].matricula <= 0 ){
    printf("Lista Vazia");}
		
	for (i=0; i<quant; i++){
    printf("\n  numero de matricula %d\n", Aluno[i].matricula);
    printf("\n informe o nome do aluno %s\n" , Aluno[i].nome);
    printf("\n informe o nome do cpf %s\n", Aluno[i].cpf);
    printf("\n informe o nome do sexo %c\n", Aluno[i].sexo);  
    printf("\n dia de nascimento %d/%d/%d\n", Aluno[i].date.dia, Aluno[i].date.mes,  Aluno[i].date.ano); }
   
    printf("-----\n\n");   
  
} 
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CADASTRO_REALIZADO -1
#define ERRO_CADASTRO_MATRICULA -2
#define ERRO_CADASTRO_SEXO -3
#define erro_matricula -4
#define atualizacao -5
#define excluido -6
#define LISTA_VAZIA -7
#define SUCESSO_ATUALIZACAO -8
#define erro -9
#define ERRO_CADASTRO_SEMESTRE -10
#define cad_cheio -11
#define TAM 4


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
int alterarAlunos(Alunos Aluno[], int quant);
int excluirAlunos(Alunos Aluno[], int quant);
void listarAlunosSexo(Alunos Aluno[], int quant);
void ltAlunosNome(Alunos Aluno[], int quant);
void ltAlunodt(Alunos Aluno[], int quant);

int main()
{    
 
  
  Alunos alu; /*Criando a variável aluno que será do tipo struct Ficha_Aluno */
  Alunos Aluno[TAM]; // vetor para armazenar a lista de alunos
  int quant = 0; // variável para controlar a quantidade de alunos cadastrados
  

int op, retorno;
int  exit = 0;
    
    while (!exit){
      
        op = MP();
      
        switch(op){
  	        case 0:{
                printf("Finalizando Escola\n");
                exit = 1;
                break;
                }
            case 1: {
                retorno = inserirAluno(Aluno, quant);
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
                listarAlunosSexo(Aluno, quant);
     	         break;
            }
            case 6: {
                ltAlunoNome(Aluno, quant);
     	         break;
            }
            case 7: {
                ltAlunodt(Aluno, quant);
                break;
            }    
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
    printf("Digite a opção:\n");
    printf("\n     0 - Sair\n");
    printf("--- DADOS ALUNO ---\n");
    printf("\n     1 - Inserir Aluno\n");
    printf("\n     2 - Listar Alunos\n");
    printf("\n     3 - Alterar Alunos \n ");
    printf("\n     4 - Excluir Alunos \n ");
    printf("\n     5- Listar Alunos por sexo \n");
    printf("\n     6- Listar Alunos por ordem \n");
    printf("\n     7- Listar Alunos por data de aniversario \n");
   		
    scanf("%d",&op);
  return op;
}

int inserirAluno(Alunos Aluno[], int quant){
    printf("\n      Cadastro de Aluno  \n");
    if (Aluno[quant].matricula == TAM){
 	      printf("\n Cadastro Cheio");
        return cad_cheio;  
    }else{  
    printf("\n informe o numero de matricula \n");
    scanf("%d", &Aluno[quant].matricula);
    getchar();
    if (Aluno[quant].matricula <= 0 ){
    return erro_matricula;
    }
    printf("Digite o nome: ");
    fgets(Aluno[quant].nome, 50, stdin); 
    size_t ln = strlen(Aluno[quant].nome) - 1; //size_t = unsigned integer type
        if (Aluno[quant].nome[ln] == '\n')
        Aluno[quant].nome[ln] = '\0'; 
    
    printf("Digite o sexo: ");
    scanf("%c", &Aluno[quant].sexo);
    Aluno[quant].sexo = toupper (Aluno[quant].sexo);
        if (Aluno[quant].sexo != 'M' && Aluno[quant].sexo != 'F') {
        return ERRO_CADASTRO_SEXO;
        }
	
    printf("Digite o dia de nascimento: ");
    scanf("%d", &Aluno[quant].date.dia);
    
    printf("Digite o mês de nascimento: ");
    scanf("%d", &Aluno[quant].date.mes);
    
    printf("Digite o ano de nascimento: ");
    scanf("%d", &Aluno[quant].date.ano);
    getchar();

    printf("Digite o CPF: ");
    fgets(Aluno[quant].cpf, 15, stdin); 
    ln = strlen(Aluno[quant].cpf) - 1; 
        if (Aluno[quant].cpf[ln] == '\n')
        Aluno[quant].cpf[ln] = '\0'; 

    printf("\n");
    
  return CADASTRO_REALIZADO;
    
    
    }
}    

void listarAlunos(Alunos Aluno[], int quant) {
    printf("\n     LISTA DE ALUNOS   \n");
    int i;
    if (quant > 0) {
        for (i = 0; i < quant; i++) {
        printf("\n  numero de matricula %d\n", Aluno[i].matricula);
        printf("\n informe o nome do aluno %s\n", Aluno[i].nome);
        printf("\n informe o nome do cpf %s\n", Aluno[i].cpf);
        printf("\n informe o nome do sexo %c\n", Aluno[i].sexo);
        printf("\n dia de nascimento %d/%d/%d\n", Aluno[i].date.dia, Aluno[i].date.mes, Aluno[i].date.ano);
        printf("---------------------------------------------------------------------\n\n");
        }
    } else {
    printf("Lista Vazia");
    }
}

void listarAlunosSexo(Alunos Aluno[], int quant) {
    printf("\n     LISTA DE ALUNOS POR SEXO   \n");
    int i;
        if (quant > 0) {
            for (i = 0; i < quant; i++) {
                if (Aluno[i].sexo == 'F'){
                printf("\n informe o nome do aluno %s\n", Aluno[i].nome);
                printf("\n sexo feminino \n");    
                } else {
                    printf("LIsta VAzia - sexo feminino");
                }
                
                if (Aluno[i].sexo != 'F'){
                printf("\n informe o nome do aluno %s\n", Aluno[i].nome);
                printf("\n sexo Masculino \n");    
                }else {
                    printf("lista VAzia - sexo masculino");
                }
            }   
        } 
        else {
        printf("Lista Vazia");
        }
    }

void ltAlunoNome(Alunos Aluno[], int quant) {
    printf("\n     LISTA DE ALUNOS  por nome  \n");
    int i, x;
    char aux[80]; 
    if (quant > 0) {
        for (i = 0; i < quant-1; i++) {
            for(x = i+1; x<=quant; x++){
                strcpy(aux, Aluno[i].nome );
                strcpy(Aluno[i].nome, Aluno[x].nome);
                strcpy(Aluno[x].nome, aux);
            
            }
        }
        for(i=0;i<quant;i++){
		printf("%s\n", Aluno[i].nome);
		printf("%s\n", aux);
	    }
    }else { printf("Lista Vazia"); }
    
} 

void ltAlunodt(Alunos Aluno[], int quant) {
    printf("\n   LISTA DE ALUNOS POR DATA DE NASCIMENTO  \n");
    int i, j, min;
    char aux[80]; 
    if (quant > 0) {
        for (i = 0; i < quant-1; i++) {
            for (j= i+1; j <= quant; j++ ){
                strcpy(aux, Aluno[i].date.dia);
                strcpy(Aluno[i].date.dia, Aluno[j].date.dia);
                strcpy(Aluno[j].date.dia, aux);    
            }
        }
        for(i=0;i<quant;i++){
	    printf("%d\n", Aluno[i].date.dia);
	    }
 
    }else { printf("Lista Vazia"); }
    

    
}


int alterarAlunos(Alunos Aluno[], int quant){
    printf("\n ALTERAR ALUNO \n");
    int i, mat;
        for (i=0; i<quant; i++){
        printf("\n informe o numero de matricula \n"); 
        scanf("%d", &mat);
        getchar();
        if (mat != Aluno[i].matricula){
        printf("MATRICULA NÃO EXISTE");
        } else {
        printf("\n informe o numero de matricula \n");
        scanf("%d", &Aluno[i].matricula); 
        getchar();
    
        printf("Digite o nome: ");
        fgets(Aluno[i].nome, 50, stdin); 
    
        printf("Digite o sexo: ");
        scanf("%c", &Aluno[i].sexo);
        getchar();
    	Aluno[i].sexo = toupper (Aluno[i].sexo);
            if (Aluno[i].sexo != 'M' && Aluno[i].sexo != 'F') {
            printf("ERRO: sexo deve ser 'M' ou 'F'\n");
            return ERRO_CADASTRO_SEXO;
            } else {
        printf("Digite o dia de nascimento: ");
        scanf("%d", &Aluno[i].date.dia);
    
        printf("Digite o mês de nascimento: ");
        scanf("%d", &Aluno[i].date.mes);
    
        printf("Digite o ano de nascimento: ");
        scanf("%d", &Aluno[i].date.ano);
        getchar();
    
        printf("Digite o CPF: ");
        fgets(Aluno[i].cpf, 15, stdin); 
        size_t ln = strlen(Aluno[i].cpf) - 1; 
        	if (Aluno[i].cpf[ln] == '\n')
            Aluno[i].cpf[ln] = '\0';
    
            printf("\n");
            printf("ATUALIZAÇÃO COM SUCESSO\n");
            return SUCESSO_ATUALIZACAO;
            }
            }
 }
 printf("Lista vazia\n");
 return LISTA_VAZIA;
}


int excluirAlunos(Alunos Aluno[], int quant) {
    printf("\n EXCLUIR ALUNO \n");
    int i, mat;
    printf("\n informe o numero de matricula \n");
    scanf("%d", &mat);
    getchar();
    for (i = 0; i < quant; i++) {
        if (mat == Aluno[i].matricula) {
            
            for (int j = i; j < quant - 1; j++) {
                Aluno[j] = Aluno[j + 1];
            }
            printf("ALUNO EXCLUIDO COM SUCESSO\n");
            return excluido;
        }
    }
    printf("MATRICULA NAO EXISTE\n");
    return erro;
}
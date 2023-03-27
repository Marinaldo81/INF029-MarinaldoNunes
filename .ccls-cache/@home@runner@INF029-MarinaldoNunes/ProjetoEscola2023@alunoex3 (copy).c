#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#define TAM 0
#define cadastro_realizado -1
#define erro_matricula -2
#define erro_sexo -3


typedef struct data{
    int dia;
    int mes;
    int ano;
    
} dt;

typedef struct aluno{
    int matricula;
    char cpf[15];
    char nome[50];
    char sexo;
    dt   Dt;
    
}al;

//função menu
int menu(void);
int cadastroaluno();



int cadaluno (al Alu[], int qnt);
void listaluno (al Alu[], int qnt);



int main(void) {
    
al alun; /*Criando a variável aluno que será do tipo struct Ficha_Aluno */
al* Alu[TAM]; // vetor para armazenar a lista de alunos
int qnt = 0; // variável para controlar a quantidade de alunos cadastrados
    
int inic, inic2;
int ret;
    
    
do {
     inic = menu();
    // Ler a opção escolhida pelo usuário
  
    // Executar a ação correspondente à opção escolhida
    switch (inic) {
    case 1:
    printf("Modulo Aluno");
   // int qnt = 0;
        do {
        inic2 = cadastroaluno();
        // Ler a opção escolhida pelo usuário
            
        // Executar a ação correspondente à opção escolhida
        switch (inic2) {
        case 1: 
        // CADASTRO ALUNO
        ret = cadaluno(Alu, qnt);
        if (ret == cadastro_realizado ){
        printf("Cadastro realizado");
        qnt++;   
        } else {
            switch(ret){
            case erro_matricula:{
            printf("Erro codigo de matricula ");
            break;
                    
            }
            case erro_sexo:{
            printf("opção invalida");
            break;    
            }
          //  default:{
         //   printf("Erro desconhecido");
        //  }
            printf(" Não foi possível fazer o cadastro\n"); 
            }
            }
        break;
          
        case 2:
        // LISTAR ALUNOS 
        listaluno(Alu, qnt);
        break;
        case 3:
        // Menu sair
        printf("Saindo do menu...\n");
        break;       
        
        case 4:
        // Menu sair
        printf("Saindo do menu...\n");
        break;
            
        case 5:
        // Menu sair
        printf("VOLTAR...\n");
            
        break;
        default:
        printf("Opção inválida. Digite novamente.\n");
        }while (inic2 != 5);
    inic = menu();
    break;    
    
    case 2:
    printf("Modulo Professores");
    break;
    case 3:
    printf("Modulo Disciplinas");
    break;
    case 4:
    // Sair do menu
    printf("Saindo do menu...\n");
    break;
    default:
    printf("Opção inválida. Digite novamente.\n");
    break;
    } while (inic != 4);
    return 0; 
    }
    }while (inic != 4);
  return 1;  
}
  
  
//função 1
int menu() {
int op;   
printf("\n-----------PROGRAMA ESCOLA---------\n ");
printf("\n     1 - CADASTRO DE ALUNO\n");
printf("\n     2 - CADASTRO DE PROFESSORES\n");
printf("\n     3 - CADASTRO DE DISCIPLINAS \n");
printf("\n     4  -  SAIR  \n");
printf("Digite a opção desejada: ");
scanf("%d", &op);
   
return op;
} 

int cadastroaluno(){
int opalu;
printf("\n-----------PROGRAMA ESCOLA - CADASTRO ALUNO ---------\n ");
printf("\n     1 - INSERIR ALUNO\n");
printf("\n     2 - LISTAR ALUNO \n");
printf("\n     3 - ATUALIZAR ALUNO\n");
printf("\n     4 - REMOVER ALUNO \n");
printf("\n     5 - VOLTAR \n"); 
printf("Digite a opção desejada: ");
scanf("%d", &opalu);
return opalu;
} 

int cadaluno (al Alu[], int qnt) {
    printf("\n      Cadastro de Aluno  \n");
    printf("\n informe o numero de matricula \n");
    scanf("%d", &Alu[qnt].matricula);
    if (Alu[qnt].matricula <= 0 ){
    return erro_matricula;
    }else {
    if (Alu[qnt].matricula == TAM){
    printf("\n Cadastro Cheio");}    
    }
    getchar();
    printf("\n informe o nome do aluno \n");                                        
    fgets(Alu[qnt].nome, 50 , stdin);
   
    size_t ln = strlen(Alu[qnt].nome) - 1; //size_t = unsigned integer type
    if (Alu[qnt].nome[ln] == '\n')
    Alu[qnt].nome[ln] = '\0';
       
    printf("\n informe o cpf \n");
    fgets(Alu[qnt].cpf, 15, stdin); 
    ln = strlen(Alu[qnt].cpf) - 1; 
    if (Alu[qnt].cpf[ln] == '\n')
    Alu[qnt].cpf[ln] = '\0';
          
    printf("\n informe o sexo \n");
    scanf("%c", &Alu[qnt].sexo);
            
    Alu[qnt].sexo = toupper(Alu[qnt].sexo);
    if (Alu[qnt].sexo != 'M' && Alu[qnt].sexo != 'F'){
    return erro_sexo;
    }
        
            /*       while(Alu[qnt].sexo != 'm' || Alu[qnt].sexo != 'f'){
              printf("Opcao invalida. Digite M ou F.\n"); 
                //pedir que o usuário escolha novamente
                printf("\n informe o sexo \n");
                scanf("%c", &Alu[qnt].sexo);
                
            } */ 
    printf("\n informe o dia de nascimento \n ");
    scanf("%d", &Alu[qnt].Dt.dia);
    getchar();
        
    printf("\n informe o mes de nascimento \n ");
    scanf("%d", &Alu[qnt].Dt.mes);
    getchar();
        
    printf("\n informe o Ano de nascimento \n ");
    scanf("%d", &Alu[qnt].Dt.ano);
    getchar();
    qnt++;
    return cadastro_realizado;
    }
    
    
void listaluno (al Alu[], int qnt) {
    int i;
    for (i=0; i<qnt; i++){
    if(Alu[qnt].matricula <= 0 ){
    printf("Lista Vazia");
    }     
    printf("\n     LISTA DE ALUNOS   \n");
    printf("\n  numero de matricula %d\n", Alu[i].matricula);
    printf("\n informe o nome do aluno %s\n" , Alu[i].nome);
    printf("\n informe o nome do cpf %s\n", Alu[i].cpf);
    printf("\n informe o nome do sexo %c\n", Alu[i].sexo);  
    printf("\n dia de nascimento %d/%d/%d\n", Alu[i].Dt.dia, Alu[i].Dt.mes,  Alu[i].Dt.ano); 
    } 
    
    }

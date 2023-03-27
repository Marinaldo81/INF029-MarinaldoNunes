#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#define n 2



int main() {

typedef struct data{
    int dia;
    int mes;
    int ano;
    
} dt;

struct aluno{
    int matricula;
    int cpf;
    char nome[50];
    char sexo[1];
    dt   Dt;
    
}al[n];

int op;
int i = 0;
do {
  
  printf("\n-----------PROGRAMA ESCOLA---------\n ");
  printf("\n     1 - CADASTRO DE ALUNO\n");
  printf("\n     2 - CADASTRO DE PROFESSORES\n");
  printf("\n     3 - CADASTRO DE DISCIPLINAS \n");
  printf("\n     4  -  SAIR  \n");
  
  // Ler a opção escolhida pelo usuário
    printf("Digite a opção desejada: ");
    scanf("%d", &op);

    // Executar a ação correspondente à opção escolhida
    switch (op) {
        case 1:
          printf("Modulo Aluno");
          do{
        int opA;      
            printf("\n-----------MODLULO ALUNO---------\n ");
    printf("\n     1 - CADASTRAR ALUNO \n");
    printf("\n     2 - ALTERAR CADASTRO \n");
    printf("\n     3 - EXCLUIR CADASTRO \n");
    printf("\n     4  -  SAIR  \n");  
    printf("Digite a opção desejada: ");
    scanf("%d", &opA);
    //    switch (opA);{
        
    //    case 1:
    if (opA == 1 ){
        printf("\n      Cadastro de Aluno  \n");
        printf("\n informe o numero de matricula \n");
        scanf("%d", &al[i].matricula);
        printf("\n informe o nome do aluno \n");
        fgets(al[i].nome, 50 , stdin);
        printf("\n informe o cpf \n");
        scanf("%d", &al[i].cpf);
        printf("\n informe o sexo");
        fgets(al[i].sexo, 1, stdin );
        printf("\n informe o dia de nascimento /n ");
        scanf("%d", &al[i].Dt.dia);
        printf("\n informe o mes de nascimento /n ");
        scanf("%d", &al[i].Dt.mes);
        printf("\n informe o dia de nascimento /n ");
        scanf("%d", &al[i].Dt.ano);
     
     i++;   
    } else {
        
    } 
     }
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
    }
} while (op != 4);
}
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

typedef struct data{
    int dia;
    int mes;
    int ano;
    
} dt;

typedef struct aluno{
    int matricula;
    int cpf;
    char nome[50];
    char sexo;
    dt   Dt;
    
}al;

al alun;
al Alu[10];
int main() {
int op;

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
          int opalu;
          int qnt = 0;
            do {
  
            printf("\n-----------PROGRAMA ESCOLA - CADASTRO ALUNO ---------\n ");
            printf("\n     1 - INSERIR ALUNO\n");
            printf("\n     2 - LISTAR ALUNO \n");
            printf("\n     3 - ATUALIZAR ALUNO\n");
            printf("\n     4 - REMOVER ALUNO \n");
            printf("\n     5 - SAIR \n");

  
  // Ler a opção escolhida pelo usuário
            printf("Digite a opção desejada: ");
            scanf("%d", &opalu);

    // Executar a ação correspondente à opção escolhida
            switch (opalu) {
            case 1:
         
            printf("\n      Cadastro de Aluno  \n");
            printf("\n informe o numero de matricula \n");
            scanf("%d", &Alu[qnt].matricula);
    //    if (Alu[qnt].matricula <= 0) {
    //    printf(" ERRO_CADASTRO_MATRICULA");
   //     }
    
        
            getchar();
            printf("\n informe o nome do aluno \n");
            fgets(Alu[qnt].nome, 50 , stdin);
        /*o fgets é uma das funções mais indicadas para ler string do teclado. 
        Ela controla o tamanho do buffer, e não deixa o buffer com lixo. 
        Entretanto ela guarda o \n ao final da string, por isso é preciso removê-lo, como feito a seguir*/
            size_t ln = strlen(Alu[qnt].nome) - 1; //size_t = unsigned integer type
            if (Alu[qnt].nome[ln] == '\n')
            Alu[qnt].nome[ln] = '\0';
       
             getchar();
       
            printf("\n informe o cpf \n");
            scanf("%d", &Alu[qnt].cpf);
            getchar();
        
        
            printf("\n informe o sexo\n");
            scanf("%c", &Alu[qnt].sexo);
            getchar();
        
            printf("\n informe o dia de nascimento \n ");
            scanf("%d", &Alu[qnt].Dt.dia);
            getchar();
        
            printf("\n informe o mes de nascimento \n ");
            scanf("%d", &Alu[qnt].Dt.mes);
            getchar();
        
            printf("\n informe o dia de nascimento \n ");
            scanf("%d", &Alu[qnt].Dt.ano);
            getchar();
            qnt++; 
            }
            break;
      
            case 2:
        
            int i=0;
            for (i=0; i<qnt; i++){
        if(Alu[qnt].matricula <= 0 ){
            printf("Lista Vazia");
        }     
        printf("\n     LISTA DE ALUNOS   \n");
        printf("\n  numero de matricula %d\n", Alu[i].matricula);
        printf("\n informe o nome do aluno %s\n" , Alu[i].nome);
        printf("\n informe o nome do cpf %d\n", Alu[i].cpf);
        printf("\n informe o nome do sexo %c\n", Alu[i].sexo);  
        printf("\n dia de nascimento %d/%d/%d\n", Alu[i].Dt.dia, Alu[i].Dt.mes,  Alu[i].Dt.ano); 
        
        }           
    
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
            printf("Saindo do menu...\n");
        break;
        default:
            printf("Opção inválida. Digite novamente.\n");
             }
             while (opalu != 5);
          
    
            
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
  return 0; 
}
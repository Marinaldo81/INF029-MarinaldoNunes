#include <stdio.h>
#include <string.h>


int main(void) {

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

al alun;    //variavel para ficha aluno
al Alu[10]; // vetor 

int op;
int qnt = 0;
do {
  
  printf("\n-----------PROGRAMA ESCOLA---------\n ");
  printf("\n     1 - INSERIR ALUNO\n");
  printf("\n     2 - LISTAR ALUNO \n");
  printf("\n     3 - SAIR \n");

  
  // Ler a opção escolhida pelo usuário
    printf("Digite a opção desejada: ");
    scanf("%d", &op);

    // Executar a ação correspondente à opção escolhida
    switch (op) {
        case 1:
       
        printf("\n      Cadastro de Aluno  \n");
        printf("\n informe o numero de matricula \n");
        scanf("%d", &Alu[qnt].matricula);
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
         break;
          
        case 2:
        //
        int i=0;
        for (i=0; i<qnt; i++){
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
        
        default:
            printf("Opção inválida. Digite novamente.\n");
            break;
    }
} while (op != 3);
return 0;
    
}
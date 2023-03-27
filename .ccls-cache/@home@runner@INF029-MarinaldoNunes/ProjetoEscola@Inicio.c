#include <stdio.h>

menu(void);

int main() {
int op, inic;

do {
  
  
    inic = menu();

    // Executar a ação correspondente à opção escolhida
    switch (inic) {
        case 1:
          printf("Modulo Aluno");
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
} while (op == 4);
  return 0; 
}

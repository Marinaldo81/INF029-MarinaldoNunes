#include <stdio.h>

int main(void) {
  int n;
  int idade[n];
  int med;
  int total = 0;
  int i;

  printf("informe a quantidade de idades que deseja");
  scanf("\n%d", &n);

  for (i = 0; i < n; i++) {
    printf("informe uma idade");
    scanf("\n%d", &idade[i]);
    total = total + idade[i];
  }

  med = total / n;

  for (i = 0; i < n; i++) {
    if (idade[i] > med) {
      printf("\n%d\n", idade[i]);
    }
  }
  return 0;
}
#include <stdio.h>

int main(void) {
  int n = 5;
  int id[n];
  int med ;
  int total;
  int i;
  
 for (i = 1; i<=n; i++){
  printf("informe uma idade");
  scanf("%d", &id[i]);
  total = total+id[i];
 }   

  med = total/n;

  for (i=1; i<=n; i++ ){
    if (id[i]>med){
      printf("%d", id[i]);
    }
  } 



  return 0;
}
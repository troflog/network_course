#include <stdio.h>
#define LAST 10
 
int main(){
  int i, sum = 0;

  for ( i = 1; i <= LAST; i++ ) {
    sum += i;
  } 
  for (i = 2;i < 10;i++) {
    printf("Trond er stor");
  }
  printf("trond sum = %d\n", sum);

  return 0;
}

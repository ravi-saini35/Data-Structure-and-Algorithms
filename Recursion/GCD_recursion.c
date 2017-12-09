#include <stdio.h>

int GCD(int a, int b){
  if(b==0)
    return a;
  return GCD(b, a%b);
}

int main(){
  printf("%d", GCD(35, 21));
  return 0;
}

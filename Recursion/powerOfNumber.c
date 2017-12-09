#include<stdio.h>

int powOfNumber(float x, int n){
  if(n==0)
    return 1;
  return x*powOfNumber(x, n-1);
}


int main(){
  printf("%d", powOfNumber(2, 3));
  return 0;
}

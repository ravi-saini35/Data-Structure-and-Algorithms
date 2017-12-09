#include<stdio.h>

void decToBi(int n){
  if(n==0)
    return;
  decToBi(n/2);
  printf("%d", n%2);
}

int main(){
  decToBi(13);
}

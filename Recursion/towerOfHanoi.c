#include<stdio.h>

void hanoi(int n, char src, char temp, char dest){
  if(n==1){
    printf("Move disk %d from %c --> %c\n", n, src, dest);
    return;
  }
  hanoi(n-1, src, dest, temp);
  printf("Move disk %d from %c --> %c\n", n, src, dest);
  hanoi(n-1, temp, src, dest);
}


int main(){
  hanoi(2, 'A', 'B', 'C');
  return 0;
}

#include<stdio.h>
#include<stdlib.h>

int factorial(int n){
    if(n==0)
        return 1;

        return n*factorial(n-1);
}


int main(){
    printf("\t**********Factorial**********\n\n");
    printf("%d\n", factorial(6));

    return 0;
}

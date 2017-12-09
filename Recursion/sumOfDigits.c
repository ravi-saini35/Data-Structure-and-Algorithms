#include<stdio.h>
#include<stdlib.h>


int sumDigits(int n){
    if(n/10==0)
        return n;
    return (sumDigits(n/10) + n%10);
}

int main(){
    printf("\t**********Sum of Digits**********\n\n");
    printf("%d\n", sumDigits(12345));

    return 0;
}

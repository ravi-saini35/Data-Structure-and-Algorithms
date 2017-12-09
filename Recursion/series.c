#include<stdio.h>
#include<stdlib.h>

int series (int n){
    int sum;
    if(n==0)
        return 0;
    sum = (n + series(n-1));
    printf("%d + ", n);
    return sum;
}

int main(){
    printf("\t**********Series**********\n\n");
    printf("%d\n", series(5));

    return 0;
}

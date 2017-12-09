#include<stdio.h>
#include<stdlib.h>

int printSum(int n){
    if(n==0){
        return 0;
    }
        printf("%d + ", n);
        return n + printSum(n-1);


}

int main(){
    printf("\t**********Print sum **********\n\n");
    printf("%d\n", printSum(15));

    return 0;
}

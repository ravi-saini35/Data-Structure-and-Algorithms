/*
File Name : bubbleSort.c
Purpose : improved bubble sort
Author: Gautam Mishra
Date: 20/12/2017
*/

//If number of swaps in a pass is zero the there is no need to proceed further
#include<stdio.h>
#define MAX 100

int main()
{
  int a[MAX], i, j, temp, n, swap;
  printf("Enter the number of elements:\t");
  scanf("%d", &n);

  for(i=0; i<n; i++){
    printf("Enter element %d\t", i+1);
    scanf("%d", &a[i]);
  }

  //Sorting starts here
  for(i=n-2; i>=0; i--){
    swap=0;
    for(j=0; j<=i; j++){
      if(a[j]>a[j+1]){
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
        swap++;
      }
    }
    if(swap==0)
      break;
  } //sorting ends


  printf("\nThe sorted list is\n");
  for(i=0; i<n; i++){
    printf("%d\t", a[i]);
  }
  printf("\n");

  return 0;
}

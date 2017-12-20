/*
File Name : bubbleSort.c
Purpose : To demonstrate bubble sort algorithm
Author: Gautam Mishra
Date: 20/12/2017
*/

#include<stdio.h>
#define MAX 100

int main()
{
  int a[MAX], i, j, temp, n;
  printf("Enter the number of elements:\t");
  scanf("%d", &n);

  for(i=0; i<n; i++){
    printf("Enter element %d\t", i+1);
    scanf("%d", &a[i]);
  }

  //Sorting starts here
  for(i=n-2; i>=0; i--){
    for(j=0; j<=i; j++){
      if(a[j]>a[j+1]){
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  } //sorting ends


  printf("\nThe sorted list is\n");
  for(i=0; i<n; i++){
    printf("%d\t", a[i]);
  }
  printf("\n");

  return 0;
}

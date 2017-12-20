/*
File Name : insertionSort.c
Purpose : To demonstrate insertion sort algorithm
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
  for(i=1; i<n; i++){
    temp = a[i];
    for(j=i-1; j>=0 && a[j]>temp; j--)
      a[j+1] = a[j];
    a[j+1] = temp;
  } //sorting ends


  printf("\nThe sorted list is\n");
  for(i=0; i<n; i++){
    printf("%d\t", a[i]);
  }
  printf("\n");

  return 0;
}

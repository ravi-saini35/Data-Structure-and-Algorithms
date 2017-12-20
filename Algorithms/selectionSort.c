/*
File Name : selectionSort.c
Purpose : To demonstrate selection sort algorithm
Author: Gautam Mishra
Date: 20/12/2017
*/

#include<stdio.h>
#define MAX 100

int main()
{
  int a[MAX], n, i, min, j, temp;
  printf("Enter the number of elements:\t");
  scanf("%d", &n);

  for(i=0; i<n; i++){
    printf("Enter %dth element\t", i+1);
    scanf("%d", &a[i]);
  }

  //Sorting starts here
  for(i=0; i<n-1; i++){
    min = i;
    for(j=i+1; j<n; j++)
      if(a[j]<a[min])
        min = j;
    if(i!=min){
      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
    }
  } //Sorting ends


  printf("\nThe sorted list is\n");
  for(i=0; i<n; i++){
    printf("%d\t", a[i]);
  }

  return 0;
}

/*
File Name : mergingSortedList.c
Purpose : To demonstrate merge sort
Author: Gautam Mishra
Date: 20/12/2017
*/
#include<stdio.h>
#define MAX 100

void merge(int a1[], int a2[], int temp[], int n1, int n2);

int main()
{
  int a1[MAX], a2[MAX], temp[2*MAX], i, n1, n2;

  printf("Enter the number of elements in 1st array:\t");
  scanf("%d", &n1);

  for(i=0; i<n1; i++){
    printf("Enter element %d\t", i+1);
    scanf("%d", &a1[i]);
  }

  printf("Enter the number of elements in 2nd array:\t");
  scanf("%d", &n2);

  for(i=0; i<n2; i++){
    printf("Enter element %d\t", i+1);
    scanf("%d", &a2[i]);
  }

  merge(a1, a2, temp, n1, n2);

  printf("\nThe merged list is\n");
  for(i=0; i<n1+n2; i++){
    printf("%d\t", temp[i]);
  }
  printf("\n");

  return 0;
}

void merge(int a1[], int a2[], int temp[], int n1, int n2){
  int i, j, k;
  k=i=j=0;
  while((i<=n1-1) && (j<=n2-1)){
    if(a1[i]<a2[j])
      temp[k++] = a1[i++];
    else
      temp[k++] = a2[j++];
  }

  while(i<=n1-1)
   temp[k++] = a1[i++];

   while(j<=n2-1)
   temp[k++] = a2[j++];
}

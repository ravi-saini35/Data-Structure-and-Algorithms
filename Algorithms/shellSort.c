/*
File Name : shellSort.c
Purpose : To demonstrate shell sort algorithm
Author: Gautam Mishra
Date: 20/12/2017
*/

#include<stdio.h>
#define MAX 100

int main()
{
  int a[MAX], i, j, temp, n, h;
  printf("Enter the number of elements:\t");
  scanf("%d", &n);

  for(i=0; i<n; i++){
    printf("Enter element %d\t", i+1);
    scanf("%d", &a[i]);
  }
  printf("Enter maximum increment:\t");
  scanf("%d", &h);

  //Sorting starts here
  while(h>=1){
    for(i=h; i<n; i++){
      temp = a[i];
      for(j=i-h; j>=0 && a[j]>temp; j=j-h)
        a[j+h] = a[j];
      a[j+h] = temp;
    }
    h = h-2;
  }
   //sorting ends


  printf("\nThe sorted list is\n");
  for(i=0; i<n; i++){
    printf("%d\t", a[i]);
  }
  printf("\n");

  return 0;
}

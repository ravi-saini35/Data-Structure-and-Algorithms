/*
File Name : mergeSortRecursive.c
Purpose : To demonstrate recursive merge sort algorithm
Author: Gautam Mishra
Date: 21/12/2017
*/

#include<stdio.h>
#define MAX 100


void merge(int a[], int temp[], int low1, int up1, int low2, int up2);
void mergeSort(int a[], int low, int up);
void copy(int a[], int temp[], int low, int up);

int main()
{
  int a[MAX], i, n;


  printf("Enter the number of elements:\t");
  scanf("%d", &n);

  for(i=0; i<n; i++){
    printf("Enter element %d\t", i+1);
    scanf("%d", &a[i]);
  }

  mergeSort(a, 0, n);

  printf("\nThe sorted list is\n");
  for(i=0; i<n; i++){
    printf("%d\t", a[i]);
  }
  printf("\n");


  return 0;
}


void mergeSort(int a[], int low, int up){
int mid = (low+up)/2;
int temp[MAX];

if(low==up)
    return;
mergeSort(a, low, mid);
mergeSort(a, mid+1, up);

merge(a, temp, low, mid, mid+1, up);
copy(a, temp, low, up);
}



void merge(int a[], int temp[], int low1, int up1, int low2, int up2){
  int i, j, k;
  k=i=low1;
  j=low2;
  while((i<=up1) && (j<=up2)){
    if(a[i]<a[j])
      temp[k++] = a[i++];
    else
      temp[k++] = a[j++];
  }

  while(i<=up1)
   temp[k++] = a[i++];

   while(j<=up2)
   temp[k++] = a[j++];
}

void copy(int a[], int temp[], int low, int up){
  int i=low;
  while(i<=up){
    a[i]=temp[i];
    i++;
  }
}

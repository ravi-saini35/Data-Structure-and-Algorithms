#include<stdio.h>
#include<stdlib.h>
#define MAX 7
//Alot of bugs, will fix sometime soon
int a[MAX];
int front, rear;

void initializeStack();
int isEmpty();
int isFull();
void display();
void insert(int);
int delete();
int peek();
int size();


void main(){
  int choice, x;

  initializeStack();

  while(1){
    printf("1.Insert an element in Queue\n");
    printf("2.delete an element from Queue\n");
    printf("3.Peek elemen\n");
    printf("4.Size of Queue\n");
    printf("5.Display the Queue\n");
    printf("6.Exit\n");
    printf("Enter Choice\n");
    scanf("%d", &choice);

    if(choice==6)
      break;

    switch(choice){

      case 1: printf("Enter the element\t");
              scanf("%d", &x);
              insert(x);
              break;
      case 2: printf("%d is deleted from Queue\n", delete());
              break;
      case 3: printf("Peek element is %d\n", peek());
              break;
      case 4: printf("size of Queue is %d\n", size());
              break;
      case 5:
              display();
	            break;
      default:printf("Enter valid choice\n\n");
              break;

    }
  }
}

void initializeStack(){
  front=rear=-1;
}

int isEmpty(){
    if(front==-1 || front==rear+1)
      return 1;
    else
      return 0;
}

int isFull(){
  if((front ==0 && rear == MAX-1) || (front==rear+1))
    return 1;
  else
  return 0;
}

int size(){
  if(isEmpty())
    return 0;
  if(isFull)
    return MAX;
  int i, sz;
  i=front;
  sz=0;
  if(front<=rear){
    while(i<rear){
      sz++;
      i++;
    }
  }
  else{
    while(i<=MAX-1){
      sz++;
      i++;
    }
    i=0;
    while(i<=rear){
      sz++;
      i++;
    }
  }
  return sz;
}

void insert(int x){
  if(isFull()){
    printf("Queue Overflow\n");
    exit(1);
  }

  if(front=-1)
    front = 0;
  if(rear=MAX-1)
    rear=0;
  else
    rear=rear+1;
    a[rear]=x;
}

int delete(){
  int x;
  if(isEmpty()){
    printf("Queue Underflow!\n");
    exit(1);
  }
  x = a[front];
  if(front==rear) // queue has only one element
  {
    front =-1;
    rear=-1;
  }else if(front==MAX-1)
    front=0;
  else
    front++;
  return x;
}

int peek(){
  if(isEmpty()){
    printf("Queue Underflow\n");
    exit(1);
  }
return a[front];
}

void display(){
  int i=front;
  printf("Queue is \n");

  if(front<=rear){
    while(i<=rear){
      printf("%d ", a[i]);
      i++;
    }
  }
  else{
    while(i<=MAX-1)
      printf("%d ", a[i++]);
    i=0;
    while(i<=rear)
      printf("%d ", a[i++]);
  }
  printf("\n");
}

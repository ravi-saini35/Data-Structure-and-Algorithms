#include<stdio.h>
#include<stdlib.h>
#define MAX 5

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
  if(rear==MAX-1)
    return 1;
  return 0;
}

int size(){
  if(isEmpty())
    return 0;
  return rear-front+1;
}

void insert(int x){
  if(isFull()){
    printf("Queue Overflow");
    exit(1);
  }

  if(front=-1)
    front = 0;
    rear++;
    a[rear]=x;
}

int delete(){
  if(isEmpty()){
    printf("Queue Underflow!\n");
    exit(1);
  }
  int x = a[front];
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
  int i;
  printf("Queue is \n");
  for(i=front; i<=rear; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
}

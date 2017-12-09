#include<stdio.h>
#include<stdlib.h>
#define MAX 7
//Alot of bugs, will fix sometime soon
int a[MAX];
int front, rear;

void initializeQueue();
int isEmpty();
int isFull();
void display();
void insertFront(int);
int deleteFront();
void insertRear();
int deleteRear();


void main(){
  int choice, x;

  initializeQueue();

  while(1){
    printf("1.Insert at front end\n");
    printf("2.Insert at rear end\n");
    printf("3.delete from front end\n");
    printf("4.delete from rear end\n");
    printf("5.Display the Queue\n");
    printf("6.Exit\n");
    printf("Enter Choice\n");
    scanf("%d", &choice);

    if(choice==6)
      break;

    switch(choice){

      case 1: printf("Enter the element\t");
              scanf("%d", &x);
              insertFront(x);
              break;
      case 2: printf("Enter the element\t");
              scanf("%d", &x);
              insertRear(x);
              break;
      case 3: printf("%d is deleted from Queue\n", deleteFront());
              break;
      case 4: printf("%d is deleted from Queue\n", deleteRear());
              break;
      case 5:
              display();
	            break;
      default:printf("Enter valid choice\n\n");
              break;

    }
  }
}

void initializeQueue(){
  front=rear=-1;
}

void insertFront(int x){
    if(isFull()){
      printf("Queue Overflow\n");
      return;
    }
    if(front==-1){
      front=0;
      rear=0;
    } else if(front==0){
      front = MAX-1;
    }
      else
      front = front -1;
  a[front] = x;
}

void insertRear(int x){
  if(isFull()){
    printf("Queue Overflow\n");
    return;
  }

  if(front==-1)
    rear = 0;
  if(rear=MAX-1)
    rear=0;
  else
    rear = rear+1;
  a[rear] = x;
}

int deleteFront(){
  int x;
  if(isFull()){
    printf("Queue Underflow!\n");
    exit(1);
  }
  x=a[front];
  if(front=rear){
    front=rear=-1;
  }
  else if(front=MAX-1){
    front = 0;
  }
  else
    front=front+1;
    return x;
}

int deleteRear(){
  int x;
  if(isFull()){
    printf("Queue Underflow!\n");
    exit(1);
  }
  x=a[front];

  if(front==rear){
    front=rear=-1;
  }
  else if(rear==0){
    rear=MAX-1;
  } else{
    rear = rear-1;
  }
  return x;
}

int isFull(){
  if((front==0 && rear == MAX-1) || (front==rear+1))
    return 1;
  else
    return 0;
}

int isEmpty(){
  if(front==-1)
    return 1;
  else
    return 0;
}

void display(){
  int i;
  if(isEmpty()){
    printf("Queue is empty\n");
    return;
  }
  printf("Queue is:\n");
  i=front;
  if(front<=rear)
  {
    while(i<=rear){
      printf("%d", a[i++]);
    }
  }
    else{
      while (i<rear) {
        printf("%d", a[i++]);
      }
    }
    printf("\n");
  }

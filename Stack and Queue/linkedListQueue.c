#include<stdio.h>
#include<stdlib.h>

struct node {
  int info;
  struct node *link;
};

void initializeStack();
int isEmpty();
void display();
void insert(int);
int delete();
int peek();
int size();

struct node *front, *rear;

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
  front=rear=NULL;
}

int isEmpty(){
  if(front==NULL)
    return 1;
  else
    return 0;
}

void insert(int x){
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  if(temp==NULL){
    printf("No memeory available\n");
    exit(1);
  }
  temp->info=x;
  temp->link=NULL;
  if(front==NULL)
    front =temp;
  else
    rear->link = temp;
  rear=temp;
}

int delete(){
  int x;
  struct node *temp;
  if(isEmpty()){
    printf("Queue Underflow!\n");
    exit(1);
  }
  temp = front;
  front = front->link;
  x=temp->info;
  free(temp);
  return x;
}

int size(){
  struct node *p;
  int s=0;
  p=front;
  while(p!=NULL){
    s++;
    p=p->link;
  }
  return s;
}

int peek(){
  if(isEmpty()){
    printf("Queue Underflow!\n");
    exit(1);
  }
  return front->info;
}

void display(){
  if(isEmpty()){
    printf("Queue underflow\n");
    exit(1);
  }
  struct node *p = front;
  printf("Queue is \n");
  while(p!=NULL){
    printf("%d ", p->info);
    p=p->link;
  }
  printf("\n\n");
}

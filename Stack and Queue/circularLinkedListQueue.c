#include<stdio.h>
#include<stdlib.h>

struct node{
  int info;
  struct node *link;
};

struct node *rear;

void initializeStack();
int isEmpty();
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
   rear=NULL;
}

int isEmpty(){
  if(rear==NULL)
    return 1;
  return 0;
}

void insert(int x){
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp->info=x;
  if(temp==NULL){
    printf("No memory available\n");
    exit(1);
  }

  if(isEmpty()){
    rear=temp;
    rear->link=temp;
  }
  else{
    temp->link=rear->link;
    rear->link=temp;
    rear=temp;
  }
}

int delete(){
  struct node *temp;
  if(isEmpty()){
    printf("Queue Underflow!\n");
    exit(1);
  }
  if(rear->link==rear){
      temp=rear;
      rear=NULL;
  }
  else{
    temp = rear->link;
    rear->link=temp->link;
  }
  int x=temp->info;
  free(temp);
  return x;
}

int peek(){
  if(isEmpty()){
    printf("Queue Underflow!\n");
    exit(1);
  }
  return rear->link->info;
}

void display(){
  struct node *p;
  if(isEmpty()){
    printf("Queue Underflow!\n");
    exit(1);
  }
  printf("Queue is \n");
  p=rear->link;
  do{
    printf("%d ", p->info);
    p=p->link;
  }while(p!=rear->link);
  printf("\n\n");
}

int size(){
  struct node *p;
  int s=0;
  p=rear->link;
  do{
    s++;
    p=p->link;
  }while(p!=rear->link);
  return s;
}

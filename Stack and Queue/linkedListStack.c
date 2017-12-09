#include<stdio.h>
#include<stdlib.h>

struct node {
  int info;
  struct node *link;
};

struct node *top;

void display();
int pop();
void initializeStack();
void push(int);
int peek();
int size();
int isEmpty();




void main(){
  int choice, x;

  initializeStack();

  while(1){
    printf("1.Push an element in Stack\n");
    printf("2.Pop an element from Stack\n");
    printf("3.Peek elemen\n");
    printf("4.Size of stack\n");
    printf("5.Display the stack\n");
    printf("6.Exit\n");

    scanf("%d", &choice);

    if(choice==6)
      break;

    switch(choice){

      case 1: printf("Enter the element\t");
              scanf("%d", &x);
              push(x);
              break;
      case 2: printf("%d poped from Stack\n", pop());
              break;
      case 3: printf("Peek element is %d\n", peek());
              break;
      case 4: printf("size of Stack is %d\n", size());
              break;
      case 5: printf("Stack is \n");
              display();
	      break;
      default:printf("Enter valid choice\n\n");
              break;

    }
  }
}


void initializeStack(){
  top = NULL;
}

int size(){
  int s=0;
  struct node *p;
  p=top;
  while (p!=NULL) {
    p=p->link;
    s++;
  }
  return s;
}

void push(int x){
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  if(temp==NULL){
    printf("Memory Full!!\n");
    exit(0);
  }
  temp->info=x;
  temp->link=top;
  top=temp;
}

int pop(){
  struct node *temp;
  int x;
  if(isEmpty()){
    printf("Stack Underflow!\n");
    exit(1);
  }
  temp=top;
  x=temp->info;
  top=top->link;
  free(temp);
  return x;
}

int peek(){
  if(isEmpty()){
    printf("Stack Underflow!\n");
    exit(1);
  }
  return top->info;
}

int isEmpty(){
  if(top==NULL)
    return 1;
  else
    return 0;
}

void display(){
  struct node *p;
  p=top;
  if(isEmpty()){
    printf("Stack is empty\n");
    return;
  }
  printf("Stack is\n");
  while(p!=NULL){
    printf("%d\n", p->info);
    p=p->link;
  }
  printf("\n");
}

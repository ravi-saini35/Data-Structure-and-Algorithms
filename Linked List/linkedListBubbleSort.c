#include<stdio.h>
#include<stdlib.h>

struct node{
int info;
struct node *link;
};


void Display(struct node*);
struct node *InsertAtBeginning(struct node*, int);
void InsertAtEnd(struct node*, int);
struct node *createList(struct node*);
void InsertAfter(struct node*, int, int);
struct node *Delete(struct node*, int);
void sortByExchangingInfo(struct node*);
struct node *sortByExchangingLinks(struct node*);




void main(){
int n, i;
struct node *start=NULL;
struct node *start1=NULL;
printf("\t********Implementation of Linked List********\n\n");
int choice, data, x, k;

start = createList(start);
while(1){
    printf("\tEnter the choice :\n\n");
    printf("\t1.Display the linked list\n");
    printf("\t2.Insert a new node in the beginning\n");
    printf("\t3.Insert a new node at the end\n");
    printf("\t4.Inset after a certain node\n");
    printf("\t5.Delete a given node\n");
    printf("\t6.sort by exchanging Info\n");
    printf("\t7.Sort by exchanging links\n");
    printf("\t8.Exit\n");
    scanf("%d", &choice);
    if(choice==8)
        break;
    switch(choice){
        case 1: Display(start);
                break;
        case 2: printf("Enter the node element:\n");
                scanf("%d", &data);
                start=InsertAtBeginning(start, data);
                break;
        case 3: printf("Enter the node element:\n");
                scanf("%d", &data);
                InsertAtEnd(start, data);
                break;
        case 4: printf("Enter the node element to be inserted:\n");
                scanf("%d", &data);
                printf("Enter node after which you want to Insert\n");
                scanf("%d", &x);
                InsertAfter(start, data, x);
                break;
        case 5: printf("Enter the node element to be deleted:\n");
                scanf("%d", &data);
                start=Delete(start, data);
                break;
        case 6:printf("Sorted!\n\n");
                sortByExchangingInfo(start);
                break;
        case 7:printf("Sorted!\n\n");
                start=sortByExchangingLinks(start);
                break;
        default:printf("\tEnter a valid choice\n");
                break;
    }
}


}



struct node *createList(struct node *start){

int n, data, i;

printf("\tEnter the number of nodes:\n");
scanf("%d", &n);

if(n==0)
return start;

printf("Enter the first node:\t");
scanf("%d", &data);
start=InsertAtBeginning(start, data);

for(i=2; i<=n; i++){
printf("Enter the next element to be Inserted\t");
scanf("%d", &data);
InsertAtEnd(start, data);
 }
 printf("\n\n");
return start;
} // end of createList()




struct node *InsertAtBeginning(struct node* start, int data){
struct node *temp;

temp= (struct node*)malloc(sizeof(struct node));
temp->info=data;
temp->link=start;
start=temp;
return start;
}


void InsertAtEnd(struct node* start, int data){

struct node *temp, *ptr;
temp= (struct node*)malloc(sizeof(struct node));
temp->info=data;
ptr=start;

while(ptr->link!=NULL)
ptr=ptr->link;

ptr->link=temp;
temp->link=NULL;
}


void Display(struct node *start){
int i;

struct node *ptr;
if(start==NULL){
printf("\tList is empty\n\n");
return;
}
printf("Displaying the linked list\n\n");
ptr=start;
while(ptr!=NULL){
printf("%d  ", ptr->info);
ptr=ptr->link;
 }
printf("\n\n");
}


void InsertAfter(struct node *start, int data, int x){

   struct node *p, *temp;
   p=start;

   while(p!=NULL){
    if(p->info==x)
        break;
    p=p->link;
   }

   if(p==NULL)
    printf("Not present in the list\n\n");
   else{
    temp = (struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=p->link;
    p->link=temp;
   }
}


struct node *Delete(struct node* start, int x){

    struct node *temp, *p;
    if(start==NULL){
        printf("List is empty");
        return start;
    }
    if(start->info==x){
        temp=start;
        start=start->link;
        free(temp);
        return start;
    }
    p=start;
    while(p->link!=NULL){
        if(p->link->info==x)
            break;
        p=p->link;
    }

    if(p->link==NULL){
        printf("node not found\n\n");
    }
    else{
        temp=p->link;
        p->link=temp->link;
        free(temp);
    }
    return start;
}


void sortByExchangingInfo(struct node *start){
  struct node *end, *p, *q;
  int temp;
  for(end=NULL; end!=start->link; end=p){
    for(p=start; p->link!=end; p=p->link){
      q=p->link;
      if(p->info > q->info){
        temp=p->info;
        p->info=q->info;
        q->info=temp;
      }
    }
  }

}

struct node *sortByExchangingLinks(struct node *start){
  struct node *end, *p, *q, *r, *temp;

  for(end=NULL; end!=start->link; end=p){
    for(r=p=start; p->link!=end;r=p, p=p->link){
        q=p->link;
        if(p->info>q->info){
          p->link=q->link;
          q->link=p;
          if(p!=start)
            r->link=q;
          else
            start=q;
          temp=p;
          p=q;
          q=temp;
        }
    }
  }
  return start;
}

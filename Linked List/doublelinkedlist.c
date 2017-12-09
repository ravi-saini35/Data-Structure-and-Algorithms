//Implementation of double linked list
#include<stdio.h>
#include<stdlib.h>




struct node{
int info;
struct node *next;
struct node *prev;
};


void Display(struct node*);
struct node *InsertAtBeginning(struct node*, int);
struct node *InsertInEmpty(struct node*, int);
void InsertAtEnd(struct node*, int);
struct node *createList(struct node*);
void InsertAfter(struct node*, int, int);
struct node *InsertBefore(struct node*, int, int);
struct node *InsertAtIndex(struct node*, int, int);
struct node *DeletefromBeginning(struct node*);
struct node *DeletefromEnd(struct node*);
struct node *Delete(struct node*, int);
struct node *Reverse(struct node*);





void main(){
int n, i;
struct node *start=NULL;
printf("\t********Implementation of Linked List********\n\n");
int choice, data, x, k;

start = createList(start);

while(1){
    printf("\tEnter the choice :\n\n");
    printf("\t1.Display the linked list\n");
    printf("\t2.Insert a new node in the beginning\n");
    printf("\t3.Insert a new node at the end\n");
    printf("\t4.Inset after a certain node\n");
    printf("\t5.Insert before a certain node\n");
    printf("\t6.Insert at a given Index\n");
    printf("\t7.Delete from the beginning\n");
    printf("\t8.Delete from the end\n");
    printf("\t9.Delete a given node n\n");
    printf("\t10.Reverse the list\n");
    printf("\t11.Exit\n");
    scanf("%d", &choice);
    if(choice==11)
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
        case 5: printf("Enter the node element to be inserted:\n");
                scanf("%d", &data);
                printf("Enter node after which you want to Insert\n");
                scanf("%d", &x);
                start=InsertBefore(start, data, x);
                break;/*
        case 6: printf("Enter the node element to be inserted:\n");
                scanf("%d", &data);
                printf("Enter the index\n");
                scanf("%d", &k);
                start=InsertAtIndex(start, data, k);
                break;
        case 7: printf("Deleted form beginnign\n\n");
                start=DeletefromBeginning(start);
                break;
        case 8: printf("Deleted form the end\n\n");
                start=DeletefromEnd(start);
                break;*/
        case 9: printf("Enter the node element to be deleted:\n");
                scanf("%d", &data);
                start=Delete(start, data);
                break;
        case 10:printf("Reversed the linked list\n\n");
                start=Reverse(start);
                break;
        default:printf("\tEnter a valid choice\n");
                break;
    }
  }
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
ptr=ptr->next;
 }
printf("\n\n");
}



struct node *InsertAtBeginning(struct node *start, int data){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->info=data;
    if(start==NULL){
        return InsertInEmpty(start, data);
    }
    temp->prev=NULL;
    temp->next=start;
    start->prev=temp;
    start=temp;

    return start;
}



struct node *InsertInEmpty(struct node *start, int data){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->prev=NULL;
    temp->next=NULL;
    start=temp;
    return start;
}

void InsertAtEnd(struct node *start, int data){
    struct node *p, *temp;
    p=start;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    while(p->next!=NULL){
        p=p->next;
    }
    temp->next=NULL;
    temp->prev=p;
    p->next=temp;
}



void InsertAfter(struct node *start, int data, int x){
    struct node *temp, *p;
    p=start;
    while(p!=NULL){
        if(p->info==x)
            break;
        p=p->next;
    }
    if(p==NULL){
        printf("Node not found\n\n");
        return;
    }
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->next=p->next;
    temp->prev=p;
    p->next->prev=temp;
    p->next=temp;
}



struct node *InsertBefore(struct node *start, int data, int x){
    struct node *temp, *p;
    p=start;
    while(p!=NULL){
        if(p->info==x)
            break;
        p=p->next;
    }
    if(p==NULL){
        printf("Node not found\n\n");
        return start;
    }
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->next=p;
    temp->prev=p->prev;
    p->prev->next=temp;
    p->prev=temp;
    return start;
}



struct node *createList(struct node *start){
    int n, data, i;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    printf("Enter the 1st node:\t");
    scanf("%d", &data);
    start=InsertInEmpty(start, data);

    for(i=2; i<=n; i++){
        printf("Enter the %dth node:\t", i);
        scanf("%d", &data);
        InsertAtEnd(start, data);
    }
    printf("\n\n");

    return start;
}


struct node *Delete(struct node *start, int x){
    struct node *temp;
    if(start==NULL){
        printf("List is empty!!\n\n");
        return start;
    }
    if(start->next==NULL){
        if(start->info==x){
                temp=start;
                start=NULL;
                free(temp);
                return start;

     } else{
         printf("Node not found\n\n");
         return start;
      }
    }

    if(start->info==x){
        temp=start;
        start=start->next;
        start->prev=NULL;
        free(temp);
        return start;
    }

    temp=start;
    while(temp->next!=NULL){
        if(temp->info==x)
            break;
        temp=temp->next;
    }

    if(temp->next==NULL){
        temp->prev->next=NULL;
        free(temp);
        return start;
    }

        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        return start;

}


struct node *Reverse(struct node *start){
    if(start==NULL)
        return start;
    struct node *p1, *p2;
    p1=start;
    p2=p1->next;
    p1->next=NULL;
    p1->prev=p2;
    while(p2!=NULL){
        p2->prev=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p2->prev;
    }
    start=p1;
    return start;
};




#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *link;
};

void Display(struct node*);
void createList(struct node*);
void InsertAtEnd(struct node*, int);
void InsertBefore(struct node*, int, int);
void InsertAtIndex(struct node*, int, int);
void Delete(struct node*, int);
void Reverse(struct node*);



void main(){
    int choice, data, x, k;
    struct node *head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    head->info=0;
    head->link=NULL;
    createList(head);

    while(1){
    printf("\tEnter the choice :\n\n");
    printf("\t1.Display the linked list\n");
    printf("\t2.Inset at end\n");
    printf("\t3.Insert before a certain node\n");
    printf("\t4.Insert at a given Index\n");
    printf("\t5.Delete a given node\n");
    printf("\t6.Reverse the list\n");
    printf("\t7.Exit\n");

    scanf("%d", &choice);
    if(choice==7)
        break;
    switch(choice){
        case 1: Display(head);
                break;
        case 2: printf("Enter the node element:\n");
                scanf("%d", &data);
                InsertAtEnd(head, data);
                break;
        case 3: printf("Enter the node element to be inserted:\n");
                scanf("%d", &data);
                printf("Enter node after which you want to Insert\n");
                scanf("%d", &x);
                InsertBefore(head, data, x);
                break;/*
        case 4: printf("Enter the node element to be inserted:\n");
                scanf("%d", &data);
                printf("Enter the index\n");
                scanf("%d", &k);
                InsertAtIndex(head, data, k);
                break;
        case 5: printf("Enter the node element to be deleted:\n");
                scanf("%d", &data);
                Delete(head, data);
                break;
        case 6: printf("Reversed the linked list\n\n");
                Reverse(head);
                break;*/
        default:printf("\tEnter a valid choice\n");
                break;
    }
  }

}



void Display(struct node *head){
    struct node *p;
    if(head->link==NULL){
        printf("List is empty\n\n");
        return;
    }
    p=head->link;
    while(p!=NULL){
        printf("%d ",p->info);
        p=p->link;
    }
    printf("\n");
}



void InsertAtEnd(struct node *head, int data){
    struct node *p, *temp;
    p=head;
    while(p->link!=NULL)
        p=p->link;

temp = (struct node*)malloc(sizeof(struct node));
temp->info=data;
p->link=temp;
temp->link=NULL;
}



void createList(struct node *head){
    int n, data, i;
    printf("Enter the no. of nodes:\t");
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        printf("Enter the %dth node\t", i);
        scanf("%d", &data);
        InsertAtEnd(head, data);
    }
}


void InsertBefore(struct node *head, int data, int x){
    struct node *p, *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    p=head;
    while(p->link!=NULL){
        if(p->link->info==x)
            break;
        p=p->link;
    }
    if(p->link==NULL){
        printf("Node not found\n\n");
        return;
    }
    temp->link=p->link;
    p->link=temp;

}






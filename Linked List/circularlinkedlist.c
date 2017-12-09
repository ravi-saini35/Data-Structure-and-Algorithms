#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};


void Display(struct node*);
struct node *InsertInBeginning(struct node*, int);
struct node *InsertInEmpty(struct node*, int);
struct node *InsertAtEnd(struct node*, int);
struct node *CreateList(struct node*);



int main()
{
    struct node *last;
    int choice, data, x;
    printf("**********Circular Linked List**********\n\n");
    last=CreateList(last);
    while(0){

    printf("\t1.Display\n");
    printf("\t2.Insert in the beginning\n");
    printf("\t3.Insert at the end\n");
    printf("\t4.Insert after a node\n");
    printf("\t5.Delete a node\n");
    printf("\t6.Quit\n");
    printf("\tEnter the choice\n");
    scanf("%d", &choice);

    switch(choice){

    case 1: Display(last);
            break;
    case 2: printf("Enter the node:\t");
            scanf("%d", &data);
            last=InsertInBeginning(last, data);
            break;
    case 3: printf("Enter the node:\t");
            scanf("%d", &data);
            last=InsertAtEnd(last, data);
            break;
    case 4: printf("Enter the node\t");
            scanf("%d", &data);
            printf("After which node:\t");
            scanf("%d", &x);
            break;
    case 5 :printf("Enter the node");
            printf("Deleted\n");
    default:break;


     }

    }

    return 0;
}



void Display(struct node *last){
    struct node *p;
    p=last->link;
    do{
        printf("%d", p->info);
        p=p->link;
    }while(p->link!=last);
}



struct node *InsertInBeginning(struct node *last, int data){
    struct node *temp;
    if(last==NULL){
        printf("List is empty\n");
        return last;
    }
    temp= (struct node*)malloc(sizeof(struct node));
    temp->info=data;

    temp->link=last->link;
    last->link=temp;
    return last;
}


struct node *InsertInEmpty(struct node *last, int data){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp=last;
    last->link=last;
    return last;
}



struct node *InsertAtEnd(struct node *last, int data){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node*));
    temp->info=data;
    temp->link=last->link;
    last->link=temp;
    last=temp;
    return last;
}



struct node *CreateList(struct node *last){
    int n, data, i;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    last=NULL;
    if(n==0)
        return last;
    printf("Enter the 1st node:\t");
    scanf("%d", &data);
    last=InsertInEmpty(last, data);

    for(i=2; i<=n; i++){
        printf("Enter the %dth node:\t");
        scanf("%d", &data);
        last=InsertAtEnd(last, data);
    }

    return last;

};



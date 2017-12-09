#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

void display(struct node*);
void search(struct node*, int);
struct node *InsertInOrder(struct node*, int);


int main(){
    printf("\t**********Sorted linked list**********\n\n");
    int x, data, choice;
    struct node *start=NULL;

    while(1){
        printf("\t1.Display the list\n");
        printf("\t2.Insert in order\n");
        printf("\t3.Search\n");
        printf("\t4.Quit\n");
        printf("Enter the choice\t");
        scanf("%d", &choice);

        if(choice==4)
            break;

        switch(choice){
            case 1 : printf("Displaying the list\n");
                     display(start);
                     break;
            case 2 : printf("Enter the node:\t");
                     scanf("%d", &data);
                     start=InsertInOrder(start, data);
                     break;
            case 3 : printf("Enter the node to search\n");
                     scanf("%d", &x);
                     search(start, x);
                     break;
            default: break;
        }
    }

    return 0;
}


void display(struct node *start){
    struct node *p;
    if(start==NULL){
        printf("List is empty\n\n");
        return;
    }
    p=start;
    while(p!=NULL){
        printf("%d ", p->info);
        p=p->link;
    }
    printf("\n\n");
}


void search(struct node *start, int x){
    struct node *p;
    int index=1;
    if(start==NULL){
        printf("List is empty\n\n");
        return;
    }
    p=start;
    while(p->link!=NULL){
        if(p->info==x)
            break;
        p=p->link;
        index++;
    }
    printf("%d ", index);
    printf("\n\n");
}


struct node *InsertInOrder(struct node *start, int data){
    struct node *temp, *p;
    temp= (struct node*)malloc(sizeof(struct node));
    temp->info=data;


    if(start==NULL || start->info<=data){
        temp->link=start;
        start=temp;
        return start;
    }

    p=start;

    while(p->link!=NULL && data<p->link->info)
        p=p->link;
    temp->link=p->link;
    p->link=temp;
    return start;

};

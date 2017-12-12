/*
file Name: binaryTree.c
Author: Gautam Mishra
Purpose: Implementation of binary tree in linked list
Date: 11/12/2017
*/
#include<stdio.h>
#include<stdlib.h>

//for tree
struct node{
  int info;
  struct node *lchild;
  struct node *rchild;
};

void display(struct node*, int);
struct node *getnode(char x);
void preorderTraversal(struct node*);
void inorderTraversal(struct node*);
void postorderTraversal(struct node*);
void levelOrder(struct node*);  //using queue to print;
int heightOfTree(struct node*);

//for queue
#define MAX 100
struct node *queue[MAX];
int front =-1, rear = -1;
void insertQueue(struct node*);
struct node *delete();
int queueEmpty();

int main()
{
  struct node *root = NULL;
  root = getnode('P');
  root->lchild = getnode('Q');
  root->rchild = getnode('R');
  root->lchild->lchild = getnode('A');
  root->lchild->rchild = getnode('B');
  root->rchild->lchild = getnode('X');

  display(root, 0);
  printf("\n\n");

  printf("Preorder :");
  preorderTraversal(root);
  printf("\n\n");

  printf("Inorder :");
  inorderTraversal(root);
  printf("\n\n");

  printf("Postorder :");
  postorderTraversal(root);
  printf("\n\n");

  printf("Level order :");
  levelOrder(root);
  printf("\n\n");

  printf("Height of tree is %d\n", heightOfTree(root));

  return 0;
}

//Don't know how the heck it worked?
struct node *getnode(char x){
  struct node *p = (struct node*)malloc(sizeof(struct node));
  p->info = x;
  p->lchild = p->rchild = NULL;
}

void display(struct node *p, int level){
  int i;
  if(p==NULL)
    return;
  display(p->rchild, level+1);
  printf("\n");

  for(i=0; i<level; i++)
    printf("   ");
  printf("%c", p->info);
  display(p->lchild, level+1);
}

void preorderTraversal(struct node *root){
  if(root==NULL)
    return;
  printf("%c", root->info);
  preorderTraversal(root->lchild);
  preorderTraversal(root->rchild);
}

void inorderTraversal(struct node *root){
  if(root==NULL)
    return;
  inorderTraversal(root->lchild);
  printf("%c", root->info);
  inorderTraversal(root->rchild);
}

void postorderTraversal(struct node *root){
  if(root==NULL)
    return;
  postorderTraversal(root->lchild);
  postorderTraversal(root->rchild);
  printf("%c", root->info);
}

void levelOrder(struct node *p){
  if(p==NULL){
    printf("Tree is empty\n");
    return;
  }

  insertQueue(p);
  while(!queueEmpty()){
    p=delete();
    printf("%c", p->info);
    if(p->lchild!=NULL)
      insertQueue(p->lchild);
    if(p->rchild!=NULL)
      insertQueue(p->rchild);
  }
}

int heightOfTree(struct node *root){
  int hL, hR;
  if(root==NULL)
    return 0;
  hL = heightOfTree(root->lchild);
  hR = heightOfTree(root->rchild);

  if(hL>hR)
    return 1 + hL;
  else
    return 1 + hR;
}


//functions for implementation of queue

int queueEmpty(){
  if(front==-1 || front==rear+1)
    return 1;
  else
    return 0;
}

void insertQueue(struct node *item){
  if(rear==MAX-1){
    printf("Queue Overflow");
    return;
  }
  if(front==-1)
    front=0;
  rear = rear+1;
  queue[rear]=item;
}

struct node *delete(){
  struct node *item;
  if(front==-1|| front==rear+1){
    printf("Queue Underflow!\n");
    return 0;
  }
  item = queue[front];
  front = front+1;
  return item;
}

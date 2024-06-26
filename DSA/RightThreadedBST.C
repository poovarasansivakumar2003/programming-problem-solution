/*****************************************************
Right Threaded Binary Search Tree
******************************************************/
//Header Files
#include<stdio.h>
#include<conio.h>

//Structure for node
struct node{
 int data;
 struct node *left;
 struct node *right;
 int RT;
};

//Typedefining the node pointer
typedef struct node *NODE;

//Function prototype
NODE create(int,NODE);
void insert_left(int,NODE);
void insert_right(int,NODE);
void inorder(NODE);
NODE inorder_successor(NODE);

//Main function
void main(){
 NODE head;
 int ch,i,n,item;
 clrscr();
 //Header node
 head=(NODE)malloc(sizeof(struct node));
 head->right=head;
 head->left=0;
 head->RT=0;
 while(1){
  printf("\n1.Create tree\n2.Inorder\n3.Exit\n");
  printf("Enter the choice\n");
  scanf("%d",&ch);
  switch(ch){
   case 1:printf("Enter number of nodes to create\n");
    scanf("%d",&n);
    for(i=1;i<n+1;i++){
     printf("Enter %d data\n",i);
     scanf("%d",&item);
     head=create(item,head);
    }
    getch();clrscr();break;
   case 2:inorder(head);
    break;
   case 3:free(head);exit(0);
   default: printf("Wrong choice\n");
    break;
  }
 }
}

NODE create(int item,NODE head){
 NODE curptr=head->left;
 if(!curptr){
  insert_left(item,head);
  return (head);
 }
 while(1){
  if(item<(curptr->data)){
   if(curptr->left!=0)
    curptr=curptr->left;
   else
    break;
  }
  else{
   if(item>(curptr->data)){
    if(curptr->RT==0)
     curptr=curptr->right;
    else
     break;
   }
  }
 }
 if(item<(curptr->data)){
  insert_left(item,curptr);
  return (head);
 }
 else{
  if(item>(curptr->data) && curptr->RT==1)
   insert_right(item,curptr);
 }
 return (head);
}

void insert_left(int item,NODE ptr){
 NODE newnode;
 newnode=(NODE)malloc(sizeof(struct node));
 newnode->left=0;
 newnode->data=item;
 newnode->right=ptr;
 newnode->RT=1;
 ptr->left=newnode;
}

void insert_right(int item,NODE ptr){
 NODE newnode;
 newnode=(NODE)malloc(sizeof(struct node));
 newnode->left=0;
 newnode->data=item;
 newnode->right=ptr->right;
 newnode->RT=1;
 ptr->right=newnode;
 ptr->RT=0;
}

void inorder(NODE head){
 NODE temp=head;
 if(head->left==0){
  printf("\n No nodes");
  return;
 }
 while(1){
  temp=inorder_successor(temp);
  if(temp==head)
   return;
  printf("%d=>",temp->data);
 }
}

NODE inorder_successor(NODE ptr){
 NODE temp=ptr->right;
 if(ptr->RT==1)
  return (temp);
 while(temp->left!=0)
  temp=temp->left;
 return (temp);
}

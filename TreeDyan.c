#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

struct node* createNode(int val);
struct node* insertLeft(struct node* root,int val);
struct node* insertright(struct node* root,int val);
void inOrderTraversal(struct node* root);
void preorderTraversal(struct node* root);
void postorderTraversal(struct node* root);
void main()
{
    int choice=0;
    char yes = 'y';
    int val;
    struct node* root = createNode(val);
    do
    {
       printf("1.Enter new node\n2.Enter the left node\n3.Enter the right node\n4.Exit\n");
       scanf("%d",&choice);
       do
       {
        switch (choice)
        {
        case 1:
        do
        {
            printf("\nEnter the value:");
            scanf("%d",&val);
            struct node* root = createNode(val);
            printf("\nnew node value is = %d",root->value);
            printf("\nDo you wnat to keep on inserting(y/n)");
            scanf(" %c",&yes);
        } while (yes!='n');
            break;
        case 2:
        do
        {
            printf("\nEnter the value of left node:");
            scanf("%d",&val);
            insertLeft(root,val);
            printf("The left node value is %d",root->left->value);
            printf("\nDo you wnat to keep on inserting left node(y/n)");
            scanf(" %c",&yes);
        } while (yes!='n');
        
        default:
            break;
        }

       } while (yes!='n');
       
    } while (choice!=4);
    
}//end of main

struct node* createNode(int val)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->value=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}//end of createNode

struct node* insertLeft(struct node* root,int val)
{
    struct node* lnode = createNode(val);
    root->left=lnode;
    return root->left;
}//end of insertleft

struct node* insertright(struct node* root,int val)
{
    struct node* Rnode = createNode(val);
    root->right=Rnode;
    return root->right;
}//end of insertright

void inOrderTraversal(struct node* root)
{
    if(root==NULL) 
        return;

    inOrderTraversal(root->left);
    printf("%d ",root->value);
    inOrderTraversal(root->right);
    
}

void preorderTraversal(struct node* root)
{
    if(root==NULL)
        return;
    
    printf("%d ",root->value);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct node* root)
{
    if(root==NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ",root->value);
}
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define size 3

struct queue
{
    int arr[size];
    int FRONT;
    int REAR;
};

typedef struct queue qu;

void printQueue();
bool IsEmpty();
bool IsFull();
void enqueue(qu *q, int item);
void dequeue(qu *q);
void peek(qu *q);
void main()
{
    qu *q = (qu *)malloc(sizeof(qu));
    q->FRONT=-1;
    q->REAR=-1;
    int choice=0,item;
    char ans='y';
    do
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                do
                {
                    if((!IsFull(q)))
                    {
                        printf("\nEnter the item to be inserted: ");
                        scanf("%d", &item);
                        enqueue(q, item);
                    }
                    if(IsFull(q))
                    {
                        printf("\nThe queue is full and might overflow");
                    }
                    
                    printf("\nDo you want to keep inserting(y/n): ");
                    scanf(" %c", &ans);
                } while (ans != 'n' && !IsFull(q)); 
                break;
            case 2:
                do
                {
                    if(!IsEmpty(q))
                    {
                        dequeue(q);
                        printf("\nDo you want to keep dequeuing(y/n): ");
                        scanf(" %c", &ans);
                    } 
                    if(IsEmpty(q))
                    {
                        printf("\nThe queue is empty and might underflow");
                    }   
                } while (ans != 'n' && !IsEmpty(q));
                break;
            case 3:
                peek(q);
                break;
            default:
                printf("\nInvalid choice");
        }
    } while (choice!=4);
    printQueue(q);
    
    

}//end of main

//printing the element in Queue
void printQueue(qu *q)
{
    if(!IsEmpty(q))
    {
        printf("\nThe element in the queue are:");
        for(int i=q->FRONT;i<=q->REAR;i++)
            printf(" arr[%d]=%d",i,q->arr[i]);
    }
    else
        printf("\nQueue is empty");
}//end of printQueue

//Check if the queue is empty
bool IsEmpty(qu *q)
{
    if(q->FRONT==-1&&q->REAR==-1)
        return true;
    else
        return false;
}//end of IsEmpty

//insert item in queue
void enqueue(qu *q, int item)
{
    if(!IsFull(q))
    {
        if(q->FRONT==-1)
            q->FRONT=0;
        q->REAR++;
        q->arr[q->REAR]=item;
    }
    else
        printf("\nQueue is full");
    
}//end of enqueue

//check if the queue is full
bool IsFull(qu *q)
{
    if(q->REAR==size-1)
        return true;
    else
        return false;
}//end of IsFull

//remove the first item 
void dequeue(qu *q)
{
    if(!IsEmpty(q))
    {
        printf("\nThe dequeu item is %d",q->arr[q->FRONT]);
        
        if(q->FRONT>q->REAR)
        {
            q->FRONT=-1;
            q->REAR=-1;
        }
        else
            q->FRONT++;
    }
    else
        printf("\nQueue is empty");
}//end of dequeue

//see the front item
void peek(qu *q)
{
    if(!IsEmpty(q))
        printf("\nThe first item in the queue is %d",q->arr[q->FRONT]);
    else
        printf("\nQueue is empty");
}
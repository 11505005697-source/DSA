#include<stdio.h>
#include<stdbool.h>
#define size 5

int arr[size];
int FRONT = -1;
int REAR = -1;
void printQueue();
bool IsEmpty();
bool IsFull();
void enqueue(int item);
void dequeue();
void peek();
void main()
{
    enqueue(22);
    enqueue(10);
    enqueue(23);
    // enqueue(15);
    // enqueue(11);
    // enqueue(13);
    printQueue();
    dequeue();
    printQueue();
    dequeue();
    printQueue();
    peek();

}//end of main

//printing the element in Queue
void printQueue()
{
    if(!IsEmpty())
    {
        printf("\nThe element in the queue are:");
        for(int i=FRONT;i<=REAR;i++)
            printf(" arr[%d]=%d",i,arr[i]);
    }
    else
        printf("\nQueue is empty");
}//end of printQueue

//Check if the queue is empty
bool IsEmpty()
{
    if(FRONT==-1&&REAR==-1)
        return true;
    else
        return false;
}//end of IsEmpty

//insert item in queue
void enqueue(int item)
{
    if(!IsFull())
    {
        if(FRONT==-1)
            FRONT=0;
        REAR++;
        arr[REAR]=item;
    }
    else
        printf("\nQueue is full");
    
}//end of enqueue

//check if the queue is full
bool IsFull()
{
    if(REAR==size-1)
        return true;
    else
        return false;
}//end of IsFull

//remove the first item 
void dequeue()
{
    if(!IsEmpty())
    {
        printf("\nThe dequeu item is %d",arr[FRONT]);
        FRONT++;
        if(FRONT>REAR)
        {
            FRONT=-1;
            REAR=-1;
        }
    }
    else
        printf("\nQueue is empty");
}//end of dequeue

//see the front item
void peek()
{
    if(!IsEmpty())
        printf("\nThe first item in the queue is %d",arr[FRONT]);
    else
        printf("\nQueue is empty");
}
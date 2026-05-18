#include<stdio.h>
void printArray(int arr[],int size);
int linearSearch(int arr[],int size,int searchElement);
void main()
{
    int size;
    printf("Enter the size of array:");
    scanf("%d",&size);

    int arr[size];
    for(int i=0;i<size;i++)
    {
        printf("Enter the %d element:",i+1);
        scanf("%d",&arr[i]);
    }

    printArray(arr,size);
    int searchElement;
    printf("\nEnter the element to be search:");
    scanf("%d",&searchElement);

    int pos = linearSearch(arr,size,searchElement);
    if(pos==-1)
        printf("%d element not found",searchElement);
}

void printArray(int arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("arr[%d]=%d ",i,arr[i]);
}

int linearSearch(int arr[],int size,int searchElement)
{
    int found,i;
    found = -1;
    for(i=0;i<size;i++)
    {
        if(arr[i]==searchElement)
        {
            printf("\nThe element %d is at %d index",searchElement,i);
            found = 0;
        }
    }
    return found;
}
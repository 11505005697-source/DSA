#include<stdio.h>
void printArray(int arr[],int size);
void selectionSort(int arr[],int size);
void swap(int *a, int *b);
void main()
{   int size;
    printf("Enter the size of the arry:");
    scanf("%d",&size);

    int arr[size];
    for(int i=0;i < size;i++)
    {
        printf("Enter the %d element:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Element in unsorted array are:");
    printArray(arr, size);
    selectionSort( arr, size);
    printf("\nElement in sorted array are:");
    printArray(arr, size);
    
    

}//end of main

void printArray(int arr[],int size)
{ 
    for(int i=0;i<size;i++)
        printf("\narr[%d] = %d ",i,arr[i]);
}//end of printArray

void selectionSort(int arr[],int size)
{
    int j,k,swapCount=0;
    for(int i=0;i<size-1;i++)
    {
        int minIndex = i;
        for( j=i+1;j<size;j++)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex = j;
            }
        }
        if(i!=minIndex)
        {
            swap(&arr[i],&arr[minIndex]);
            swapCount++;
        }

        // printf("\nThe %d count:",i+1);
        // for(int k=0;k<size;k++)
        //     printf("%d ",arr[k]);
        
    }
    printf("\nTotal number of swap %d",swapCount);
}//end of selectionSort


void swap(int *a, int *b)
{
    int temp = *a;   
    *a = *b;
    *b = temp;
}


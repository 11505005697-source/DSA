#include<stdio.h>
void printArray(int arr[],int size);
int partition();
void quickSort(int arr[],int low,int high);
void swap(int *a,int *b);
void main()
{
    int size;
    printf("Enter the sixe of array:");
    scanf("%d",&size);

    int arr[size];

    for(int i=0;i<size;i++)
    {
        printf("Enter the %d Element:",i+1);
        scanf("%d",&arr[i]);
    }

    printf("Unsorted array:\n");
    printArray(arr,size);

    quickSort(arr,0,size-1);

    printf("\nQuick sort arry applied:\n");
    printArray(arr,size);

}//end of main

void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
        printf("%d=arr[%d] ",i,arr[i]);
        
}//end of printArray

void quickSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int p = partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high); 
    }
}

int partition(int arr[],int low,int high)
{
    int pivot = arr[high];
    int j= low - 1;
    int i;
    for(i=low;i<high;i++)
    {
        if(arr[i]<=pivot)
        {
            j++;
            swap(&arr[i],&arr[j]);
        }   
    }
    swap(&arr[j+1],&arr[high]);
    return j+1;
}//end of partition

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}//end of swap
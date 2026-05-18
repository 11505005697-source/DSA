#include<stdio.h>
void printArray(int arr[],int arrSize);
void insertionSort();
void main()
{
    int i,arrSize;
    printf("Enter the array size:");
    scanf("%d",&arrSize);

    int arr[arrSize];

    for(i=0;i<arrSize;i++)
    {
        printf("Enter the %d element:",i+1);
        scanf("%d",&arr[i]);
    }

    printf("The unsorted array:");
    printArray(arr, arrSize);

    insertionSort(arr, arrSize);

    printf("\nThe sorted array:");
    printArray(arr, arrSize);
    
}//end of main

void printArray(int arr[],int arrSize)
{
    int i;
    for(i=0;i<arrSize;i++)
        printf(" %d",arr[i]);

}//end of printArray

void insertionSort(int arr[], int arrSize)
{
    int i, key,j;
    for(i=1;i<arrSize;i++)
    {
        key = arr[i];
        j = i - 1;

        while (key < arr[j] && j>0)
        {
            arr[j+1]=arr[j];
            j--;

        }
        arr[j+1]=key;
    }
}//end of insertionSort
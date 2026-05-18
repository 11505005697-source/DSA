#include<stdio.h>
void selectionArray();
void displayArray();
void main()
{
    int i,arrSize;
    printf("Enter the array size:");
    scanf("%d",&arrSize);

    int arr[arrSize];

    for(i=0;i<arrSize;i++)
    {
        printf("Enter %d element of the array:",i+1);
        scanf("%d",&arr[i]);
    }

    printf("The unsorted array:");
    displayArray(arr, arrSize);

    selectionArray(arr, arrSize);

    printf("\nThe sorted array:");
    displayArray(arr, arrSize);
}

void selectionArray(int arr[],int arrSize)
{
    int i,j,minIndex;
    for(i=0;i<arrSize;i++)
    {
        minIndex=i;
        for(j=i+1;j<arrSize;j++)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

}

void displayArray(int arr[],int arrSize)
{
    int i;
    for(i=0;i<arrSize;i++)
        printf(" %d",arr[i]);
}
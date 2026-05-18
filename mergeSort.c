#include<stdio.h>
void printArray(int arr[],int size);
void mergeSort(int arr[],int l,int r);
void merge(int leftArray[],int sizeLA,int rightArray[],int sizeRA,int sortedArray[]);
void main()
{
    int size,l,r;
    printf("Enter the size of array:");
    scanf("%d",&size);
    
    int arr[size];

    for(int i=0;i<size;i++)
    {
        printf("Enter the element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    
    printf("The unsorted array is:");
    printArray(arr,size);
    
    mergeSort(arr, 0, size-1);
    
    printf("\nThe sorted array is:");
    printArray(arr,size);

}//end of main

void printArray(int arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("\narr[%d] = %d ",i,arr[i]);
}//end of printArray

void mergeSort(int arr[],int l,int r)
{   
    int i,j=0;
    int size=(r-l)+1;
    int mid=size / 2;
    int leftArray[mid];
    int rightArray[size - mid];
    if(size==1)
        return;
    for(i=0;i<size;i++)
    {
        if(i<mid)
        {
            leftArray[i] = arr[i];
        }
        else
        {
            rightArray[j] = arr[i];
            j++;
        }
    }
    printf("\nElement in left array:");
    printArray(leftArray,mid);

    printf("\nElement in right array:");
    printArray(rightArray,size - mid);

    mergeSort(leftArray ,l ,(mid - 1)+l );
    mergeSort(rightArray ,mid + l ,r );

    int sizeLA = sizeof(leftArray)/sizeof(leftArray[0]);
    int sizeRA = sizeof(rightArray)/sizeof(rightArray[0]);

    // printf("\nThe size of left array is %d",sizeLA);
    // printf("\nThe size of right array is %d",sizeRA);
    merge(leftArray,sizeLA,rightArray,sizeRA,arr);
    
    
}

void merge(int leftArray[],int sizeLA,int rightArray[],int sizeRA,int sortedArray[])
{
    int l,r,i;
    l=0,r=0,i=0;

    while (l < sizeLA && r < sizeRA)
    {
        if(leftArray[l]<rightArray[r])
        {
            sortedArray[i] = leftArray[l];
            i++;
            l++;
        }
        else
        {
            sortedArray[i] = rightArray[r];
            i++;
            r++;
        }
    }
    
    while(l<sizeLA)
    {
        sortedArray[i]=leftArray[l];
        i++;
        l++;
    }

    while(r<sizeRA)
    {
        sortedArray[i]=rightArray[r];
        i++;
        r++;
    }
}
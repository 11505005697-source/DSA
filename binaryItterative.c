#include<stdio.h>
#include<stdbool.h>
bool checkSorted(int arr[],int size);
int binarySearch(int arr[],int seaechElement,int l,int h);
void main()
{
    int size,i,l,h;

    printf("Enter the size of array:");
    scanf("%d",&size);

    int arr[size];

    for(i=0;i<size;i++)
    {
        printf("Enter the %d element:",i);
        scanf("%d",&arr[i]);
    }

   
    bool check = checkSorted(arr,size);
    if(check == true)
    {   
        printf("The array is sorted");
        int seaechElement;
        printf("\nEnter the element to be search:");
        scanf("%d",&seaechElement);
        l=0;
        h=size-1;
        int bin= binarySearch(arr,seaechElement,l,h);
        if(bin == -1)
            printf("\nElement not found");
        else
            printf("\nThe element %d is at %d index",seaechElement,bin);
    }
    else
        printf("The array is not sorted");   
        
}//end of main

bool checkSorted(int arr[],int size)
{ 
    bool boolAcc = true;
    for(int i=0;i<size-1;i++)
    {
        if(arr[i] > arr[i+1])
            boolAcc = false;     
    }
    return boolAcc;

    // bool boolDec = true;
    // for(int i=0;i < size-1;i++)
    // {
    //     if(arr[i] < arr[i+1])
    //         boolDec = false;
    // }
    // return boolDec;
}//end of cheackSort

int binarySearch(int arr[],int seaechElement,int l,int h)
{
    
    int mid;
    if(l<=h)//recrusive code
    {
        mid=(l+h)/2;
        if(seaechElement==arr[mid])
            return mid;
        if(seaechElement>arr[mid])
        {
            return binarySearch(arr,seaechElement,mid+1,h);
        }
        else
        {
            return binarySearch(arr,seaechElement,l,mid-1);  
        }
    }
    return -1;
    // while (l<=h)//iterative code
    // {
    //     mid= (l + h)/ 2;
    //     if(seaechElement == arr[mid])
    //             return mid;
        
    //     if(seaechElement > arr[mid])
    //     {
    //         l=mid+1;
    //     }
    //     else
    //     // if(seaechElement < arr[mid])
    //     {
    //         h=mid-1;
    //     }
    // }
    // return -1;     
}//end of binarySearch
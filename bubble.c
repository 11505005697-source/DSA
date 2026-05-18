#include <stdio.h>

void bubblesort(int arr[], int arrysize);
void printArray(int arr[], int arrysize);

void main()
{
    int arrysize,i ;
    printf("Enter the size of array: ");
    scanf("%d",&arrysize);
    int arr[arrysize];
    
    for(i=0;i < arrysize;i++)
    {
        printf("the %d Element of array: ",i );
        scanf("%d" , &arr[i]);
    }
    
    
    printf("The unsorted array: ");
    printArray(arr, arrysize);

    bubblesort(arr , arrysize);

    printf("\nThe sorted array: ");
    printArray(arr,  arrysize);
     
}//end of main


void printArray(int arr[], int arrysize)
{
    int i;
    for ( i = 0; i < arrysize; i++)
        printf(" %d", arr[i]);
}//end of printArray

void bubblesort(int arr[], int arrysize)
{
    int i,j,k,swapCount=0;
    for(i=0;i < arrysize;i++)
    {   
        for(j=0;j<arrysize - i;j++)
        {
            if(!(arr[j] < arr[j+1]))
            {
                int temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapCount++;
            }
        }
        if(i!=j)
        {
            printf("\nPass %d:",i+1);
            for(k=0;k<arrysize;k++)
                printf(" %d",arr[k]);  
        }
               
    }
    printf("\nTotal number of swap: %d",swapCount);
}//end of bubblesort;/
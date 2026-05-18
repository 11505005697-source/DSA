#include<stdio.h>
#include<stdbool.h>
bool linearSearch(int arr[],int size,int searchElement);
void main()
{
    int size,i;
    printf("Enter the size of array:");
    scanf("%d",&size);
    
    int arr[size];
    for(i=0;i<size;i++)
    {
        printf("Enter the %d element:",i+1);
        scanf("%d",&arr[i]);
    }
    int searchElement;
    printf("Enter the element to be find:");
    scanf("%d",&searchElement);

    bool boolpos = linearSearch(arr,size,searchElement);
    if(boolpos==false)
        printf("Element %d not found",searchElement);

}

bool linearSearch(int arr[],int size,int searchElement)
{
    bool boolFound;
    boolFound=false;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==searchElement)
        {
            printf("\nThe %d element is at %d index",searchElement,i);
            boolFound=true;
        }
    }
    return boolFound;
}
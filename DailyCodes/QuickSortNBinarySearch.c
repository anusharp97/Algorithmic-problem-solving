#include <stdio.h>
#include <stdlib.h>
int partition(int a[],int l,int u)
{
    int temp,v,i,j;
    v=a[l];
    i=l;
    j=u+1;
    do
    {
        do
        {
            i++;
        }while(a[i]<v && i<=u);
        do
            j--;
            while(v<a[j]);
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    a[l]=a[j];
    a[j]=v;
    return j;
}
void quickSort(int arr[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(arr,l,u);
        quickSort(arr,l,j-1);
        quickSort(arr,j+1,u);
    }
}
int binarySearch(int arr[],int n,int x)
{
    int mid,start,end;
    start=0;
    end=n-1;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(x==arr[mid])
            return mid;
        else if(x<arr[mid])
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return -1;
}
int main()
{
    int n;
    int x;
    int i;
    printf("Enter the array size\n");
    scanf("%d",&n);
    int array[n];
    //int array[7]={10,8,5,9,2,1,6};
    printf("Read %d elements\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    quickSort(array,0,n-1);
    printf("\nArray after sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n\nEnter the element to search:\n");
    scanf("%d",&x);
    int res;
    res=binarySearch(array,n,x);


    if(res != -1)
    {
        printf("Element is found at index %d\n",res);
    }
    else
    {
        printf("No such element in the array!\n");
    }
    return 0;
}

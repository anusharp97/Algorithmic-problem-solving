#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

void printArray(int H[], int n)
{
    int i;
    for(i=1;i<n;i++)
    {
        printf("%d ",H[i]);
    }
    printf("\n");
}
void swap(int H[], int n)
{
    int temp;
    temp=H[1];
    H[1]=H[n];
    H[n]=temp;
}
void heapSort(int H[],int n)
{
    //printf("Inside\n");
    while(n>=1)
    {
        swap(H,n);
        n=n-1;
        bottomUpHeap(H,n);
    }
}

void bottomUpHeap(int H[], int n)
{
    int i,k,v,j;
    bool heap;
    for(i=(n/2);i>=1;i--)
    {
        k = i;
        v = H[k];
        heap = false;
        while(!heap && ((2*k)<=n))
        {
            j=(2*k);
            if(j<n)     ///if 2 children
            {
                if(H[j]<H[j+1])     /// get the maximum of 2 children
                    j=j+1;
            }
            if(v>=H[j])             ///if it's already heap
            {
                heap=true;
            }
            else                    /// if not swap appropriate child and parent
            {
                H[k]=H[j];
                k=j;
            }
        }
        H[k]=v;
    }
}

int main()
{
    int n=8;
    int H[8]={0,3,2,7,9,11,5,6};
    printf("Initial Array:\n");
    printArray(H,n);
    bottomUpHeap(H,n-1);
    printf("After heapification:\n");
    printArray(H,n);
    heapSort(H,n-1);
    printf("After heap sort:\n");
    printArray(H,n);
    return 0;
}

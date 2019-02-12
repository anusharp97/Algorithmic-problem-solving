#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    //int A[8]={-2,-3,4,-1,-2,1,5,-3};
    int A[n];
    int max=0,tmax=0;
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    for(i=0;i<n;i++)
    {
        tmax=tmax+A[i];
        if(tmax<0)
            tmax=0;
        if(max<tmax)
            max=tmax;
    }
    printf("%d ",max);
}

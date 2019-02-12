#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sum(int n,int arr[])
{
    int i,j,k;
    arr[0]=1;
    for(i=0,j=3;j<=n;i++,j++)
    {
         arr[j]=arr[j]+arr[i];
    }
        for(i=0,j=5;j<=n;i++,j++)
    {
        arr[j]=arr[j]+arr[i];
    }
    for(i=0,j=10;j<=n;i++,j++)
    {
        arr[j]=arr[j]+arr[i];
    }
    for(i=0;i<=n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return arr[n];
}
int main()
{
    //printf("Hello world!\n");
    int n,i,ways;
    scanf("%d",&n);
    int arr[n+1];
    memset(arr,0,(n+1)*sizeof(int));
    ways=sum(n,arr);
    printf("%d number of ways.",ways);
    return 0;
}

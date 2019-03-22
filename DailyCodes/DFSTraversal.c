#include <stdio.h>
#include <stdlib.h>

int count=1;
void DFS(int, int[]);
int G[10][10],visited[10],n;    
//n is no of vertices and graph is sorted in array G[10][10]

int main()
{
    int i,j;
    printf("Enter number of vertices:");

	scanf("%d",&n);
    int arr[2*n];
    //read the adjecency matrix
	printf("\nEnter adjecency matrix of the graph:");

	for(i=0;i<n;i++)
       for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);

    //visited is initialized to zero
   for(i=0;i<n;i++)
        visited[i]=0;
    arr[0]=count++;
    DFS(0, arr);
    arr[1]=count++;
    for(i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            arr[2*i]=count++;
           DFS(i, arr);
           arr[(2*i)+1]=count++;
        }
    }
    ///prints pre and post order traversal
    for(i=0;i<(2*n);i=i+2)
    {
        printf("%d %d\n",arr[i],arr[i+1]);
    }
return 0;
}

void DFS(int i, int arr[])
{
    int j;
	//printf("\n%d",i);
    visited[i]=1;

	for(j=0;j<n;j++)
       if(!visited[j]&&G[i][j]==1)
       {
           arr[2*j]=count++;
           DFS(j, arr);
           arr[(2*j)+1]=count++;
       }

}

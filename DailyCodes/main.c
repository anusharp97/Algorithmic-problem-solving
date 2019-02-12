#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int n1,int n2)
{
    if(n1>n2)
        return n1;
    else
        return n2;
}
int main()
{
    char str1[100];
    char str2[100];
    int i,j,k,l;
    scanf("%s",str1);
    //char str1[]="lmnop";
    //char  str2[]="lmmnoop";
    scanf("%s",str2);
    int len_str1=strlen(str1);
    int len_str2=strlen(str2);
    //printf("%s is str1 and length: %d\n %s is str2 and length: %d\n",str1,len_str1,str2,len_str2);
    int subseq[len_str1+1][len_str2+1];
    for(i=0;i<=len_str1;i++)
    {
        subseq[i][0]=0;
    }
    for(i=0;i<=len_str2;i++)
    {
        subseq[0][i]=0;
    }
    for(i=1;i<=len_str1;i++)
    {
        for(j=1;j<=len_str2;j++)
        {
            //printf("%c %c",str1[i-1],str2[j-1]);
            if(str2[j-1]==str1[i-1])
            {
                subseq[i][j]=subseq[i-1][j-1]+1;
            }
            else
                subseq[i][j]=max(subseq[i-1][j],subseq[i][j-1]);
        }
    }
    for(i=0;i<=len_str1;i++)
    {
        for(j=0;j<=len_str2;j++)
        {
            printf("%d ",subseq[i][j]);
        }
        printf("\n");
    }
    return 0;
}

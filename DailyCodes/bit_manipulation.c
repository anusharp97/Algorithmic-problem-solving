#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void bit_manipulation(char data[],int set_size)
{
    int i,j;
    unsigned int size=pow(2,set_size);
    for(i=0;i<size;i++)
    {
        for(j=0;j<set_size;j++)
        {
            if(i &(1<<j))
            {
                printf("%c",data[j]);
            }
        }
        printf("\n");
    }
}
int main()
{
    char data[3]={'a','b','c'};
    int set_size=3;
    bit_manipulation(data,set_size);
    return 0;
}


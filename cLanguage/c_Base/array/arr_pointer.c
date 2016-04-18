#include <stdio.h>

void max(int *[3]);//??int arr[][3]

int main()
{
    int arr[4][3];
    int (*p)[3];
    int i,j;
    for(p=arr;p<arr+4;p++)
    {
        for(i=0;i<3;i++)
        {
            scanf("%d",*p+i);//??
        }
    }

    for(p=arr;p<arr+4;p++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d",*(*p+j));//??
        }
    }
    return 0;
}






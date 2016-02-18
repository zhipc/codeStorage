#include <stdio.h>

int main()
{
    char cs[5]={0x11,0x22,0x33,0x44,0x55};
    char *parr[5];
    int x;
    for(x=0;x<5;x++)
    {
        printf("%p ",&cs[x]);
    }
    printf("\n");
    
    for(x=0;x<5;x++)
    {
        parr[x]=&cs[x];
    }
                               //4 5   //&cs[0]  //&cs[1]
    printf("%p %p %p %p\n",parr,parr+1,parr[0],parr[0]+1);
    return 0;
}



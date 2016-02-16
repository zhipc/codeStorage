#include <stdio.h>
int add(int x,int y)
{
    return x+y;
}
int sub(int x,int y)
{
    return x-y;
}
int mul(int x,int y)
{
    return x*y;
}
int err()
{
    printf("input error\n");
    return -1;
}
int div(int x,int y)
{
    if(y==0)
    {
        err();
    }
    return x/y;
}
int main()
{
    int (*farr[])()={add,sub,mul,div,err};  
    int x=0,a=0,b=0;

    printf("Please input 1-4:\n"
            "0:add\n"
            "1:sub\n"
            "2:mul\n"
            "3:div\n");
    while (1) {
        scanf("%d%d%d",&x,&a,&b);
        if (x > 3 || x < 0) {
            err();
        }
        printf("%d\n",farr[x](a,b));
    }
    return 0;
}

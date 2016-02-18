/*
 *此例中arr[5]的值为0，其也是变量i在系统栈中的位置，所以i被赋值为0，导致运行时死循环
 *i在arr之后声明也会出现死循环，有点费解~
 *
 * */
#include <stdio.h>

int main()
{
    int i,arr[5];
    for(i=0;i<=5;i++)
    {
        arr[i]=0;//arr[5]=0  --->i=0;
        printf("arr[%d]=%d\t",i,arr[i]);
    }
    printf("\n");
    return 0;
}

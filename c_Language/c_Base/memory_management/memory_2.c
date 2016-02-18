/*
 *通过此题可以看出来系统栈内存的自动分配原则，从高地址向低地址
 *
 * */
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[]="this is a this";
    char str2[]="is";
    char *pc=strstr(str1,str2);
    printf("%p\n",pc);
    printf("%p\n",str1);
    printf("%p\n",str2);
    return 0;
}

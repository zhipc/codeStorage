#include <stdio.h>
#include "str.h"

int main()
{
    char str1[]="this is good test";
    char str2[]="oo";
    puts(strstr(str1,str2));
    return 0;
}


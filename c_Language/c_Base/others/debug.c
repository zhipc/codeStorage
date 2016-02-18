/*
 *编译时：gcc c16.c -D DEBUG -Wall -o exe
 *
 * */
#include <stdio.h>

int main()
{
#ifdef DEBUG
    printf("debug....\n");
#endif
    printf("xvdfdsfds\n");
    return 0;
}

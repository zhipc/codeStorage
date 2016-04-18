#include <stdio.h>
#include <string.h>

char *max_len(char *strs[],int n);

int main(int argc,char * argv[])
{
    char *pc=max_len(argv,argc);
    puts(pc);
    return 0;
}

char *max_len(char *strs[],int n)
{
    int len=0;
    char *pc=NULL;
    while(*strs)
    {
        if(strlen(*strs)>len)
        {
            len=strlen(*strs);
            pc=*strs;
        }
        strs++;
    }
    return pc;
}





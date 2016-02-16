#include <stdio.h>

int  strlen(const char *s)//abcde\0
{
    int count=0;
    while(*(s+count++));//fei 0  0 '\0'->0
    return count-1;
   /* int count=0;
    int x;
    for(x=0;s[x]!='\0';x++)
    {
        count++;
    }
    return count;*/
}


char *strcpy(char *dest, const char *src)
{
    int i=0;
    while((dest[i]=src[i])!='\0')
        i++;
    return dest;
   /* int x;
    for(x=0;src[x]!='\0';x++)
    {
        dest[x]=src[x];
    }
    dest[x]='\0';
    return dest;*/
}


char *strcat(char *dest, const char *src)
{
    int len=strlen(dest);
    strcpy(dest+len,src);
    return dest;
}


//等0  大1 小-1
int strcmp(const char *s1, const char *s2)
{
    int x;
    for(x=0;s1[x]==s2[x];x++)
    {
        if(s1[x]=='\0')
            return 0;
    }
    if(s1[x]-s2[x]>0)
        return 1;
    else    
        return -1;    
}


char *strstr(const char *haystack, const char *needle)
{
    int x,y;
    for(x=0;haystack[x]!='\0';x++)
    {
        for(y=0;needle[y]!='\0';y++)
        {
            if(haystack[x+y]!=needle[y])
                break;
        }
        if(needle[y]=='\0')
        {
            return (char *)(haystack+x);
        }
    }
    return NULL;
}












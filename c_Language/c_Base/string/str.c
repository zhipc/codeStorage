#include <stdio.h>
#include <string.h>

int strcmpmy(const char *dest, const char *src)
{
    while (*src == *dest) {
        if (*src == '\0') {
            return 0;
        }
        src++;
        dest++;
    }
    if (*dest > *src) {
        return 1;
    } 
    return -1;
}

char *str(const char *haystack, const char *needle)
{
    int i;
    char *in;
    char *inle;
    for (i = 0; haystack[i] != '\0'; i++) {
        in = (char *)(haystack + i);
        inle = (char *)needle;
        while (*in == *inle) {
            //putchar(*inle);
            in++;
            inle++;
        }
        if (*inle == '\0') {
            return (char *)(haystack + i);
        }
    }
    char *p = "no found";
    return p;
}

/*
 *此为在尚观时写的，我觉得可以将其中涉及到flag的全部去掉，感觉没什么用，
 *找到时直接返回(char *)(haystack+i)，未找到时返回NULL
 *
 * */
char *strstr(const char *haystack, const char *needle)
{
    int i,j=0,flag=0;
    for(i=0;*(haystack+i)!='\0'&&*(needle+j)!='\0'; i++)
    {   

        if(*(haystack+i)==*(needle+j)&&(!strcmp(needle,haystack+i)))
        {   
            flag=1;
            return (char *)haystack+i;
        }   
        j++;
    }   
    if(flag==0)
    {   
        return NULL;
    }   
    return 0;
}

int main()
{
    //char buf[20] = "helloo";
    //printf("%d\n", strcmpmy(buf, "hello"));
    char haystack[30] = {0};
    fgets(haystack, sizeof(haystack), stdin);
    haystack[strlen(haystack) - 1] = '\0';
    char needle[10] = {0};
    fgets(needle, sizeof(needle), stdin);
    needle[strlen(needle) - 1] = '\0';
    printf("%s\n", str(haystack, needle));
    return 0;
}

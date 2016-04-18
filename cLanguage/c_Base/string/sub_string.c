/*
 *   统计子串的出现次数
 *   this is good tist
 *   is
 *   3
 *
 *
 * */
#include <stdio.h>
#include <string.h>
#define N 100
int count(char *str,char *str1)
{
    char *p=str,*p1=str1;
    int n,count=0;
    while(*p) {
        n=0;
        while(*p++==*p1++) {
            n++;
        }
        if(n==strlen(str1)) {
            count++;
        }
        p1=str1;
    }
    return count;
}
int main()
{
    char str[N],str1[N];
    printf("Please intput a string:\n");
    fgets(str,sizeof(str),stdin);
    printf("Please input the substring:\n");
    fgets(str1,sizeof(str1),stdin);
    str1[strlen(str1)-1]='\0';
    printf("%d\n",count(str,str1));
    return 0;
}

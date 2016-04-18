#include <stdio.h>
#include <string.h>
#include "tool/tool.h"
#define N 20
char *combin(const char *s1,const char *s2)
{
    int *p1,*p2,*p,*p3=p;
    create_memory((void **)&p,2*N*sizeof(char));
    for(p1=s1,p2=s2;(p1<s1+N)&&(p2<s2+N);) {
        if(*p1<*p2) {
            *p3++=*p1++;
        }else{
            *p3++=*p2++;
        }
    }
    while(p1<s1+N) {
        *p3++=*p1++;
    }
    while(p2<s2+N) {
        *p3++=*p2++;
    }
    *p3='\0';
    return p;
//    return p3-strlen(s1)-strlen(s2)-1;
}
int main()
{
    char *pc1,*pc2;
    create_memory((void **)&pc1,N*sizeof(char));
    create_memory((void **)&pc2,N*sizeof(char));
    fgets(pc1,N,stdin);
    fgets(pc2,N,stdin);
    printf("%s\n",combin(pc1,pc2));
    free_memory((void **)&pc1);
    free_memory((void **)&pc2);
    return 0;
}

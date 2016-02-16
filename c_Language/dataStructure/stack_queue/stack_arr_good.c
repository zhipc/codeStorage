/*
 *推荐使用这种方式实现栈。（栈的数组实现）
 *可以优化的是：当栈的大小不够用时，开辟当前栈大小2倍的空间，将当前栈空间复制到新开辟的空间中
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 100
#define N 2
typedef struct node{
    int *bottom;
    int *top;
    int stacksize;
}snode,*pnode;
void create_memory(void **p,int size)
{
    *p=malloc(size);
    if(*p==NULL)
    {
        printf("error!\n");
        exit(-1);
    }
}
void init_stack(pnode *s)
{
    create_memory((void **)s,sizeof(snode));
    (*s)->stacksize=STACKSIZE;
    create_memory((void **)&((*s)->bottom), (*s)->stacksize * sizeof(int));
    (*s)->top=(*s)->bottom;
}
void push(pnode s,int elem)
{
    if(s->top-s->bottom >= s->stacksize)
    {
        printf("stack_full!\n");
        exit(-1);
    }
    *s->top++=elem;
}
int pop(pnode s)
{
    if(s->top==s->bottom)
    {
        printf("stack_empty!\n");
        exit(-1);
    }
    return *--s->top;
}
int main()
{
    pnode s=NULL;
    int x=0;
    init_stack(&s);

    scanf("%d",&x);
    if(x<0)
    {
        printf("-");
        x=-x;
    }
    while(x)
    {
        push(s,x%N);
        x=x/N;
    }
    while(s->bottom < s->top)
    {
        printf("%d",pop(s));
    }
    printf("\n");
    return 0;
}

/*
 *栈的链表实现不推荐应用，由于其频繁申请和释放内存，非常消耗系统资源
 *虽然如此，本程序还是有很多值得学习的地方
 *
 * */
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
    struct node *pre;
}snode,*pnode;
typedef struct stack{
    pnode top;
    pnode bottom;
}sstack,*pstack;
void create_memory(void **p,int size)
{
    *p=malloc(size);
    if(*p==NULL)
    {
        printf("error!\n");
        exit(-1);
    }
}
void init_node(pnode *phead,int size)
{
    create_memory((void **)phead,size);
    (*phead)->next=NULL;
    (*phead)->pre=NULL;
}
void init_stack(pstack *s)
{
    create_memory((void **)s,sizeof(sstack));
    init_node(&(*s)->bottom,sizeof(snode));
    (*s)->top=(*s)->bottom;
}
void push(pstack s,int num)
{
    pnode pnew;
    init_node(&pnew,sizeof(snode));
    if(pnew==NULL)
    {
        printf("full!\n");
        exit(-1);
    }
    pnew->data=num;

    s->top->next=pnew;
    pnew->pre=s->top;
    s->top=pnew;
}
int pop(pstack s)
{
    if(s->bottom==s->top)
    {
        printf("empty!\n");
        exit(-1);
    }
    int num;
    
    num=s->top->data;
    s->top=s->top->pre;
    //destory(&ptmp);
    return num;
}
int main()
{
    pstack s=NULL;
    init_stack(&s);
    
    int x,i;
    int po;
    int jc=1;
    scanf("%d",&x);
    for(i=x; i>0; i--)
    {
        printf("push %d\n",i);
        push(s,i);
    }
    for(i=0; i<x; i++)
    {
        po=pop(s);
        printf("pop %d\n",po);
        jc=jc*po;
    }
    printf("%d\n",jc);
    return 0;
}

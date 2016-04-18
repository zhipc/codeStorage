/*
 *链表实现栈
 *此种方法不好，因为栈的操作一般比较频繁，所以不适合每次push的时候都开辟空间，pop的时候都释放空间
 *
 *
 * */
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
}snode, *pnode;

void init_node(pnode *phead, int size)
{
    *phead = malloc(size);
    if (*phead == NULL) {
        perror("malloc");
        exit(-1);
    }
    (*phead)->prev = *phead;
    (*phead)->next = *phead;
}

void destroy_node(pnode *phead)
{
    if (*phead != NULL) {
        free(*phead);
        *phead == NULL;
    }
}

void push(pnode phead, int x)
{
    pnode pnew;
    init_node(&pnew, sizeof(snode));
    pnew->data = x;

    pnew->prev = phead->prev;
    pnew->next = phead;
    phead->prev->next = pnew;
    phead->prev = pnew;
}

int pop(pnode phead)
{
    pnode ptmp = phead->prev;
    if (ptmp == phead) {
        perror("stack empty");
        exit(-1);
    }
    int ret = ptmp->data;
    ptmp->prev->next = phead;
    phead->prev = ptmp->prev;
    destroy_node(&ptmp);
    return ret;
}

int main()
{
    pnode phead;
    init_node(&phead, sizeof(snode));
    
    int x;
    scanf("%d", &x);
    while (x) {
        push(phead, x % 2);
        printf("push %d\n", x % 2);
        x /= 2;
    }
    while (phead->prev != phead) {
        printf("%d", pop(phead));
    }
    printf("\n");
    return 0;
}

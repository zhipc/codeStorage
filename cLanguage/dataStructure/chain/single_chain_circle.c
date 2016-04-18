/*
 *单循环链表
 *
 * */
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}snode, *pnode;

void init_node(pnode *phead, int size)
{
    *phead = malloc(size);
    if (*phead == NULL) {
        perror("malloc");
        exit(-1);
    }
    (*phead)->next = *phead;    //与单链表不同的第一处
}

void create_head_chain(pnode phead)
{
    int x = 0;
    pnode pnew = NULL;
    while (1) {
        scanf("%d", &x);
        if (x < 0) {
            break;
        }
        init_node(&pnew, sizeof(snode));
        pnew->data = x;
        pnew->next = phead->next;
        phead->next = pnew;
    }
}

void create_end_chain(pnode phead)
{
    int x = 0;
    pnode pnew = NULL;
    pnode plast = phead;
    while (1) {
        scanf("%d", &x);
        if (x < 0) {
            break;
        }
        init_node(&pnew, sizeof(snode));
        pnew->data = x;
        pnew->next = phead;     //与单链表不同的第二处
        plast->next = pnew;
        plast = pnew;
    }
}

void create_chain(pnode phead)
{
    create_end_chain(phead);
}

void show_chain(pnode phead)
{
    pnode ptmp = phead->next;
    for (; ptmp != phead; ptmp = ptmp->next) {  //与单链表不同的第三处
        printf("%d ", ptmp->data);
    }
    printf("\n");
}

void destroy_node(pnode *phead)
{
    if (*phead != NULL) {
        free(*phead);
        *phead = NULL;
    }
}

void destroy_chain(pnode *phead)
{
    pnode ptmp = NULL;
    if (*phead != NULL) {
        while ((*phead)->next != *phead) {  //与单链表不同的第四处
            ptmp = (*phead)->next;
            (*phead)->next = ptmp->next;
            destroy_node(&ptmp);
        }
        destroy_node(phead);
    }
}

int main()
{
    pnode phead = NULL;
    init_node(&phead, sizeof(snode));
    create_chain(phead);
    show_chain(phead);
    destroy_chain(&phead);
    return 0;
}

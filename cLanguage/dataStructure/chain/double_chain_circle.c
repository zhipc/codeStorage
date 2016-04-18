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

        pnew->prev = phead;
        pnew->next = phead->next;
        phead->next->prev = pnew;
        phead->next = pnew;
    }
}

void create_end_chain(pnode phead)
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

        pnew->prev = phead->prev;
        pnew->next = phead;
        phead->prev->next = pnew;
        phead->prev = pnew;
    }
}

void create_chain(pnode phead)
{
    create_end_chain(phead);
}

void show_positive_chain(pnode phead)
{
    pnode ptmp = phead->next;
    for (; ptmp != phead; ptmp = ptmp->next) {
        printf("%d ", ptmp->data);
    }
    printf("\n");
}

void show_inverse_chain(pnode phead)
{
    pnode ptmp = phead->prev;
    for (; ptmp != phead; ptmp = ptmp->prev) {
        printf("%d ", ptmp->data);
    }
    printf("\n");
}

void show_chain(pnode phead)
{
    show_inverse_chain(phead);
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
        while ((*phead)->next != *phead) {
            ptmp = (*phead)->next;
            (*phead)->next = ptmp->next;
            ptmp->next->prev = *phead;
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

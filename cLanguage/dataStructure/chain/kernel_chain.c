#include <stdio.h>
#include <stdlib.h>
#define N 10
#define list_entry(type, ptr, member) ((type *)((unsigned long)ptr-(unsigned long)&((type *)0)->member))

struct list_head {
    struct list_head *prev;
    struct list_head *next;
};

struct node {
    int data;
    struct list_head list;
};

struct node *init_node(int size, int data)
{
    struct node *pnew = malloc(size);
    pnew->data = data;
    pnew->list.next = &pnew->list;
    pnew->list.prev = &pnew->list;
    return pnew;
}

void insert_to_chain(struct list_head *prev, struct list_head *next, struct list_head *pinsert)
{
    pinsert->next = next;
    pinsert->prev = prev;
    prev->next = pinsert;
    next->prev = pinsert;
}

void insert_to_chain_tail(struct list_head *phead, struct list_head *pinsert)
{
    insert_to_chain(phead->prev, phead, pinsert);
}

void create_chain(struct node *phead, int node_num)
{
    int i;
    struct node *pnew = NULL;
    for (i = 0; i < node_num; i++) {
        pnew = init_node(sizeof(struct node), i + 1);
        insert_to_chain_tail(&phead->list, &pnew->list);
    }
}

void show_chain(struct list_head *phead)
{
    struct list_head *pindex = NULL;
    for (pindex = phead->next; pindex != phead; pindex = pindex->next) {
        printf("%d->", list_entry(struct node, pindex, list)->data);
    }
    printf("null\n");
}

int main()
{
    struct node *phead;
    phead = init_node(sizeof(struct node), -1);
    create_chain(phead, N);
    show_chain(&phead->list);
    return 0;
}

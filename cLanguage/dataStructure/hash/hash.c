#include <stdio.h>
#include <stdlib.h>
#define N 32

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

void create_end_chain(pnode phead, pnode pnew)
{
    pnew->prev = phead->prev;
    pnew->next = phead;
    phead->prev->next = pnew;
    phead->prev = pnew;
}

void create_chain(pnode phead)
{
    pnode pnew = NULL;
    int x;
    while (1) {
        scanf("%d", &x);
        if (x < 0) {
            break;
        }
        init_node(&pnew, sizeof(snode));
        pnew->data = x;
        create_end_chain(phead, pnew);
    }
}

void phead_to_arr(pnode arr[], pnode phead)
{
    pnode pindex = NULL;
    for (pindex = phead->next; pindex != phead; pindex = phead->next) {
        pindex->next->prev = phead;
        phead->next = pindex->next;
        create_end_chain(arr[pindex->data >> 1 & 31], pindex);
    }
}

void show_chain(pnode phead)
{
    pnode pindex = NULL;
    for (pindex = phead->next; pindex != phead; pindex = pindex->next) {
        printf("%d ", pindex->data);
    }
    printf("\n");
}

int main()
{
    pnode phead = NULL;
    pnode arr[N];
    int i;
    init_node(&phead, sizeof(snode));
    for (i = 0; i < N; i++) {
        init_node(&arr[i], sizeof(snode));
    }

    create_chain(phead);
    phead_to_arr(arr, phead);
    for (i = 0; i < N; i++) {
        if (arr[i]->next != arr[i]) {
            printf("this is %d chain\n", i);
            show_chain(arr[i]);
        }
    }
    return 0;
}

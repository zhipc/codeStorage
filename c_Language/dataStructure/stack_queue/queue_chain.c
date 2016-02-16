/*
 *gcc编译时会出现错误，但是用g++可以编译通过
 *和栈类似，队列也不适合用链表实现，也是因为频繁开辟和释放内存空间
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
    *phead = (pnode)malloc(size);
    if (*phead == NULL) {
        perror("malloc");
        exit(-1);
    }
    (*phead)->next = NULL;
}

void destroy_node(pnode *phead)
{
    if (*phead != NULL) {
        free(*phead);
        *phead = NULL;
    }
}

void queue_in(pnode queue, int data)
{
    pnode pnew;
    static pnode plast = queue; 
    init_node(&pnew, sizeof(snode));
    pnew->data = data;
    
    plast->next = pnew;
    plast = pnew;
}

int queue_out(pnode queue)
{
    int ret;
    pnode ptmp;
    if (queue->next == queue) {
        perror("queue empty");
        exit(-1);
    }
    ret = queue->next->data;
    ptmp = queue->next;
    queue->next = ptmp->next;
    destroy_node(&ptmp);
    return ret;
}

void show_queue(pnode queue)
{
    pnode ptmp;
    for (ptmp = queue->next; ptmp != NULL; ptmp = ptmp->next) {
        printf("%d ", ptmp->data);
    }
    printf("\n");
}

int main()
{
    pnode queue;
    init_node(&queue, sizeof(snode));

    int data;
    while (1) {
        scanf("%d", &data);
        queue_in(queue, data); 
        show_queue(queue);
        scanf("%d", &data);
        queue_in(queue, data); 
        show_queue(queue);

        queue_out(queue);
        show_queue(queue);
        printf("***************************\n");
    }  
    return 0;
}

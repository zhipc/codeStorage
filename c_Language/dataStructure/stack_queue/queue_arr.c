/*
 *循环队列的实现
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUEUESIZE 5

struct queue {
    int *pout;
    int *pin;
    int *start;
    int queue_size;
};

void create_memory(void **p, int size)
{
    *p = malloc(size);
    if (*p == NULL) {
        perror("malloc");
        exit(-1);
    }
}

void init_queue(struct queue **q)
{
    create_memory((void **)q, sizeof(struct queue));
    (*q)->queue_size = QUEUESIZE;
    create_memory((void **)&(*q)->pout, (*q)->queue_size * sizeof(int));
    memset((*q)->pout, 0, (*q)->queue_size * sizeof(int));
    (*q)->start = (*q)->pin = (*q)->pout;
}

void queue_in(struct queue *q, int data)
{
    if (((q->pin + 1) - q->pout) % q->queue_size == 0) {
        printf("queue full\n");
        exit(-1);
    }
    *q->pin = data;
    printf("queue_in %d\n", data);
    q->pin = q->pin + 1;
    q->pin = (q->pin - q->start) % q->queue_size + q->start;
}

int queue_out(struct queue *q)
{
    if (q->pin == q->pout) {
        printf("queue empty\n");
        exit(-1);
    }
    int data = *q->pout;
    *q->pout = 0;
    printf("queue_out %d\n", data);
    q->pout = q->pout + 1;
    q->pout = (q->pout - q->start) % q->queue_size + q->start;
    return data;
}

void show_queue(struct queue *q)
{
    int *ptmp;
    for (ptmp = q->start; ptmp < q->start + q->queue_size; ptmp++) {
        printf("%d ", *ptmp);
    }
    printf("\n");
}

int main()
{
    struct queue *queue = NULL;
    init_queue(&queue);

    int x;
    while (1) {
        scanf("%d", &x);
        queue_in(queue, x); 
        show_queue(queue);
        scanf("%d", &x);
        queue_in(queue, x); 
        show_queue(queue);

        queue_out(queue);
        show_queue(queue);
        printf("***************************\n");
    }   
    return 0;
}

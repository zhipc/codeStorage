#include "queue.h"

void init_queue(pnode *queue)
{
    int i;
    *queue = malloc(sizeof(snode));
    if (*queue == NULL) {
        perror("malloc");
        exit(-1);
    }
    for (i = 0; i < N; i++) {
        (*queue)->arr[i] = 0;
    }   
    (*queue)->pin = 0;
    (*queue)->pout = 0;
}

void queue_in(pnode queue, ptree data)
{
    if ((queue->pin + 1) % N == queue->pout) {
        perror("queue full");
        exit(-1);
    }
    queue->arr[queue->pin] = data;
    queue->pin = (queue->pin + 1) % N;
}

ptree queue_out(pnode queue)
{
    ptree ret;
    if (queue->pout == queue->pin) {
        perror("queue empty");
        exit(-1);
    }
    ret = queue->arr[queue->pout];
    queue->arr[queue->pout] = 0;
    queue->pout = (queue->pout + 1) % N;
    return ret;
}

void show_queue(pnode queue)
{
    int i;
    for (i = 0; i < N; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

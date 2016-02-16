#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct node {
    int arr[N];
    int pin;
    int pout;
}snode, *pnode;

void queue_in(pnode queue, int x)
{
    if ((queue->pin + 1) % N == queue->pout) {
        perror("queue full");
        exit(-1);
    }
    queue->arr[queue->pin] = x;
    queue->pin = (queue->pin + 1) % N;
}

int queue_out(pnode queue)
{
    int ret;
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

int main()
{
    int x;
    pnode queue = malloc(sizeof(snode));
    for (x = 0; x < N; x++) {
        queue->arr[x] = 0;
    }
    queue->pin = 0;
    queue->pout = 0;

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

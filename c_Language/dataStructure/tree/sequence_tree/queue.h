#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct node {
    char arr[N];
    int pin;
    int pout;
}snode, *pnode;

void queue_in(pnode queue, int x);

int queue_out(pnode queue);

void show_queue(pnode queue);

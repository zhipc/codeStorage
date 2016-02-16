/*
 *数组栈实现
 *p37行为何会出错？？
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct node {
    int arr[N];
    int top;
}snode, *pnode;

void push(pnode stack, int x)
{
    if (stack->top >= N) {
        perror("stack full!");
        exit(-1);
    }
    stack->arr[stack->top++] = x;
}

int pop(pnode stack)
{
    if (stack->top <= 0) {
        perror("stack empty!");
        exit(-1);
    } 
    return stack->arr[--stack->top];
}

int main()
{
    int x;
    pnode stack = malloc(sizeof(snode));
    //stack->arr[N] = {0};
    for (x = 0; x < N; x++) {
        stack->arr[x] = 0;
    }
    stack->top = 0;

    scanf("%d", &x);
    while (x) {
        push(stack, x % 2);
        printf("push %d\n", x % 2);
        x = x / 2;
    }
    while (stack->top > 0) {
        printf("%d", pop(stack));
    }
    printf("\n");
    return 0;
}

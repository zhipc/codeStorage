/*
 *基数排序
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#define N 10

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
    pnode pnew;
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

int max_digit(pnode phead)
{
    pnode ptmp = phead->next;
    int max = phead->next->data;
    int digit = 0;
    for (; ptmp != phead; ptmp = ptmp->next) {
        if (ptmp->data > max) {
            max = ptmp->data;
        }
    }
    while (max) {
        digit++;
        max /= 10;
    }
    return digit;
}

/*
 *拆链时计算arr[]的下标有两种方法：一是先取余再除，二是先除后取余。
 *我觉得应该选择方法一，虽然方法二易于理解，但其在每次调用时，内层循环会重复计算
 *
 * */
void phead_to_arr(pnode phead, pnode arr[])
{
    static int time = 1;
    int flag = 1;
    int i;
    pnode ptmp = phead->next;

    //printf("***********************************\n");
    //printf("this is %d times\n", time);
    for (i = 0; i < time; i++) {
        flag *= 10;
    }
    for (; ptmp != phead; ptmp = phead->next) {
        ptmp->next->prev = phead;
        phead->next = ptmp->next;
        create_end_chain(arr[ptmp->data % flag * 10 / flag], ptmp);
        //printf("%d to arr[%d]\n", ptmp->data, ptmp->data % flag * 10 / flag);
    }
    time++;
}

/*
void phead_to_arr2(pnode phead,pnode *arr)
{
    int counter=0,j=0;
    static int i=0;
    pnode ptmp;
    for(ptmp=phead->next; ptmp!=phead; ptmp=phead->next) {
        counter=ptmp->data;
        for(j=0; j<i; j++) {
            counter=counter/10;
        }
        ptmp->next->prev=phead;
        phead->next=ptmp->next;
        create_end_chain(arr[counter%10],ptmp);
    }
    i++;
}
*/

void arr_to_phead(pnode phead, pnode arr[])
{
    int i;
    pnode ptmp;
    for (i = 0; i < 10; i++) {
        for (ptmp = arr[i]->next; ptmp != arr[i]; ptmp = arr[i]->next) {
            ptmp->next->prev = arr[i];
            arr[i]->next = ptmp->next;
            create_end_chain(phead, ptmp);
        }
    }
}

void show_chain(pnode phead)
{
    pnode ptmp = phead->next;
    for (; ptmp != phead; ptmp = ptmp->next) {
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
    int i, digit;
    pnode phead = NULL;
    init_node(&phead, sizeof(snode));
    create_chain(phead);

    pnode arr[N];
    for (i = 0; i < N; i++) {
        init_node(&arr[i], sizeof(snode));
    }

    digit = max_digit(phead); 
    for (i = 0; i < digit; i++) {
        phead_to_arr(phead, arr);
        arr_to_phead(phead, arr);
    }

    show_chain(phead);
    for (i = 0; i < N; i++) {
        destroy_chain(&arr[i]);
    }
    destroy_chain(&phead);
    return 0;
}

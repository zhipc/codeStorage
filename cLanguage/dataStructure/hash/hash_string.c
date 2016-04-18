#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 26

typedef struct node {
    char *str;
    struct node *prev;
    struct node *next;
}snode, *pnode;

void create_memory(void **p, int size)
{
    *p = malloc(size);
    if (*p == NULL) {
        perror("malloc");
        exit(-1);
    }
}

void init_node(pnode *phead, int size)
{
    create_memory((void **)phead, size);
    (*phead)->prev = *phead;
    (*phead)->next = *phead;
}

void create_chain(pnode arr[])
{
    pnode pnew;

    while (1) {
        char buf[1024] = "";
        scanf("%s", buf);
        //if (strcmp(buf, "quit") == 0) {
        if (strlen(buf) == 0) {
            break;
        }
        init_node(&pnew, sizeof(snode));
        create_memory((void **)&pnew->str, strlen(buf)+1);
        strcpy(pnew->str, buf);

        pnew->next = arr[*buf - 'a'];
        pnew->prev = arr[*buf - 'a']->prev;
        arr[*buf - 'a']->prev->next = pnew;
        arr[*buf - 'a']->prev = pnew;
    }
}

void show_chain(pnode arr[])
{
    int i;
    for (i = 0; i < N; i++) {
        if (arr[i]->next != arr[i]) {
            pnode pindex;
            printf("this is %c chain:\n", 'a' + i);
            for (pindex = arr[i]->next; pindex != arr[i]; pindex = pindex->next) {
                printf("%s ", pindex->str);
            }
            printf("\n\n");
        }
    }
}

void find_chain(pnode arr[])
{
    while (1) {
        printf("please input the word you want to find:\n");
        char buf[100] = "";
        pnode pindex = NULL;
        int count = 0;
        int column = 0;

        scanf("%s", buf);
        for (pindex = arr[*buf - 'a']->next; pindex != arr[*buf - 'a']; pindex = pindex->next) {
            column++;
            if (strcmp(buf, pindex->str) == 0) {
                count++;
                printf("this is the %d's %s\t", count, buf);
                printf("%s in %c chain %d column\n", buf, *buf, column);
            }
        }
        if (count == 0) {
            printf("no found\n");
        }
    }
}

int main()
{
    pnode arr[N];
    int i;
    for (i = 0; i < N; i++) {
        init_node(&arr[i], sizeof(snode));
    }
    create_chain(arr);
    show_chain(arr);
    find_chain(arr);
    return 0;
}

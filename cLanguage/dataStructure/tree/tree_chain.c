#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree *lc;
    struct tree *rc;
};

void init_node(struct tree **phead, int size)
{
    *phead = malloc(size);
    if (*phead == NULL) {
        perror("malloc");
        exit(-1);
    }

    (*phead)->lc = NULL;
    (*phead)->rc = NULL;
}

void init_node_head(struct tree **phead, int size)
{
    init_node(phead, size);
    int data;
    scanf("%d", &data);
    (*phead)->data = data;
}

void add_node(struct tree *phead, struct tree *pnew)
{
    if (phead->data >= pnew->data) {
        if (phead->lc == NULL) {
            phead->lc = pnew;
        } else {
            add_node(phead->lc, pnew);
        }
    } else {
        if (phead->rc == NULL) {
            phead->rc = pnew;
        } else {
            add_node(phead->rc, pnew);
        }
    }
}

void create_tree(struct tree *phead)
{
    struct tree *pnew;
    int data;
    while (1) {
        scanf("%d", &data);
        if (data < 0) {
            break;
        }
        init_node(&pnew, sizeof(struct tree));
        pnew->data = data;
        add_node(phead, pnew);
    }
}

void first_tree(struct tree *phead)
{
    printf("%d ", phead->data);
    if (phead->lc != NULL) {
        first_tree(phead->lc);
    }
    if (phead->rc != NULL) {
        first_tree(phead->rc);
    }
}

void middle_tree(struct tree *phead)
{
    if (phead->lc != NULL) {
        middle_tree(phead->lc);
    }
    printf("%d ", phead->data);
    if (phead->rc != NULL) {
        middle_tree(phead->rc);
    }
}

void last_tree(struct tree *phead)
{
    if (phead->lc != NULL) {
        last_tree(phead->lc);
    }
    if (phead->rc != NULL) {
        last_tree(phead->rc);
    }
    printf("%d ", phead->data);
}

void show_tree(struct tree *phead)
{
    printf("this is first tree:\n");
    first_tree(phead);
    printf("\n");
    printf("this is middle tree:\n");
    middle_tree(phead);
    printf("\n");
    printf("this is last tree:\n");
    last_tree(phead);
    printf("\n");
}

int main()
{
    struct tree *phead = NULL;
    init_node_head(&phead, sizeof(struct tree));
    create_tree(phead);
    show_tree(phead);
    return 0;
}

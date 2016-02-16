#include <stdio.h>
#include "queue.h"

typedef struct tree {
    char data;
    struct tree *lc;
    struct tree *rc;
}stree, *ptree;

void init_node(ptree *root)
{
    *root = malloc(sizeof(stree));
    if (*root == NULL) {
        perror("malloc");
    }

    (*root)->lc = NULL;
    (*root)->rc = NULL;
}
void create_tree(ptree *root)
{
    int data;
    scanf("%c", &data);
    if (data == '#') {
        *root = NULL;
    } else {
        init_node(root);
        (*root)->data = data;
        create_tree(&(*root)->lc);
        create_tree(&(*root)->rc);
    }
}

void op_tree(pnode queue, ptree root)
{
    queue_in(queue, root);
    while (1) {
        root = queue_out(queue);
        if (root->lc != NULL) {
            queue_in(queue, root->lc);
        }
        if (root->rc != NULL) {
            queue_in(queue, root->rc);
        }
    }
}

int main()
{
    ptree root = NULL;
    create_tree(&root);

    pnode queue = NULL;
    init_queue(&queue);
    queue_in(queue, root->data);

    show_queue(queue);
    return 0;
}

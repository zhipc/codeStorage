/*
 *先序创建二叉树，以‘#’表示当前节点为空
 *
 * */
#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    char data;
    struct tree *lc;
    struct tree *rc;
}stree, *ptree;

void init_node(ptree *root, int size)
{
    *root = malloc(size);
    if (*root == NULL) {
        perror("malloc");
        exit(-1);
    }
    (*root)->lc = NULL;
    (*root)->rc = NULL;
}

void create_tree(ptree *root)
{
    char c = getchar();
    if (c == '#') {
        *root = NULL;
    } else {
        init_node(root, sizeof(stree));
        (*root)->data = c;
        create_tree(&(*root)->lc);
        create_tree(&(*root)->rc);
    }
}

void first_tree(struct tree *root)
{
    printf("%c ", root->data);
    if (root->lc != NULL) {
        first_tree(root->lc);
    }   
    if (root->rc != NULL) {
        first_tree(root->rc);
    }   
}

void middle_tree(struct tree *root)
{
    if (root->lc != NULL) {
        middle_tree(root->lc);
    }   
    printf("%c ", root->data);
    if (root->rc != NULL) {
        middle_tree(root->rc);
    }   
}

void last_tree(struct tree *root)
{
    if (root->lc != NULL) {
        last_tree(root->lc);
    }   
    if (root->rc != NULL) {
        last_tree(root->rc);
    }   
    printf("%c ", root->data);
}

void show_tree(struct tree *root)
{
    printf("this is first tree:\n");
    first_tree(root);
    printf("\n");
    printf("this is middle tree:\n");
    middle_tree(root);
    printf("\n");
    printf("this is last tree:\n");
    last_tree(root);
    printf("\n");
}

int main()
{
    ptree root = NULL;
    create_tree(&root);
    show_tree(root);
    return 0;
}

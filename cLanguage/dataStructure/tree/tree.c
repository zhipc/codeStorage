#include <stdio.h>
#define N 10

typedef struct tree {
    int data;
    int lc;
    int rc;
}stree, *ptree;

void input_arr(int arr[], int length)
{
    srand(time(NULL));
    int i;
    for (i = 0; i < length; i++) {
        arr[i] = rand() % 100;
    }
}

void output_arr(int arr[], int length)
{
    int i;
    for (i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void init_tree(stree arr[])
{
    int i;
    for (i = 0; i < N; i++) {
        arr[i].lc = -1;
        arr[i].rc = -1;
    }
}

void add_node(stree arr_tree[], int index, int new)
{
    if (arr_tree[index].data >= arr_tree[new].data) {
        if (arr_tree[index].lc == -1) {
            arr_tree[index].lc = new;
        } else {
            add_node(arr_tree, arr_tree[index].lc, new);
        }
    } else {
        if (arr_tree[index].rc == -1) {
            arr_tree[index].rc = new;
        } else {
            add_node(arr_tree, arr_tree[index].rc, new);
        }
    }
}

void create_tree(stree arr_tree[], int arr[])
{
    int i;
    for (i = 0; i < N; i++) {
        arr_tree[i].data = arr[i];
        if (i != 0) {
            add_node(arr_tree, 0, i);
        }
    }
}

void first_tree(stree arr_tree[], int index)
{
    printf("%d ", arr_tree[index].data);
    if (arr_tree[index].lc != -1) {
        first_tree(arr_tree, arr_tree[index].lc);
    }
    if (arr_tree[index].rc != -1) {
        first_tree(arr_tree, arr_tree[index].rc);
    }
}

void middle_tree(stree arr_tree[], int index)
{
    if (arr_tree[index].lc != -1) {
        middle_tree(arr_tree, arr_tree[index].lc);
    }
    printf("%d ", arr_tree[index].data);
    if (arr_tree[index].rc != -1) {
        middle_tree(arr_tree, arr_tree[index].rc);
    }
}

void last_tree(stree arr_tree[], int index)
{
    if (arr_tree[index].lc != -1) {
        last_tree(arr_tree, arr_tree[index].lc);
    }
    if (arr_tree[index].rc != -1) {
        last_tree(arr_tree, arr_tree[index].rc);
    }
    printf("%d ", arr_tree[index].data);
}

void show_tree(stree arr_tree[], int index)
{
    printf("this is first tree:\n");
    first_tree(arr_tree, index);
    printf("\n");
    printf("this is middle tree:\n");
    middle_tree(arr_tree, index);
    printf("\n");
    printf("this is last tree:\n");
    last_tree(arr_tree, index);
    printf("\n");
}

int main()
{
    int arr[N];
    input_arr(arr, N);
    output_arr(arr, N);
    stree arr_tree[N];
    init_tree(arr_tree);
    create_tree(arr_tree, arr);
    show_tree(arr_tree, 0);
    return 0;
}
